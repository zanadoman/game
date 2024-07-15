#ifndef GAME_SPACE_HPP
#define GAME_SPACE_HPP

#include <game/asteroid.hpp>
#include <game/laser.hpp>
#include <game/player_ship.hpp>
#include <wizard_engine/wizard_engine.hpp>

class space final {
  private:
    std::tuple<float, float, float> sphere_coordinate(float minimum,
                                                      float maximum);

    player_ship _player;

    static constexpr float _laser_far = 300'000;
    std::vector<laser> _lasers;
    void update_lasers();

    static constexpr size_t _asteroid_count = 1000;
    static constexpr float _asteroid_near = 50'000;
    static constexpr float _asteroid_far = 300'000;
    std::vector<asteroid> _asteroids;
    void update_asteroids();

  public:
    space();
    ~space();
    void update();
};

#endif
