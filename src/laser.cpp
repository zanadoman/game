#include <game/assets.hpp>
#include <game/laser.hpp>

float laser::z() const {
    return _z;
}

laser::laser(float x, float y, float z, float x_speed, float y_speed,
             float z_speed)
    : entity({}, x, y) {
    float i;

    _z = z;
    _x_speed = x_speed;
    _y_speed = y_speed;
    _z_speed = z_speed;

    for (i = -1; i <= 1; i += 0.1f) {
        _sprites.push_back(std::shared_ptr<wze::sprite>(
            new wze::sprite(this->x(), this->y(), this->z(), 0, 100, 100, true,
                            assets::laser_texture(), 0,
                            std::numeric_limits<uint8_t>::max(), 0)));
        _sprites.back()->set_x_offset(i * x_speed / 2);
        _sprites.back()->set_y_offset(i * y_speed / 2);
    }

    std::ranges::for_each(
        _sprites, [this](std::shared_ptr<wze::sprite> const& sprite) -> void {
            components().push_back(sprite);
        });

    recompose();
}

void laser::update() {
    set_x(x() + _x_speed * wze::timer::delta_time());
    set_y(y() + _y_speed * wze::timer::delta_time());
    _z = z() + _z_speed * wze::timer::delta_time();

    for (size_t i = 0; i < _sprites.size(); ++i) {
        _sprites.at(i)->set_z(z() - 300 + i * 30);
    }
}
