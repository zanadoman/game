#include <game/assets.hpp>
#include <game/asteroid.hpp>

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

asteroid::asteroid(float x, float y, float z) {
    float value;
    std::shared_ptr<wze::texture> texture;
    float diameter;
    float half_diameter;

    value = wze::math::random(0.f, 100.f);
    if (97.5f < value) {
        texture = assets::asteroids_sapphire_texture();
        _explosion =
            wze::animator(assets::asteroids_sapphire_explosion_animation());
        _hitpoints = 70;
    } else if (92.5f < value) {
        texture = assets::asteroids_ruby_texture();
        _explosion =
            wze::animator(assets::asteroids_ruby_explosion_animation());
        _hitpoints = 60;
    } else if (87.5f < value) {
        texture = assets::asteroids_moldavite_texture();
        _explosion =
            wze::animator(assets::asteroids_moldavite_explosion_animation());
        _hitpoints = 50;
    } else if (80 < value) {
        texture = assets::asteroids_carneol_texture();
        _explosion =
            wze::animator(assets::asteroids_carneol_explosion_animation());
        _hitpoints = 40;
    } else if (50 < value) {
        texture = assets::asteroids_wolframite_texture();
        _explosion =
            wze::animator(assets::asteroids_wolframite_explosion_animation());
        _hitpoints = 30;
    } else {
        texture = assets::asteroids_pyrite_texture();
        _explosion =
            wze::animator(assets::asteroids_pyrite_explosion_animation());
        _hitpoints = 20;
    }

    diameter = wze::math::random(4000.f, 8000.f);
    _appearance = std::shared_ptr<wze::sprite>(new wze::sprite{
        x, y, z, wze::math::random(0.f, wze::math::to_radians(360)), diameter,
        diameter, true, texture, std::numeric_limits<uint8_t>::max(),
        std::numeric_limits<uint8_t>::max(),
        std::numeric_limits<uint8_t>::max(), 0});

    half_diameter = diameter / 2;
    _hitbox = {{{-half_diameter, -half_diameter},
                {-half_diameter, half_diameter},
                {half_diameter, half_diameter},
                {half_diameter, -half_diameter}},
               this->x(),
               this->y(),
               this->z()};

    _explosion.set_frame_time(40);
    _explosion.targets().push_back(_appearance);

    _minimum_z = this->z() - 500;
    _maximum_z = this->z() + 500;
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
