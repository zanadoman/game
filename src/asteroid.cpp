#include "game/enums.hpp"
#include <game/assets.hpp>
#include <game/asteroid.hpp>
#include <game/asteroid_loot.hpp>
#include <game/player_ship.hpp>

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

asteroid::asteroid(float x, float y, float z) {
    float value;
    std::shared_ptr<wze::texture> texture;
    float diameter;
    float half_diameter;

    value = wze::math::random(0.f, 100.f);
    if (97.5f < value) {
        texture = assets::asteroids_sapphire_texture();
        _explosion = {assets::asteroids_sapphire_explosion_animation()};
        _material = MATERIAL_SAPPHIRE;
        _hitpoints = 70;
    } else if (92.5f < value) {
        texture = assets::asteroids_ruby_texture();
        _explosion = {assets::asteroids_ruby_explosion_animation()};
        _material = MATERIAL_RUBY;
        _hitpoints = 60;
    } else if (87.5f < value) {
        texture = assets::asteroids_moldavite_texture();
        _explosion = {assets::asteroids_moldavite_explosion_animation()};
        _material = MATERIAL_MOLDAVITE;
        _hitpoints = 50;
    } else if (80 < value) {
        texture = assets::asteroids_carneol_texture();
        _explosion = {assets::asteroids_carneol_explosion_animation()};
        _material = MATERIAL_CARNEOL;
        _hitpoints = 40;
    } else if (50 < value) {
        texture = assets::asteroids_wolframite_texture();
        _explosion = {assets::asteroids_wolframite_explosion_animation()};
        _material = MATERIAL_WOLFRAMITE;
        _hitpoints = 30;
    } else {
        texture = assets::asteroids_pyrite_texture();
        _explosion = {assets::asteroids_pyrite_explosion_animation()};
        _material = MATERIAL_PYRITE;
        _hitpoints = 20;
    }

    diameter = wze::math::random(4000.f, 8000.f);
    _appearance = std::shared_ptr<wze::sprite>(new wze::sprite{
        x, y, z, wze::math::to_radians(wze::math::random(0.f, 360.f)), diameter,
        diameter, true, texture, std::numeric_limits<uint8_t>::max(),
        std::numeric_limits<uint8_t>::max(),
        std::numeric_limits<uint8_t>::max(), 0});

    _explosion.set_frame_time(40);
    _explosion.targets().push_back(_appearance);

    half_diameter = diameter / 2;
    _hitbox = {{{-half_diameter, -half_diameter},
                {-half_diameter, half_diameter},
                {half_diameter, half_diameter},
                {half_diameter, -half_diameter}},
               this->x(),
               this->y(),
               this->z()};
}

bool asteroid::update(player_ship& player_ship) {
    if (_hitpoints <= 0) {
        return !_explosion.play();
    }

    if (_appearance->color_a() != std::numeric_limits<uint8_t>::max()) {
        _appearance->set_color_a(
            std::min(_appearance->color_a() + wze::timer::delta_time(),
                     (float)std::numeric_limits<uint8_t>::max()));
    }

    if (z() - 2000 < player_ship.z() && player_ship.z() < z() + 2000 &&
        player_ship.hitbox()->overlap(_hitbox)) {
        player_ship.damage(_hitpoints);
        _hitpoints = 0;
    }

    return true;
}

void asteroid::damage(std::vector<asteroid_loot>& asteroid_loots,
                      float hitpoints) {
    if (0 < _hitpoints) {
        if ((_hitpoints -= hitpoints) <= 0) {
            asteroid_loots.push_back({x(), y(), z(), _material});
        }
    }
}
