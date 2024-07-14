#include <game/assets.hpp>
#include <game/space.hpp>

std::tuple<float, float, float> space::sphere_coordinate(float minimum,
                                                         float maximum) {
    float x;
    float y;
    float z;
    float normalization;
    float radius;

    x = wze::math::random(-1, 1);
    y = wze::math::random(-1, 1);
    z = wze::math::random(-1, 1);

    if ((normalization = sqrt(powf(x, 2) + powf(y, 2) + powf(z, 2)))) {
        x /= normalization;
        y /= normalization;
        z /= normalization;
    }

    radius = wze::math::random(minimum, maximum);
    return {x * radius, y * radius, z * radius};
}

void space::update_lasers() {
    std::vector<laser>::iterator iterator;

    for (iterator = _lasers.begin(); iterator != _lasers.end(); ++iterator) {
        if (_laser_far < sqrtf(powf(iterator->x() - _player.x(), 2) +
                               powf(iterator->y() - _player.y(), 2) +
                               powf(iterator->z() - _player.z(), 2))) {
            _lasers.erase(iterator--);
        } else {
            iterator->update();
        }
    }
}

void space::update_asteroids() {
    std::ranges::for_each(_asteroids, [this](asteroid& asteroid) -> void {
        if (_asteroid_far <
            sqrtf(powf(asteroid.appearance().x() - _player.x(), 2) +
                  powf(asteroid.appearance().y() - _player.y(), 2) +
                  powf(asteroid.appearance().z() - _player.z(), 2))) {
            asteroid.~asteroid();
            std::apply(
                [&asteroid](float x, float y, float z) -> void {
                    new (&asteroid) class asteroid(x, y, z);
                },
                sphere_coordinate(_asteroid_near, _asteroid_far));
        } else {
            asteroid.update();
        }
    });
}

space::space() {
    size_t i;

    wze::renderer::set_space_texture(assets::space_texture());

    for (i = 0; i != _asteroid_count; ++i) {
        std::apply([this](float x, float y,
                          float z) -> void { _asteroids.push_back({x, y, z}); },
                   sphere_coordinate(_asteroid_near, _asteroid_far));
    }
}

space::~space() {
    wze::renderer::set_space_texture({});
}

void space::update() {
    _player.update(_lasers, _asteroids);
    update_lasers();
    update_asteroids();
}
