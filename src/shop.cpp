#include <game/assets.hpp>
#include <game/enums.hpp>
#include <game/gem_trade.hpp>
#include <game/save_data.hpp>
#include <game/shop.hpp>
#include <game/trade.hpp>

void shop::update_trade() {
    if (wze::math::length(_player.x() + 675, _player.y() + 152.5f) < 300) {
        if (!_trade) {
            _trade.reset(new trade(-675, -352.5, TRADE_TYPE_STORAGE));
        } else {
            _trade->update();
        }
    } else if (wze::math::length(_player.x() - 675, _player.y() + 152.5f) <
               300) {
        if (!_trade) {
            _trade.reset(new trade(675, -352.5, TRADE_TYPE_CANNON));
        } else {
            _trade->update();
        }
    } else if (wze::math::length(_player.x() + 675, _player.y() - 657.5f) <
               300) {
        if (!_trade) {
            _trade.reset(new trade(-675, 457.5, TRADE_TYPE_ARMOR));
        } else {
            _trade->update();
        }
    } else if (wze::math::length(_player.x() - 675, _player.y() - 657.5f) <
               300) {
        if (!_trade) {
            _trade.reset(new trade(675, 457.5, TRADE_TYPE_ENGINE));

        } else {
            _trade->update();
        }
    } else if (wze::math::length(_player.x(), _player.y() + 595) < 300) {
        if (!_gem_trade) {
            _gem_trade.reset(new gem_trade);
        } else {
            _gem_trade->update();
        }
    } else {
        _trade.reset();
        _gem_trade.reset();
    }
}

scene_type shop::update_door_right() {
    float distance;

    distance = wze::math::length(_player.x() - 1815, _player.y() + 397.5f);

    if (!_door_right_animating && (distance <= 500) != _door_right_open) {
        _door_right_animating = true;
        _door_right_sound.play();
        if (!_door_right_animation.reversed()) {
            _door_right_light.set_color_r(137);
            _door_right_light.set_color_g(221);
            _door_right_light.set_color_b(70);
        } else {
            _door_right_light.set_color_r(228);
            _door_right_light.set_color_g(44);
            _door_right_light.set_color_b(56);
        }
    }

    if (_door_right_animating && _door_right_animation.play()) {
        _door_right->set_texture(_door_right_animation.frames().back());
        _door_right_animation.reverse();
        _door_right_animation.reset();
        _door_right_open = !_door_right_open;
        _door_right_animating = false;
    }

    _door_right_proxy = distance <= 150;
    if (_door_right_open && !_door_right_animating && _door_right_proxy) {
        if (_color != 0) {
            _color = std::max(0.f, _color - 0.2f * wze::timer::delta_time());
        }
    } else if (!_door_left_proxy) {
        if (_color != std::numeric_limits<uint8_t>::max()) {
            _color = std::min(_color + 0.2f * wze::timer::delta_time(),
                              (float)std::numeric_limits<uint8_t>::max());
        }
    }
    wze::renderer::set_space_color_r(_color);
    wze::renderer::set_space_color_g(_color);
    wze::renderer::set_space_color_b(_color);
    wze::renderer::set_background_color_r(
        _color / std::numeric_limits<uint8_t>::max() * 18);
    wze::renderer::set_background_color_g(
        _color / std::numeric_limits<uint8_t>::max() * 18);
    wze::renderer::set_background_color_b(
        _color / std::numeric_limits<uint8_t>::max() * 38);

    return !_color ? SCENE_TYPE_HANGAR : SCENE_TYPE_SHOP;
}

scene_type shop::update_door_left() {
    float distance;

    distance = wze::math::length(_player.x() + 1815, _player.y() + 397.5f);

    if (!_door_left_animating && (distance <= 500) != _door_left_open) {
        _door_left_animating = true;
        _door_left_sound.play();
        if (!_door_left_animation.reversed()) {
            _door_left_light.set_color_r(137);
            _door_left_light.set_color_g(221);
            _door_left_light.set_color_b(70);
        } else {
            _door_left_light.set_color_r(228);
            _door_left_light.set_color_g(44);
            _door_left_light.set_color_b(56);
        }
    }

    if (_door_left_animating && _door_left_animation.play()) {
        _door_left->set_texture(_door_left_animation.frames().back());
        _door_left_animation.reverse();
        _door_left_animation.reset();
        _door_left_open = !_door_left_open;
        _door_left_animating = false;
    }

    _door_left_proxy = distance <= 150;
    if (_door_left_open && !_door_left_animating && _door_left_proxy) {
        if (_color != 0) {
            _color = std::max(0.f, _color - 0.2f * wze::timer::delta_time());
        }
    } else if (!_door_right_proxy) {
        if (_color != std::numeric_limits<uint8_t>::max()) {
            _color = std::min(_color + 0.2f * wze::timer::delta_time(),
                              (float)std::numeric_limits<uint8_t>::max());
        }
    }
    wze::renderer::set_space_color_r(_color);
    wze::renderer::set_space_color_g(_color);
    wze::renderer::set_space_color_b(_color);
    wze::renderer::set_background_color_r(
        _color / std::numeric_limits<uint8_t>::max() * 18);
    wze::renderer::set_background_color_g(
        _color / std::numeric_limits<uint8_t>::max() * 18);
    wze::renderer::set_background_color_b(
        _color / std::numeric_limits<uint8_t>::max() * 38);

    return !_color ? SCENE_TYPE_MENU : SCENE_TYPE_SHOP;
}

