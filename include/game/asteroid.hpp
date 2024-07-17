#ifndef GAME_ASTEROID_HPP
#define GAME_ASTEROID_HPP

#include <wizard_engine/wizard_engine.hpp>

class asteroid final {
  private:
    std::shared_ptr<wze::sprite> _appearance;
    wze::animator _explosion;
    wze::polygon _hitbox;
    float _hitpoints;

  public:
    wze::polygon const& hitbox() const;
    float x() const;
    float y() const;
    float z() const;

    asteroid(float x, float y, float z);
    bool update();
    void damage(float hitpoints);
};

#endif
