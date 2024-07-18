#ifndef GAME_ASSETS_HPP
#define GAME_ASSETS_HPP

#include <wizard_engine/wizard_engine.hpp>

class assets final {
  private:
    static std::shared_ptr<wze::font> _normal_font;
    static std::shared_ptr<wze::font> _bold_font;

    static std::shared_ptr<wze::texture> _placeholder_texture;
    static std::shared_ptr<wze::texture> _space_texture;

    static std::shared_ptr<wze::texture> _player_ship_base_texture;
    static std::shared_ptr<wze::texture> _player_ship_crosshair_texture;

    static std::shared_ptr<wze::texture> _laser_texture;
    static std::vector<std::shared_ptr<wze::texture>>
        _laser_explosion_animation;

    static std::vector<std::shared_ptr<wze::texture>>
        _asteroids_pyrite_textures;
    static std::vector<std::shared_ptr<wze::texture>>
        _asteroids_wolframite_textures;
    static std::vector<std::shared_ptr<wze::texture>>
        _asteroids_carneol_textures;
    static std::vector<std::shared_ptr<wze::texture>>
        _asteroids_moldavite_textures;
    static std::vector<std::shared_ptr<wze::texture>> _asteroids_ruby_textures;
    static std::vector<std::shared_ptr<wze::texture>>
        _asteroids_sapphire_textures;

    static std::shared_ptr<wze::texture> _asteroids_pyrite_gem_texture;
    static std::shared_ptr<wze::texture> _asteroids_wolframite_gem_texture;
    static std::shared_ptr<wze::texture> _asteroids_carneol_gem_texture;
    static std::shared_ptr<wze::texture> _asteroids_moldavite_gem_texture;
    static std::shared_ptr<wze::texture> _asteroids_ruby_gem_texture;
    static std::shared_ptr<wze::texture> _asteroids_sapphire_gem_texture;

    static std::vector<std::shared_ptr<wze::texture>>
        _asteroids_pyrite_explosion_animation;
    static std::vector<std::shared_ptr<wze::texture>>
        _asteroids_wolframite_explosion_animation;
    static std::vector<std::shared_ptr<wze::texture>>
        _asteroids_carneol_explosion_animation;
    static std::vector<std::shared_ptr<wze::texture>>
        _asteroids_moldavite_explosion_animation;
    static std::vector<std::shared_ptr<wze::texture>>
        _asteroids_ruby_explosion_animation;
    static std::vector<std::shared_ptr<wze::texture>>
        _asteroids_sapphire_explosion_animation;

    static std::shared_ptr<wze::texture> _enemy_rear_texture;
    static std::shared_ptr<wze::texture> _enemy_rear_up_texture;
    static std::shared_ptr<wze::texture> _enemy_rear_down_texture;
    static std::shared_ptr<wze::texture> _enemy_rear_left_texture;
    static std::shared_ptr<wze::texture> _enemy_rear_right_texture;
    static std::vector<std::shared_ptr<wze::texture>>
        _enemy_rear_loop_animation;
    static std::shared_ptr<wze::texture> _enemy_front_texture;
    static std::shared_ptr<wze::texture> _enemy_front_up_texture;
    static std::shared_ptr<wze::texture> _enemy_front_down_texture;
    static std::shared_ptr<wze::texture> _enemy_front_left_texture;
    static std::shared_ptr<wze::texture> _enemy_front_right_texture;
    static std::vector<std::shared_ptr<wze::texture>>
        _enemy_front_loop_animation;

    static std::vector<std::shared_ptr<wze::texture>>
        _enemy_explosion_animation;

    assets() = default;

  public:
    static std::shared_ptr<wze::font> const& normal_font();
    static std::shared_ptr<wze::font> const& bold_font();

    static std::shared_ptr<wze::texture> const& placeholder_texture();
    static std::shared_ptr<wze::texture> const& space_texture();

    static std::shared_ptr<wze::texture> const& player_ship_base_texture();
    static std::shared_ptr<wze::texture> const& player_ship_crosshair_texture();

    static std::shared_ptr<wze::texture> const& laser_texture();
    static std::vector<std::shared_ptr<wze::texture>> const&
    laser_explosion_animation();

    static std::shared_ptr<wze::texture> const& asteroids_pyrite_texture();
    static std::shared_ptr<wze::texture> const& asteroids_wolframite_texture();
    static std::shared_ptr<wze::texture> const& asteroids_carneol_texture();
    static std::shared_ptr<wze::texture> const& asteroids_moldavite_texture();
    static std::shared_ptr<wze::texture> const& asteroids_ruby_texture();
    static std::shared_ptr<wze::texture> const& asteroids_sapphire_texture();

    static std::shared_ptr<wze::texture> const& asteroids_pyrite_gem_texture();
    static std::shared_ptr<wze::texture> const&
    asteroids_wolframite_gem_texture();
    static std::shared_ptr<wze::texture> const& asteroids_carneol_gem_texture();
    static std::shared_ptr<wze::texture> const&
    asteroids_moldavite_gem_texture();
    static std::shared_ptr<wze::texture> const& asteroids_ruby_gem_texture();
    static std::shared_ptr<wze::texture> const&
    asteroids_sapphire_gem_texture();

    static std::vector<std::shared_ptr<wze::texture>> const&
    asteroids_pyrite_explosion_animation();
    static std::vector<std::shared_ptr<wze::texture>> const&
    asteroids_wolframite_explosion_animation();
    static std::vector<std::shared_ptr<wze::texture>> const&
    asteroids_carneol_explosion_animation();
    static std::vector<std::shared_ptr<wze::texture>> const&
    asteroids_moldavite_explosion_animation();
    static std::vector<std::shared_ptr<wze::texture>> const&
    asteroids_ruby_explosion_animation();
    static std::vector<std::shared_ptr<wze::texture>> const&
    asteroids_sapphire_explosion_animation();

    static std::shared_ptr<wze::texture> const& enemy_rear_texture();
    static std::shared_ptr<wze::texture> const& enemy_rear_up_texture();
    static std::shared_ptr<wze::texture> const& enemy_rear_down_texture();
    static std::shared_ptr<wze::texture> const& enemy_rear_left_texture();
    static std::shared_ptr<wze::texture> const& enemy_rear_right_texture();
    static std::vector<std::shared_ptr<wze::texture>> const&
    enemy_rear_loop_animation();
    static std::shared_ptr<wze::texture> const& enemy_front_texture();
    static std::shared_ptr<wze::texture> const& enemy_front_up_texture();
    static std::shared_ptr<wze::texture> const& enemy_front_down_texture();
    static std::shared_ptr<wze::texture> const& enemy_front_left_texture();
    static std::shared_ptr<wze::texture> const& enemy_front_right_texture();
    static std::vector<std::shared_ptr<wze::texture>> const&
    enemy_front_loop_animation();

    static std::vector<std::shared_ptr<wze::texture>> const&
    enemy_explosion_animation();

    static void initialize();
};

#endif
