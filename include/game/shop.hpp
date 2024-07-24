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

    std::shared_ptr<wze::sprite> _door;
    wze::animator _door_animation;
    wze::speaker _door_sound;
    bool _door_animating;
    bool _door_open;
    void update_door();

    

  public:
    shop();
    ~shop();
    void update();
};

#endif