void shop::update_money() {
    std::shared_ptr<wze::image> image;

    image = wze::assets::create_image(std::to_string(save_data::player_money()),
                                      assets::bold_font());
    _money_count.set_width((float)image->w / (float)image->h * 70);
    _money_count.set_x(1205 - _money_count.width() / 2 - 50);
    _money_count.set_texture(wze::assets::create_texture(image));
}

shop::shop() : _player(1615, -397.5) {
    _color = 0.2;
    wze::renderer::set_space_color_r(_color);
    wze::renderer::set_space_color_g(_color);
    wze::renderer::set_space_color_b(_color);
    wze::renderer::set_background_color_r(_color);
    wze::renderer::set_background_color_g(_color);
    wze::renderer::set_background_color_b(_color);

    _background_sprite = {0,
                          0,
                          wze::camera::focus(),
                          0,
                          5120,
                          2880,
                          true,
                          assets::shop_background_texture(),
                          std::numeric_limits<uint8_t>::max(),
                          std::numeric_limits<uint8_t>::max(),
                          std::numeric_limits<uint8_t>::max(),
                          std::numeric_limits<uint8_t>::max(),
                          wze::FLIP_NONE,
                          true,
                          1};
    _storage_sprite = {0,
                       0,
                       wze::camera::focus(),
                       0,
                       5120,
                       2880,
                       true,
                       assets::shop_storage_texture(),
                       std::numeric_limits<uint8_t>::max(),
                       std::numeric_limits<uint8_t>::max(),
                       std::numeric_limits<uint8_t>::max(),
                       std::numeric_limits<uint8_t>::max(),
                       wze::FLIP_NONE,
                       true,
                       std::numeric_limits<uint8_t>::max()};
    _damage_sprite = {0,
                      0,
                      wze::camera::focus(),
                      0,
                      5120,
                      2880,
                      true,
                      assets::shop_damage_texture(),
                      std::numeric_limits<uint8_t>::max(),
                      std::numeric_limits<uint8_t>::max(),
                      std::numeric_limits<uint8_t>::max(),
                      std::numeric_limits<uint8_t>::max(),
                      wze::FLIP_NONE,
                      true,
                      std::numeric_limits<uint8_t>::max()};
    _hitpoints_sprite = {0,
                         0,
                         wze::camera::focus(),
                         0,
                         5120,
                         2880,
                         true,
                         assets::shop_hitpoints_texture(),
                         std::numeric_limits<uint8_t>::max(),
                         std::numeric_limits<uint8_t>::max(),
                         std::numeric_limits<uint8_t>::max(),
                         std::numeric_limits<uint8_t>::max(),
                         wze::FLIP_NONE,
                         true,
                         std::numeric_limits<uint8_t>::max()};
    _speed_sprite = {0,
                     0,
                     wze::camera::focus(),
                     0,
                     5120,
                     2880,
                     true,
                     assets::shop_speed_texture(),
                     std::numeric_limits<uint8_t>::max(),
                     std::numeric_limits<uint8_t>::max(),
                     std::numeric_limits<uint8_t>::max(),
                     std::numeric_limits<uint8_t>::max(),
                     wze::FLIP_NONE,
                     true,
                     std::numeric_limits<uint8_t>::max()};

    _top_hitbox = {
        {{{-1495, 100}, {-1495, -0}, {1495, -0}, {1495, 100}}, 0, -820},
        0,
        0,
        0};
    _bottom_hitbox = {
        {{{-1495, 0}, {-1495, -100}, {1495, -100}, {1495, 0}}, 0, 1535},
        0,
        0,
        0};
    _left_hitbox = {{
                        {{0, 422.5}, {0, -422.5}, {100, -422.5}, {100, 422.5}},
                        -2250,
                        342.5,
                    },
                    0,
                    0,
                    0};
    _right_hitbox = {
        {{{-100, 422.5}, {-100, -422.5}, {0, -422.5}, {0, 422.5}}, 2250, 342.5},
        0,
        0,
        0};
    _top_left_hitbox = {{{{0, 0}, {640, 0}, {0, 650}}, -2135, -720}, 0, 0, 0};
    _top_right_hitbox = {{{{0, 0}, {-640, 0}, {0, 650}}, 2135, -720}, 0, 0, 0};
    _bottom_left_hitbox = {
        {{{0, 0}, {640, 0}, {0, -650}}, -2135, 1415}, 0, 0, 0};
    _bottom_right_hitbox = {
        {{{0, 0}, {-640, 0}, {0, -650}}, 2135, 1415}, 0, 0, 0};
    _gems_hitbox = {
        {{{-750, 0}, {-690, 60}, {0, 215}, {690, 60}, {750, 0}}, 0, -720},
        0,
        0,
        0};
    _storage_hitbox = {
        {{{-427, 50}, {-322, -50}, {427, -50}, {322, 50}}, -697.5, -37.5},
        0,
        0,
        0};
    _damage_hitbox = {
        {{{-427, 50}, {-322, -50}, {427, -50}, {322, 50}}, 697.5, -37.5},
        0,
        0,
        0};
    _hitpoints_hitbox = {
        {{{-427, 50}, {-322, -50}, {427, -50}, {322, 50}}, -697.5, 785},
        0,
        0,
        0};
    _speed_hitbox = {
        {{{-427, 50}, {-322, -50}, {427, -50}, {322, 50}}, 697.5, 785},
        0,
        0,
        0};

    _door_right = std::shared_ptr<wze::sprite>(new wze::sprite(
        0, 0, wze::camera::focus(), 0, 5120, 2880, true,
        assets::shop_door_animation().back(),
        std::numeric_limits<uint8_t>::max(),
        std::numeric_limits<uint8_t>::max(),
        std::numeric_limits<uint8_t>::max(),
        std::numeric_limits<uint8_t>::max(), wze::FLIP_NONE, true, 0));
    _door_right_light = {0,
                         0,
                         wze::camera::focus(),
                         0,
                         5120,
                         2880,
                         true,
                         assets::shop_door_light_texture(),
                         137,
                         221,
                         70,
                         std::numeric_limits<uint8_t>::max(),
                         wze::FLIP_NONE};
    _door_right_animation = {assets::shop_door_animation(), 100, {_door_right}};
    _door_right_animation.reverse();
    _door_right_animating = false;
    _door_right_open = true;
    _door_right_sound = {assets::door_sound(),
                         std::numeric_limits<int8_t>::max(),
                         1500,
                         true,
                         1815,
                         -397.5};

    _door_left = std::shared_ptr<wze::sprite>(new wze::sprite(
        0, 0, wze::camera::focus(), 0, 5120, 2880, true,
        assets::shop_door_animation().back(),
        std::numeric_limits<uint8_t>::max(),
        std::numeric_limits<uint8_t>::max(),
        std::numeric_limits<uint8_t>::max(),
        std::numeric_limits<uint8_t>::max(), wze::FLIP_HORIZONTAL, true, 0));
    _door_left_light = {0,
                        0,
                        wze::camera::focus(),
                        0,
                        5120,
                        2880,
                        true,
                        assets::shop_door_light_texture(),
                        137,
                        221,
                        70,
                        std::numeric_limits<uint8_t>::max(),
                        wze::FLIP_HORIZONTAL};
    _door_left_animation = {assets::shop_door_animation(), 100, {_door_left}};
    _door_left_animation.reverse();
    _door_left_animating = false;
    _door_left_open = true;
    _door_left_sound = {assets::door_sound(),
                        std::numeric_limits<int8_t>::max(),
                        1500,
                        true,
                        -1815,
                        -397.5};

    _money = {1205, -645, 0, 0, 75, 75, false, assets::stellar_token()};
    _money_count = {0, -645, 0, 0, 0, 70, false, {}};
    _space_station_ambiance_sound = {assets::space_station_ambiance_sound()};
}

