#ifndef GAME_ASSETS_HPP
#define GAME_ASSETS_HPP

#include <wizard_engine/wizard_engine.hpp>

class assets final {
  private:
    assets() = default;

  public:
    static std::shared_ptr<wze::texture> const& placeholder_texture();
    static std::shared_ptr<wze::texture> const& laser_texture();
    static std::shared_ptr<wze::texture> const& player_ship_texture();
    static std::shared_ptr<wze::texture> const& asteroid_texture();
    static std::shared_ptr<wze::texture> const& space_texture();
};

#endif
