#include <algorithm>
#include <game/assets.hpp>
#include <game/asteroid.hpp>
#include <game/player_ship.hpp>
#include <stdexcept>

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

asteroid::asteroid(float x, float y, float z)
    : _explosion(assets::asteroids_wolframite_explosion_animation(), 40, {}) {
    std::shared_ptr<wze::texture> texture;
    float roll;

    roll = wze::math::random(1.f, 100.f);

    if (97.5f < roll) {
        _material = MATERIAL_SAPPHIRE;
    } else if (92.5f < roll) {
        _material = MATERIAL_RUBY;
    } else if (87.5f < roll) {
        _material = MATERIAL_MOLDAVITE;
    } else if (80 < roll) {
        _material = MATERIAL_CARNEOL;
    } else if (50 < roll) {
        _material = MATERIAL_WOLFRAMITE;
    } else {
        _material = MATERIAL_PYRITE;
    }

    switch (material()) {
    case MATERIAL_PYRITE:
        texture = assets::asteroids_pyrite_texture();
        break;
    case MATERIAL_WOLFRAMITE:
        texture = assets::asteroids_wolframite_texture();
        break;
    case MATERIAL_CARNEOL:
        texture = assets::asteroids_carneol_texture();
        break;
    case MATERIAL_MOLDAVITE:
        texture = assets::asteroids_moldavite_texture();
        break;
    case MATERIAL_RUBY:
        texture = assets::asteroids_ruby_texture();
        break;
    case MATERIAL_SAPPHIRE:
        texture = assets::asteroids_sapphire_texture();
        break;
    default:
        throw std::out_of_range("shit happens");
    }

    _appearance = std::shared_ptr<wze::sprite>(new wze::sprite{
        x, y, z, wze::math::random(0, wze::math::to_radians(360)),
        wze::math::random(_minimum_size, _maximum_size),
        wze::math::random(_maximum_size, _maximum_size), true, texture,
        std::numeric_limits<uint8_t>::max(),
        std::numeric_limits<uint8_t>::max(),
        std::numeric_limits<uint8_t>::max(), 0});

    _hitbox = {{{-_appearance->width() / 2, -_appearance->height() / 2},
                {-_appearance->width() / 2, _appearance->height() / 2},
                {_appearance->width() / 2, _appearance->height() / 2},
                {_appearance->width() / 2, -_appearance->height() / 2}},
               this->x(),
               this->y(),
               this->z()};

    _explosion.targets().push_back(_appearance);
    _hitpoints = 40;
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
