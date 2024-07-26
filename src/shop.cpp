#include <game/assets.hpp>
#include <game/enums.hpp>
#include <game/shop.hpp>
#include <game/trade.hpp>

void shop::update_trade() {
    if (wze::math::length(_player.x() + 675, _player.y() + 152.5f) < 300) {
        if (!_trade) {
            _trade.reset(new trade(-675, -352.5, TRADE_TYPE_ARMOR));
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
            _trade.reset(new trade(-675, 457.5, TRADE_TYPE_ENGINE));
        } else {
            _trade->update();
        }
    } else if (wze::math::length(_player.x() - 675, _player.y() - 657.5f) <
               300) {
        if (!_trade) {
            _trade.reset(new trade(675, 457.5, TRADE_TYPE_STORAGE));

        } else {
            _trade->update();
        }
    } else {
        _trade.reset();
    }
}

scene_type shop::update_door() {
    float distance;

    distance = wze::math::length(_player.x() - 1815, _player.y() + 397.5f);

    if (!_door_animating && (distance <= 500) != _door_open) {
        _door_animating = true;
        _door_sound.play();
        if (!_door_animation.reversed()) {
            _door_light.set_color_r(137);
            _door_light.set_color_g(221);
            _door_light.set_color_b(70);
        } else {
            _door_light.set_color_r(228);
            _door_light.set_color_g(44);
            _door_light.set_color_b(56);
        }
    }

    if (_door_animating && _door_animation.play()) {
        _door->set_texture(_door_animation.frames().back());
        _door_animation.reverse();
        _door_animation.reset();
        _door_open = !_door_open;
        _door_animating = false;
    }

    return _door_open && !_door_animating && distance <= 150 ? SCENE_TYPE_HANGAR
                                                             : SCENE_TYPE_SHOP;
}

shop::shop() {
    wze::renderer::set_background_color_r(18);
    wze::renderer::set_background_color_g(18);
    wze::renderer::set_background_color_b(38);

    _background = {0,
                   0,
                   wze::camera::focus(),
                   0,
                   5120,
                   2880,
                   true,
                   assets::shop_background_texture()};

    _top = {{{{-1495, 100}, {-1495, -0}, {1495, -0}, {1495, 100}}, 0, -820},
            0,
            0,
            0};
    _bottom = {{{{-1495, 0}, {-1495, -100}, {1495, -100}, {1495, 0}}, 0, 1535},
               0,
               0,
               0};
    _left = {{
                 {{0, 422.5}, {0, -422.5}, {100, -422.5}, {100, 422.5}},
                 -2250,
                 342.5,
             },
             0,
             0,
             0};
    _right = {
        {{{-100, 422.5}, {-100, -422.5}, {0, -422.5}, {0, 422.5}}, 2250, 342.5},
        0,
        0,
        0};
    _top_left = {{{{0, 0}, {640, 0}, {0, 650}}, -2135, -720}, 0, 0, 0};
    _top_right = {{{{0, 0}, {-640, 0}, {0, 650}}, 2135, -720}, 0, 0, 0};
    _bottom_left = {{{{0, 0}, {640, 0}, {0, -650}}, -2135, 1415}, 0, 0, 0};
    _bottom_right = {{{{0, 0}, {-640, 0}, {0, -650}}, 2135, 1415}, 0, 0, 0};

    _door = std::shared_ptr<wze::sprite>(new wze::sprite(
        0, 0, wze::camera::focus(), 0, 5120, 2880, true,
        assets::shop_door_animation().front(),
        std::numeric_limits<uint8_t>::max(),
        std::numeric_limits<uint8_t>::max(),
        std::numeric_limits<uint8_t>::max(),
        std::numeric_limits<uint8_t>::max(), wze::FLIP_NONE, true, 0));
    _door_light = {0,
                   0,
                   wze::camera::focus(),
                   0,
                   5120,
                   2880,
                   true,
                   assets::shop_door_light_texture(),
                   228,
                   44,
                   56};
    _door_animation = {assets::shop_door_animation(), 100, {_door}};
    _door_animating = false;
    _door_open = false;

    _door_sound = {assets::shop_door_open_sound()};
}

shop::~shop() {
    wze::renderer::set_background_color_r(0);
    wze::renderer::set_background_color_g(0);
    wze::renderer::set_background_color_b(0);
}

scene_type shop::update() {
    _player.update();
    update_trade();
    return update_door();
}
