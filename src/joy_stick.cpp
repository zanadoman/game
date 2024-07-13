#include <game/joy_stick.hpp>

float joy_stick::value() const {
    return _value;
}

float joy_stick::direction() const {
    return _direction;
}

joy_stick::joy_stick() {
    _value = 0;
    _direction = 0;
}

void joy_stick::update() {
    _value = wze::math::length(wze::input::cursor_absolute_x(),
                               wze::input::cursor_absolute_y());
    _direction = wze::math::angle(wze::input::cursor_absolute_x(),
                                  wze::input::cursor_absolute_y());

    if (_value < _dead_zone) {
        _value = 0;
    } else if (_edge_zone < _value) {
        _value = _edge_zone;
    }
}
