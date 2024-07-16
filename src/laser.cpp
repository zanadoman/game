#include <game/assets.hpp>
#include <game/laser.hpp>

float laser::z() const {
    return _z;
}

laser::laser(float x, float y, float z, float x_speed, float y_speed,
             float z_speed, float length, float diameter, uint8_t color_r,
             uint8_t color_g, uint8_t color_b)
    : entity({}, x, y) {
    size_t i;

    _z = z;
    _x_speed = x_speed;
    _y_speed = y_speed;
    _z_speed = z_speed;
    _half_length = length / 2;
    _length_skip = _half_length / 10;

    for (i = 0; i != 20; ++i) {
        _sprites.push_back(std::shared_ptr<wze::sprite>(new wze::sprite(
            this->x(), this->y(), this->z(), 0, diameter, diameter, true,
            assets::laser_texture(), color_r, color_g, color_b,
            std::numeric_limits<uint8_t>::max(), wze::FLIP_NONE, true,
            std::numeric_limits<uint8_t>::max(), false, 0, 0, 0, true, true,
            false, false, false)));
    }

    std::ranges::for_each(
        _sprites, [this](std::shared_ptr<wze::sprite> const& sprite) -> void {
            components().push_back(sprite);
        });
}

bool laser::update(std::vector<asteroid>& asteroids) {
    float z_movement;

    set_x(x() + _x_speed * wze::timer::delta_time());
    set_y(y() + _y_speed * wze::timer::delta_time());
    _z += z_movement = _z_speed * wze::timer::delta_time();

    for (asteroid& asteroid : asteroids) {
        if (asteroid.z() - z_movement < z() &&
            z() <= asteroid.z() + z_movement &&
            asteroid.hitbox().inside(x(), y())) {
            asteroid.damage(10);
            return false;
        }
    }

    for (size_t i = 0; i < _sprites.size(); ++i) {
        _sprites.at(i)->set_z(z() - _half_length + _length_skip * i);
    }

    return true;
}
