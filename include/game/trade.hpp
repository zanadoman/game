#ifndef GAME_TRADE_HPP
#define GAME_TRADE_HPP

#include <wizard_engine/wizard_engine.hpp>
#include <game/enums.hpp>
#include <game/button.hpp>
#include <functional>

class trade final {
  private:
    trade_type _trade_type;
    wze::sprite _background;
    std::function<uint8_t()> _level;
    std::function<void (uint8_t)> _set_level;
    wze::sprite _level1;
    wze::sprite _level2;
    wze::sprite _level3;
    button _button;

  public:
    trade(float x, float y, trade_type trade_type);
    void update();
};

#endif
