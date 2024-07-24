#include <game/assets.hpp>
#include <game/shop.hpp>

void shop::update_door() {
    bool open;

    open = wze::math::length(_player.x() - 1815, _player.y() + 397.5f) <= 500;

    if ((_door->texture() != _door_animation.frames().front() ||
         (open && !_door_open)) &&
        _door_animation.play()) {
        _door->set_texture(_door_animation.frames().back());
        _door_animation.reverse();
        _door_animation.reset();
        _door_open = true;
    } else if ((_door->texture() != _door_animation.frames().front() ||
                (!open && _door_open)) &&
               _door_animation.play()) {
        _door->set_texture(_door_animation.frames().back());
        _door_animation.reverse();
        _door_animation.reset();
        _door_open = false;
    }
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
    _door_animation = {assets::shop_door_animation(), 100, {_door}};
    _door_open = false;
}

shop::~shop() {
    wze::renderer::set_background_color_r(0);
    wze::renderer::set_background_color_g(0);
    wze::renderer::set_background_color_b(0);
}

void shop::update() {
    _player.update();
    update_door();
}
