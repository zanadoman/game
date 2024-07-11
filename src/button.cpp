#include <game/button.hpp>

button_state button::state() const {
    return _state;
}

float button::x() const {
    return _x;
}

float button::y() const {
    return _y;
}

float button::z() const {
    return 0;
}

float button::angle() const {
    return 0;
}

float button::width() const {
    return _width;
}

float button::height() const {
    return _height;
}

bool button::spatial() const {
    return false;
}

std::shared_ptr<wze::texture> const& button::texture() const {
    return _texture;
}

uint8_t button::color_r() const {
    return std::numeric_limits<uint8_t>::max();
}

uint8_t button::color_g() const {
    return std::numeric_limits<uint8_t>::max();
}

uint8_t button::color_b() const {
    return std::numeric_limits<uint8_t>::max();
}

uint8_t button::color_a() const {
    return std::numeric_limits<uint8_t>::max();
}

wze::flip button::flip() const {
    return wze::FLIP_NONE;
}

bool button::visible() const {
    return true;
}

uint8_t button::priority() const {
    return std::numeric_limits<uint8_t>::max() / 2;
}

button::button(float x, float y, float width, float height,
               std::shared_ptr<wze::texture> const& texture) {
    _state = BUTTON_STATE_NONE;
    _x = x;
    _y = y;
    _width = width;
    _height = height;
    _texture = texture;

    /* sarkok kiszámítása */
    _minimum_x = _x - _width / 2;
    _maximum_x = _x + _width / 2;
    _minimum_y = _y - _height / 2;
    _maximum_y = _y + _height / 2;
}

void button::update() {
    uint8_t state;

    /**
     * valid állapotok: 0 - NONE, 1 - HOVERED,
     * 3 - HOVERED & ONCLICK, 5 - HOVERED & POSTCLICK
     */

    state = _state; /* uint8_t alias bitműveletek miatt */
    if (_minimum_x <= wze::input::cursor_absolute_x() &&
        wze::input::cursor_absolute_x() <= _maximum_x &&
        _minimum_y <= wze::input::cursor_absolute_y() &&
        wze::input::cursor_absolute_y() <= _maximum_y) { /* rajta van az egér */
        state |= BUTTON_STATE_HOVERED;
        if (wze::input::key(wze::KEY_MOUSE_LEFT)) { /* kattintva van - 3 */
            state |= BUTTON_STATE_ONCLICK;
            state &= ~BUTTON_STATE_POSTCLICK;
        } else if (state & BUTTON_STATE_ONCLICK) { /* kattintva volt - 5 */
            state &= ~BUTTON_STATE_ONCLICK;
            state |= BUTTON_STATE_POSTCLICK;
        } else { /* nincs kattintva és nem volt kattintva - 1*/
            state &= ~BUTTON_STATE_ONCLICK;
            state &= ~BUTTON_STATE_POSTCLICK;
        }
    } else {
        state = BUTTON_STATE_NONE; /* nincs rajta az egér - 0*/
    }

    _state = (button_state)state;
}
