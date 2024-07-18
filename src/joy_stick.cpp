#include <game/assets.hpp>
#include <game/joy_stick.hpp>

float joy_stick::value() const {
    return _value;
}

float joy_stick::direction() const {
    return _direction;
}

joy_stick::joy_stick() {
    _crosshair = {0,  0,  0,     0,
                  36, 36, false, assets::player_ship_crosshair_texture()};
    _value = 0;
    _direction = 0;
}

void joy_stick::update() {
    _crosshair.set_x(_crosshair.x() + wze::input::cursor_relative_x());
    _crosshair.set_y(_crosshair.y() + wze::input::cursor_relative_y());
    _value = wze::math::length(_crosshair.x(), _crosshair.y());
    _direction = wze::math::angle(_crosshair.x(), _crosshair.y());

    if (200 < value()) {
        _value = 200;
        _crosshair.set_x(wze::math::move_x(value(), direction()));
        _crosshair.set_y(wze::math::move_y(value(), direction()));
    }
}
