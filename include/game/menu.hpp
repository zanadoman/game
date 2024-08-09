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
    button _volume_decrease;
    button _sens_decrease;
    button _volume_increase;
    button _sens_increase;

    wze::sprite _volume_sprite;
    wze::sprite _mouse_sens_sprite;
    wze::sprite _volume_value;
    wze::sprite _sens_value;
    int8_t _volume;
    float _mouse_sens;

    wze::sprite _title;
    wze::sprite _made_by_sprite;
    wze::sprite _doman_sprite;
    wze::sprite _roland_sprite;
    wze::sprite _franck_sprite;
    wze::sprite _lili_sprite;

    std::shared_ptr<wze::sprite> _door;
    wze::animator _door_animation;
    bool _door_animating;
    bool _door_open;
    wze::speaker _door_sound;
    scene_type update_door();

    wze::sprite _player_sprite;

    void update_space();

  public:
    menu();
    ~menu();
    scene_type update() final;
};

#endif
