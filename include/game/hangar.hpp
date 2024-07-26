#ifndef GAME_HANGAR_HPP
#define GAME_HANGAR_HPP

#include <game/enums.hpp>
#include <game/player.hpp>
#include <game/scene.hpp>
#include <wizard_engine/wizard_engine.hpp>

class hangar final : public scene {
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
    hangar();
    ~hangar();
    scene_type update() final;
};

#endif
