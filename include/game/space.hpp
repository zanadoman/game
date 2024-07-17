#ifndef GAME_SPACE_HPP
#define GAME_SPACE_HPP

#include <game/player_ship.hpp>
#include <wizard_engine/wizard_engine.hpp>

class enemy_ship;
class asteroid;

class space final {
  private:
    std::tuple<float, float, float> sphere_coordinate(float minimum,
                                                      float maximum) const;

    player_ship _player_ship;

    std::vector<enemy_ship> _enemy_ships;
    void update_enemy_ships();

    std::vector<asteroid> _asteroids;
    void update_asteroids();

    std::vector<laser> _lasers;
    void update_lasers();

  public:
    space();
    ~space();
    void update();
};

#endif
