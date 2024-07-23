#include <game/assets.hpp>
#include <game/asteroid.hpp>
#include <game/asteroid_loot.hpp>
#include <game/enemy_ship.hpp>
#include <game/laser.hpp>
#include <game/save_data.hpp>
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

void space::update_difficulty() {
    _difficulty = std::clamp(
        ceilf(
            (save_data::pyrite_count() * 1 + save_data::wolframite_count() * 2 +
             save_data::carneol_count() * 3 + save_data::moldavite_count() * 4 +
             save_data::ruby_count() * 5 + save_data::sapphire_count() * 6) /
            400.f * 5),
        0.f, 5.f);
}

void space::update_enemy_ships() {
    std::vector<enemy_ship>::iterator enemy_ship;
    enemy_difficulty enemy_difficulty;
    size_t count;
    size_t i;

    for (enemy_ship = _enemy_ships.begin(); enemy_ship != _enemy_ships.end();
         ++enemy_ship) {
        if (300'000 < sqrtf(powf(enemy_ship->x() - _player_ship.x(), 2) +
                            powf(enemy_ship->y() - _player_ship.y(), 2) +
                            powf(enemy_ship->z() - _player_ship.z(), 2)) ||
            !enemy_ship->update(_player_ship, _enemy_ships, _asteroids, _lasers,
                                _speakers)) {
            _enemy_ships.erase(enemy_ship--);
            if (!_enemy_ships.size()) {
                _last_spawn = wze::timer::current_time();
            }
        }
    }

    if (!_enemy_ships.size() &&
        _last_spawn + _spawn_time < wze::timer::current_time()) {
        switch (_difficulty) {
        case 1:
            enemy_difficulty = ENEMY_DIFFICULTY_EASY;
            count = wze::math::random(1, 2);
            _spawn_time = wze::math::random(60'000, 80'000);
            break;
        case 2:
            enemy_difficulty = ENEMY_DIFFICULTY_EASY;
            count = wze::math::random(1, 2);
            _spawn_time = wze::math::random(50'000, 70'000);
            break;
        case 3:
            enemy_difficulty = ENEMY_DIFFICULTY_NORMAL;
            count = wze::math::random(2, 3);
            _spawn_time = wze::math::random(40'000, 60'000);
            break;
        case 4:
            enemy_difficulty = ENEMY_DIFFICULTY_NORMAL;
            count = wze::math::random(2, 3);
            _spawn_time = wze::math::random(30'000, 50'000);
            break;
        case 5:
            enemy_difficulty = ENEMY_DIFFICULTY_HARD;
            count = wze::math::random(3, 4);
            _spawn_time = wze::math::random(20'000, 40'000);
            break;
        default:
            return;
        }

        for (i = 0; i != count; ++i) {
            std::apply(
                [this, enemy_difficulty](float x, float y, float z) -> void {
                    _enemy_ships.push_back(
                        {_player_ship.x() + x, _player_ship.y() + y,
                         _player_ship.z() + z, enemy_difficulty});
                },
                sphere_coordinate(50'000, 100'000));
        }
    }
}

std::tuple<float, float, float, material> space::asteroid() {
    float random;
    material material;

    random = wze::math::random(0, 20 * _difficulty);
    if (95 < random) {
        material = MATERIAL_SAPPHIRE;
    } else if (75 < random) {
        material = MATERIAL_RUBY;
    } else if (55 < random) {
        material = MATERIAL_MOLDAVITE;
    } else if (35 < random) {
        material = MATERIAL_CARNEOL;
    } else if (15 < random) {
        material = MATERIAL_WOLFRAMITE;
    } else {
        material = MATERIAL_PYRITE;
    }

    return std::apply(
        [ this, material ](float x, float y, float z)
            -> std::tuple<float, float, float, enum material> {
            return {_player_ship.x() + x, _player_ship.y() + y,
                    _player_ship.z() + z, material};
        },
        sphere_coordinate(50'000, 300'000));
}

void space::update_asteroids() {
    std::ranges::for_each(_asteroids, [this](class asteroid& asteroid) -> void {
        if (300'000 < sqrtf(powf(asteroid.x() - _player_ship.x(), 2) +
                            powf(asteroid.y() - _player_ship.y(), 2) +
                            powf(asteroid.z() - _player_ship.z(), 2)) ||
            !asteroid.update(_player_ship, _asteroid_loots, _speakers)) {
            asteroid.~asteroid();
            std::apply(
                [&asteroid](float x, float y, float z,
                            material material) -> void {
                    new (&asteroid) class asteroid(x, y, z, material);
                },
                this->asteroid());
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
                           _asteroid_loots, _speakers)) {
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

void space::update_speakers() {
    std::vector<wze::speaker>::iterator speaker;

    for (speaker = _speakers.begin(); speaker != _speakers.end(); ++speaker) {
        if (!speaker->playing()) {
            _speakers.erase(speaker--);
        }
    }

    if (!_enemy_ships.size() && !_ambiance_music.playing()) {
        _fight_music.stop(3'000);
        _ambiance_music.play(3'000, std::numeric_limits<uint16_t>::max());
    } else if (_enemy_ships.size() && !_fight_music.playing()) {
        _ambiance_music.stop(3'000);
        _fight_music.play(3'000, std::numeric_limits<uint16_t>::max());
    }
}

space::space() {
    size_t i;

    wze::input::set_cursor_visible(false);
    wze::renderer::set_space_texture(assets::space_texture());

    _difficulty = 0;
    _player_ship = {};
    _enemy_ships = {};
    _last_spawn = wze::timer::current_time();
    _spawn_time = wze::math::random(20'000, 40'000);
    _asteroids = {};
    _asteroid_loots = {};
    _lasers = {};
    _particles = {};
    _ambiance_music = {assets::space_ambiance_music_sound(),
                       std::numeric_limits<int8_t>::max() / 2};
    _fight_music = {assets::space_fight_music_sound(),
                    std::numeric_limits<int8_t>::max() / 2};

    update_difficulty();

    for (i = 0; i != 1'000; ++i) {
        std::apply(
            [this](float x, float y, float z, material material) -> void {
                _asteroids.push_back({x, y, z, material});
            },
            asteroid());
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
    wze::input::set_cursor_visible(true);
}

void space::update() {
    update_difficulty();
    _player_ship.update(_difficulty, _lasers, _speakers);
    update_enemy_ships();
    update_asteroids();
    update_asteroid_loots();
    update_lasers();
    update_particles();
    update_speakers();
}
