#include <game/assets.hpp>
#include <game/save_data.hpp>
#include <game/trade.hpp>

trade::trade(float x, float y, trade_type trade_type)
    : _button(x + 147.5f, y + 120, wze::camera::focus() * 0.95f, 0, 270, 70,
              true, std::numeric_limits<uint8_t>::max(),
              {{-135, 35}, {-135, -35}, {135, -35}, {135, 35}},
              assets::button_none_texture(), assets::button_hovered_texture(),
              assets::button_hovered_texture(), "Vásárol", 0, 0, 0) {
    std::shared_ptr<wze::image> image;

    _trade_type = trade_type;
    _background = {x,   y,    wze::camera::focus() * 0.95f,      0, 725,
                   390, true, assets::trade_background_texture()};

    switch (_trade_type) {
    case TRADE_TYPE_ARMOR:
        image = wze::assets::create_image(
            "Extra kemény\nűrpáncélzat, mely\nhatékonyan védi hajódat\naz "
            "űrbanditák\ntámadásaitól.\nNem bánod meg!",
            assets::normal_font());
        _tier = save_data::player_ship_hitpoints_tier;
        _set_tier = save_data::set_player_ship_hitpoints_tier;
        break;
    case TRADE_TYPE_ENGINE:
        image = wze::assets::create_image(
            "Gyorsabb hajtómű,\ngyorsabb bányászás,\nmagasabb órabér!\nVálassz "
            "szomszédos\nrendszerekből importált\nhajtóműveink közül!",
            assets::normal_font());
        _tier = save_data::player_ship_speed_tier;
        _set_tier = save_data::set_player_ship_speed_tier;
        break;
    case TRADE_TYPE_STORAGE:
        image = wze::assets::create_image(
            "Ha úgy érzed\nűrhajód folyton tele,\nnem férnek el\na "
            "rakományaid\nakkor ideje\nrakteret növelni!",
            assets::normal_font());
        _tier = save_data::player_ship_storage_tier;
        _set_tier = save_data::set_player_ship_storage_tier;
        break;
    case TRADE_TYPE_CANNON:
        image = wze::assets::create_image(
            "Nincs biztonságos\nbányászás elrettentő\ntűzerő nélkül, vegyél\n"
            "tőlem extra erős\nlézer ágyúkat, hogy\nmegvédhesd magad!",
            assets::normal_font());
        _tier = save_data::player_ship_damage_tier;
        _set_tier = save_data::set_player_ship_damage_tier;
        break;
    }

    _tier_sprite = {x - 145, y + 42.5f, wze::camera::focus() * 0.95f, 0, 165,
                    25,      true};
    _price = 0;
    _price_sprite = {x - 147.5f, y + 115, wze::camera::focus() * 0.95f, 0, 270,
                     70,         true};
    _text_sprite = {x + 142.5f,
                    y - 50,
                    wze::camera::focus() * 0.95f,
                    0,
                    290,
                    (float)image->h / (float)image->w * 290,
                    true,
                    wze::assets::create_texture(image)};
}

void trade::update() {
    std::shared_ptr<wze::image> image;

    _button.update();

    if (_button.state() & BUTTON_STATE_POSTCLICK && _tier() < 3 &&
        _price <= save_data::player_money()) {
        _set_tier(_tier() + 1);
        save_data::set_player_money(save_data::player_money() - _price);
    }

    _tier_sprite.set_texture(assets::trade_tier_textures().at(_tier()));
    _price = (_tier() + 1) * 1000;

    image = wze::assets::create_image(
        _tier() < 3 ? std::to_string(_price) + " ST" : "Elfogyott",
        assets::bold_font());
    _price_sprite.set_width((float)image->w / (float)image->h * 70);
    _price_sprite.set_texture(wze::assets::create_texture(image));
}
