#ifndef GAME_LASER_HPP
#define GAME_LASER_HPP

#include <wizard_engine/wizard_engine.hpp>
#include <game/asteroid.hpp>

class laser final : public wze::entity {
  private:
    float _z;
    float _x_speed;
    float _y_speed;
    float _z_speed;
    float _half_length;
    float _length_skip;
    std::vector<std::shared_ptr<wze::sprite>> _sprites;

  public:
    float z() const;
    laser(float x, float y, float z, float x_speed, float y_speed,
          float z_speed, float length, float diameter, uint8_t color_r,
          uint8_t color_g, uint8_t color_b);
    bool update(std::vector<asteroid>& asteroids);
};

#endif
