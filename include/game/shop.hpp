#ifndef GAME_SHOP_HPP
#define GAME_SHOP_HPP

#include <game/player.hpp>
#include <game/scene.hpp>
#include <wizard_engine/wizard_engine.hpp>

class trade;

class shop final : public scene {
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

    std::unique_ptr<trade> _trade;
    void update_trade();

    std::shared_ptr<wze::sprite> _door;
    wze::sprite _door_light;
    wze::animator _door_animation;
    wze::speaker _door_sound;
    bool _door_animating;
    bool _door_open;
    void update_door();

  public:
    shop();
    ~shop();
    scene_type update() final;
};

#endif
