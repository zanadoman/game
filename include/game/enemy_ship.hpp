#ifndef GAME_ENEMY_SHIP_HPP
#define GAME_ENEMY_SHIP_HPP

#include <game/asteroid.hpp>
#include <game/player_ship.hpp>
#include <wizard_engine/wizard_engine.hpp>

class enemy_ship final : wze::entity {
  private:
    std::shared_ptr<wze::sprite> _appearance;
    std::shared_ptr<wze::polygon> _hitbox;
    float _z;
    float _speed;

    void dodge_asteroid(asteroid const& asteroid);
    void set_appearance();

  public:
    float z() const;
    void set_z(float z);

    enemy_ship(float x, float y, float z);
    bool update(player_ship& player_ship,
                std::vector<asteroid> const& asteroids);
};

#endif
