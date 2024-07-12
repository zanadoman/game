#include <game/button.hpp>

wze::sprite const& button::appearance() const {
    return _appearance;
}

wze::polygon const& button::hitbox() const {
    return _hitbox;
}

button_state button::state() const {
    return _state;
}

std::shared_ptr<wze::texture> const& button::texture_none() const {
    return _texture_none;
}

void button::set_texture_none(
    std::shared_ptr<wze::texture> const& texture_none) {
    _texture_none = texture_none;
}

std::shared_ptr<wze::texture> const& button::texture_hovered() const {
    return _texture_hovered;
}

void button::set_texture_hovered(
    std::shared_ptr<wze::texture> const& texture_hovered) {
    _texture_hovered = texture_hovered;
}

std::shared_ptr<wze::texture> const& button::texture_onclick() const {
    return _texture_onclick;
}

void button::set_texture_onclick(
    std::shared_ptr<wze::texture> const& texture_onclick) {
    _texture_onclick = texture_onclick;
}

button::button(float x, float y, float angle, float width, float height,
               uint8_t priority,
               std::vector<std::pair<float, float>> const& hitbox,
               std::shared_ptr<wze::texture> const& texture_none,
               std::shared_ptr<wze::texture> const& texture_hovered,
               std::shared_ptr<wze::texture> const& texture_onclick)
    : _appearance(x, y, 0, angle, width, height, false, texture_none,
                  std::numeric_limits<uint8_t>::max(),
                  std::numeric_limits<uint8_t>::max(),
                  std::numeric_limits<uint8_t>::max(),
                  std::numeric_limits<uint8_t>::max(), wze::FLIP_NONE, true,
                  priority),
      _hitbox(hitbox, x, y, angle) {
    _state = BUTTON_STATE_NONE;
    set_texture_none(texture_none);
    set_texture_hovered(texture_hovered);
    set_texture_onclick(texture_onclick);
}

void button::update() {
    float cursor_x;
    float cursor_y;
    uint8_t state;

    if (appearance().spatial() && wze::camera::z() < appearance().z()) {
        std::tie(cursor_x, cursor_y) =
            wze::input::cursor_spatial(appearance().z());
    } else {
        cursor_x = wze::input::cursor_absolute_x();
        cursor_y = wze::input::cursor_absolute_y();
    }

    state = this->state();

    if (hitbox().inside(cursor_x, cursor_y)) {
        state |= BUTTON_STATE_HOVERED;
        if (wze::input::key(wze::KEY_MOUSE_LEFT)) {
            state |= BUTTON_STATE_ONCLICK;
            state &= ~BUTTON_STATE_POSTCLICK;
            _appearance.set_texture(texture_onclick());
        } else if (state & BUTTON_STATE_ONCLICK) {
            state &= ~BUTTON_STATE_ONCLICK;
            state |= BUTTON_STATE_POSTCLICK;
            _appearance.set_texture(texture_onclick());
        } else {
            state &= ~BUTTON_STATE_ONCLICK;
            state &= ~BUTTON_STATE_POSTCLICK;
            _appearance.set_texture(texture_hovered());
        }
    } else {
        state = BUTTON_STATE_NONE;
        _appearance.set_texture(texture_none());
    }

    _state = (button_state)state;
}
