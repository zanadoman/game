#ifndef GAME_ENEMY_SHIP_HPP
#define GAME_ENEMY_SHIP_HPP

#include <wizard_engine/wizard_engine.hpp>

class player_ship;
class asteroid;
class laser;

class enemy_ship final : public wze::entity {
  private:
    std::shared_ptr<wze::sprite> _appearance;
    wze::animator _rear_loop;
    wze::animator _front_loop;
    wze::animator _explosion;
    std::shared_ptr<wze::polygon> _hitbox;

    float _speed;
    float _x_speed;
    float _y_speed;
    float _z_speed;
    bool dodge(float x, float y, float z, float near);
    bool dodge_asteroids(std::vector<asteroid> const& asteroids);
    bool dodge_enemy_ships(std::vector<enemy_ship> const& enemy_ships);
    bool follow_player_ship(player_ship const& player_ship);

    uint64_t _last_appearance_update;
    void update_appearance();

    float _left_cannon_x_offset;
    float _right_cannon_x_offset;
    float _cannon_y_offset;
    std::pair<float, float> _left_cannon;
    std::pair<float, float> _right_cannon;
    void update_cannons();

    uint64_t _attack_begin;
    bool _attacking;
    bool _target_locked;
    bool _active_cannon;
    uint64_t _last_shot;
    uint16_t _reload_time;
    void shoot(player_ship const& player_ship, std::vector<laser>& lasers);

    float _hitpoints;

  public:
    std::shared_ptr<wze::polygon> const& hitbox() const;
    float z() const;
    void set_z(float z);

    enemy_ship(float x, float y, float z);
    bool update(player_ship const& player_ship,
                std::vector<enemy_ship> const& enemy_ships,
                std::vector<asteroid> const& asteroids,
                std::vector<laser>& lasers);

    void damage(float hitpoints);
};

#endif
