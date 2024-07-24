#ifndef GAME_SHOP_HPP
#define GAME_SHOP_HPP

#include <game/player.hpp>
#include <wizard_engine/wizard_engine.hpp>

class shop final {
  private:
    wze::sprite _background;

    wze::collider _top;
    wze::collider _bottom;
    wze::collider _left;
    wze::collider _right;
    wze::collider _top_left;
    wze::collider _top_right;
    wze::collider _bottom_left;
    wze::collider _bottom_right;

    player _player;

  public:
    shop();
    void update();
};

#endif
