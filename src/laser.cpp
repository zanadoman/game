#include <game/assets.hpp>
#include <game/asteroid.hpp>
#include <game/enemy_ship.hpp>
#include <game/laser.hpp>
#include <game/player_ship.hpp>

float laser::z() const {
    return _z;
}

laser::laser(float x, float y, float z, float x_speed, float y_speed,
             float z_speed, float length, float diameter, uint8_t color_r,
             uint8_t color_g, uint8_t color_b, uint16_t damage,
             std::vector<wze::speaker>& speakers)
    : entity({}, x + x_speed, y + y_speed) {
    float normalization;
    float x_offset;
    float y_offset;
    float i;

    _explosion = {assets::laser_explosion_animation(), 50, {}};
    _diameter = diameter;
    _color_r = color_r;
    _color_g = color_g;
    _color_b = color_b;

    _z = z + z_speed;
    _x_speed = x_speed;
    _y_speed = y_speed;
    _z_speed = z_speed;

    normalization =
        sqrtf(powf(_x_speed, 2) + powf(_y_speed, 2) + powf(_z_speed, 2));

    _half_length = abs(_z_speed) / normalization * length / 2;
    _length_skip = _half_length / 10.5f;
    _damage = damage;
    _destroyed = false;

    x_offset = _x_speed / normalization * length * (0 < _z_speed ? 1 : -1);
    y_offset = _y_speed / normalization * length * (0 < _z_speed ? 1 : -1);

    for (i = -1; i <= 1; i += 0.1f) {
        _sprites.push_back(std::shared_ptr<wze::sprite>(new wze::sprite(
            this->x(), this->y(), this->z(), 0, _diameter, _diameter, true,
            assets::laser_texture(), _color_r, _color_g, _color_b,
            std::numeric_limits<uint8_t>::max(), wze::FLIP_NONE, true,
            std::numeric_limits<uint8_t>::max(), false, x_offset / 2 * i,
            y_offset / 2 * i, 0, true, true, false, false, false)));
    }

    std::ranges::for_each(
        _sprites, [this](std::shared_ptr<wze::sprite> const& sprite) -> void {
            components().push_back(sprite);
        });

    _passed_by = false;

    speakers.push_back({assets::laser_sound(),
                        std::numeric_limits<int8_t>::max() / 2, 50'000, false,
                        x, y, z, true});
    speakers.back().align_panning();
    speakers.back().play();
}

bool laser::update(player_ship& player_ship,
                   std::vector<enemy_ship>& enemy_ships,
                   std::vector<asteroid>& asteroids,
                   std::vector<asteroid_loot>& asteroid_loots,
                   std::vector<wze::speaker>& speakers) {
    float z_movement;
    size_t i;

    if (_destroyed) {
        return !_explosion.play();
    }

    set_x(x() + _x_speed * wze::timer::delta_time());
    set_y(y() + _y_speed * wze::timer::delta_time());
    _z += z_movement = _z_speed * wze::timer::delta_time();

    for (asteroid& asteroid : asteroids) {
        if (asteroid.z() - abs(z_movement) < z() &&
            z() < asteroid.z() + abs(z_movement) &&
            asteroid.hitbox().inside(x(), y())) {
            asteroid.damage(asteroid_loots, speakers, _damage);
            _destroyed = true;
        }
    }

    for (enemy_ship& enemy_ship : enemy_ships) {
        if (enemy_ship.z() - abs(z_movement) < z() &&
            z() < enemy_ship.z() + abs(z_movement) &&
            enemy_ship.hitbox()->inside(x(), y())) {
            enemy_ship.damage(speakers, _damage);
            _destroyed = true;
        }
    }

    if (player_ship.z() - abs(z_movement) < z() &&
        z() < player_ship.z() + abs(z_movement)) {
        if (!_passed_by) {
            speakers.push_back({assets::laser_passing_sound(),
                                std::numeric_limits<int8_t>::max(), 25'000,
                                false, x(), y(), z(), true});
            speakers.back().align_panning();
            speakers.back().play();
            _passed_by = true;
        }
        if (player_ship.hitbox()->inside(x(), y())) {
            player_ship.damage(_damage);
            _destroyed = true;
        }
    }

    if (_destroyed) {
        _sprites.clear();
        _appearance = std::shared_ptr<wze::sprite>(new wze::sprite(
            x(), y(), z() + _half_length * (0 < _z_speed ? -1 : 1),
            wze::math::to_radians(wze::math::random(0.f, 360.f)),
            _diameter * 10, _diameter * 10, true, assets::laser_texture(),
            _color_r, _color_g, _color_b, std::numeric_limits<uint8_t>::max(),
            wze::FLIP_NONE, true, std::numeric_limits<uint8_t>::max(), true, 0,
            0, 0, true, true, false, false, false));
        _explosion.targets().push_back(_appearance);
        speakers.push_back({assets::laser_explosion_sound(),
                            std::numeric_limits<int8_t>::max() / 4, 50'000,
                            false, x(), y(), z(), true});
        speakers.back().align_panning();
        speakers.back().play();
    } else {
        for (i = 0; i < _sprites.size(); ++i) {
            _sprites.at(i)->set_z(z() - _half_length + _length_skip * i);
        }
    }

    return true;
}
