#include <game/assets.hpp>
#include <game/laser.hpp>

float laser::z() const {
    return _z;
}

void laser::set_z(float z) {
    _z = z;
}

laser::laser(float x, float y, float z, float x_angle, float y_angle)
    : entity({}, x, y) {
    set_z(z);
    _x_angle = x_angle;
    _y_angle = y_angle;

    /* eltolt sprite generálás */
    for (int8_t i = -50; i <= 50; i += 5) {
        _sprites.push_back(std::shared_ptr<wze::sprite>(
            new wze::sprite(this->x(), this->y(), this->z(), 0, 15, 15, true,
                            assets::laser_texture(), 0,
                            std::numeric_limits<uint8_t>::max(), 0)));
        _sprites.back()->set_x_offset(i * cosf(_y_angle));
        _sprites.back()->set_y_offset(i * sinf(_x_angle));
    }

    /* komponensek hozzáadása az entity base-hez */
    for (std::shared_ptr<wze::sprite> const& sprite : _sprites) {
        components().push_back(sprite);
    }

    recompose(); /* frissíti az új komponenseket */
}

void laser::update() {
    /* entity mozgatása */
    set_x(x() + cosf(_y_angle) * wze::timer::delta_time());
    set_y(y() + sinf(_x_angle) * wze::timer::delta_time());
    set_z(z() + sinf(_y_angle) * cosf(_x_angle) * wze::timer::delta_time());

    /* sprite-ok mozgatása */
    for (size_t i = 0; i < _sprites.size(); ++i) {
        _sprites.at(i)->set_z(z() - 50 +
                              i * 5 * sinf(_y_angle) * cosf(_x_angle));
    }
}
