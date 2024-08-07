#ifndef GAME_MENU_HPP
#define GAME_MENU_HPP

#include <game/scene.hpp>
#include <game/button.hpp>
#include <wizard_engine/wizard_engine.hpp>

class menu final : public scene {
  private:
    float _color;

    std::tuple<float, float, float> sphere_coordinate(float minimum,
                                                      float maximum) const;

    std::vector<wze::sprite> _asteroids;
    std::vector<wze::sprite> _particles;

    wze::sprite _background_texture;

    button _start_button;
    button _restart_button;
    button _exit_button;
    button _volume_button;
    button _mouse_sens_button;

    std::shared_ptr<wze::sprite> _door;
    wze::animator _door_animation;
    bool _door_animating;
    bool _door_open;
    wze::speaker _door_sound;
    bool _door_proxy;
    scene_type update_door();

    wze::sprite _player_sprite;

    void update_space();

  public:
    menu();
    ~menu();
    scene_type update() final;
};

#endif
