#ifndef GAME_BUTTON_HPP
#define GAME_BUTTON_HPP

#include <wizard_engine/wizard_engine.hpp>

enum button_state {
    BUTTON_STATE_NONE = 0b0000,
    BUTTON_STATE_HOVERED = 0b0001,
    BUTTON_STATE_ONCLICK = 0b0010,
    BUTTON_STATE_POSTCLICK = 0b0100
};

class button final {
  private:
    wze::sprite _appearance;
    wze::sprite _text;
    wze::polygon _hitbox;
    button_state _state;
    bool _enabled;
    std::shared_ptr<wze::texture> _texture_none;
    std::shared_ptr<wze::texture> _texture_hovered;
    std::shared_ptr<wze::texture> _texture_onclick;
    std::shared_ptr<wze::sound> _accept_sound;
    std::shared_ptr<wze::sound> _refuse_sound;
    wze::speaker _speaker;

  public:
    button_state state() const;
    bool enabled() const;
    void set_enabled(bool enabled);

    button(float x, float y, float z, float angle, float width, float height,
           bool spatial, uint8_t priority,
           std::vector<std::pair<float, float>> const& hitbox,
           std::shared_ptr<wze::texture> const& texture_none,
           std::shared_ptr<wze::texture> const& texture_hovered,
           std::shared_ptr<wze::texture> const& texture_onclick,
           std::string const& text, uint8_t text_color_r, uint8_t text_color_g,
           uint8_t text_color_b, std::shared_ptr<wze::sound> accept_sound,
           std::shared_ptr<wze::sound> refuse_sound);
    ~button();

    void update();
};

#endif
