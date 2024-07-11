#ifndef GAME_ASSETS_HPP
#define GAME_ASSETS_HPP

#include <wizard_engine/wizard_engine.hpp>

/* assets osztály a get-ereiben statikusan load-olja be az assetteket */
class assets final {
  private:
    /* példányosítás letiltása */
    assets() = default;

  public:
    /* asset neve után típus suffix következzen */

    static std::shared_ptr<wze::texture> const& placeholder_texture();
    static std::shared_ptr<wze::texture> const& laser_texture();
    static std::shared_ptr<wze::texture> const& player_ship_texture();
    static std::shared_ptr<wze::texture> const& asteroid_texture();
};

#endif
