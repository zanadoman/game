#include <game/assets.hpp>

std::shared_ptr<wze::font> assets::_normal_font;
std::shared_ptr<wze::font> assets::_bold_font;

std::shared_ptr<wze::texture> assets::_placeholder_texture;
std::shared_ptr<wze::texture> assets::_space_texture;
std::shared_ptr<wze::texture> assets::_stellar_token;

std::shared_ptr<wze::texture> assets::_button_none_texture;
std::shared_ptr<wze::texture> assets::_button_hovered_texture;

std::shared_ptr<wze::texture> assets::_player_ship_base_texture;
std::shared_ptr<wze::texture> assets::_player_ship_crosshair_texture;
std::shared_ptr<wze::texture> assets::_player_ship_warning_texture;
std::vector<std::shared_ptr<wze::texture>>
    assets::_player_ship_hitpoints_textures;
std::vector<std::shared_ptr<wze::texture>>
    assets::_player_ship_storage_textures;
std::vector<std::shared_ptr<wze::texture>>
    assets::_player_ship_difficulty_textures;

std::shared_ptr<wze::texture> assets::_laser_texture;
std::shared_ptr<wze::texture> assets::_laser_marker_texture;
std::vector<std::shared_ptr<wze::texture>> assets::_laser_explosion_animation;

std::vector<std::shared_ptr<wze::texture>> assets::_asteroids_pyrite_textures;
std::vector<std::shared_ptr<wze::texture>>
    assets::_asteroids_wolframite_textures;
std::vector<std::shared_ptr<wze::texture>> assets::_asteroids_carneol_textures;
std::vector<std::shared_ptr<wze::texture>>
    assets::_asteroids_moldavite_textures;
std::vector<std::shared_ptr<wze::texture>> assets::_asteroids_ruby_textures;
std::vector<std::shared_ptr<wze::texture>> assets::_asteroids_sapphire_textures;

std::shared_ptr<wze::texture> assets::_asteroids_pyrite_gem_texture;
std::shared_ptr<wze::texture> assets::_asteroids_wolframite_gem_texture;
std::shared_ptr<wze::texture> assets::_asteroids_carneol_gem_texture;
std::shared_ptr<wze::texture> assets::_asteroids_moldavite_gem_texture;
std::shared_ptr<wze::texture> assets::_asteroids_ruby_gem_texture;
std::shared_ptr<wze::texture> assets::_asteroids_sapphire_gem_texture;
std::shared_ptr<wze::texture> assets::_asteroids_pyrite_gem_ui_texture;
std::shared_ptr<wze::texture> assets::_asteroids_wolframite_gem_ui_texture;
std::shared_ptr<wze::texture> assets::_asteroids_carneol_gem_ui_texture;
std::shared_ptr<wze::texture> assets::_asteroids_moldavite_gem_ui_texture;
std::shared_ptr<wze::texture> assets::_asteroids_ruby_gem_ui_texture;
std::shared_ptr<wze::texture> assets::_asteroids_sapphire_gem_ui_texture;

std::vector<std::shared_ptr<wze::texture>>
    assets::_asteroids_pyrite_explosion_animation;
std::vector<std::shared_ptr<wze::texture>>
    assets::_asteroids_wolframite_explosion_animation;
std::vector<std::shared_ptr<wze::texture>>
    assets::_asteroids_carneol_explosion_animation;
std::vector<std::shared_ptr<wze::texture>>
    assets::_asteroids_moldavite_explosion_animation;
std::vector<std::shared_ptr<wze::texture>>
    assets::_asteroids_ruby_explosion_animation;
std::vector<std::shared_ptr<wze::texture>>
    assets::_asteroids_sapphire_explosion_animation;

std::vector<std::shared_ptr<wze::texture>> assets::_enemies_easy_textures;
std::vector<std::shared_ptr<wze::texture>>
    assets::_enemies_easy_rear_loop_animation;
std::vector<std::shared_ptr<wze::texture>>
    assets::_enemies_easy_front_loop_animation;

std::vector<std::shared_ptr<wze::texture>> assets::_enemies_normal_textures;
std::vector<std::shared_ptr<wze::texture>>
    assets::_enemies_normal_rear_loop_animation;
std::vector<std::shared_ptr<wze::texture>>
    assets::_enemies_normal_front_loop_animation;

std::vector<std::shared_ptr<wze::texture>> assets::_enemies_hard_textures;
std::vector<std::shared_ptr<wze::texture>>
    assets::_enemies_hard_rear_loop_animation;
std::vector<std::shared_ptr<wze::texture>>
    assets::_enemies_hard_front_loop_animation;
std::vector<std::shared_ptr<wze::texture>> assets::_enemies_explosion_animation;

std::shared_ptr<wze::texture> assets::_shop_background_texture;
std::shared_ptr<wze::texture> assets::_shop_foreground_texture;
std::vector<std::shared_ptr<wze::texture>> assets::_shop_door_animation;
std::shared_ptr<wze::texture> assets::_shop_door_light_texture;
std::shared_ptr<wze::texture> assets::_shop_storage_texture;
std::shared_ptr<wze::texture> assets::_shop_damage_texture;
std::shared_ptr<wze::texture> assets::_shop_hitpoints_texture;
std::shared_ptr<wze::texture> assets::_shop_speed_texture;

std::shared_ptr<wze::texture> assets::_trade_background_texture;
std::vector<std::shared_ptr<wze::texture>> assets::_trade_tier_textures;

std::shared_ptr<wze::texture> assets::_gem_trade_background_texture;
std::shared_ptr<wze::texture> assets::_damage_upgrade_icon;
std::shared_ptr<wze::texture> assets::_speed_upgrade_icon;
std::shared_ptr<wze::texture> assets::_storage_upgrade_icon;
std::shared_ptr<wze::texture> assets::_health_upgrade_icon;

std::shared_ptr<wze::texture> assets::_hangar_background_texture;
std::shared_ptr<wze::texture> assets::_hangar_rail_texture;
std::shared_ptr<wze::texture> assets::_hangar_ships_texture;
std::vector<std::shared_ptr<wze::texture>> assets::_hangar_door_animation;

std::shared_ptr<wze::texture> assets::_player_backidle1_texture;
std::shared_ptr<wze::texture> assets::_player_backidle2_texture;
std::shared_ptr<wze::texture> assets::_player_backidle3_texture;
std::shared_ptr<wze::texture> assets::_player_backidle4_texture;
std::shared_ptr<wze::texture> assets::_player_back_texture;
std::shared_ptr<wze::texture> assets::_player_backwalk1_texture;
std::shared_ptr<wze::texture> assets::_player_backwalk2_texture;
std::shared_ptr<wze::texture> assets::_player_frontidle1_texture;
std::shared_ptr<wze::texture> assets::_player_frontidle2_texture;
std::shared_ptr<wze::texture> assets::_player_frontidle3_texture;
std::shared_ptr<wze::texture> assets::_player_frontidle4_texture;
std::shared_ptr<wze::texture> assets::_player_front_texture;
std::shared_ptr<wze::texture> assets::_player_frontwalk1_texture;
std::shared_ptr<wze::texture> assets::_player_frontwalk2_texture;
std::shared_ptr<wze::texture> assets::_player_leftidle1_texture;
std::shared_ptr<wze::texture> assets::_player_leftidle2_texture;
std::shared_ptr<wze::texture> assets::_player_left_texture;
std::shared_ptr<wze::texture> assets::_player_leftwalk1_texture;
std::shared_ptr<wze::texture> assets::_player_leftwalk2_texture;
std::shared_ptr<wze::texture> assets::_player_rightidle1_texture;
std::shared_ptr<wze::texture> assets::_player_rightidle2_texture;
std::shared_ptr<wze::texture> assets::_player_right_texture;
std::shared_ptr<wze::texture> assets::_player_rightwalk1_texture;
std::shared_ptr<wze::texture> assets::_player_rightwalk2_texture;
std::vector<std::shared_ptr<wze::texture>> assets::_player_front_idle_animation;
std::vector<std::shared_ptr<wze::texture>> assets::_player_front_walk_animation;
std::vector<std::shared_ptr<wze::texture>> assets::_player_back_idle_animation;
std::vector<std::shared_ptr<wze::texture>> assets::_player_back_walk_animation;
std::vector<std::shared_ptr<wze::texture>> assets::_player_left_idle_animation;
std::vector<std::shared_ptr<wze::texture>> assets::_player_left_walk_animation;
std::vector<std::shared_ptr<wze::texture>> assets::_player_right_idle_animation;
std::vector<std::shared_ptr<wze::texture>> assets::_player_right_walk_animation;

