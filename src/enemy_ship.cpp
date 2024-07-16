#include <game/assets.hpp>
#include <game/enemy_ship.hpp>

float enemy_ship::z() const {
    return _z;
}

void enemy_ship::set_z(float z) {
    _z = z;
    _appearance->set_z(this->z());
}

void enemy_ship::dodge_asteroid(asteroid const& asteroid) {
    float x_difference;
    float y_difference;
    float normalization;

    x_difference = x() - asteroid.x();
    y_difference = y() - asteroid.y();
    if (!x_difference && !y_difference) {
        x_difference = wze::math::random(-1.f, 1.f);
        y_difference = wze::math::random(-1.f, 1.f);
    }

    normalization = wze::math::length(x_difference, y_difference);
    set_x(x() +
          x_difference / normalization * _speed * wze::timer::delta_time());
    set_y(y() +
          y_difference / normalization * _speed * wze::timer::delta_time());
}

enemy_ship::enemy_ship(float x, float y, float z) : entity({}, x, y) {
    _appearance = std::shared_ptr<wze::sprite>(new wze::sprite(
        this->x(), this->y(), z, 0, 4000, 4000, true,
        assets::placeholder_texture(), std::numeric_limits<uint8_t>::max(),
        std::numeric_limits<uint8_t>::max(),
        std::numeric_limits<uint8_t>::max(),
        std::numeric_limits<uint8_t>::max(), wze::FLIP_NONE, true,
        std::numeric_limits<uint8_t>::max(), true, 0, 0, 0, true, true, true,
        false, false));
    set_z(z);
    _speed = 10;
    components().push_back(_appearance);
}

bool enemy_ship::update(player_ship& player_ship,
                        std::vector<asteroid> const& asteroids) {
    float x_distance;
    float y_distance;
    float normalization;

    if (z() < player_ship.z() + 20000) {
        set_z(z() + _speed * wze::timer::delta_time());
    } else if (player_ship.z() + 50000 < z()) {
        set_z(z() - _speed * wze::timer::delta_time());
    }

    for (asteroid const& asteroid : asteroids) {
        if (asteroid.z() - 5000 < z() && z() < asteroid.z() + 5000 &&
            wze::math::length(asteroid.x() - x(), asteroid.y() - y()) < 10000) {
            dodge_asteroid(asteroid);
            return true;
        }
    }

    x_distance = player_ship.x() - x();
    y_distance = player_ship.y() - y();
    if (10000 < (normalization = wze::math::length(x_distance, y_distance))) {
        set_x(x() +
              x_distance / normalization * _speed * wze::timer::delta_time());
        set_y(y() +
              y_distance / normalization * _speed * wze::timer::delta_time());
    }

    return true;
}
