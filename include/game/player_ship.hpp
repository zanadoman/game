#ifndef GAME_PLAYER_SHIP_HPP
#define GAME_PLAYER_SHIP_HPP

#include <game/laser.hpp>
#include <game/updateable.hpp>
#include <wizard_engine/wizard_engine.hpp>

class player_ship final : public updateable, public wze::entity {
  private:
    static constexpr float _cannons_x_offset = 100;
    static constexpr float _cannons_y_offset = 50;
    static constexpr uint8_t _reload_time = 200;
    float _z;
    wze::sprite _cockpit;
    std::vector<std::unique_ptr<laser>> _lasers;
    std::pair<float, float> _left_cannon;
    std::pair<float, float> _right_cannon;
    bool _active_cannon;
    uint64_t _last_shot;

    void update_cannons_x();
    void update_cannons_y();
    void shoot();

  public:
    void set_x(float x) override;
    void set_y(float y) override;
    float z() const;
    void set_z(float z);
    void set_angle(float angle) override;

    player_ship();
    void update() final;
};

#endif
