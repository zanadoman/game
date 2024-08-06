#ifndef GAME_MENU_HPP
#define GAME_MENU_HPP

#include <game/scene.hpp>
#include <wizard_engine/wizard_engine.hpp>

class menu final : public scene {
  private:
    float _color;

    std::tuple<float, float, float> sphere_coordinate(float minimum,
                                                      float maximum) const;

    std::vector<wze::sprite> _asteroids;
    std::vector<wze::sprite> _particles;
    void update_space();

  public:
    menu();
    ~menu();
    scene_type update() final;
};

#endif
