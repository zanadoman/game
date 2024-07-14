#include <algorithm>
#include <game/assets.hpp>
#include <game/asteroid.hpp>

enum material asteroid::material() const {
    return _material;
}

wze::polygon const& asteroid::hitbox() const {
    return _hitbox;
}

float asteroid::x() const {
    return _appearance->x();
}

float asteroid::y() const {
    return _appearance->y();
}

float asteroid::z() const {
    return _appearance->z();
}

float asteroid::minimum_z() const {
    return _minimum_z;
}

float asteroid::maximum_z() const {
    return _maximum_z;
}

asteroid::asteroid(float x, float y, float z) : _explosion({}, 100, {}) {
    _material =
        (enum material)wze::math::random((int64_t)0, (int64_t)MATERIAL_COUNT);
    _appearance = std::shared_ptr<wze::sprite>(new wze::sprite{
        x, y, z, wze::math::random(0, wze::math::to_radians(360)),
        wze::math::random(_minimum_size, _maximum_size),
        wze::math::random(_maximum_size, _maximum_size), true,
        assets::asteroid_texture(), std::numeric_limits<uint8_t>::max(),
        std::numeric_limits<uint8_t>::max(),
        std::numeric_limits<uint8_t>::max(), 0});
    _hitbox = {{}, this->x(), this->y(), this->z()};
    _explosion.targets().push_back(_appearance);
    _hitpoints = 100;
    _minimum_z = this->z() - 100;
    _maximum_z = this->z() + 100;
}

bool asteroid::update() {
    if (_appearance->color_a() != std::numeric_limits<uint8_t>::max()) {
        _appearance->set_color_a(
            std::min(_appearance->color_a() + wze::timer::delta_time(),
                     (float)std::numeric_limits<uint8_t>::max()));
    }

    return !(_hitpoints <= 0 && _explosion.play());
}

void asteroid::damage(float hitpoints) {
    if (0 < _hitpoints) {
        _hitpoints -= hitpoints;
    }
}
