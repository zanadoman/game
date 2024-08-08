#include <game/assets.hpp>
#include <game/save_data.hpp>
#include <game/trade.hpp>

trade::trade(float x, float y, trade_type trade_type)
    : _button(x + 147.5f, y + 120, wze::camera::focus() * 0.95f, 0, 270, 70,
              true, std::numeric_limits<uint8_t>::max(),
              {{-135, 35}, {-135, -35}, {135, -35}, {135, 35}},
              assets::button_none_texture(), assets::button_hovered_texture(),
              assets::button_hovered_texture(), "Vásárol", 0, 0, 0,
              assets::shop_selling_sound(), assets::refuse_sound()) {
    std::shared_ptr<wze::image> image;

    _trade_type = trade_type;
    _background = {x,   y,    wze::camera::focus() * 0.95f,      0, 725,
                   390, true, assets::trade_background_texture()};
    _icon_sprite = {x - 147, y - 75, wze::camera::focus() * 0.95f, 0, 283,
                    135,     true};

    switch (_trade_type) {
    case TRADE_TYPE_ARMOR:
        image = wze::assets::create_image(
            "Extra kemény\nűrpáncélzat, mely\nhatékonyan\nvédi rakományod az\n"
            "űrbanditák\ntámadásaitól!",
            assets::normal_font());
        _tier = save_data::player_ship_hitpoints_tier;
        _set_tier = save_data::set_player_ship_hitpoints_tier;
        _icon_sprite.set_texture(assets::health_upgrade_icon());
        break;
    case TRADE_TYPE_ENGINE:
        image = wze::assets::create_image(
            "Gyorsabb hajtómű,\ngyorsabb bányászás,\nmagasabb órabér!\nVálassz "
            "legújabb\nhajtóműveink közül!",
            assets::normal_font());
        _tier = save_data::player_ship_speed_tier;
        _set_tier = save_data::set_player_ship_speed_tier;
        _icon_sprite.set_texture(assets::speed_upgrade_icon());
        break;
    case TRADE_TYPE_STORAGE:
        image = wze::assets::create_image(
            "Ha úgy érzed\nűrhajód folyton tele,\nnem férnek el\na "
            "rakományaid\nakkor ideje\nrakteret növelni!",
            assets::normal_font());
        _tier = save_data::player_ship_storage_tier;
        _set_tier = save_data::set_player_ship_storage_tier;
        _icon_sprite.set_texture(assets::storage_upgrade_icon());
        break;
    case TRADE_TYPE_CANNON:
        image = wze::assets::create_image(
            "Nincs biztonságos\nbányászás megfelelő\ntűzerő nélkül, vegyél\n"
            "tőlem extra erős\nlézer ágyúkat, hogy\nmegvédhesd magad!",
            assets::normal_font());
        _tier = save_data::player_ship_damage_tier;
        _set_tier = save_data::set_player_ship_damage_tier;
        _icon_sprite.set_texture(assets::damage_upgrade_icon());
        break;
    }

    _tier_sprite = {x - 145, y + 42.5f, wze::camera::focus() * 0.95f, 0, 165,
                    25,      true};
    _price = 0;
    _price_sprite = {x - 147.5f, y + 120, wze::camera::focus() * 0.95f, 0, 270,
                     45,         true};
    _text_sprite = {x + 152.5f,
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

    _button.set_enabled(_price <= save_data::player_money() && _tier() < 3);

    _tier_sprite.set_texture(assets::trade_tier_textures().at(_tier()));
    _price = (_tier() + 1) * 5000;

    image = wze::assets::create_image(
        _tier() < 3 ? std::to_string(_price) + " ST" : "Elfogyott",
        _tier() < 3 ? assets::bold_font() : assets::normal_font());
    _price_sprite.set_width((float)image->w / (float)image->h * 45);
    _price_sprite.set_texture(wze::assets::create_texture(image));
}
