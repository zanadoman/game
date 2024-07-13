#ifndef GAME_SPACE_HPP
#define GAME_SPACE_HPP

#include <game/asteroid.hpp>
#include <game/laser.hpp>
#include <game/player_ship.hpp>
#include <wizard_engine/wizard_engine.hpp>

class space final {
  private:
    player_ship _player;
    std::vector<asteroid> _asteroids;
    std::vector<laser> _lasers;

    asteroid create_asteroid();
    void update_asteroids();

  public:
    space();
    void update();
};

#endif
