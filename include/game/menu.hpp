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

    button _start_button;
    button _restart_button;
    button _exit_button;

    wze::sprite _player_sprite;

    void update_space();

  public:
    menu();
    ~menu();
    scene_type update() final;
};

#endif
