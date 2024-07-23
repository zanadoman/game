#ifndef GAME_ENEMY_SHIP_HPP
#define GAME_ENEMY_SHIP_HPP

#include <functional>
#include <game/enums.hpp>
#include <wizard_engine/wizard_engine.hpp>

class player_ship;
class asteroid;
class laser;

class enemy_ship final : public wze::entity {
  private:
    std::function<std::vector<std::shared_ptr<wze::texture>> const&(void)>
        _textures;
    std::shared_ptr<wze::sprite> _appearance;
    std::shared_ptr<wze::speaker> _sound;
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

    std::pair<float, float> _left_cannon;
    std::pair<float, float> _right_cannon;
    bool _active_cannon;
    uint64_t _attack_begin;
    bool _attacking;
    bool _target_locked;
    uint64_t _last_shot;
    uint16_t _damage;
    void shoot(player_ship const& player_ship, std::vector<laser>& lasers,
               std::vector<wze::speaker>& speakers);

    uint16_t _current_hitpoints;
    uint16_t _max_hitpoints;

    std::array<wze::sprite, 50> _particles;
    uint8_t _particles_color_r;
    uint8_t _particles_color_g;
    uint8_t _particles_color_b;
    void update_particles();

  public:
    std::shared_ptr<wze::polygon> const& hitbox() const;
    float z() const;
    void set_z(float z);

    enemy_ship(float x, float y, float z, enemy_difficulty enemy_difficulty);
    bool update(player_ship const& player_ship,
                std::vector<enemy_ship> const& enemy_ships,
                std::vector<asteroid> const& asteroids,
                std::vector<laser>& lasers,
                std::vector<wze::speaker>& speakers);
    void damage(std::vector<wze::speaker>& speakers, uint16_t hitpoints);
};

#endif
