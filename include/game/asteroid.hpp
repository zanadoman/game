#ifndef GAME_ASTEROID_HPP
#define GAME_ASTEROID_HPP

#include <wizard_engine/wizard_engine.hpp>

enum material { MATERIAL_IRON, MATERIAL_GOLD, MATERIAL_COUNT };

class asteroid final {
  private:
    enum material _material;
    wze::sprite _appearance;
    wze::polygon _hitbox;
    float _minimum_z;
    float _maximum_z;
    float _transparency;

  public:
    enum material material() const;
    wze::sprite const& appearance() const;
    wze::polygon const& hitbox() const;
    float minimum_z() const;
    float maximum_z() const;

    asteroid(float x, float y, float z);
    void update();
};

#endif
