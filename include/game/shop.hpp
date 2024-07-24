#ifndef GAME_SHOP_HPP
#define GAME_SHOP_HPP

#include <wizard_engine/wizard_engine.hpp>
#include <game/player.hpp>

class shop final {
  private:
    wze::sprite _background;

    player _player; 

  public:
    shop();
    void update();
};

#endif
