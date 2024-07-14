#ifndef GAME_PLAYER_SHIP_HPP
#define GAME_PLAYER_SHIP_HPP

#include <game/asteroid.hpp>
#include <game/joy_stick.hpp>
#include <game/laser.hpp>
#include <wizard_engine/wizard_engine.hpp>

class player_ship final : public wze::entity {
  private:
    static constexpr float _cannons_x_offset = 300;
    static constexpr float _cannons_y_offset = 150;
    static constexpr uint8_t _reload_time = 200;
    float _x_speed;
    float _y_speed;
    joy_stick _joy_stick;
    float _z;
    wze::sprite _cockpit;
    std::pair<float, float> _left_cannon;
    std::pair<float, float> _right_cannon;
    bool _active_cannon;
    uint64_t _last_shot;

    void update_movement();
    void update_cannons_x();
    void update_cannons_y();
    void shoot(std::vector<laser>& lasers);

  public:
    void set_x(float x) override;
    void set_y(float y) override;
    float z() const;
    void set_z(float z);
    void set_angle(float angle) override;

    player_ship();
    void update(std::vector<laser>& lasers);
};

#endif
