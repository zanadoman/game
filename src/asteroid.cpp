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

asteroid::asteroid(float x, float y, float z, material material) {
    std::shared_ptr<wze::texture> texture;
    float diameter;
    float half_diameter;

    switch (_material = material) {
    case MATERIAL_PYRITE:
        texture = assets::asteroids_pyrite_texture();
        _explosion = {assets::asteroids_pyrite_explosion_animation()};
        _hitpoints = 30;
        break;

    case MATERIAL_WOLFRAMITE:
        texture = assets::asteroids_wolframite_texture();
        _explosion = {assets::asteroids_wolframite_explosion_animation()};
        _hitpoints = 50;
        break;

    case MATERIAL_CARNEOL:
        texture = assets::asteroids_carneol_texture();
        _explosion = {assets::asteroids_carneol_explosion_animation()};
        _hitpoints = 70;
        break;

    case MATERIAL_MOLDAVITE:
        texture = assets::asteroids_moldavite_texture();
        _explosion = {assets::asteroids_moldavite_explosion_animation()};
        _hitpoints = 90;
        break;

    case MATERIAL_RUBY:
        texture = assets::asteroids_ruby_texture();
        _explosion = {assets::asteroids_ruby_explosion_animation()};
        _hitpoints = 110;
        break;

    case MATERIAL_SAPPHIRE:
        texture = assets::asteroids_sapphire_texture();
        _explosion = {assets::asteroids_sapphire_explosion_animation()};
        _hitpoints = 130;
        break;
    }

    diameter = wze::math::random(4'000.f, 8'000.f);
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

bool asteroid::update(player_ship& player_ship,
                      std::vector<asteroid_loot>& asteroid_loots,
                      std::vector<wze::speaker>& speakers) {
    if (!_hitpoints) {
        return !_explosion.play();
    }

    if (_appearance->color_a() != std::numeric_limits<uint8_t>::max()) {
        _appearance->set_color_a(
            std::min(_appearance->color_a() + wze::timer::delta_time(),
                     (float)std::numeric_limits<uint8_t>::max()));
    }

    if (z() - 2'000 < player_ship.z() && player_ship.z() < z() + 2'000 &&
        player_ship.hitbox()->overlap(_hitbox)) {
        player_ship.damage(_hitpoints);
        damage(asteroid_loots, speakers, _hitpoints);
    }

    return true;
}

void asteroid::damage(std::vector<asteroid_loot>& asteroid_loots,
                      std::vector<wze::speaker>& speakers, uint16_t hitpoints) {
    if (_hitpoints && !(_hitpoints = std::max(0, _hitpoints - hitpoints))) {
        asteroid_loots.push_back({x(), y(), z(), _material});
        speakers.push_back({assets::explosion_sound(),
                            std::numeric_limits<int8_t>::max() / 2, 300'000,
                            false, x(), y(), z(), true});
        speakers.back().align_panning();
        speakers.back().play();
    }
}
