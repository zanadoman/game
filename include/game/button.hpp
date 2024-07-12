#ifndef GAME_BUTTON_HPP
#define GAME_BUTTON_HPP

#include <game/updateable.hpp>
#include <wizard_engine/wizard_engine.hpp>

enum button_state {
    BUTTON_STATE_NONE = 0b0000,
    BUTTON_STATE_HOVERED = 0b0001,
    BUTTON_STATE_ONCLICK = 0b0010,
    BUTTON_STATE_POSTCLICK = 0b0100
};

class button final : public updateable {
  private:
    wze::sprite _appearance;
    wze::polygon _hitbox;
    button_state _state;
    std::shared_ptr<wze::texture> _texture_none;
    std::shared_ptr<wze::texture> _texture_hovered;
    std::shared_ptr<wze::texture> _texture_onclick;

  public:
    wze::sprite const& appearance() const;

    wze::polygon const& hitbox() const;

    button_state state() const;

    std::shared_ptr<wze::texture> const& texture_none() const;
    void set_texture_none(std::shared_ptr<wze::texture> const& texture_none);

    std::shared_ptr<wze::texture> const& texture_hovered() const;
    void
    set_texture_hovered(std::shared_ptr<wze::texture> const& texture_hovered);

    std::shared_ptr<wze::texture> const& texture_onclick() const;
    void
    set_texture_onclick(std::shared_ptr<wze::texture> const& texture_onclick);

    button(float x, float y, float angle, float width, float height,
           uint8_t priority, std::vector<std::pair<float, float>> const& hitbox,
           std::shared_ptr<wze::texture> const& texture_none,
           std::shared_ptr<wze::texture> const& texture_hovered,
           std::shared_ptr<wze::texture> const& texture_onclick);

    void update() final;
};

#endif
