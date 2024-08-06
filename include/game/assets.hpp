#ifndef GAME_ASSETS_HPP
#define GAME_ASSETS_HPP

#include <wizard_engine/wizard_engine.hpp>

class assets final {
  private:
    static std::shared_ptr<wze::font> _normal_font;
    static std::shared_ptr<wze::font> _bold_font;

    static std::shared_ptr<wze::texture> _placeholder_texture;
    static std::shared_ptr<wze::texture> _space_texture;
    static std::shared_ptr<wze::texture> _stellar_token;

    static std::shared_ptr<wze::texture> _button_none_texture;
    static std::shared_ptr<wze::texture> _button_hovered_texture;

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
    static std::shared_ptr<wze::texture> _laser_marker_texture;
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

    static std::shared_ptr<wze::texture> _shop_background_texture;
    static std::shared_ptr<wze::texture> _shop_foreground_texture;
    static std::vector<std::shared_ptr<wze::texture>> _shop_door_animation;
    static std::shared_ptr<wze::texture> _shop_door_light_texture;
    static std::shared_ptr<wze::texture> _shop_storage_texture;
    static std::shared_ptr<wze::texture> _shop_damage_texture;
    static std::shared_ptr<wze::texture> _shop_hitpoints_texture;
    static std::shared_ptr<wze::texture> _shop_speed_texture;

    static std::shared_ptr<wze::texture> _trade_background_texture;
    static std::vector<std::shared_ptr<wze::texture>> _trade_tier_textures;
    static std::shared_ptr<wze::texture> _damage_upgrade_icon;
    static std::shared_ptr<wze::texture> _speed_upgrade_icon;
    static std::shared_ptr<wze::texture> _storage_upgrade_icon;
    static std::shared_ptr<wze::texture> _health_upgrade_icon;

    static std::shared_ptr<wze::texture> _gem_trade_background_texture;
    static std::shared_ptr<wze::texture> _decrease_button;
    static std::shared_ptr<wze::texture> _increase_button;

    static std::shared_ptr<wze::texture> _hangar_background_texture;
    static std::shared_ptr<wze::texture> _hangar_rail_texture;
    static std::shared_ptr<wze::texture> _hangar_ships_texture;
    static std::vector<std::shared_ptr<wze::texture>> _hangar_door_animation;

    static std::shared_ptr<wze::texture> _main_menu_background_texture;

    static std::shared_ptr<wze::texture> _player_backidle1_texture;
    static std::shared_ptr<wze::texture> _player_backidle2_texture;
    static std::shared_ptr<wze::texture> _player_backidle3_texture;
    static std::shared_ptr<wze::texture> _player_backidle4_texture;
    static std::shared_ptr<wze::texture> _player_back_texture;
    static std::shared_ptr<wze::texture> _player_backwalk1_texture;
    static std::shared_ptr<wze::texture> _player_backwalk2_texture;
    static std::shared_ptr<wze::texture> _player_frontidle1_texture;
    static std::shared_ptr<wze::texture> _player_frontidle2_texture;
    static std::shared_ptr<wze::texture> _player_frontidle3_texture;
    static std::shared_ptr<wze::texture> _player_frontidle4_texture;
    static std::shared_ptr<wze::texture> _player_front_texture;
    static std::shared_ptr<wze::texture> _player_frontwalk1_texture;
    static std::shared_ptr<wze::texture> _player_frontwalk2_texture;
    static std::shared_ptr<wze::texture> _player_leftidle1_texture;
    static std::shared_ptr<wze::texture> _player_leftidle2_texture;
    static std::shared_ptr<wze::texture> _player_left_texture;
    static std::shared_ptr<wze::texture> _player_leftwalk1_texture;
    static std::shared_ptr<wze::texture> _player_leftwalk2_texture;
    static std::shared_ptr<wze::texture> _player_rightidle1_texture;
    static std::shared_ptr<wze::texture> _player_rightidle2_texture;
    static std::shared_ptr<wze::texture> _player_right_texture;
    static std::shared_ptr<wze::texture> _player_rightwalk1_texture;
    static std::shared_ptr<wze::texture> _player_rightwalk2_texture;
    static std::vector<std::shared_ptr<wze::texture>>
        _player_front_idle_animation;
    static std::vector<std::shared_ptr<wze::texture>>
        _player_front_walk_animation;
    static std::vector<std::shared_ptr<wze::texture>>
        _player_back_idle_animation;
    static std::vector<std::shared_ptr<wze::texture>>
        _player_back_walk_animation;
    static std::vector<std::shared_ptr<wze::texture>>
        _player_left_idle_animation;
    static std::vector<std::shared_ptr<wze::texture>>
        _player_left_walk_animation;
    static std::vector<std::shared_ptr<wze::texture>>
        _player_right_idle_animation;
    static std::vector<std::shared_ptr<wze::texture>>
        _player_right_walk_animation;

    static std::shared_ptr<wze::texture> _quest_npc1_texture;
    static std::shared_ptr<wze::texture> _quest_npc2_texture;
    static std::shared_ptr<wze::texture> _quest_npc3_texture;
    static std::shared_ptr<wze::texture> _quest_npc4_texture;
    static std::shared_ptr<wze::texture> _quest_npc5_texture;
    static std::vector<std::shared_ptr<wze::texture>> _quest_npc_animation;

