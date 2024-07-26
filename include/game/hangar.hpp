#ifndef GAME_HANGAR_HPP
#define GAME_HANGAR_HPP

#include <game/enums.hpp>
#include <game/player.hpp>
#include <game/scene.hpp>
#include <wizard_engine/wizard_engine.hpp>

class hangar final : public scene {
  private:
    wze::sprite _background;
    wze::collider _top_hitbox;
    wze::collider _bottom_hitbox;
    wze::collider _left_hitbox;
    wze::collider _right_hitbox;
    wze::collider _top_right_hitbox;
    wze::collider _bottom_left_hitbox;
    wze::collider _bottom_right_hitbox;
    wze::collider _boss_hitbox;
    wze::collider _ornament_hitbox;

    player _player;

  public:
    hangar();
    ~hangar();
    scene_type update() final;
};

#endif
