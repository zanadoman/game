#include <game/assets.hpp>
#include <game/joy_stick.hpp>

float joy_stick::x() const {
    return _crosshair.x();
}

float joy_stick::y() const {
    return _crosshair.y();
}

joy_stick::joy_stick() {
    _crosshair = {0,  0,  0,     0,
                  36, 36, false, assets::player_ship_crosshair_texture()};
}

void joy_stick::update() {
    float value;

    _crosshair.set_x(_crosshair.x() + wze::input::cursor_relative_x());
    _crosshair.set_y(_crosshair.y() + wze::input::cursor_relative_y());

    if (200 < (value = wze::math::length(_crosshair.x(), _crosshair.y()))) {
        _crosshair.set_x(_crosshair.x() / value * 200);
        _crosshair.set_y(_crosshair.y() / value * 200);
    }
}
