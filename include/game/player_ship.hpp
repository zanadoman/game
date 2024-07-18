#ifndef GAME_PLAYER_SHIP_HPP
#define GAME_PLAYER_SHIP_HPP

#include <game/joy_stick.hpp>
#include <game/enums.hpp>
#include <wizard_engine/wizard_engine.hpp>

class laser;

class player_ship final : public wze::entity {
  private:
    wze::sprite _cockpit;
    wze::sprite _warning;
    float _warning_opacity;
    wze::sprite _pyrite_icon;
    wze::sprite _pyrite_count;
    wze::sprite _wolframite_icon;
    wze::sprite _wolframite_count;
    wze::sprite _carneol_icon;
    wze::sprite _carneol_count;
    wze::sprite _moldavite_icon;
    wze::sprite _moldavite_count;
    wze::sprite _ruby_icon;
    wze::sprite _ruby_count;
    wze::sprite _sapphire_icon;
    wze::sprite _sapphire_count;
    wze::sprite _hitpoints_count;
    wze::sprite _storage_count;
    std::shared_ptr<wze::polygon> _hitbox;
    void update_hud();

    joy_stick _joy_stick;
    float _joy_stick_x;
    float _joy_stick_y;
    void update_joy_stick();

    float _speed;
    void update_movement();

    std::pair<float, float> _left_cannon;
    std::pair<float, float> _right_cannon;
    void update_cannons_x();
    void update_cannons_y();

    bool _active_cannon;
    float _laser_speed;
    uint64_t _last_shot;
    uint16_t _reload_time;
    float _damage;
    void shoot(std::vector<laser>& lasers);

    float _current_hitpoints;
    float _max_hitpoints;

    uint16_t _storage;

  public:
    std::shared_ptr<wze::polygon> const& hitbox() const;
    void set_x(float x) final;
    void set_y(float y) final;
    float z() const;
    void set_z(float z);
    void set_angle(float angle) final;

    player_ship();
    void update(std::vector<laser>& lasers);
    void damage(float hitpoints);
    void asteroid_loot(material material);
};

#endif
