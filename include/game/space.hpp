#ifndef GAME_SPACE_HPP
#define GAME_SPACE_HPP

#include "wizard_engine/speaker.hpp"
#include <game/enums.hpp>
#include <game/player_ship.hpp>
#include <wizard_engine/wizard_engine.hpp>

class enemy_ship;
class asteroid;
class asteroid_loot;
class laser;

class space final {
  private:
    std::tuple<float, float, float> sphere_coordinate(float minimum,
                                                      float maximum) const;

    uint8_t _difficulty;
    void update_difficulty();

    player_ship _player_ship;

    std::vector<enemy_ship> _enemy_ships;
    uint64_t _last_spawn;
    uint32_t _spawn_time;
    void update_enemy_ships();

    std::vector<class asteroid> _asteroids;
    std::tuple<float, float, float, material> asteroid();
    void update_asteroids();

    std::vector<asteroid_loot> _asteroid_loots;
    void update_asteroid_loots();

    std::vector<laser> _lasers;
    void update_lasers();

    std::vector<wze::sprite> _particles;
    void update_particles();

    wze::speaker _ambiance_music;
    wze::speaker _fight_music;
    void update_music();

  public:
    space();
    ~space();
    void update();
};

#endif
