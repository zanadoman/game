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
    static std::shared_ptr<wze::texture> _player_ship_warning_texture;
    static std::vector<std::shared_ptr<wze::texture>>
        _player_ship_hitpoints_textures;
    static std::vector<std::shared_ptr<wze::texture>>
        _player_ship_storage_textures;
    static std::vector<std::shared_ptr<wze::texture>>
        _player_ship_difficulty_textures;

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
    static std::shared_ptr<wze::texture> _asteroids_pyrite_gem_ui_texture;
    static std::shared_ptr<wze::texture> _asteroids_wolframite_gem_ui_texture;
    static std::shared_ptr<wze::texture> _asteroids_carneol_gem_ui_texture;
    static std::shared_ptr<wze::texture> _asteroids_moldavite_gem_ui_texture;
    static std::shared_ptr<wze::texture> _asteroids_ruby_gem_ui_texture;
    static std::shared_ptr<wze::texture> _asteroids_sapphire_gem_ui_texture;

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

    static std::vector<std::shared_ptr<wze::texture>> _enemies_easy_textures;
    static std::vector<std::shared_ptr<wze::texture>>
        _enemies_easy_rear_loop_animation;
    static std::vector<std::shared_ptr<wze::texture>>
        _enemies_easy_front_loop_animation;

    static std::vector<std::shared_ptr<wze::texture>> _enemies_normal_textures;
    static std::vector<std::shared_ptr<wze::texture>>
        _enemies_normal_rear_loop_animation;
    static std::vector<std::shared_ptr<wze::texture>>
        _enemies_normal_front_loop_animation;

    static std::vector<std::shared_ptr<wze::texture>> _enemies_hard_textures;
    static std::vector<std::shared_ptr<wze::texture>>
        _enemies_hard_rear_loop_animation;
    static std::vector<std::shared_ptr<wze::texture>>
        _enemies_hard_front_loop_animation;

    static std::vector<std::shared_ptr<wze::texture>>
        _enemies_explosion_animation;

    static std::shared_ptr<wze::sound> _space_ambiance_music_sound;
    static std::shared_ptr<wze::sound> _space_fight_music_sound;
    static std::shared_ptr<wze::sound> _player_ship_warning_sound;
    static std::shared_ptr<wze::sound> _laser_sound;
    static std::shared_ptr<wze::sound> _laser_explosion_sound;
    static std::shared_ptr<wze::sound> _laser_passing_sound;
    static std::vector<std::shared_ptr<wze::sound>> _explosion_sounds;

    assets() = default;

  public:
    static std::shared_ptr<wze::font> const& normal_font();
    static std::shared_ptr<wze::font> const& bold_font();

    static std::shared_ptr<wze::texture> const& placeholder_texture();
    static std::shared_ptr<wze::texture> const& space_texture();

    static std::shared_ptr<wze::texture> const& player_ship_base_texture();
    static std::shared_ptr<wze::texture> const& player_ship_crosshair_texture();
    static std::shared_ptr<wze::texture> const& player_ship_warning_texture();
    static std::vector<std::shared_ptr<wze::texture>> const&
    player_ship_hitpoints_textures();
    static std::vector<std::shared_ptr<wze::texture>> const&
    player_ship_storage_textures();
    static std::vector<std::shared_ptr<wze::texture>> const&
    player_ship_difficulty_textures();

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
    static std::shared_ptr<wze::texture> const&
    asteroids_pyrite_gem_ui_texture();
    static std::shared_ptr<wze::texture> const&
    asteroids_wolframite_gem_ui_texture();
    static std::shared_ptr<wze::texture> const&
    asteroids_carneol_gem_ui_texture();
    static std::shared_ptr<wze::texture> const&
    asteroids_moldavite_gem_ui_texture();
    static std::shared_ptr<wze::texture> const& asteroids_ruby_gem_ui_texture();
    static std::shared_ptr<wze::texture> const&
    asteroids_sapphire_gem_ui_texture();

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

    static std::vector<std::shared_ptr<wze::texture>> const&
    enemies_easy_textures();
    static std::vector<std::shared_ptr<wze::texture>> const&
    enemies_easy_rear_loop_animation();
    static std::vector<std::shared_ptr<wze::texture>> const&
    enemies_easy_front_loop_animation();

    static std::vector<std::shared_ptr<wze::texture>> const&
    enemies_normal_textures();
    static std::vector<std::shared_ptr<wze::texture>> const&
    enemies_normal_rear_loop_animation();
    static std::vector<std::shared_ptr<wze::texture>> const&
    enemies_normal_front_loop_animation();

    static std::vector<std::shared_ptr<wze::texture>> const&
    enemies_hard_textures();
    static std::vector<std::shared_ptr<wze::texture>> const&
    enemies_hard_rear_loop_animation();
    static std::vector<std::shared_ptr<wze::texture>> const&
    enemies_hard_front_loop_animation();

    static std::vector<std::shared_ptr<wze::texture>> const&
    enemies_explosion_animation();

    static std::shared_ptr<wze::sound> const& space_ambiance_music_sound();
    static std::shared_ptr<wze::sound> const& space_fight_music_sound();
    static std::shared_ptr<wze::sound> const& player_ship_warning_sound();
    static std::shared_ptr<wze::sound> const& laser_sound();
    static std::shared_ptr<wze::sound> const& laser_explosion_sound();
    static std::shared_ptr<wze::sound> const& laser_passing_sound();
    static std::shared_ptr<wze::sound> const& explosion_sound();

    static void initialize();
};

#endif
