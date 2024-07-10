#ifndef GAME_LASER_HPP
#define GAME_LASER_HPP

#include <wizard_engine/wizard_engine.hpp>

class laser : public wze::entity {
  private:
    float _z;
    std::vector<std::shared_ptr<wze::sprite>> _sprites;

  public:
    float z() const;
    void set_z(float z);

    laser(float x, float y, float z);
    void update();
};

#endif