std::shared_ptr<wze::sound> assets::_space_ambiance_music_sound;
std::shared_ptr<wze::sound> assets::_space_fight_music_sound;
std::shared_ptr<wze::sound> assets::_player_ship_warning_sound;
std::shared_ptr<wze::sound> assets::_player_ship_asteroid_loot_accepted_sound;
std::shared_ptr<wze::sound> assets::_player_ship_asteroid_loot_rejected_sound;
std::shared_ptr<wze::sound> assets::_laser_sound;
std::shared_ptr<wze::sound> assets::_laser_marker_sound;
std::shared_ptr<wze::sound> assets::_laser_explosion_sound;
std::shared_ptr<wze::sound> assets::_laser_passing_sound;
std::vector<std::shared_ptr<wze::sound>> assets::_explosion_sounds;
std::shared_ptr<wze::sound> assets::_ship_sound;
std::shared_ptr<wze::sound> assets::_door_sound;
std::shared_ptr<wze::sound> assets::_shop_selling_sound;
std::vector<std::shared_ptr<wze::sound>> assets::_player_step_sounds;
std::shared_ptr<wze::sound> assets::_accept_sound;
std::shared_ptr<wze::sound> assets::_refuse_sound;

std::shared_ptr<wze::font> const& assets::normal_font() {
    return _normal_font;
}

std::shared_ptr<wze::font> const& assets::bold_font() {
    return _bold_font;
}

std::shared_ptr<wze::texture> const& assets::placeholder_texture() {
    return _placeholder_texture;
}

std::shared_ptr<wze::texture> const& assets::space_texture() {
    return _space_texture;
}

std::shared_ptr<wze::texture> const& assets::stellar_token() {
    return _stellar_token;
}

std::shared_ptr<wze::texture> const& assets::button_none_texture() {
    return _button_none_texture;
}

std::shared_ptr<wze::texture> const& assets::button_hovered_texture() {
    return _button_hovered_texture;
}

std::shared_ptr<wze::texture> const& assets::player_ship_base_texture() {
    return _player_ship_base_texture;
}

std::shared_ptr<wze::texture> const& assets::player_ship_crosshair_texture() {
    return _player_ship_crosshair_texture;
}

std::shared_ptr<wze::texture> const& assets::player_ship_warning_texture() {
    return _player_ship_warning_texture;
}

std::vector<std::shared_ptr<wze::texture>> const&
assets::player_ship_hitpoints_textures() {
    return _player_ship_hitpoints_textures;
}

std::vector<std::shared_ptr<wze::texture>> const&
assets::player_ship_storage_textures() {
    return _player_ship_storage_textures;
}

std::vector<std::shared_ptr<wze::texture>> const&
assets::player_ship_difficulty_textures() {
    return _player_ship_difficulty_textures;
}

std::shared_ptr<wze::texture> const& assets::laser_texture() {
    return _laser_texture;
}

std::shared_ptr<wze::texture> const& assets::laser_marker_texture() {
    return _laser_marker_texture;
}

std::vector<std::shared_ptr<wze::texture>> const&
assets::laser_explosion_animation() {
    return _laser_explosion_animation;
}

std::shared_ptr<wze::texture> const& assets::asteroids_pyrite_texture() {
    return _asteroids_pyrite_textures.at(
        wze::math::random<size_t>(0, _asteroids_pyrite_textures.size() - 1));
}

std::shared_ptr<wze::texture> const& assets::asteroids_wolframite_texture() {
    return _asteroids_wolframite_textures.at(wze::math::random<size_t>(
        0, _asteroids_wolframite_textures.size() - 1));
}

std::shared_ptr<wze::texture> const& assets::asteroids_carneol_texture() {
    return _asteroids_carneol_textures.at(
        wze::math::random<size_t>(0, _asteroids_carneol_textures.size() - 1));
}

std::shared_ptr<wze::texture> const& assets::asteroids_moldavite_texture() {
    return _asteroids_moldavite_textures.at(
        wze::math::random<size_t>(0, _asteroids_moldavite_textures.size() - 1));
}

std::shared_ptr<wze::texture> const& assets::asteroids_ruby_texture() {
    return _asteroids_ruby_textures.at(
        wze::math::random<size_t>(0, _asteroids_ruby_textures.size() - 1));
}

std::shared_ptr<wze::texture> const& assets::asteroids_sapphire_texture() {
    return _asteroids_sapphire_textures.at(
        wze::math::random<size_t>(0, _asteroids_sapphire_textures.size() - 1));
}

std::shared_ptr<wze::texture> const& assets::asteroids_pyrite_gem_texture() {
    return _asteroids_pyrite_gem_texture;
}

std::shared_ptr<wze::texture> const&
assets::asteroids_wolframite_gem_texture() {
    return _asteroids_wolframite_gem_texture;
}

std::shared_ptr<wze::texture> const& assets::asteroids_carneol_gem_texture() {
    return _asteroids_carneol_gem_texture;
}

std::shared_ptr<wze::texture> const& assets::asteroids_moldavite_gem_texture() {
    return _asteroids_moldavite_gem_texture;
}

std::shared_ptr<wze::texture> const& assets::asteroids_ruby_gem_texture() {
    return _asteroids_ruby_gem_texture;
}

std::shared_ptr<wze::texture> const& assets::asteroids_sapphire_gem_texture() {
    return _asteroids_sapphire_gem_texture;
}

std::shared_ptr<wze::texture> const& assets::asteroids_pyrite_gem_ui_texture() {
    return _asteroids_pyrite_gem_ui_texture;
}

std::shared_ptr<wze::texture> const&
assets::asteroids_wolframite_gem_ui_texture() {
    return _asteroids_wolframite_gem_ui_texture;
}

std::shared_ptr<wze::texture> const&
assets::asteroids_carneol_gem_ui_texture() {
    return _asteroids_carneol_gem_ui_texture;
}

std::shared_ptr<wze::texture> const&
assets::asteroids_moldavite_gem_ui_texture() {
    return _asteroids_moldavite_gem_ui_texture;
}

std::shared_ptr<wze::texture> const& assets::asteroids_ruby_gem_ui_texture() {
    return _asteroids_ruby_gem_ui_texture;
}

std::shared_ptr<wze::texture> const&
assets::asteroids_sapphire_gem_ui_texture() {
    return _asteroids_sapphire_gem_ui_texture;
}

std::vector<std::shared_ptr<wze::texture>> const&
assets::asteroids_pyrite_explosion_animation() {
    return _asteroids_pyrite_explosion_animation;
}

std::vector<std::shared_ptr<wze::texture>> const&
assets::asteroids_wolframite_explosion_animation() {
    return _asteroids_wolframite_explosion_animation;
}

std::vector<std::shared_ptr<wze::texture>> const&
assets::asteroids_carneol_explosion_animation() {
    return _asteroids_carneol_explosion_animation;
}

