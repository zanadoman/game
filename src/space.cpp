#include <game/assets.hpp>
#include <game/asteroid.hpp>
#include <game/asteroid_loot.hpp>
#include <game/enemy_ship.hpp>
#include <game/laser.hpp>
#include <game/space.hpp>

std::tuple<float, float, float> space::sphere_coordinate(float minimum,
                                                         float maximum) const {
    float x;
    float y;
    float z;
    float normalization;
    float radius;

    x = wze::math::random(-1.f, 1.f);
    y = wze::math::random(-1.f, 1.f);
    z = wze::math::random(-1.f, 1.f);

    if ((normalization = sqrt(powf(x, 2) + powf(y, 2) + powf(z, 2)))) {
        x /= normalization;
        y /= normalization;
        z /= normalization;
    }

    radius = wze::math::random(minimum, maximum);
    return {x * radius, y * radius, z * radius};
}

void space::update_enemy_ships() {
    std::vector<enemy_ship>::iterator enemy_ship;

    for (enemy_ship = _enemy_ships.begin(); enemy_ship != _enemy_ships.end();
         ++enemy_ship) {
        if (300'000 < sqrtf(powf(enemy_ship->x() - _player_ship.x(), 2) +
                            powf(enemy_ship->y() - _player_ship.y(), 2) +
                            powf(enemy_ship->z() - _player_ship.z(), 2)) ||
            !enemy_ship->update(_player_ship, _enemy_ships, _asteroids,
                                _lasers)) {
            _enemy_ships.erase(enemy_ship--);
        }
    }
}

void space::update_asteroids() {
    std::ranges::for_each(_asteroids, [this](asteroid& asteroid) -> void {
        if (300'000 < sqrtf(powf(asteroid.x() - _player_ship.x(), 2) +
                            powf(asteroid.y() - _player_ship.y(), 2) +
                            powf(asteroid.z() - _player_ship.z(), 2)) ||
            !asteroid.update(_player_ship)) {
            asteroid.~asteroid();
            std::apply(
                [this, &asteroid](float x, float y, float z) -> void {
                    new (&asteroid) class asteroid(_player_ship.x() + x,
                                                   _player_ship.y() + y,
                                                   _player_ship.z() + z);
                },
                sphere_coordinate(50'000, 300'000));
        }
    });
}

void space::update_asteroid_loots() {
    std::vector<asteroid_loot>::iterator asteroid_loot;

    for (asteroid_loot = _asteroid_loots.begin();
         asteroid_loot != _asteroid_loots.end(); ++asteroid_loot) {
        if (300'000 < sqrtf(powf(asteroid_loot->x() - _player_ship.x(), 2) +
                            powf(asteroid_loot->y() - _player_ship.y(), 2) +
                            powf(asteroid_loot->z() - _player_ship.z(), 2)) ||
            !asteroid_loot->update(_player_ship)) {
            _asteroid_loots.erase(asteroid_loot--);
        }
    }
}

void space::update_lasers() {
    std::vector<laser>::iterator laser;

    for (laser = _lasers.begin(); laser != _lasers.end(); ++laser) {
        if (300'000 < sqrtf(powf(laser->x() - _player_ship.x(), 2) +
                            powf(laser->y() - _player_ship.y(), 2) +
                            powf(laser->z() - _player_ship.z(), 2)) ||
            !laser->update(_player_ship, _enemy_ships, _asteroids,
                           _asteroid_loots)) {
            _lasers.erase(laser--);
        }
    }
}

void space::update_particles() {
    std::ranges::for_each(_particles, [this](wze::sprite& particle) -> void {
        if (particle.z() < _player_ship.z() ||
            100'000 < sqrtf(powf(particle.x() - _player_ship.x(), 2) +
                           powf(particle.y() - _player_ship.y(), 2) +
                           powf(particle.z() - _player_ship.z(), 2))) {
            particle.~sprite();
            std::apply(
                [this, &particle](float x, float y, float z) -> void {
                    new (&particle) wze::sprite(
                        _player_ship.x() + x, _player_ship.y() + y,
                        _player_ship.z() + abs(z),
                        wze::math::to_radians(wze::math::random(0.f, 360.f)),
                        wze::math::random(50.f, 100.f),
                        wze::math::random(50.f, 100.f), true,
                        assets::placeholder_texture());
                },
                sphere_coordinate(10'000, 100'000));
        }
    });
}

space::space() {
    size_t i;

    wze::renderer::set_space_texture(assets::space_texture());

    for (i = 0; i != 3; ++i) {
        std::apply(
            [this](float x, float y, float z) -> void {
                _enemy_ships.push_back({_player_ship.x() + x,
                                        _player_ship.y() + y,
                                        _player_ship.z() + z});
            },
            sphere_coordinate(50'000, 100'000));
    }

    for (i = 0; i != 1'000; ++i) {
        std::apply(
            [this](float x, float y, float z) -> void {
                _asteroids.push_back({_player_ship.x() + x,
                                      _player_ship.y() + y,
                                      _player_ship.z() + z});
            },
            sphere_coordinate(50'000, 300'000));
    }

    for (i = 0; i != 200; ++i) {
        std::apply(
            [this](float x, float y, float z) -> void {
                _particles.push_back(
                    {_player_ship.x() + x, _player_ship.y() + y,
                     _player_ship.z() + abs(z),
                     wze::math::to_radians(wze::math::random(0.f, 360.f)),
                     wze::math::random(50.f, 100.f),
                     wze::math::random(50.f, 100.f), true,
                     assets::placeholder_texture()});
            },
            sphere_coordinate(10'000, 100'000));
    }
}

space::~space() {
    wze::renderer::set_space_texture({});
}

void space::update() {
    _player_ship.update(_lasers);
    update_enemy_ships();
    update_asteroids();
    update_asteroid_loots();
    update_lasers();
    update_particles();
}
