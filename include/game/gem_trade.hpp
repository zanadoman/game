#ifndef GAME_GEM_TRADE_HPP
#define GAME_GEM_TRADE_HPP

#include <game/button.hpp>
#include <game/enums.hpp>
#include <wizard_engine/wizard_engine.hpp>

class gem_trade final {
  private:
    wze::sprite _background;

    wze::sprite _pyrite_count;
    wze::sprite _wolframite_count;
    wze::sprite _carneol_count;
    wze::sprite _moldavite_count;
    wze::sprite _ruby_count;
    wze::sprite _sapphire_count;

    button _pyrite_decrease;
    button _pyrite_increase;
    button _wolframite_decrease;
    button _wolframite_increase;
    button _carneol_decrease;
    button _carneol_increase;
    button _moldavite_decrease;
    button _moldavite_increase;
    button _ruby_decrease;
    button _ruby_increase;
    button _sapphire_decrease;
    button _sapphire_increase;

    uint8_t _pyrite_sell_count;
    uint8_t _wolframite_sell_count;
    uint8_t _carneol_sell_count;
    uint8_t _moldavite_sell_count;
    uint8_t _ruby_sell_count;
    uint8_t _sapphire_sell_count;

    wze::sprite _pyrite_sell;
    wze::sprite _wolframite_sell;
    wze::sprite _carneol_sell;
    wze::sprite _moldavite_sell;
    wze::sprite _ruby_sell;
    wze::sprite _sapphire_sell;

    wze::sprite _pyrite_price;
    wze::sprite _wolframite_price;
    wze::sprite _carneol_price;
    wze::sprite _moldavite_price;
    wze::sprite _ruby_price;
    wze::sprite _sapphire_price;

    std::vector<std::tuple<material, wze::sprite, wze::sprite>> _items;
    void
    add_item(material material,
             std::function<std::shared_ptr<wze::texture> const&()> texture);
    void
    update_item(std::vector<std::tuple<material, wze::sprite,
                                       wze::sprite>>::iterator const& iterator,
                uint8_t count, uint16_t price);

    wze::sprite _summary;

    button _sell;

  public:
    gem_trade();
    void update();
};

#endif
