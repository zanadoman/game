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
             uint8_t color_g, uint8_t color_b, float damage)
    : entity({}, x + x_speed, y + y_speed) {
    float normalization;
    float x_offset;
    float y_offset;
    float i;

    _z = z + z_speed;
    _x_speed = x_speed;
    _y_speed = y_speed;
    _z_speed = z_speed;

    normalization =
        sqrtf(powf(_x_speed, 2) + powf(_y_speed, 2) + powf(_z_speed, 2));

    _half_length = abs(_z_speed) / normalization * length / 2;
    _length_skip = _half_length / 10.5f;
    _damage = damage;

    x_offset = _x_speed / normalization * length * (0 < _z_speed ? 1 : -1);
    y_offset = _y_speed / normalization * length * (0 < _z_speed ? 1 : -1);

    for (i = -1; i <= 1; i += 0.1f) {
        _sprites.push_back(std::shared_ptr<wze::sprite>(new wze::sprite(
            this->x(), this->y(), this->z(), 0, diameter, diameter, true,
            assets::laser_texture(), color_r, color_g, color_b,
            std::numeric_limits<uint8_t>::max(), wze::FLIP_NONE, true,
            std::numeric_limits<uint8_t>::max(), false, x_offset / 2 * i,
            y_offset / 2 * i, 0, true, true, false, false, false)));
    }

    std::ranges::for_each(
        _sprites, [this](std::shared_ptr<wze::sprite> const& sprite) -> void {
            components().push_back(sprite);
        });
}

bool laser::update(player_ship& player_ship,
                   std::vector<enemy_ship>& enemy_ships,
                   std::vector<asteroid>& asteroids,
                   std::vector<asteroid_loot>& asteroid_loots) {
    float z_movement;
    size_t i;

    set_x(x() + _x_speed * wze::timer::delta_time());
    set_y(y() + _y_speed * wze::timer::delta_time());
    _z += z_movement = _z_speed * wze::timer::delta_time();

    for (asteroid& asteroid : asteroids) {
        if (asteroid.z() - abs(z_movement) < z() &&
            z() < asteroid.z() + abs(z_movement) &&
            asteroid.hitbox().inside(x(), y())) {
            asteroid.damage(asteroid_loots, _damage);
            return false;
        }
    }

    for (enemy_ship& enemy_ship : enemy_ships) {
        if (enemy_ship.z() - abs(z_movement) < z() &&
            z() < enemy_ship.z() + abs(z_movement) &&
            enemy_ship.hitbox()->inside(x(), y())) {
            enemy_ship.damage(_damage);
            return false;
        }
    }

    if (player_ship.z() - abs(z_movement) < z() &&
        z() < player_ship.z() + abs(z_movement) &&
        player_ship.hitbox()->inside(x(), y())) {
        player_ship.damage(_damage);
        return false;
    }

    for (i = 0; i < _sprites.size(); ++i) {
        _sprites.at(i)->set_z(z() - _half_length + _length_skip * i);
    }

    return true;
}
