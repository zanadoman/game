#ifndef GAME_SHOP_HPP
#define GAME_SHOP_HPP

#include <game/enums.hpp>
#include <game/player.hpp>
#include <game/scene.hpp>
#include <wizard_engine/wizard_engine.hpp>

class trade;
class gem_trade;

class shop final : public scene {
  private:
    float _color;

    wze::sprite _background_sprite;
    wze::sprite _storage_sprite;
    wze::sprite _damage_sprite;
    wze::sprite _hitpoints_sprite;
    wze::sprite _speed_sprite;

    wze::collider _top_hitbox;
    wze::collider _bottom_hitbox;
    wze::collider _left_hitbox;
    wze::collider _right_hitbox;
    wze::collider _top_left_hitbox;
    wze::collider _top_right_hitbox;
    wze::collider _bottom_left_hitbox;
    wze::collider _bottom_right_hitbox;
    wze::collider _gems_hitbox;
    wze::collider _storage_hitbox;
    wze::collider _damage_hitbox;
    wze::collider _hitpoints_hitbox;
    wze::collider _speed_hitbox;

    player _player;

    std::unique_ptr<trade> _trade;
    std::unique_ptr<gem_trade> _gem_trade;
    void update_trade();

    std::shared_ptr<wze::sprite> _door;
    wze::sprite _door_light;
    wze::animator _door_animation;
    wze::speaker _door_sound;
    bool _door_animating;
    bool _door_open;
    scene_type update_door();

  public:
    shop();
    ~shop();
    scene_type update() final;
};

#endif
