#include <game/assets.hpp>
#include <game/laser.hpp>

float laser::z() const {
    return _z;
}

void laser::set_z(float z) {
    _z = z;
}

laser::laser(float x, float y, float z) {
    set_x(x);
    set_y(y);
    set_z(z);

    /* eltolt sprite generálás */
    for (float i = z - 50; i < z + 50; i += 5) {
        _sprites.push_back(std::shared_ptr<wze::sprite>(new wze::sprite(
            x, y, z + i, 0, 15, 15, true, assets::laser_texture(), 0,
            std::numeric_limits<uint8_t>::max(), 0)));
    }

    /* komponensek hozzáadása az entity base-hez */
    for (std::shared_ptr<wze::sprite> const& sprite : _sprites) {
        components().push_back(sprite);
    }

    recompose(); /* frissíti az új komponenseket */
}

void laser::update() {
    /* entity mozgatása */
    set_z(z() + wze::timer::delta_time());

    /* sprite-ok mozgatása */
    for (size_t i = 0; i < _sprites.size(); ++i) {
        _sprites.at(i)->set_z(z() - 50 + i * 5);
    }
}
