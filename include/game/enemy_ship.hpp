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
    float _x_speed;
    float _y_speed;
    float _z_speed;
    bool _ready;
    uint64_t _last_attack;
    bool _attacking;
    wze::animator _rear_loop;
    wze::animator _front_loop;
    uint64_t _last_appearance_update;

    bool dodge_asteroids(std::vector<asteroid> const& asteroids);
    bool dodge_enemy_ships(std::vector<enemy_ship> const& enemy_ships);
    void update_appearance();

  public:
    float z() const;
    void set_z(float z);

    enemy_ship(float x, float y, float z);
    bool update(player_ship& player_ship,
                std::vector<enemy_ship> const& enemy_ships,
                std::vector<asteroid> const& asteroids);
};

#endif