    static std::shared_ptr<wze::sound> _space_ambiance_music_sound;
    static std::shared_ptr<wze::sound> _space_fight_music_sound;
    static std::shared_ptr<wze::sound> _player_ship_warning_sound;
    static std::shared_ptr<wze::sound>
        _player_ship_asteroid_loot_accepted_sound;
    static std::shared_ptr<wze::sound>
        _player_ship_asteroid_loot_rejected_sound;
    static std::shared_ptr<wze::sound> _laser_sound;
    static std::shared_ptr<wze::sound> _laser_marker_sound;
    static std::shared_ptr<wze::sound> _laser_explosion_sound;
    static std::shared_ptr<wze::sound> _laser_passing_sound;
    static std::vector<std::shared_ptr<wze::sound>> _explosion_sounds;
    static std::shared_ptr<wze::sound> _ship_sound;
    static std::shared_ptr<wze::sound> _door_sound;
    static std::shared_ptr<wze::sound> _shop_selling_sound;
    static std::shared_ptr<wze::sound> _space_station_ambiance_sound;
    static std::vector<std::shared_ptr<wze::sound>> _player_step_sounds;
    static std::shared_ptr<wze::sound> _accept_sound;
    static std::shared_ptr<wze::sound> _refuse_sound;

    assets() = default;

  public:
    static std::shared_ptr<wze::font> const& normal_font();
    static std::shared_ptr<wze::font> const& bold_font();

    static std::shared_ptr<wze::texture> const& placeholder_texture();
    static std::shared_ptr<wze::texture> const& space_texture();
    static std::shared_ptr<wze::texture> const& stellar_token();

    static std::shared_ptr<wze::texture> const& button_none_texture();
    static std::shared_ptr<wze::texture> const& button_hovered_texture();

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
    static std::shared_ptr<wze::texture> const& laser_marker_texture();
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

    static std::shared_ptr<wze::texture> const& shop_background_texture();
    static std::shared_ptr<wze::texture> const& shop_foreground_texture();
    static std::vector<std::shared_ptr<wze::texture>> const&
    shop_door_animation();
    static std::shared_ptr<wze::texture> const& shop_door_light_texture();
    static std::shared_ptr<wze::texture> const& shop_storage_texture();
    static std::shared_ptr<wze::texture> const& shop_damage_texture();
    static std::shared_ptr<wze::texture> const& shop_hitpoints_texture();
    static std::shared_ptr<wze::texture> const& shop_speed_texture();

    static std::shared_ptr<wze::texture> const& trade_background_texture();
    static std::shared_ptr<wze::texture> const& decrease_button();
    static std::shared_ptr<wze::texture> const& increase_button();
    static std::vector<std::shared_ptr<wze::texture>> const&
    trade_tier_textures();
    static std::shared_ptr<wze::texture> const& damage_upgrade_icon();
    static std::shared_ptr<wze::texture> const& speed_upgrade_icon();
    static std::shared_ptr<wze::texture> const& storage_upgrade_icon();
    static std::shared_ptr<wze::texture> const& health_upgrade_icon();

    static std::shared_ptr<wze::texture> const& gem_trade_background_texture();

    static std::shared_ptr<wze::texture> const& hangar_background_texture();
    static std::shared_ptr<wze::texture> const& hangar_rail_texture();
    static std::shared_ptr<wze::texture> const& hangar_ships_texture();
    static std::vector<std::shared_ptr<wze::texture>> const&
    hangar_door_animation();

    static std::shared_ptr<wze::texture> const& main_menu_background_texture();

    static std::vector<std::shared_ptr<wze::texture>> const&
    player_front_idle_animation();
    static std::vector<std::shared_ptr<wze::texture>> const&
    player_front_walk_animation();
    static std::vector<std::shared_ptr<wze::texture>> const&
    player_back_idle_animation();
    static std::vector<std::shared_ptr<wze::texture>> const&
    player_back_walk_animation();
    static std::vector<std::shared_ptr<wze::texture>> const&
    player_left_idle_animation();
    static std::vector<std::shared_ptr<wze::texture>> const&
    player_left_walk_animation();
    static std::vector<std::shared_ptr<wze::texture>> const&
    player_right_idle_animation();
    static std::vector<std::shared_ptr<wze::texture>> const&
    player_right_walk_animation();

    static std::vector<std::shared_ptr<wze::texture>> const&
    quest_npc_animation();

    static std::shared_ptr<wze::sound> const& space_ambiance_music_sound();
    static std::shared_ptr<wze::sound> const& space_fight_music_sound();
    static std::shared_ptr<wze::sound> const& player_ship_warning_sound();
    static std::shared_ptr<wze::sound> const&
    player_ship_asteroid_loot_accepted_sound();
    static std::shared_ptr<wze::sound> const&
    player_ship_asteroid_loot_rejected_sound();
    static std::shared_ptr<wze::sound> const& laser_sound();
    static std::shared_ptr<wze::sound> const& laser_marker_sound();
    static std::shared_ptr<wze::sound> const& laser_explosion_sound();
    static std::shared_ptr<wze::sound> const& laser_passing_sound();
    static std::shared_ptr<wze::sound> const& explosion_sound();
    static std::shared_ptr<wze::sound> const& ship_sound();
    static std::shared_ptr<wze::sound> const& door_sound();
    static std::shared_ptr<wze::sound> const& shop_selling_sound();
    static std::shared_ptr<wze::sound> const& space_station_ambiance_sound();
    static std::shared_ptr<wze::sound> const& player_step_sounds();
    static std::shared_ptr<wze::sound> const& accept_sound();
    static std::shared_ptr<wze::sound> const& refuse_sound();

    static void initialize();
};

#endif
