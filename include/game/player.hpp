#ifndef GAME_PLAYER_HPP
#define GAME_PLAYER_HPP

#include <wizard_engine/wizard_engine.hpp>

class player final : public wze::collider {
  private:
    std::shared_ptr<wze::sprite> _appearance;

  public:
    player();
    void update();
};

#endif
