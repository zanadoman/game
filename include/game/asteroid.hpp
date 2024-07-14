#ifndef GAME_ASTEROID_HPP
#define GAME_ASTEROID_HPP

#include <wizard_engine/wizard_engine.hpp>

enum material { MATERIAL_IRON, MATERIAL_GOLD, MATERIAL_COUNT };

class asteroid final {
  private:
    static constexpr float _minimum_size = 4'000;
    static constexpr float _maximum_size = 8'000;
    enum material _material;
    std::shared_ptr<wze::sprite> _appearance;
    wze::polygon _hitbox;
    wze::animator _explosion;
    float _hitpoints;
    float _minimum_z;
    float _maximum_z;

  public:
    enum material material() const;
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
