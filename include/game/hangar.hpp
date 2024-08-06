#ifndef GAME_HANGAR_HPP
#define GAME_HANGAR_HPP

#include <game/enums.hpp>
#include <game/player.hpp>
#include <game/scene.hpp>
#include <wizard_engine/wizard_engine.hpp>

class hangar final : public scene {
  private:
    std::tuple<float, float, float> sphere_coordinate(float minimum,
                                                      float maximum) const;

    float _color;

    wze::sprite _background;
    wze::sprite _rail;
    wze::sprite _ships;
    wze::collider _top_hitbox;
    wze::collider _bottom_hitbox;
    wze::collider _left_hitbox;
    wze::collider _right_hitbox;
    wze::collider _top_right_hitbox;
    wze::collider _bottom_left_hitbox;
    wze::collider _bottom_right_hitbox;
    wze::collider _boss_hitbox;
    wze::collider _ornament_hitbox;
    wze::collider _hitbox1;
    wze::collider _hitbox2;
    wze::collider _hitbox3;
    wze::collider _hitbox4;
    wze::collider _hitbox5;
    wze::collider _hitbox6;

    player _player;

    std::vector<wze::sprite> _asteroids;
    std::vector<wze::sprite> _particles;
    void update_space();

    std::shared_ptr<wze::sprite> _door;
    wze::animator _door_animation;
    wze::speaker _door_sound;
    bool _door_animating;
    bool _door_open;
    bool _door_proxy;
    scene_type update_door();

    bool _ship_proxy;
    scene_type update_ship();

    wze::sprite _money;
    wze::sprite _money_count;
    void update_money();

    wze::speaker _space_station_ambiance_sound;

    std::shared_ptr<wze::sprite> _quest_npc;
    wze::animator _quest_npc_animation;

  public:
    hangar();
    ~hangar();
    scene_type update() final;
};

#endif