std::vector<std::shared_ptr<wze::texture>> const&
assets::asteroids_moldavite_explosion_animation() {
    return _asteroids_moldavite_explosion_animation;
}

std::vector<std::shared_ptr<wze::texture>> const&
assets::asteroids_ruby_explosion_animation() {
    return _asteroids_ruby_explosion_animation;
}

std::vector<std::shared_ptr<wze::texture>> const&
assets::asteroids_sapphire_explosion_animation() {
    return _asteroids_sapphire_explosion_animation;
}

std::vector<std::shared_ptr<wze::texture>> const&
assets::enemies_easy_textures() {
    return _enemies_easy_textures;
}

std::vector<std::shared_ptr<wze::texture>> const&
assets::enemies_easy_rear_loop_animation() {
    return _enemies_easy_rear_loop_animation;
}

std::vector<std::shared_ptr<wze::texture>> const&
assets::enemies_easy_front_loop_animation() {
    return _enemies_easy_front_loop_animation;
}

std::vector<std::shared_ptr<wze::texture>> const&
assets::enemies_normal_textures() {
    return _enemies_normal_textures;
}

std::vector<std::shared_ptr<wze::texture>> const&
assets::enemies_normal_rear_loop_animation() {
    return _enemies_normal_rear_loop_animation;
}

std::vector<std::shared_ptr<wze::texture>> const&
assets::enemies_normal_front_loop_animation() {
    return _enemies_normal_front_loop_animation;
}

std::vector<std::shared_ptr<wze::texture>> const&
assets::enemies_hard_textures() {
    return _enemies_hard_textures;
}

std::vector<std::shared_ptr<wze::texture>> const&
assets::enemies_hard_rear_loop_animation() {
    return _enemies_hard_rear_loop_animation;
}

std::vector<std::shared_ptr<wze::texture>> const&
assets::enemies_hard_front_loop_animation() {
    return _enemies_hard_front_loop_animation;
}

std::vector<std::shared_ptr<wze::texture>> const&
assets::enemies_explosion_animation() {
    return _enemies_explosion_animation;
}

std::shared_ptr<wze::texture> const& assets::shop_background_texture() {
    return _shop_background_texture;
}

std::shared_ptr<wze::texture> const& assets::shop_foreground_texture() {
    return _shop_foreground_texture;
}

std::vector<std::shared_ptr<wze::texture>> const&
assets::shop_door_animation() {
    return _shop_door_animation;
}

std::shared_ptr<wze::texture> const& assets::shop_door_light_texture() {
    return _shop_door_light_texture;
}

std::shared_ptr<wze::texture> const& assets::shop_storage_texture() {
    return _shop_storage_texture;
}

std::shared_ptr<wze::texture> const& assets::shop_damage_texture() {
    return _shop_damage_texture;
}

std::shared_ptr<wze::texture> const& assets::shop_hitpoints_texture() {
    return _shop_hitpoints_texture;
}

std::shared_ptr<wze::texture> const& assets::shop_speed_texture() {
    return _shop_speed_texture;
}

std::shared_ptr<wze::texture> const& assets::trade_background_texture() {
    return _trade_background_texture;
}

std::vector<std::shared_ptr<wze::texture>> const&
assets::trade_tier_textures() {
    return _trade_tier_textures;
}

std::shared_ptr<wze::texture> const& assets::damage_upgrade_icon() {
    return _damage_upgrade_icon;
}

std::shared_ptr<wze::texture> const& assets::speed_upgrade_icon() {
    return _speed_upgrade_icon;
}

std::shared_ptr<wze::texture> const& assets::storage_upgrade_icon() {
    return _storage_upgrade_icon;
}

std::shared_ptr<wze::texture> const& assets::health_upgrade_icon() {
    return _health_upgrade_icon;
}

std::shared_ptr<wze::texture> const& assets::gem_trade_background_texture() {
    return _gem_trade_background_texture;
}

std::shared_ptr<wze::texture> const& assets::hangar_background_texture() {
    return _hangar_background_texture;
}

std::shared_ptr<wze::texture> const& assets::hangar_rail_texture() {
    return _hangar_rail_texture;
}

std::shared_ptr<wze::texture> const& assets::hangar_ships_texture() {
    return _hangar_ships_texture;
}

std::vector<std::shared_ptr<wze::texture>> const&
assets::hangar_door_animation() {
    return _hangar_door_animation;
}

std::vector<std::shared_ptr<wze::texture>>
assets::player_front_idle_animation() {
    return _player_front_idle_animation;
}

std::vector<std::shared_ptr<wze::texture>>
assets::player_front_walk_animation() {
    return _player_front_walk_animation;
}

std::vector<std::shared_ptr<wze::texture>>
assets::player_back_idle_animation() {
    return _player_back_idle_animation;
}

std::vector<std::shared_ptr<wze::texture>>
assets::player_back_walk_animation() {
    return _player_back_walk_animation;
}

std::vector<std::shared_ptr<wze::texture>>
assets::player_left_idle_animation() {
    return _player_left_idle_animation;
}

std::vector<std::shared_ptr<wze::texture>>
assets::player_left_walk_animation() {
    return _player_left_walk_animation;
}

std::vector<std::shared_ptr<wze::texture>>
assets::player_right_idle_animation() {
    return _player_right_idle_animation;
}

std::vector<std::shared_ptr<wze::texture>>
assets::player_right_walk_animation() {
    return _player_right_walk_animation;
}

std::shared_ptr<wze::sound> const& assets::space_ambiance_music_sound() {
    return _space_ambiance_music_sound;
}

std::shared_ptr<wze::sound> const& assets::space_fight_music_sound() {
    return _space_fight_music_sound;
}

std::shared_ptr<wze::sound> const& assets::player_ship_warning_sound() {
    return _player_ship_warning_sound;
}

std::shared_ptr<wze::sound> const&
assets::player_ship_asteroid_loot_accepted_sound() {
    return _player_ship_asteroid_loot_accepted_sound;
}

std::shared_ptr<wze::sound> const&
assets::player_ship_asteroid_loot_rejected_sound() {
    return _player_ship_asteroid_loot_rejected_sound;
}

std::shared_ptr<wze::sound> const& assets::laser_sound() {
    return _laser_sound;
}

std::shared_ptr<wze::sound> const& assets::laser_marker_sound() {
    return _laser_marker_sound;
}

std::shared_ptr<wze::sound> const& assets::laser_explosion_sound() {
    return _laser_explosion_sound;
}

std::shared_ptr<wze::sound> const& assets::laser_passing_sound() {
    return _laser_passing_sound;
}

std::shared_ptr<wze::sound> const& assets::explosion_sound() {
    return _explosion_sounds.at(
        wze::math::random<size_t>(0, _explosion_sounds.size() - 1));
}

std::shared_ptr<wze::sound> const& assets::ship_sound() {
    return _ship_sound;
}

std::shared_ptr<wze::sound> const& assets::door_sound() {
    return _door_sound;
}

std::shared_ptr<wze::sound> const& assets::shop_selling_sound() {
    return _shop_selling_sound;
}

std::shared_ptr<wze::sound> const& assets::player_step_sounds() {
    return _player_step_sounds.at(
        wze::math::random<size_t>(0, _player_step_sounds.size() - 1));
}

std::shared_ptr<wze::sound> const& assets::accept_sound() {
    return _accept_sound;
}

std::shared_ptr<wze::sound> const& assets::refuse_sound() {
    return _refuse_sound;
}

