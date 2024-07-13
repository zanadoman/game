#include <game/space.hpp>
#include <game/assets.hpp>

asteroid space::create_asteroid() {
    float x;
    float y;
    float z;
    float v;
    float r;

    x = wze::math::random(-100, 100);
    y = wze::math::random(-100, 100);
    z = wze::math::random(-100, 100);

    if ((v = sqrt(powf(x, 2) + powf(y, 2) + powf(z, 2)))) {
        x /= v;
        y /= v;
        z /= v;
    }

    r = wze::math::random(50000, 200000);
    printf("%f %f %f\n", (double)(x * r), (double)(y * r), (double)(z * r));

    return {_player.x() + x * r, _player.y() + y * r, _player.z() + z * r};
}

void space::update_asteroids() {
    size_t i;

    for (i = 0; i != _asteroids.size(); ++i) {
        if (200000 <
            sqrtf(powf(_asteroids.at(i).appearance().x() - _player.x(), 2) +
                  powf(_asteroids.at(i).appearance().y() - _player.y(), 2) +
                  powf(_asteroids.at(i).appearance().z() - _player.z(), 2))) {
            _asteroids.at(i).~asteroid();
            new (&_asteroids.at(i)) asteroid(create_asteroid());
        }
        _asteroids.at(i).update();
    }
}

space::space() {
    size_t i;

    wze::renderer::set_space_texture(assets::space_texture());

    for (i = 0; i != 1000; ++i) {
        _asteroids.push_back(create_asteroid());
    }
}

void space::update() {
    _player.update();
    update_asteroids();
}
