#include <game/assets.hpp>
#include <game/save_data.hpp>
#include <game/trade.hpp>

trade::trade(float x, float y, trade_type trade_type)
    : _button(x + 150, y + 75, wze::camera::focus() * 0.9f, 0, 100, 50, true,
              std::numeric_limits<uint8_t>::max(),
              {{-50, 25}, {-50, -25}, {50, -25}, {50, 25}},
              assets::placeholder_texture(), assets::shop_background_texture(),
              assets::space_texture(), "Vásárol", 0, 0, 0) {
    _trade_type = trade_type;
    _background = {x,
                   y,
                   wze::camera::focus() * 0.9f,
                   0,
                   600,
                   300,
                   true,
                   assets::placeholder_texture(),
                   0,
                   0,
                   0,
                   std::numeric_limits<uint8_t>::max() / 2};
    _level1 = {_background.x() - 150,
               _background.y(),
               _background.z(),
               0,
               50,
               50,
               true};
    _level2 = {
        _background.x(), _background.y(), _background.z(), 0, 50, 50, true};
    _level3 = {_background.x() + 150,
               _background.y(),
               _background.z(),
               0,
               50,
               50,
               true};

    switch (_trade_type) {
    case TRADE_TYPE_ARMOR:
        _level = save_data::player_ship_hitpoints_tier;
        _set_level = save_data::set_player_ship_hitpoints_tier;
        break;
    case TRADE_TYPE_ENGINE:
        _level = save_data::player_ship_speed_tier;
        _set_level = save_data::set_player_ship_speed_tier;
        break;
    case TRADE_TYPE_STORAGE:
        _level = save_data::player_ship_storage_tier;
        _set_level = save_data::set_player_ship_storage_tier;
        break;
    case TRADE_TYPE_CANNON:
        _level = save_data::player_ship_damage_tier;
        _set_level = save_data::set_player_ship_damage_tier;
        break;
    }

    switch (_level()) {
    case 0:
        _level1.set_texture(assets::placeholder_texture());
        _level2.set_texture(assets::placeholder_texture());
        _level3.set_texture(assets::placeholder_texture());
        _price = 1000;
        break;
    case 1:
        _level1.set_texture(assets::asteroids_ruby_gem_texture());
        _level2.set_texture(assets::placeholder_texture());
        _level3.set_texture(assets::placeholder_texture());
        _price = 2000;
        break;
    case 2:
        _level1.set_texture(assets::asteroids_ruby_gem_texture());
        _level2.set_texture(assets::asteroids_ruby_gem_texture());
        _level3.set_texture(assets::placeholder_texture());
        _price = 3000;
        break;
    default:
        _level1.set_texture(assets::asteroids_ruby_gem_texture());
        _level2.set_texture(assets::asteroids_ruby_gem_texture());
        _level3.set_texture(assets::asteroids_ruby_gem_texture());
        _price = 0;
        break;
    }
}

void trade::update() {
    _button.update();

    if (_button.state() & BUTTON_STATE_POSTCLICK && _level() < 3 &&
        _price <= save_data::player_money()) {
        _set_level(_level() + 1);
        save_data::set_player_money(save_data::player_money() - _price);
    }

    switch (_level()) {
    case 0:
        _level1.set_texture(assets::placeholder_texture());
        _level2.set_texture(assets::placeholder_texture());
        _level3.set_texture(assets::placeholder_texture());
        _price = 1000;
        break;
    case 1:
        _level1.set_texture(assets::asteroids_ruby_gem_texture());
        _level2.set_texture(assets::placeholder_texture());
        _level3.set_texture(assets::placeholder_texture());
        _price = 2000;
        break;
    case 2:
        _level1.set_texture(assets::asteroids_ruby_gem_texture());
        _level2.set_texture(assets::asteroids_ruby_gem_texture());
        _level3.set_texture(assets::placeholder_texture());
        _price = 3000;
        break;
    default:
        _level1.set_texture(assets::asteroids_ruby_gem_texture());
        _level2.set_texture(assets::asteroids_ruby_gem_texture());
        _level3.set_texture(assets::asteroids_ruby_gem_texture());
        _price = 0;
        break;
    }
}
