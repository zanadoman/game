#ifndef GAME_JOY_STICK_HPP
#define GAME_JOY_STICK_HPP

#include <game/updateable.hpp>
#include <wizard_engine/wizard_engine.hpp>

class joy_stick final : public updateable {
  private:
    static constexpr float _dead_zone = 20;
    static constexpr float _edge_zone = 150;
    float _value;
    float _direction;

  public:
    float value() const;
    float direction() const;

    joy_stick();
    void update() final;
};

#endif
