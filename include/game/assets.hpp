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
    static std::shared_ptr<wze::texture> const& space_texture();

    static std::shared_ptr<wze::texture> const& asteroids_pyrite_texture();
    static std::shared_ptr<wze::texture> const& asteroids_wolframite_texture();
    static std::shared_ptr<wze::texture> const& asteroids_carneol_texture();
    static std::shared_ptr<wze::texture> const& asteroids_moldavite_texture();
    static std::shared_ptr<wze::texture> const& asteroids_ruby_texture();
    static std::shared_ptr<wze::texture> const& asteroids_sapphire_texture();

    static std::vector<std::shared_ptr<wze::texture>> const&
    asteroids_iron_explosion_animation();
};

#endif
