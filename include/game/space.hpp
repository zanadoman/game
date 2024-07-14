#ifndef GAME_SPACE_HPP
#define GAME_SPACE_HPP

#include <game/asteroid.hpp>
#include <game/laser.hpp>
#include <game/player_ship.hpp>
#include <wizard_engine/wizard_engine.hpp>

class space final {
  private:
    player_ship _player;
    std::vector<laser> _lasers;

    static constexpr size_t _asteroid_count = 1000;
    static constexpr float _asteroid_near = 50'000;
    static constexpr float _asteroid_far = 200'000;
    std::vector<asteroid> _asteroids;

    std::tuple<float, float, float> sphere_coordinate(float minimum,
                                                      float maximum);
    void update_asteroids();

  public:
    space();
    ~space();
    void update();
};

#endif
