#include <game/assets.hpp>
#include <game/asteroid.hpp>
#include <immintrin.h>

enum material asteroid::material() const {
    return _material;
}

wze::sprite const& asteroid::appearance() const {
    return _appearance;
}

wze::polygon const& asteroid::hitbox() const {
    return _hitbox;
}

float asteroid::minimum_z() const {
    return _minimum_z;
}

float asteroid::maximum_z() const {
    return _maximum_z;
}

asteroid::asteroid(float x, float y, float z) {
    _appearance = {x,
                   y,
                   z,
                   (float)wze::math::random(0, wze::math::to_radians(360)),
                   (float)wze::math::random(3000, 6000),
                   (float)wze::math::random(3000, 6000),
                   true,
                   assets::asteroid_texture(),
                   std::numeric_limits<uint8_t>::max(),
                   std::numeric_limits<uint8_t>::max(),
                   std::numeric_limits<uint8_t>::max(),
                   0};
    _hitbox = {{}, x, y, z};
    _transparency = 0;
}

void asteroid::update() {
    if (_transparency != std::numeric_limits<uint8_t>::max()) {
        _transparency =
            std::min(_transparency + 0.1f * wze::timer::delta_time(),
                     (float)std::numeric_limits<uint8_t>::max());
        _appearance.set_color_a(_transparency);
    }
}
