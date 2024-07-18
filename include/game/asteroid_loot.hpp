#ifndef GAME_ASTEROID_LOOT_HPP
#define GAME_ASTEROID_LOOT_HPP

#include <game/enums.hpp>
#include <wizard_engine/wizard_engine.hpp>

class player_ship;

class asteroid_loot final : public wze::entity {
  private:
    std::shared_ptr<wze::sprite> _appearance;
    material _material;

  public:
    float z() const;
    void set_z(float z);

    asteroid_loot(float x, float y, float z, enum material material);
    bool update(player_ship& player_ship);
};

#endif
