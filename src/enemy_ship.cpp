#include <game/assets.hpp>
#include <game/asteroid.hpp>
#include <game/enemy_ship.hpp>
#include <game/laser.hpp>
#include <game/player_ship.hpp>

bool enemy_ship::dodge(float x, float y, float z, float near) {
    float x_distance;
    float y_distance;
    float distance;

    if (z - near < this->z() && this->z() < z + near &&
        (distance = wze::math::length(x_distance = this->x() - x,
                                      y_distance = this->y() - y)) < near) {
        if (!x_distance && !y_distance) {
            x_distance = wze::math::random(-1.f, 1.f);
            y_distance = wze::math::random(-1.f, 1.f);
            distance = wze::math::length(x_distance, y_distance);
        }
        _x_speed = x_distance / distance * _speed;
        _y_speed = y_distance / distance * _speed;
        return true;
    }

    return false;
}

bool enemy_ship::dodge_asteroids(std::vector<asteroid> const& asteroids) {
    for (asteroid const& asteroid : asteroids) {
        if (dodge(asteroid.x(), asteroid.y(), asteroid.z(), 7'000)) {
            return true;
        }
    }

    return false;
}

bool enemy_ship::dodge_enemy_ships(std::vector<enemy_ship> const& enemy_ships) {
    for (enemy_ship const& enemy_ship : enemy_ships) {
        if (&enemy_ship != this &&
            dodge(enemy_ship.x(), enemy_ship.y(), enemy_ship.z(), 20'000)) {
            return true;
        }
    }

    return false;
}

bool enemy_ship::follow_player_ship(player_ship const& player_ship) {
    float x_distance;
    float y_distance;
    float distance;
    bool adjusted;

    x_distance = player_ship.x() - x();
    y_distance = player_ship.y() - y();
    distance = wze::math::length(x_distance, y_distance);
    adjusted = false;

    if (20'000 < distance) {
        _x_speed = x_distance / distance * _speed;
        _y_speed = y_distance / distance * _speed;
        adjusted = true;
    }

    if (z() < player_ship.z() + 20'000) {
        _z_speed = _speed;
        adjusted = true;
    } else if (player_ship.z() + 50'000 < z()) {
        _z_speed = -_speed;
        adjusted = true;
    }

    return adjusted;
}

void enemy_ship::update_appearance() {
    float speed_length;
    float speed_angle;
    float x_speed;
    float y_speed;

    speed_length = wze::math::length(_x_speed, _y_speed);
    speed_angle = wze::math::angle(_x_speed, _y_speed) + angle();
    x_speed = wze::math::move_x(speed_length, speed_angle);
    y_speed = wze::math::move_y(speed_length, speed_angle);

    if (_target_locked) {
        if (abs(x_speed) < abs(y_speed)) {
            if (0 < y_speed) {
                _appearance->set_texture(
                    _textures().at(ENEMY_FRONT_DOWN_TEXTURE));
            } else {
                _appearance->set_texture(
                    _textures().at(ENEMY_FRONT_UP_TEXTURE));
            }
        } else if (abs(y_speed) < abs(x_speed)) {
            if (0 < x_speed) {
                _appearance->set_texture(
                    _textures().at(ENEMY_FRONT_RIGHT_TEXTURE));
            } else {
                _appearance->set_texture(
                    _textures().at(ENEMY_FRONT_LEFT_TEXTURE));
            }
        } else {
            _appearance->set_texture(_textures().at(ENEMY_FRONT_TEXTURE));
        }
    } else {
        if (abs(x_speed) < abs(y_speed)) {
            if (0 < y_speed) {
                _appearance->set_texture(
                    _textures().at(ENEMY_REAR_DOWN_TEXTURE));
            } else {
                _appearance->set_texture(_textures().at(ENEMY_REAR_UP_TEXTURE));
            }
        } else if (abs(y_speed) < abs(x_speed)) {
            if (0 < x_speed) {
                _appearance->set_texture(
                    _textures().at(ENEMY_REAR_RIGHT_TEXTURE));
            } else {
                _appearance->set_texture(
                    _textures().at(ENEMY_REAR_LEFT_TEXTURE));
            }
        } else {
            _appearance->set_texture(_textures().at(ENEMY_FRONT_TEXTURE));
        }
    }
}

void enemy_ship::shoot(player_ship const& player_ship,
                       std::vector<laser>& lasers,
                       std::vector<wze::speaker>& speakers) {
    float x_distance;
    float y_distance;
    float z_distance;
    float normalization;
    std::pair<float, float> cannon;
    float speed;

    cannon = (_active_cannon = !_active_cannon) ? _left_cannon : _right_cannon;
    x_distance = player_ship.x() - (x() + cannon.first);
    y_distance = player_ship.y() - (y() + cannon.second);
    z_distance = player_ship.z() - z();
    normalization =
        sqrtf(powf(x_distance, 2) + powf(y_distance, 2) + powf(z_distance, 2));
    speed = _speed * 10;

    lasers.push_back({x() + cannon.first, y() + cannon.second, z(),
                      x_distance / normalization * speed,
                      y_distance / normalization * speed,
                      z_distance / normalization * speed, 1'000, 300, 228, 44,
                      56, _damage, speakers});
}

void enemy_ship::update_particles() {
    std::ranges::for_each(_particles, [this](wze::sprite& particle) -> void {
        float distance;
        float ratio;
        float size;

        if (10'000 < (distance = sqrtf(powf(particle.x() - x(), 2) +
                                       powf(particle.y() - y(), 2) +
                                       powf(particle.z() - z(), 2)))) {
            particle.set_x(x() + wze::math::random(-1'000.f, 1'000.f));
            particle.set_y(y() + wze::math::random(-1'000.f, 1'000.f));
            particle.set_z(z() + wze::math::random(0.f, _target_locked
                                                            ? 10'000.f
                                                            : -10'000.f));
            distance = sqrtf(powf(particle.x() - x(), 2) +
                             powf(particle.y() - y(), 2) +
                             powf(particle.z() - z(), 2));
        }

        ratio = distance / 10'000;
        size = 100 + ratio * 300;

        particle.set_width(size);
        particle.set_height(size);
        particle.set_color_r(_particles_color_r);
        particle.set_color_g(_particles_color_g);
        particle.set_color_b(_particles_color_b);
        particle.set_color_a(
            round((1 - ratio) * std::numeric_limits<uint8_t>::max()));
    });
}

std::shared_ptr<wze::polygon> const& enemy_ship::hitbox() const {
    return _hitbox;
}

float enemy_ship::z() const {
    return _appearance->z();
}

void enemy_ship::set_z(float z) {
    _appearance->set_z(z);
}

enemy_ship::enemy_ship(float x, float y, float z,
                       enemy_difficulty enemy_difficulty)
    : entity({}, x, y) {
    switch (enemy_difficulty) {
    case ENEMY_DIFFICULTY_EASY:
        _textures = assets::enemies_easy_textures;
        _rear_loop = assets::enemies_easy_rear_loop_animation();
        _front_loop = assets::enemies_easy_front_loop_animation();
        _speed = 10;
        _damage = 10;
        _current_hitpoints = _max_hitpoints = 100;
        break;
    case ENEMY_DIFFICULTY_NORMAL:
        _textures = assets::enemies_normal_textures;
        _rear_loop = assets::enemies_normal_rear_loop_animation();
        _front_loop = assets::enemies_normal_front_loop_animation();
        _speed = 15;
        _damage = 20;
        _current_hitpoints = _max_hitpoints = 200;
        break;
    case ENEMY_DIFFICULTY_HARD:
        _textures = assets::enemies_hard_textures;
        _rear_loop = assets::enemies_hard_rear_loop_animation();
        _front_loop = assets::enemies_hard_front_loop_animation();
        _speed = 20;
        _damage = 30;
        _current_hitpoints = _max_hitpoints = 300;
        break;
    }

    _appearance = std::shared_ptr<wze::sprite>(new wze::sprite(
        this->x(), this->y(), z, 0, 8'000, 8'000, true,
        _textures().at(ENEMY_REAR_TEXTURE), std::numeric_limits<uint8_t>::max(),
        std::numeric_limits<uint8_t>::max(),
        std::numeric_limits<uint8_t>::max(), 0, wze::FLIP_NONE, true,
        std::numeric_limits<uint8_t>::max(), true, 0, 0, 0, true, true, true,
        false, false));
    _rear_loop.set_frame_time(150);
    _rear_loop.targets().push_back({_appearance});
    _front_loop.set_frame_time(150);
    _front_loop.targets().push_back({_appearance});
    _explosion = {assets::enemies_explosion_animation(), 40, {_appearance}};
    _hitbox = std::shared_ptr<wze::polygon>(
        new wze::polygon({{-7'000, 0}, {0, 3'000}, {7'000, 0}, {0, -3'000}},
                         this->x(), this->y()));

    _x_speed = 0;
    _y_speed = 0;
    _z_speed = 0;

    _last_appearance_update = 0;

    _left_cannon = {this->x() - 2'000, this->y() + 500};
    _right_cannon = {this->x() + 2'000, this->y() + 500};
    _active_cannon = false;
    _attack_begin = 0;
    _attacking = false;
    _target_locked = false;
    _last_shot = 0;

    std::ranges::for_each(_particles, [](wze::sprite& particle) -> void {
        particle.set_spatial(true);
        particle.set_texture(assets::placeholder_texture());
    });
    _particles_color_r = 61;
    _particles_color_g = 177;
    _particles_color_b = 200;

    components().push_back(_appearance);
    components().push_back(_hitbox);
}

bool enemy_ship::update(player_ship const& player_ship,
                        std::vector<enemy_ship> const& enemy_ships,
                        std::vector<asteroid> const& asteroids,
                        std::vector<laser>& lasers,
                        std::vector<wze::speaker>& speakers) {
    bool on_target;

    if (!_current_hitpoints) {
        return !_explosion.play();
    }

    if (_appearance->color_a() != std::numeric_limits<uint8_t>::max()) {
        _appearance->set_color_a(
            std::min(_appearance->color_a() + wze::timer::delta_time(),
                     (float)std::numeric_limits<uint8_t>::max()));
    }

    on_target =
        !dodge_asteroids(asteroids) && !dodge_enemy_ships(enemy_ships) &&
        !dodge(player_ship.x(), player_ship.y(), player_ship.z(), 7'000) &&
        !follow_player_ship(player_ship);

    set_x(x() + _x_speed * wze::timer::delta_time());
    set_y(y() + _y_speed * wze::timer::delta_time());
    set_z(z() + _z_speed * wze::timer::delta_time());
    if (angle() < player_ship.angle() - wze::math::to_radians(10)) {
        set_angle(angle() + _speed / 1'500 * wze::timer::delta_time());
    } else if (player_ship.angle() + wze::math::to_radians(10) < angle()) {
        set_angle(angle() - _speed / 1'500 * wze::timer::delta_time());
    }

    if (_attacking && _attack_begin + 2'500 < wze::timer::current_time()) {
        _attacking = false;
    } else if (on_target &&
               _attack_begin + 5'000 < wze::timer::current_time()) {
        _attacking = true;
        _attack_begin = wze::timer::current_time();
    }

    if (_attacking && !_target_locked) {
        if (_rear_loop.play()) {
            set_angle(angle() + (wze::math::random<bool>(0.5)
                                     ? wze::math::to_radians(180)
                                     : -wze::math::to_radians(180)));
            _target_locked = true;
            _rear_loop.reset();
        }
    } else if (!_attacking && _target_locked) {
        if (_front_loop.play()) {
            set_angle(angle() + (wze::math::random<bool>(0.5)
                                     ? wze::math::to_radians(180)
                                     : -wze::math::to_radians(180)));
            _target_locked = false;
            _front_loop.reset();
        }
    } else if (_last_appearance_update + 150 < wze::timer::current_time()) {
        update_appearance();
        _last_appearance_update = wze::timer::current_time();
    }

    if (_attacking && _target_locked &&
        _last_shot + 300 < wze::timer::current_time()) {
        _left_cannon.first =
            wze::math::transform_x(-2'000, 500, transformation_matrix());
        _left_cannon.second =
            wze::math::transform_y(-2'000, 500, transformation_matrix());
        _right_cannon.first =
            wze::math::transform_x(2'000, 500, transformation_matrix());
        _right_cannon.second =
            wze::math::transform_y(2'000, 500, transformation_matrix());
        shoot(player_ship, lasers, speakers);
        _last_shot = wze::timer::current_time();
    }

    update_particles();

    return true;
}

void enemy_ship::damage(uint16_t hitpoints) {
    if (_current_hitpoints) {
        _current_hitpoints = std::max(0, _current_hitpoints - hitpoints);
        _particles_color_r =
            228 - ((float)_current_hitpoints / (float)_max_hitpoints) * 167;
        _particles_color_g =
            44 + ((float)_current_hitpoints / (float)_max_hitpoints) * 133;
        _particles_color_b =
            56 + ((float)_current_hitpoints / (float)_max_hitpoints) * 144;
    }
}