shop::~shop() {
    wze::renderer::set_background_color_r(0);
    wze::renderer::set_background_color_g(0);
    wze::renderer::set_background_color_b(0);
    wze::renderer::set_space_color_r(std::numeric_limits<uint8_t>::max());
    wze::renderer::set_space_color_g(std::numeric_limits<uint8_t>::max());
    wze::renderer::set_space_color_b(std::numeric_limits<uint8_t>::max());
}

scene_type shop::update() {
    scene_type door_right;
    scene_type door_left;

    _player.update();
    update_trade();
    if (!_space_station_ambiance_sound.playing()) {
        _space_station_ambiance_sound.play();
    }

    if (_player.y() < -87.5f) {
        _storage_sprite.set_priority(128);
        _damage_sprite.set_priority(128);
    } else {
        _storage_sprite.set_priority(126);
        _damage_sprite.set_priority(126);
    }

    if (_player.y() < 735) {
        _hitpoints_sprite.set_priority(128);
        _speed_sprite.set_priority(128);
    } else {
        _hitpoints_sprite.set_priority(126);
        _speed_sprite.set_priority(126);
    }

    update_money();

    door_right = update_door_right();
    if (_door_right_proxy) {
        return door_right;
    }

    door_left = update_door_left();
    if (_door_left_proxy) {
        return door_left;
    }

    return SCENE_TYPE_SHOP;
}
