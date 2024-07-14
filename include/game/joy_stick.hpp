#ifndef GAME_JOY_STICK_HPP
#define GAME_JOY_STICK_HPP

#include <wizard_engine/wizard_engine.hpp>

class joy_stick final {
  private:
    static constexpr float _maximum = 200;
    float _value;
    float _direction;
    wze::sprite _crosshair;

  public:
    float value() const;
    float direction() const;

    joy_stick();
    void update();
};

#endif
