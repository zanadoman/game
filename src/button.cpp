#include <game/assets.hpp>
#include <game/button.hpp>

button_state button::state() const {
    return _state;
}

bool button::enabled() const {
    return _enabled;
}

void button::set_enabled(bool enabled) {
    _enabled = enabled;
}

button::button(float x, float y, float z, float angle, float width,
               float height, bool spatial, uint8_t priority,
               std::vector<std::pair<float, float>> const& hitbox,
               std::shared_ptr<wze::texture> const& texture_none,
               std::shared_ptr<wze::texture> const& texture_hovered,
               std::shared_ptr<wze::texture> const& texture_onclick,
               std::string const& text, uint8_t text_color_r,
               uint8_t text_color_g, uint8_t text_color_b,
               std::shared_ptr<wze::sound> accept_sound,
               std::shared_ptr<wze::sound> refuse_sound) {
    std::shared_ptr<wze::image> image;

    _appearance = {x,
                   y,
                   z,
                   angle,
                   width,
                   height,
                   spatial,
                   texture_none,
                   std::numeric_limits<uint8_t>::max(),
                   std::numeric_limits<uint8_t>::max(),
                   std::numeric_limits<uint8_t>::max(),
                   std::numeric_limits<uint8_t>::max(),
                   wze::FLIP_NONE,
                   true,
                   priority};

    if (!text.empty()) {
        image = wze::assets::create_image(text, assets::normal_font());
        _text = {
            x,
            y - 0.1f * height,
            z,
            angle,
            (float)image->w / (float)image->h * 0.7f * height,
            0.7f * height,
            spatial,
            wze::assets::create_texture(image),
            text_color_r,
            text_color_g,
            text_color_b,
            std::numeric_limits<uint8_t>::max(),
            wze::FLIP_NONE,
            true,
            (uint8_t)std::min((priority + 1),
                              (int32_t)std::numeric_limits<uint8_t>::max())};
    }

    _hitbox = {hitbox, x, y, angle};
    _state = BUTTON_STATE_NONE;
    set_enabled(true);
    _texture_none = texture_none;
    _texture_hovered = texture_hovered;
    _texture_onclick = texture_onclick;
    _accept_sound = accept_sound;
    _refuse_sound = refuse_sound;
    _speaker = {};
}

button::~button() {
    if (_state & BUTTON_STATE_HOVERED) {
        wze::input::set_cursor_appearance(
            wze::assets::create_cursor(wze::SYSTEM_CURSOR_ARROW));
    }
}

void button::update() {
    uint8_t state;

    state = this->state();

    if (std::apply(
            [this](float x, float y) -> bool { return _hitbox.inside(x, y); },
            _appearance.spatial()
                ? wze::input::cursor_spatial(_appearance.z())
                : std::pair<float, float>(wze::input::cursor_absolute_x(),
                                          wze::input::cursor_absolute_y()))) {
        state |= BUTTON_STATE_HOVERED;
        if (wze::input::key(wze::KEY_MOUSE_LEFT)) {
            state |= BUTTON_STATE_ONCLICK;
            state &= ~BUTTON_STATE_POSTCLICK;
            _appearance.set_texture(_texture_onclick);
        } else if (state & BUTTON_STATE_ONCLICK) {
            state &= ~BUTTON_STATE_ONCLICK;
            state |= BUTTON_STATE_POSTCLICK;
            _appearance.set_texture(_texture_onclick);
            _speaker.set_sound(enabled() ? _accept_sound : _refuse_sound);
            if (_speaker.sound()) {
                _speaker.play();
            }
        } else {
            state &= ~BUTTON_STATE_ONCLICK;
            state &= ~BUTTON_STATE_POSTCLICK;
            _appearance.set_texture(_texture_hovered);
        }
    } else {
        state = BUTTON_STATE_NONE;
        _appearance.set_texture(_texture_none);
    }

    if (~_state & state & BUTTON_STATE_HOVERED) {
        wze::input::set_cursor_appearance(
            wze::assets::create_cursor(wze::SYSTEM_CURSOR_HAND));
    } else if (_state & ~state & BUTTON_STATE_HOVERED) {
        wze::input::set_cursor_appearance(
            wze::assets::create_cursor(wze::SYSTEM_CURSOR_ARROW));
    }

    _state = (button_state)state;
}
