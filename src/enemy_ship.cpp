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

    if (15'000 < distance) {
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
                _appearance->set_texture(assets::enemy_front_down_texture());
            } else {
                _appearance->set_texture(assets::enemy_front_up_texture());
            }
        } else if (abs(y_speed) < abs(x_speed)) {
            if (0 < x_speed) {
                _appearance->set_texture(assets::enemy_front_right_texture());
            } else {
                _appearance->set_texture(assets::enemy_front_left_texture());
            }
        } else {
            _appearance->set_texture(assets::enemy_front_texture());
        }
    } else {
        if (abs(x_speed) < abs(y_speed)) {
            if (0 < y_speed) {
                _appearance->set_texture(assets::enemy_rear_down_texture());
            } else {
                _appearance->set_texture(assets::enemy_rear_up_texture());
            }
        } else if (abs(y_speed) < abs(x_speed)) {
            if (0 < x_speed) {
                _appearance->set_texture(assets::enemy_rear_right_texture());
            } else {
                _appearance->set_texture(assets::enemy_rear_left_texture());
            }
        } else {
            _appearance->set_texture(assets::enemy_rear_texture());
        }
    }
}

void enemy_ship::shoot(player_ship const& player_ship,
                       std::vector<laser>& lasers) {
    float x_distance;
    float y_distance;
    float z_distance;
    float normalization;
    std::pair<float, float> cannon;

    cannon = (_active_cannon = !_active_cannon) ? _left_cannon : _right_cannon;
    x_distance = player_ship.x() - (x() + cannon.first);
    y_distance = player_ship.y() - (y() + cannon.second);
    z_distance = player_ship.z() - z();
    normalization =
        sqrtf(powf(x_distance, 2) + powf(y_distance, 2) + powf(z_distance, 2));

    lasers.push_back(
        {x() + cannon.first, y() + cannon.second, z(),
         x_distance / normalization * 100, y_distance / normalization * 100,
         z_distance / normalization * 100, 1000, 300, 228, 44, 56, 10});
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

enemy_ship::enemy_ship(float x, float y, float z) : entity({}, x, y) {
    _appearance = std::shared_ptr<wze::sprite>(new wze::sprite(
        this->x(), this->y(), z, 0, 8000, 8000, true,
        assets::enemy_rear_texture(), std::numeric_limits<uint8_t>::max(),
        std::numeric_limits<uint8_t>::max(),
        std::numeric_limits<uint8_t>::max(),
        std::numeric_limits<uint8_t>::max(), wze::FLIP_NONE, true,
        std::numeric_limits<uint8_t>::max(), true, 0, 0, 0, true, true, true,
        false, false));
    _rear_loop = {assets::enemy_rear_loop_animation(), 150, {_appearance}};
    _front_loop = {assets::enemy_front_loop_animation(), 150, {_appearance}};
    _explosion = {assets::enemy_explosion_animation(), 40, {_appearance}};
    _hitbox = std::shared_ptr<wze::polygon>(
        new wze::polygon({{-7'000, 0}, {0, 3'000}, {7'000, 0}, {0, -3'000}},
                         this->x(), this->y()));

    _speed = 10;
    _x_speed = 0;
    _y_speed = 0;
    _z_speed = 0;

    _last_appearance_update = 0;

    _attack_begin = 0;
    _attacking = false;
    _target_locked = false;
    _active_cannon = false;
    _last_shot = 0;
    _reload_time = 300;

    _hitpoints = 100;

    components().push_back(_appearance);
    components().push_back(_hitbox);
}

bool enemy_ship::update(player_ship const& player_ship,
                        std::vector<enemy_ship> const& enemy_ships,
                        std::vector<asteroid> const& asteroids,
                        std::vector<laser>& lasers) {
    bool on_target;

    if (_hitpoints <= 0) {
        return !_explosion.play();
    }

    on_target =
        !dodge_asteroids(asteroids) && !dodge_enemy_ships(enemy_ships) &&
        !dodge(player_ship.x(), player_ship.y(), player_ship.z(), 7'000) &&
        !follow_player_ship(player_ship);

    set_x(x() + _x_speed * wze::timer::delta_time());
    set_y(y() + _y_speed * wze::timer::delta_time());
    set_z(z() + _z_speed * wze::timer::delta_time());
    if (angle() < player_ship.angle() - wze::math::to_radians(10)) {
        set_angle(angle() + 0.01f * wze::timer::delta_time());
    } else if (player_ship.angle() + wze::math::to_radians(10) < angle()) {
        set_angle(angle() - 0.01f * wze::timer::delta_time());
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
        _last_shot + _reload_time < wze::timer::current_time()) {
        _left_cannon.first =
            wze::math::transform_x(-2000, 500, transformation_matrix());
        _left_cannon.second =
            wze::math::transform_y(-2000, 500, transformation_matrix());
        _right_cannon.first =
            wze::math::transform_x(2000, 500, transformation_matrix());
        _right_cannon.second =
            wze::math::transform_y(2000, 500, transformation_matrix());
        shoot(player_ship, lasers);
        _last_shot = wze::timer::current_time();
    }

    return true;
}

void enemy_ship::damage(float hitpoints) {
    if (0 < _hitpoints) {
        _hitpoints -= hitpoints;
    }
}
