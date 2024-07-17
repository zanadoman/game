#ifndef GAME_PLAYER_SHIP_HPP
#define GAME_PLAYER_SHIP_HPP

#include <game/joy_stick.hpp>
#include <wizard_engine/wizard_engine.hpp>

class laser;

class player_ship final : public wze::entity {
  private:
    wze::sprite _cockpit;
    std::shared_ptr<wze::polygon> _hitbox;

    joy_stick _joy_stick;
    float _joy_stick_x;
    float _joy_stick_y;
    void update_joy_stick();

    static constexpr float _movement_speed = 5;
    static constexpr float _rotation_speed = 0.001;
    float _z;
    void update_movement();

    static constexpr float _cannons_x_offset = 400;
    static constexpr float _cannons_y_offset = 200;
    std::pair<float, float> _left_cannon;
    std::pair<float, float> _right_cannon;
    void update_cannons_x();
    void update_cannons_y();

    static constexpr float _laser_speed = 100;
    static constexpr float _laser_length = 1000;
    static constexpr float _laser_diameter = 300;
    static constexpr uint8_t _laser_color_r = 0;
    static constexpr uint8_t _laser_color_g = 150;
    static constexpr uint8_t _laser_color_b = 255;
    static constexpr uint8_t _reload_time = 200;
    bool _active_cannon;
    uint64_t _last_shot;
    void shoot(std::vector<laser>& lasers);

    uint64_t _last_damage;

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
};

#endif
