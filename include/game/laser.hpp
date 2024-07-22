#ifndef GAME_LASER_HPP
#define GAME_LASER_HPP

#include <wizard_engine/wizard_engine.hpp>

class player_ship;
class enemy_ship;
class asteroid;
class asteroid_loot;

class laser final : public wze::entity {
  private:
    std::shared_ptr<wze::sprite> _appearance;
    wze::animator _explosion;
    float _diameter;
    uint8_t _color_r;
    uint8_t _color_g;
    uint8_t _color_b;

    float _z;
    float _x_speed;
    float _y_speed;
    float _z_speed;
    float _half_length;
    float _length_skip;
    uint16_t _damage;
    bool _destroyed;
    std::vector<std::shared_ptr<wze::sprite>> _sprites;

  public:
    float z() const;
    laser(float x, float y, float z, float x_speed, float y_speed,
          float z_speed, float length, float diameter, uint8_t color_r,
          uint8_t color_g, uint8_t color_b, uint16_t damage,
          std::vector<wze::speaker>& speakers);
    bool update(player_ship& player_ship, std::vector<enemy_ship>& enemy_ships,
                std::vector<asteroid>& asteroids,
                std::vector<asteroid_loot>& asteroid_loots,
                std::vector<wze::speaker>& speakers);
};

#endif
