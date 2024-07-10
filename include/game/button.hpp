#ifndef GAME_BUTTON_HPP
#define GAME_BUTTON_HPP

#include <game/updateable.hpp>
#include <wizard_engine/wizard_engine.hpp>

/**
 * valid állapotok: 0 - NONE, 1 - HOVERED,
 * 3 - HOVERED & ONCLICK, 5 - HOVERED & POSTCLICK,
 */
enum button_state {
    BUTTON_STATE_NONE = 0b0000'0000,
    BUTTON_STATE_HOVERED = 0b0000'0001,
    BUTTON_STATE_ONCLICK = 0b0000'0010,
    BUTTON_STATE_POSTCLICK = 0b0000'0100
};

class button final : public wze::renderable, public updateable {
  private:
    button_state _state;
    float _x;
    float _y;
    float _width;
    float _height;
    std::shared_ptr<wze::texture> _texture;
    float _minimum_x;
    float _maximum_x;
    float _minimum_y;
    float _maximum_y;

  public:
    button_state state() const;

    float x() const final;
    float y() const final;
    float z() const final;
    float angle() const final;
    float width() const final;
    float height() const final;
    bool spatial() const final;
    std::shared_ptr<wze::texture> const& texture() const final;
    uint8_t color_r() const final;
    uint8_t color_g() const final;
    uint8_t color_b() const final;
    uint8_t color_a() const final;
    wze::flip flip() const final;
    bool visible() const final;
    uint8_t priority() const final;

    button(float x, float y, float width, float height,
           std::shared_ptr<wze::texture> const& texture);

    void update() final;
};

#endif
