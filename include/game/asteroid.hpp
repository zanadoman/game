#ifndef GAME_ASTEROID_HPP
#define GAME_ASTEROID_HPP

#include <wizard_engine/wizard_engine.hpp>

class asteroid final {
  private:
    std::shared_ptr<wze::sprite> _appearance;
    wze::polygon _hitbox;
    wze::animator _explosion;
    float _hitpoints;
    float _minimum_z;
    float _maximum_z;

  public:
    wze::polygon const& hitbox() const;
    float x() const;
    float y() const;
    float z() const;
    float minimum_z() const;
    float maximum_z() const;

    asteroid(float x, float y, float z);
    bool update();
    void damage(float hitpoints);
};

#endif
