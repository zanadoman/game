#ifndef GAME_JOY_STICK_HPP
#define GAME_JOY_STICK_HPP

#include <wizard_engine/wizard_engine.hpp>

class joy_stick final {
  private:
    wze::sprite _crosshair;

  public:
    float x() const;
    float y() const;
    joy_stick();
    void update();
};

#endif
