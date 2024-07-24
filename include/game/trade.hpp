#ifndef GAME_TRADE_HPP
#define GAME_TRADE_HPP

#include <functional>
#include <game/button.hpp>
#include <game/enums.hpp>
#include <wizard_engine/wizard_engine.hpp>

class trade final {
  private:
    trade_type _trade_type;
    uint16_t _price;
    wze::sprite _background;
    std::function<uint8_t()> _level;
    std::function<void(uint8_t)> _set_level;
    wze::sprite _level1;
    wze::sprite _level2;
    wze::sprite _level3;
    button _button;

  public:
    trade(float x, float y, trade_type trade_type);
    void update();
};

#endif
