#include <game/assets.hpp>
#include <game/shop.hpp>

shop::shop() {
    _background = {0,    0,    wze::camera::focus(),     0, 5120,
                   2880, true, assets::shop_background()};
}

void shop::update() {
    _player.update();
}