void assets::initialize() {
    _normal_font = wze::assets::load_font(
        "./assets/PixelifySans-VariableFont_wght.ttf", 48);
    _bold_font =
        wze::assets::load_font("./assets/PixelifySans-VariableFont_wght.ttf",
                               48, wze::FONT_STYLE_BOLD);

    _placeholder_texture = wze::assets::create_texture(
        wze::assets::load_image("./assets/placeholder.png"));
    _space_texture = wze::assets::create_texture(
        wze::assets::load_image("./assets/space.png"));
    _stellar_token = wze::assets::create_texture(
        wze::assets::load_image("./assets/stellar_token.png"));

    _button_none_texture = wze::assets::create_texture(
        wze::assets::load_image("./assets/button/none.png"));
    _button_hovered_texture = wze::assets::create_texture(
        wze::assets::load_image("./assets/button/hovered.png"));

    _player_ship_base_texture = wze::assets::create_texture(
        wze::assets::load_image("./assets/player_ship/base.png"));
    _player_ship_crosshair_texture = wze::assets::create_texture(
        wze::assets::load_image("./assets/player_ship/crosshair.png"));
    _player_ship_warning_texture = wze::assets::create_texture(
        wze::assets::load_image("./assets/player_ship/warning.png"));
    _player_ship_hitpoints_textures = {
        nullptr,
        wze::assets::create_texture(
            wze::assets::load_image("./assets/player_ship/hitpoints/1.png")),
        wze::assets::create_texture(
            wze::assets::load_image("./assets/player_ship/hitpoints/2.png")),
        wze::assets::create_texture(
            wze::assets::load_image("./assets/player_ship/hitpoints/3.png")),
        wze::assets::create_texture(
            wze::assets::load_image("./assets/player_ship/hitpoints/4.png")),
        wze::assets::create_texture(
            wze::assets::load_image("./assets/player_ship/hitpoints/5.png")),
        wze::assets::create_texture(
            wze::assets::load_image("./assets/player_ship/hitpoints/6.png")),
        wze::assets::create_texture(
            wze::assets::load_image("./assets/player_ship/hitpoints/7.png")),
        wze::assets::create_texture(
            wze::assets::load_image("./assets/player_ship/hitpoints/8.png")),
        wze::assets::create_texture(
            wze::assets::load_image("./assets/player_ship/hitpoints/9.png")),
        wze::assets::create_texture(
            wze::assets::load_image("./assets/player_ship/hitpoints/10.png"))};
    _player_ship_storage_textures = {
        nullptr,
        wze::assets::create_texture(
            wze::assets::load_image("./assets/player_ship/storage/1.png")),
        wze::assets::create_texture(
            wze::assets::load_image("./assets/player_ship/storage/2.png")),
        wze::assets::create_texture(
            wze::assets::load_image("./assets/player_ship/storage/3.png")),
        wze::assets::create_texture(
            wze::assets::load_image("./assets/player_ship/storage/4.png")),
        wze::assets::create_texture(
            wze::assets::load_image("./assets/player_ship/storage/5.png")),
        wze::assets::create_texture(
            wze::assets::load_image("./assets/player_ship/storage/6.png")),
        wze::assets::create_texture(
            wze::assets::load_image("./assets/player_ship/storage/7.png")),
        wze::assets::create_texture(
            wze::assets::load_image("./assets/player_ship/storage/8.png")),
        wze::assets::create_texture(
            wze::assets::load_image("./assets/player_ship/storage/9.png")),
        wze::assets::create_texture(
            wze::assets::load_image("./assets/player_ship/storage/10.png"))};
    _player_ship_difficulty_textures = {
        nullptr,
        wze::assets::create_texture(
            wze::assets::load_image("./assets/player_ship/difficulty/1.png")),
        wze::assets::create_texture(
            wze::assets::load_image("./assets/player_ship/difficulty/2.png")),
        wze::assets::create_texture(
            wze::assets::load_image("./assets/player_ship/difficulty/3.png")),
        wze::assets::create_texture(
            wze::assets::load_image("./assets/player_ship/difficulty/4.png")),
        wze::assets::create_texture(
            wze::assets::load_image("./assets/player_ship/difficulty/5.png"))};

    _laser_texture = wze::assets::create_texture(
        wze::assets::load_image("./assets/laser/laser.png"));
    _laser_marker_texture = wze::assets::create_texture(
        wze::assets::load_image("./assets/laser/marker.png"));
    _laser_explosion_animation = {
        wze::assets::create_texture(
            wze::assets::load_image("./assets/laser/explosion/1.png")),
        wze::assets::create_texture(
            wze::assets::load_image("./assets/laser/explosion/2.png")),
        wze::assets::create_texture(
            wze::assets::load_image("./assets/laser/explosion/3.png")),
        wze::assets::create_texture(
            wze::assets::load_image("./assets/laser/explosion/4.png")),
        wze::assets::create_texture(
            wze::assets::load_image("./assets/laser/explosion/5.png")),
        wze::assets::create_texture(
            wze::assets::load_image("./assets/laser/explosion/6.png"))};

    _asteroids_pyrite_textures = {
        wze::assets::create_texture(
            wze::assets::load_image("./assets/asteroids/pyrite/1.png")),
        wze::assets::create_texture(
            wze::assets::load_image("./assets/asteroids/pyrite/2.png")),
        wze::assets::create_texture(
            wze::assets::load_image("./assets/asteroids/pyrite/3.png"))};

    _asteroids_wolframite_textures = {
        wze::assets::create_texture(
            wze::assets::load_image("./assets/asteroids/wolframite/1.png")),
        wze::assets::create_texture(
            wze::assets::load_image("./assets/asteroids/wolframite/2.png")),
        wze::assets::create_texture(
            wze::assets::load_image("./assets/asteroids/wolframite/3.png"))};

    _asteroids_carneol_textures = {
        wze::assets::create_texture(
            wze::assets::load_image("./assets/asteroids/carneol/1.png")),
        wze::assets::create_texture(
            wze::assets::load_image("./assets/asteroids/carneol/2.png")),
        wze::assets::create_texture(
            wze::assets::load_image("./assets/asteroids/carneol/3.png"))};

    _asteroids_moldavite_textures = {
        wze::assets::create_texture(
            wze::assets::load_image("./assets/asteroids/moldavite/1.png")),
        wze::assets::create_texture(
            wze::assets::load_image("./assets/asteroids/moldavite/2.png")),
        wze::assets::create_texture(
            wze::assets::load_image("./assets/asteroids/moldavite/3.png"))};

    _asteroids_ruby_textures = {
        wze::assets::create_texture(
            wze::assets::load_image("./assets/asteroids/ruby/1.png")),
        wze::assets::create_texture(
            wze::assets::load_image("./assets/asteroids/ruby/2.png")),
        wze::assets::create_texture(
            wze::assets::load_image("./assets/asteroids/ruby/3.png"))};

    _asteroids_sapphire_textures = {
        wze::assets::create_texture(
            wze::assets::load_image("./assets/asteroids/sapphire/1.png")),
        wze::assets::create_texture(
            wze::assets::load_image("./assets/asteroids/sapphire/2.png")),
        wze::assets::create_texture(
            wze::assets::load_image("./assets/asteroids/sapphire/3.png"))};

    _asteroids_pyrite_gem_texture = wze::assets::create_texture(
        wze::assets::load_image("./assets/asteroids/pyrite/gem.png"));
    _asteroids_wolframite_gem_texture = wze::assets::create_texture(
        wze::assets::load_image("./assets/asteroids/wolframite/gem.png"));
    _asteroids_carneol_gem_texture = wze::assets::create_texture(
        wze::assets::load_image("./assets/asteroids/carneol/gem.png"));
    _asteroids_moldavite_gem_texture = wze::assets::create_texture(
        wze::assets::load_image("./assets/asteroids/moldavite/gem.png"));
    _asteroids_ruby_gem_texture = wze::assets::create_texture(
        wze::assets::load_image("./assets/asteroids/ruby/gem.png"));
    _asteroids_sapphire_gem_texture = wze::assets::create_texture(
        wze::assets::load_image("./assets/asteroids/sapphire/gem.png"));

    _asteroids_pyrite_gem_ui_texture = wze::assets::create_texture(
        wze::assets::load_image("./assets/asteroids/pyrite/gem_ui.png"));
    _asteroids_wolframite_gem_ui_texture = wze::assets::create_texture(
        wze::assets::load_image("./assets/asteroids/wolframite/gem_ui.png"));
    _asteroids_carneol_gem_ui_texture = wze::assets::create_texture(
        wze::assets::load_image("./assets/asteroids/carneol/gem_ui.png"));
    _asteroids_moldavite_gem_ui_texture = wze::assets::create_texture(
        wze::assets::load_image("./assets/asteroids/moldavite/gem_ui.png"));
    _asteroids_ruby_gem_ui_texture = wze::assets::create_texture(
        wze::assets::load_image("./assets/asteroids/ruby/gem_ui.png"));
    _asteroids_sapphire_gem_ui_texture = wze::assets::create_texture(
        wze::assets::load_image("./assets/asteroids/sapphire/gem_ui.png"));

    _asteroids_pyrite_explosion_animation = {
        wze::assets::create_texture(wze::assets::load_image(
            "./assets/asteroids/pyrite/explosion/1.png")),
        wze::assets::create_texture(wze::assets::load_image(
            "./assets/asteroids/pyrite/explosion/2.png")),
        wze::assets::create_texture(wze::assets::load_image(
            "./assets/asteroids/pyrite/explosion/3.png")),
        wze::assets::create_texture(wze::assets::load_image(
            "./assets/asteroids/pyrite/explosion/4.png")),
        wze::assets::create_texture(wze::assets::load_image(
            "./assets/asteroids/pyrite/explosion/5.png")),
        wze::assets::create_texture(wze::assets::load_image(
            "./assets/asteroids/pyrite/explosion/6.png")),
        wze::assets::create_texture(wze::assets::load_image(
            "./assets/asteroids/pyrite/explosion/7.png")),
        wze::assets::create_texture(wze::assets::load_image(
            "./assets/asteroids/pyrite/explosion/8.png")),
        wze::assets::create_texture(wze::assets::load_image(
            "./assets/asteroids/pyrite/explosion/9.png")),
        wze::assets::create_texture(wze::assets::load_image(
            "./assets/asteroids/pyrite/explosion/10.png")),
        wze::assets::create_texture(wze::assets::load_image(
            "./assets/asteroids/pyrite/explosion/11.png")),
        wze::assets::create_texture(wze::assets::load_image(
            "./assets/asteroids/pyrite/explosion/12.png")),
        wze::assets::create_texture(wze::assets::load_image(
            "./assets/asteroids/pyrite/explosion/13.png")),
        wze::assets::create_texture(wze::assets::load_image(
            "./assets/asteroids/pyrite/explosion/14.png")),
        wze::assets::create_texture(wze::assets::load_image(
            "./assets/asteroids/pyrite/explosion/15.png"))};

    _asteroids_wolframite_explosion_animation = {
        wze::assets::create_texture(wze::assets::load_image(
            "./assets/asteroids/wolframite/explosion/1.png")),
        wze::assets::create_texture(wze::assets::load_image(
            "./assets/asteroids/wolframite/explosion/2.png")),
        wze::assets::create_texture(wze::assets::load_image(
            "./assets/asteroids/wolframite/explosion/3.png")),
        wze::assets::create_texture(wze::assets::load_image(
            "./assets/asteroids/wolframite/explosion/4.png")),
        wze::assets::create_texture(wze::assets::load_image(
            "./assets/asteroids/wolframite/explosion/5.png")),
        wze::assets::create_texture(wze::assets::load_image(
            "./assets/asteroids/wolframite/explosion/6.png")),
        wze::assets::create_texture(wze::assets::load_image(
            "./assets/asteroids/wolframite/explosion/7.png")),
        wze::assets::create_texture(wze::assets::load_image(
            "./assets/asteroids/wolframite/explosion/8.png")),
        wze::assets::create_texture(wze::assets::load_image(
            "./assets/asteroids/wolframite/explosion/9.png")),
        wze::assets::create_texture(wze::assets::load_image(
            "./assets/asteroids/wolframite/explosion/10.png")),
        wze::assets::create_texture(wze::assets::load_image(
            "./assets/asteroids/wolframite/explosion/11.png")),
        wze::assets::create_texture(wze::assets::load_image(
            "./assets/asteroids/wolframite/explosion/12.png")),
        wze::assets::create_texture(wze::assets::load_image(
            "./assets/asteroids/wolframite/explosion/13.png")),
        wze::assets::create_texture(wze::assets::load_image(
            "./assets/asteroids/wolframite/explosion/14.png")),
        wze::assets::create_texture(wze::assets::load_image(
            "./assets/asteroids/wolframite/explosion/15.png"))};

    _asteroids_carneol_explosion_animation = {
        wze::assets::create_texture(wze::assets::load_image(
            "./assets/asteroids/carneol/explosion/1.png")),
        wze::assets::create_texture(wze::assets::load_image(
            "./assets/asteroids/carneol/explosion/2.png")),
        wze::assets::create_texture(wze::assets::load_image(
            "./assets/asteroids/carneol/explosion/3.png")),
        wze::assets::create_texture(wze::assets::load_image(
            "./assets/asteroids/carneol/explosion/4.png")),
        wze::assets::create_texture(wze::assets::load_image(
            "./assets/asteroids/carneol/explosion/5.png")),
        wze::assets::create_texture(wze::assets::load_image(
            "./assets/asteroids/carneol/explosion/6.png")),
        wze::assets::create_texture(wze::assets::load_image(
            "./assets/asteroids/carneol/explosion/7.png")),
        wze::assets::create_texture(wze::assets::load_image(
            "./assets/asteroids/carneol/explosion/8.png")),
        wze::assets::create_texture(wze::assets::load_image(
            "./assets/asteroids/carneol/explosion/9.png")),
        wze::assets::create_texture(wze::assets::load_image(
            "./assets/asteroids/carneol/explosion/10.png")),
        wze::assets::create_texture(wze::assets::load_image(
            "./assets/asteroids/carneol/explosion/11.png")),
        wze::assets::create_texture(wze::assets::load_image(
            "./assets/asteroids/carneol/explosion/12.png")),
        wze::assets::create_texture(wze::assets::load_image(
            "./assets/asteroids/carneol/explosion/13.png")),
        wze::assets::create_texture(wze::assets::load_image(
            "./assets/asteroids/carneol/explosion/14.png")),
        wze::assets::create_texture(wze::assets::load_image(
            "./assets/asteroids/carneol/explosion/15.png"))};

    _asteroids_moldavite_explosion_animation = {
        wze::assets::create_texture(wze::assets::load_image(
            "./assets/asteroids/moldavite/explosion/1.png")),
        wze::assets::create_texture(wze::assets::load_image(
            "./assets/asteroids/moldavite/explosion/2.png")),
        wze::assets::create_texture(wze::assets::load_image(
            "./assets/asteroids/moldavite/explosion/3.png")),
        wze::assets::create_texture(wze::assets::load_image(
            "./assets/asteroids/moldavite/explosion/4.png")),
        wze::assets::create_texture(wze::assets::load_image(
            "./assets/asteroids/moldavite/explosion/5.png")),
        wze::assets::create_texture(wze::assets::load_image(
            "./assets/asteroids/moldavite/explosion/6.png")),
        wze::assets::create_texture(wze::assets::load_image(
            "./assets/asteroids/moldavite/explosion/7.png")),
        wze::assets::create_texture(wze::assets::load_image(
            "./assets/asteroids/moldavite/explosion/8.png")),
        wze::assets::create_texture(wze::assets::load_image(
            "./assets/asteroids/moldavite/explosion/9.png")),
        wze::assets::create_texture(wze::assets::load_image(
            "./assets/asteroids/moldavite/explosion/10.png")),
        wze::assets::create_texture(wze::assets::load_image(
            "./assets/asteroids/moldavite/explosion/11.png")),
        wze::assets::create_texture(wze::assets::load_image(
            "./assets/asteroids/moldavite/explosion/12.png")),
        wze::assets::create_texture(wze::assets::load_image(
            "./assets/asteroids/moldavite/explosion/13.png")),
        wze::assets::create_texture(wze::assets::load_image(
            "./assets/asteroids/moldavite/explosion/14.png")),
        wze::assets::create_texture(wze::assets::load_image(
            "./assets/asteroids/moldavite/explosion/15.png"))};

    _asteroids_ruby_explosion_animation = {
        wze::assets::create_texture(
            wze::assets::load_image("./assets/asteroids/ruby/explosion/1.png")),
        wze::assets::create_texture(
            wze::assets::load_image("./assets/asteroids/ruby/explosion/2.png")),
        wze::assets::create_texture(
            wze::assets::load_image("./assets/asteroids/ruby/explosion/3.png")),
        wze::assets::create_texture(
            wze::assets::load_image("./assets/asteroids/ruby/explosion/4.png")),
        wze::assets::create_texture(
            wze::assets::load_image("./assets/asteroids/ruby/explosion/5.png")),
        wze::assets::create_texture(
            wze::assets::load_image("./assets/asteroids/ruby/explosion/6.png")),
        wze::assets::create_texture(
            wze::assets::load_image("./assets/asteroids/ruby/explosion/7.png")),
        wze::assets::create_texture(
            wze::assets::load_image("./assets/asteroids/ruby/explosion/8.png")),
        wze::assets::create_texture(
            wze::assets::load_image("./assets/asteroids/ruby/explosion/9.png")),
        wze::assets::create_texture(wze::assets::load_image(
            "./assets/asteroids/ruby/explosion/10.png")),
        wze::assets::create_texture(wze::assets::load_image(
            "./assets/asteroids/ruby/explosion/11.png")),
        wze::assets::create_texture(wze::assets::load_image(
            "./assets/asteroids/ruby/explosion/12.png")),
        wze::assets::create_texture(wze::assets::load_image(
            "./assets/asteroids/ruby/explosion/13.png")),
        wze::assets::create_texture(wze::assets::load_image(
            "./assets/asteroids/ruby/explosion/14.png")),
        wze::assets::create_texture(wze::assets::load_image(
            "./assets/asteroids/ruby/explosion/15.png"))};

    _asteroids_sapphire_explosion_animation = {
        wze::assets::create_texture(wze::assets::load_image(
            "./assets/asteroids/sapphire/explosion/1.png")),
        wze::assets::create_texture(wze::assets::load_image(
            "./assets/asteroids/sapphire/explosion/2.png")),
        wze::assets::create_texture(wze::assets::load_image(
            "./assets/asteroids/sapphire/explosion/3.png")),
        wze::assets::create_texture(wze::assets::load_image(
            "./assets/asteroids/sapphire/explosion/4.png")),
        wze::assets::create_texture(wze::assets::load_image(
            "./assets/asteroids/sapphire/explosion/5.png")),
        wze::assets::create_texture(wze::assets::load_image(
            "./assets/asteroids/sapphire/explosion/6.png")),
        wze::assets::create_texture(wze::assets::load_image(
            "./assets/asteroids/sapphire/explosion/7.png")),
        wze::assets::create_texture(wze::assets::load_image(
            "./assets/asteroids/sapphire/explosion/8.png")),
        wze::assets::create_texture(wze::assets::load_image(
            "./assets/asteroids/sapphire/explosion/9.png")),
        wze::assets::create_texture(wze::assets::load_image(
            "./assets/asteroids/sapphire/explosion/10.png")),
        wze::assets::create_texture(wze::assets::load_image(
            "./assets/asteroids/sapphire/explosion/11.png")),
        wze::assets::create_texture(wze::assets::load_image(
            "./assets/asteroids/sapphire/explosion/12.png")),
        wze::assets::create_texture(wze::assets::load_image(
            "./assets/asteroids/sapphire/explosion/13.png")),
        wze::assets::create_texture(wze::assets::load_image(
            "./assets/asteroids/sapphire/explosion/14.png")),
        wze::assets::create_texture(wze::assets::load_image(
            "./assets/asteroids/sapphire/explosion/15.png"))};

    _enemies_easy_textures = {
        wze::assets::create_texture(
            wze::assets::load_image("./assets/enemies/easy/rear.png")),
        wze::assets::create_texture(
            wze::assets::load_image("./assets/enemies/easy/rear_up.png")),
        wze::assets::create_texture(
            wze::assets::load_image("./assets/enemies/easy/rear_down.png")),
        wze::assets::create_texture(
            wze::assets::load_image("./assets/enemies/easy/rear_left.png")),
        wze::assets::create_texture(
            wze::assets::load_image("./assets/enemies/easy/rear_right.png")),
        wze::assets::create_texture(
            wze::assets::load_image("./assets/enemies/easy/front.png")),
        wze::assets::create_texture(
            wze::assets::load_image("./assets/enemies/easy/front_up.png")),
        wze::assets::create_texture(
            wze::assets::load_image("./assets/enemies/easy/front_down.png")),
        wze::assets::create_texture(
            wze::assets::load_image("./assets/enemies/easy/front_left.png")),
        wze::assets::create_texture(
            wze::assets::load_image("./assets/enemies/easy/front_right.png"))};
    _enemies_easy_rear_loop_animation = {
        wze::assets::create_texture(
            wze::assets::load_image("./assets/enemies/easy/rear_loop1.png")),
        wze::assets::create_texture(
            wze::assets::load_image("./assets/enemies/easy/rear_loop2.png")),
        wze::assets::create_texture(
            wze::assets::load_image("./assets/enemies/easy/rear_loop3.png"))};
    _enemies_easy_front_loop_animation = {
        wze::assets::create_texture(
            wze::assets::load_image("./assets/enemies/easy/front_loop1.png")),
        wze::assets::create_texture(
            wze::assets::load_image("./assets/enemies/easy/front_loop2.png")),
        wze::assets::create_texture(
            wze::assets::load_image("./assets/enemies/easy/front_loop3.png"))};

    _enemies_normal_textures = {
        wze::assets::create_texture(
            wze::assets::load_image("./assets/enemies/normal/rear.png")),
        wze::assets::create_texture(
            wze::assets::load_image("./assets/enemies/normal/rear_up.png")),
        wze::assets::create_texture(
            wze::assets::load_image("./assets/enemies/normal/rear_down.png")),
        wze::assets::create_texture(
            wze::assets::load_image("./assets/enemies/normal/rear_left.png")),
        wze::assets::create_texture(
            wze::assets::load_image("./assets/enemies/normal/rear_right.png")),
        wze::assets::create_texture(
            wze::assets::load_image("./assets/enemies/normal/front.png")),
        wze::assets::create_texture(
            wze::assets::load_image("./assets/enemies/normal/front_up.png")),
        wze::assets::create_texture(
            wze::assets::load_image("./assets/enemies/normal/front_down.png")),
        wze::assets::create_texture(
            wze::assets::load_image("./assets/enemies/normal/front_left.png")),
        wze::assets::create_texture(wze::assets::load_image(
            "./assets/enemies/normal/front_right.png"))};
    _enemies_normal_rear_loop_animation = {
        wze::assets::create_texture(
            wze::assets::load_image("./assets/enemies/normal/rear_loop1.png")),
        wze::assets::create_texture(
            wze::assets::load_image("./assets/enemies/normal/rear_loop2.png")),
        wze::assets::create_texture(
            wze::assets::load_image("./assets/enemies/normal/rear_loop3.png"))};
    _enemies_normal_front_loop_animation = {
        wze::assets::create_texture(
            wze::assets::load_image("./assets/enemies/normal/front_loop1.png")),
        wze::assets::create_texture(
            wze::assets::load_image("./assets/enemies/normal/front_loop2.png")),
        wze::assets::create_texture(wze::assets::load_image(
            "./assets/enemies/normal/front_loop3.png"))};

    _enemies_hard_textures = {
        wze::assets::create_texture(
            wze::assets::load_image("./assets/enemies/hard/rear.png")),
        wze::assets::create_texture(
            wze::assets::load_image("./assets/enemies/hard/rear_up.png")),
        wze::assets::create_texture(
            wze::assets::load_image("./assets/enemies/hard/rear_down.png")),
        wze::assets::create_texture(
            wze::assets::load_image("./assets/enemies/hard/rear_left.png")),
        wze::assets::create_texture(
            wze::assets::load_image("./assets/enemies/hard/rear_right.png")),
        wze::assets::create_texture(
            wze::assets::load_image("./assets/enemies/hard/front.png")),
        wze::assets::create_texture(
            wze::assets::load_image("./assets/enemies/hard/front_up.png")),
        wze::assets::create_texture(
            wze::assets::load_image("./assets/enemies/hard/front_down.png")),
        wze::assets::create_texture(
            wze::assets::load_image("./assets/enemies/hard/front_left.png")),
        wze::assets::create_texture(
            wze::assets::load_image("./assets/enemies/hard/front_right.png"))};
    _enemies_hard_rear_loop_animation = {
        wze::assets::create_texture(
            wze::assets::load_image("./assets/enemies/hard/rear_loop1.png")),
        wze::assets::create_texture(
            wze::assets::load_image("./assets/enemies/hard/rear_loop2.png")),
        wze::assets::create_texture(
            wze::assets::load_image("./assets/enemies/hard/rear_loop3.png"))};
    _enemies_hard_front_loop_animation = {
        wze::assets::create_texture(
            wze::assets::load_image("./assets/enemies/hard/front_loop1.png")),
        wze::assets::create_texture(
            wze::assets::load_image("./assets/enemies/hard/front_loop2.png")),
        wze::assets::create_texture(
            wze::assets::load_image("./assets/enemies/hard/front_loop3.png"))};
    _enemies_explosion_animation = {
        wze::assets::create_texture(
            wze::assets::load_image("./assets/enemies/explosion/1.png")),
        wze::assets::create_texture(
            wze::assets::load_image("./assets/enemies/explosion/2.png")),
        wze::assets::create_texture(
            wze::assets::load_image("./assets/enemies/explosion/3.png")),
        wze::assets::create_texture(
            wze::assets::load_image("./assets/enemies/explosion/4.png")),
        wze::assets::create_texture(
            wze::assets::load_image("./assets/enemies/explosion/5.png")),
        wze::assets::create_texture(
            wze::assets::load_image("./assets/enemies/explosion/6.png")),
        wze::assets::create_texture(
            wze::assets::load_image("./assets/enemies/explosion/7.png")),
        wze::assets::create_texture(
            wze::assets::load_image("./assets/enemies/explosion/8.png")),
        wze::assets::create_texture(
            wze::assets::load_image("./assets/enemies/explosion/9.png")),
        wze::assets::create_texture(
            wze::assets::load_image("./assets/enemies/explosion/10.png"))};

    _shop_background_texture = wze::assets::create_texture(
        wze::assets::load_image("./assets/shop/background.png"));
    _shop_foreground_texture = wze::assets::create_texture(
        wze::assets::load_image("./assets/shop/foreground.png"));
    _shop_door_animation = {
        wze::assets::create_texture(
            wze::assets::load_image("./assets/shop/door/1.png")),
        wze::assets::create_texture(
            wze::assets::load_image("./assets/shop/door/2.png")),
        wze::assets::create_texture(
            wze::assets::load_image("./assets/shop/door/3.png")),
        wze::assets::create_texture(
            wze::assets::load_image("./assets/shop/door/4.png")),
        wze::assets::create_texture(
            wze::assets::load_image("./assets/shop/door/5.png")),
        wze::assets::create_texture(
            wze::assets::load_image("./assets/shop/door/6.png")),
        wze::assets::create_texture(
            wze::assets::load_image("./assets/shop/door/7.png")),
        wze::assets::create_texture(
            wze::assets::load_image("./assets/shop/door/8.png")),
        wze::assets::create_texture(
            wze::assets::load_image("./assets/shop/door/9.png")),
        wze::assets::create_texture(
            wze::assets::load_image("./assets/shop/door/10.png")),
        wze::assets::create_texture(
            wze::assets::load_image("./assets/shop/door/11.png")),
        wze::assets::create_texture(
            wze::assets::load_image("./assets/shop/door/12.png")),
        wze::assets::create_texture(
            wze::assets::load_image("./assets/shop/door/13.png"))};
    _shop_door_light_texture = wze::assets::create_texture(
        wze::assets::load_image("./assets/shop/door/light.png"));
    _shop_storage_texture = wze::assets::create_texture(
        wze::assets::load_image("./assets/shop/storage.png"));
    _shop_damage_texture = wze::assets::create_texture(
        wze::assets::load_image("./assets/shop/damage.png"));
    _shop_hitpoints_texture = wze::assets::create_texture(
        wze::assets::load_image("./assets/shop/hitpoints.png"));
    _shop_speed_texture = wze::assets::create_texture(
        wze::assets::load_image("./assets/shop/speed.png"));

    _trade_background_texture = wze::assets::create_texture(
        wze::assets::load_image("./assets/trade/background.png"));
    _trade_tier_textures = {
        wze::assets::create_texture(
            wze::assets::load_image("./assets/trade/tier/0.png")),
        wze::assets::create_texture(
            wze::assets::load_image("./assets/trade/tier/1.png")),
        wze::assets::create_texture(
            wze::assets::load_image("./assets/trade/tier/2.png")),
        wze::assets::create_texture(
            wze::assets::load_image("./assets/trade/tier/3.png"))};
    _damage_upgrade_icon = wze::assets::create_texture(
        wze::assets::load_image("./assets/trade/icons/cannon_icon1.png"));
    _speed_upgrade_icon = wze::assets::create_texture(
        wze::assets::load_image("./assets/trade/icons/speed_icon1.png"));
    _storage_upgrade_icon = wze::assets::create_texture(
        wze::assets::load_image("./assets/trade/icons/storage_icon1.png"));
    _health_upgrade_icon = wze::assets::create_texture(
        wze::assets::load_image("./assets/trade/icons/health_icon1.png"));

    _gem_trade_background_texture = {wze::assets::create_texture(
        wze::assets::load_image("./assets/gem_trade/background.png"))};

    _hangar_background_texture = wze::assets::create_texture(
        wze::assets::load_image("./assets/hangar/background.png"));
    _hangar_rail_texture = wze::assets::create_texture(
        wze::assets::load_image("./assets/hangar/rail.png"));
    _hangar_ships_texture = wze::assets::create_texture(
        wze::assets::load_image("./assets/hangar/ships.png"));
    _hangar_door_animation = {
        wze::assets::create_texture(
            wze::assets::load_image("./assets/hangar/door/1.png")),
        wze::assets::create_texture(
            wze::assets::load_image("./assets/hangar/door/2.png")),
        wze::assets::create_texture(
            wze::assets::load_image("./assets/hangar/door/3.png")),
        wze::assets::create_texture(
            wze::assets::load_image("./assets/hangar/door/4.png")),
        wze::assets::create_texture(
            wze::assets::load_image("./assets/hangar/door/5.png")),
        wze::assets::create_texture(
            wze::assets::load_image("./assets/hangar/door/6.png")),
        wze::assets::create_texture(
            wze::assets::load_image("./assets/hangar/door/7.png")),
        wze::assets::create_texture(
            wze::assets::load_image("./assets/hangar/door/8.png")),
        wze::assets::create_texture(
            wze::assets::load_image("./assets/hangar/door/9.png")),
        wze::assets::create_texture(
            wze::assets::load_image("./assets/hangar/door/10.png")),
        wze::assets::create_texture(
            wze::assets::load_image("./assets/hangar/door/11.png")),
        wze::assets::create_texture(
            wze::assets::load_image("./assets/hangar/door/12.png")),
        wze::assets::create_texture(
            wze::assets::load_image("./assets/hangar/door/13.png"))};

    _player_backidle1_texture = wze::assets::create_texture(
        wze::assets::load_image("./assets/player/backidle1.png"));
    _player_backidle2_texture = wze::assets::create_texture(
        wze::assets::load_image("./assets/player/backidle2.png"));
    _player_backidle3_texture = wze::assets::create_texture(
        wze::assets::load_image("./assets/player/backidle3.png"));
    _player_backidle4_texture = wze::assets::create_texture(
        wze::assets::load_image("./assets/player/backidle4.png"));
    _player_back_texture = wze::assets::create_texture(
        wze::assets::load_image("./assets/player/back.png"));
    _player_backwalk1_texture = wze::assets::create_texture(
        wze::assets::load_image("./assets/player/backwalk1.png"));
    _player_backwalk2_texture = wze::assets::create_texture(
        wze::assets::load_image("./assets/player/backwalk2.png"));
    _player_frontidle1_texture = wze::assets::create_texture(
        wze::assets::load_image("./assets/player/frontidle1.png"));
    _player_frontidle2_texture = wze::assets::create_texture(
        wze::assets::load_image("./assets/player/frontidle2.png"));
    _player_frontidle3_texture = wze::assets::create_texture(
        wze::assets::load_image("./assets/player/frontidle3.png"));
    _player_frontidle4_texture = wze::assets::create_texture(
        wze::assets::load_image("./assets/player/frontidle4.png"));
    _player_front_texture = wze::assets::create_texture(
        wze::assets::load_image("./assets/player/front.png"));
    _player_frontwalk1_texture = wze::assets::create_texture(
        wze::assets::load_image("./assets/player/frontwalk1.png"));
    _player_frontwalk2_texture = wze::assets::create_texture(
        wze::assets::load_image("./assets/player/frontwalk2.png"));
    _player_leftidle1_texture = wze::assets::create_texture(
        wze::assets::load_image("./assets/player/leftidle1.png"));
    _player_leftidle2_texture = wze::assets::create_texture(
        wze::assets::load_image("./assets/player/leftidle2.png"));
    _player_left_texture = wze::assets::create_texture(
        wze::assets::load_image("./assets/player/left.png"));
    _player_leftwalk1_texture = wze::assets::create_texture(
        wze::assets::load_image("./assets/player/leftwalk1.png"));
    _player_leftwalk2_texture = wze::assets::create_texture(
        wze::assets::load_image("./assets/player/leftwalk2.png"));
    _player_rightidle1_texture = wze::assets::create_texture(
        wze::assets::load_image("./assets/player/rightidle1.png"));
    _player_rightidle2_texture = wze::assets::create_texture(
        wze::assets::load_image("./assets/player/rightidle2.png"));
    _player_right_texture = wze::assets::create_texture(
        wze::assets::load_image("./assets/player/right.png"));
    _player_rightwalk1_texture = wze::assets::create_texture(
        wze::assets::load_image("./assets/player/rightwalk1.png"));
    _player_rightwalk2_texture = wze::assets::create_texture(
        wze::assets::load_image("./assets/player/rightwalk2.png"));
    _player_front_idle_animation = {
        _player_frontidle1_texture, _player_frontidle2_texture,
        _player_frontidle3_texture, _player_frontidle4_texture};
    _player_front_walk_animation = {
        _player_frontwalk1_texture,
        _player_front_texture,
        _player_frontwalk2_texture,
        _player_front_texture,
    };
    _player_back_idle_animation = {
        _player_backidle1_texture, _player_backidle2_texture,
        _player_backidle3_texture, _player_backidle4_texture};
    _player_back_walk_animation = {
        _player_backwalk1_texture,
        _player_back_texture,
        _player_backwalk2_texture,
        _player_back_texture,
    };
    _player_left_idle_animation = {_player_leftidle1_texture,
                                   _player_leftidle2_texture};
    _player_left_walk_animation = {
        _player_leftwalk1_texture,
        _player_left_texture,
        _player_leftwalk2_texture,
        _player_left_texture,
    };
    _player_right_idle_animation = {_player_rightidle1_texture,
                                    _player_rightidle2_texture};
    _player_right_walk_animation = {
        _player_rightwalk1_texture,
        _player_right_texture,
        _player_rightwalk2_texture,
        _player_right_texture,
    };

    _space_ambiance_music_sound =
        wze::assets::load_sound("./assets/sounds/space_ambiance.mp3");
    _space_fight_music_sound =
        wze::assets::load_sound("./assets/sounds/space_fight.mp3");
    _player_ship_warning_sound =
        wze::assets::load_sound("./assets/sounds/player_ship_warning.ogg");
    _player_ship_asteroid_loot_accepted_sound = wze::assets::load_sound(
        "./assets/sounds/player_ship_asteroid_loot_accepted.ogg");
    _player_ship_asteroid_loot_rejected_sound = wze::assets::load_sound(
        "./assets/sounds/player_ship_asteroid_loot_rejected.ogg");
    _laser_sound = wze::assets::load_sound("./assets/sounds/laser.wav");
    _laser_marker_sound =
        wze::assets::load_sound("./assets/sounds/laser_marker.mp3");
    _laser_explosion_sound =
        wze::assets::load_sound("./assets/sounds/laser_explosion.ogg");
    _laser_passing_sound =
        wze::assets::load_sound("./assets/sounds/laser_passing.wav");
    _explosion_sounds = {
        wze::assets::load_sound("./assets/sounds/explosion1.ogg"),
        wze::assets::load_sound("./assets/sounds/explosion2.ogg"),
        wze::assets::load_sound("./assets/sounds/explosion3.ogg")};
    _ship_sound = wze::assets::load_sound("./assets/sounds/ship.wav");
    _door_sound = wze::assets::load_sound("./assets/sounds/door.ogg");
    _shop_selling_sound =
        wze::assets::load_sound("./assets/sounds/shop_selling.mp3");
    _player_step_sounds = {
        wze::assets::load_sound("./assets/sounds/player_step1.mp3"),
        wze::assets::load_sound("./assets/sounds/player_step2.mp3"),
        wze::assets::load_sound("./assets/sounds/player_step3.mp3"),
        wze::assets::load_sound("./assets/sounds/player_step4.mp3"),
        wze::assets::load_sound("./assets/sounds/player_step5.mp3"),
        wze::assets::load_sound("./assets/sounds/player_step6.mp3")};
    _accept_sound = wze::assets::load_sound("./assets/sounds/accept.ogg");
    _refuse_sound = wze::assets::load_sound("./assets/sounds/refuse.ogg");
}
