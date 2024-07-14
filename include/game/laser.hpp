#ifndef GAME_LASER_HPP
#define GAME_LASER_HPP

#include <wizard_engine/wizard_engine.hpp>

class laser final : public wze::entity {
  private:
    float _z;
    float _x_speed;
    float _y_speed;
    float _z_speed;
    std::vector<std::shared_ptr<wze::sprite>> _sprites;

  public:
    float z() const;

    laser(float x, float y, float z, float x_speed, float y_speed,
          float z_speed);
    void update();
};

#endif
