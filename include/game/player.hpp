#ifndef GAME_PLAYER_HPP
#define GAME_PLAYER_HPP

#include <wizard_engine/wizard_engine.hpp>
#include <game/enums.hpp>

class player final : public wze::collider {
  private:
    std::shared_ptr<wze::sprite> _appearance;
    wze::speaker _step_sounds;
    wze::animator _front_idle;
    wze::animator _front_walk;
    wze::animator _back_idle;
    wze::animator _back_walk;
    wze::animator _left_idle;
    wze::animator _left_walk;
    wze::animator _right_idle;
    wze::animator _right_walk;
    direction _direction;

  public:
    player(float x, float y);
    void update();
};

#endif
