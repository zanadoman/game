#ifndef GAME_ASTEROID_HPP
#define GAME_ASTEROID_HPP

#include <game/enums.hpp>
#include <wizard_engine/wizard_engine.hpp>

class player_ship;
class asteroid_loot;

class asteroid final {
  private:
    std::shared_ptr<wze::sprite> _appearance;
    wze::animator _explosion;
    wze::polygon _hitbox;
    material _material;
    uint16_t _hitpoints;

  public:
    wze::polygon const& hitbox() const;
    float x() const;
    float y() const;
    float z() const;

    asteroid(float x, float y, float z, material material);
    bool update(player_ship& player_ship,
                std::vector<asteroid_loot>& asteroid_loots);
    void damage(std::vector<asteroid_loot>& asteroid_loots, uint16_t hitpoints);
};

#endif
