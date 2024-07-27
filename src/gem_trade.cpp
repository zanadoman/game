#include <game/assets.hpp>
#include <game/gem_trade.hpp>
#include <game/save_data.hpp>
#include <string>

#define Z (wze::camera::focus() * 0.95f)

gem_trade::gem_trade()
    : _pyrite_decrease(-566.5, -595 - 60, Z, 0, 30, 35, true,
                       std::numeric_limits<uint8_t>::max(),
                       {{-15, 15}, {-15, -15}, {15, -15}, {15, 15}},
                       assets::placeholder_texture(),
                       assets::placeholder_texture(),
                       assets::placeholder_texture(), "", 0, 0, 0),
      _pyrite_increase(-382.5, -595 - 60, Z, 0, 30, 35, true,
                       std::numeric_limits<uint8_t>::max(),
                       {{-15, 15}, {-15, -15}, {15, -15}, {15, 15}},
                       assets::placeholder_texture(),
                       assets::placeholder_texture(),
                       assets::placeholder_texture(), "", 0, 0, 0),
      _wolframite_decrease(-272.5, -595 - 60, Z, 0, 30, 35, true,
                           std::numeric_limits<uint8_t>::max(),
                           {{-15, 15}, {-15, -15}, {15, -15}, {15, 15}},
                           assets::placeholder_texture(),
                           assets::placeholder_texture(),
                           assets::placeholder_texture(), "", 0, 0, 0),
      _wolframite_increase(-87.5, -595 - 60, Z, 0, 30, 35, true,
                           std::numeric_limits<uint8_t>::max(),
                           {{-15, 15}, {-15, -15}, {15, -15}, {15, 15}},
                           assets::placeholder_texture(),
                           assets::placeholder_texture(),
                           assets::placeholder_texture(), "", 0, 0, 0),
      _carneol_decrease(22.5, -595 - 60, Z, 0, 30, 35, true,
                        std::numeric_limits<uint8_t>::max(),
                        {{-15, 15}, {-15, -15}, {15, -15}, {15, 15}},
                        assets::placeholder_texture(),
                        assets::placeholder_texture(),
                        assets::placeholder_texture(), "", 0, 0, 0),
      _carneol_increase(207.5, -595 - 60, Z, 0, 30, 35, true,
                        std::numeric_limits<uint8_t>::max(),
                        {{-15, 15}, {-15, -15}, {15, -15}, {15, 15}},
                        assets::placeholder_texture(),
                        assets::placeholder_texture(),
                        assets::placeholder_texture(), "", 0, 0, 0),
      _moldavite_decrease(-566.5, -595 + 375, Z, 0, 30, 35, true,
                          std::numeric_limits<uint8_t>::max(),
                          {{-15, 15}, {-15, -15}, {15, -15}, {15, 15}},
                          assets::placeholder_texture(),
                          assets::placeholder_texture(),
                          assets::placeholder_texture(), "", 0, 0, 0),
      _moldavite_increase(-382.5, -595 + 375, Z, 0, 30, 35, true,
                          std::numeric_limits<uint8_t>::max(),
                          {{-15, 15}, {-15, -15}, {15, -15}, {15, 15}},
                          assets::placeholder_texture(),
                          assets::placeholder_texture(),
                          assets::placeholder_texture(), "", 0, 0, 0),
      _ruby_decrease(-272.5, -595 + 375, Z, 0, 30, 35, true,
                     std::numeric_limits<uint8_t>::max(),
                     {{-15, 15}, {-15, -15}, {15, -15}, {15, 15}},
                     assets::placeholder_texture(),
                     assets::placeholder_texture(),
                     assets::placeholder_texture(), "", 0, 0, 0),
      _ruby_increase(-87.5, -595 + 375, Z, 0, 30, 35, true,
                     std::numeric_limits<uint8_t>::max(),
                     {{-15, 15}, {-15, -15}, {15, -15}, {15, 15}},
                     assets::placeholder_texture(),
                     assets::placeholder_texture(),
                     assets::placeholder_texture(), "", 0, 0, 0),
      _sapphire_decrease(22.5, -595 + 375, Z, 0, 30, 35, true,
                         std::numeric_limits<uint8_t>::max(),
                         {{-15, 15}, {-15, -15}, {15, -15}, {15, 15}},
                         assets::placeholder_texture(),
                         assets::placeholder_texture(),
                         assets::placeholder_texture(), "", 0, 0, 0),
      _sapphire_increase(207.5, -595 + 375, Z, 0, 30, 35, true,
                         std::numeric_limits<uint8_t>::max(),
                         {{-15, 15}, {-15, -15}, {15, -15}, {15, 15}},
                         assets::placeholder_texture(),
                         assets::placeholder_texture(),
                         assets::placeholder_texture(), "", 0, 0, 0) {
    std::shared_ptr<wze::image> image;

    _background = {0,    -595, Z,    0,
                   1395, 1005, true, assets::gem_trade_background_texture()};

    _pyrite_count = {
        _background.x() - 412.5f, _background.y() - 370, Z, 0, 0, 30, true};
    _wolframite_count = {
        _background.x() - 117.5f, _background.y() - 370, Z, 0, 0, 30, true};
    _carneol_count = {
        _background.x() + 177.5f, _background.y() - 370, Z, 0, 0, 30, true};
    _moldavite_count = {
        _background.x() - 412.5f, _background.y() + 65, Z, 0, 0, 30, true};
    _ruby_count = {
        _background.x() - 117.5f, _background.y() + 65, Z, 0, 0, 30, true};
    _sapphire_count = {
        _background.x() + 177.5f, _background.y() + 65, Z, 0, 0, 30, true};

    _pyrite_sell_count = 0;
    _wolframite_sell_count = 0;
    _carneol_sell_count = 0;
    _moldavite_sell_count = 0;
    _ruby_sell_count = 0;
    _sapphire_sell_count = 0;

    _pyrite_sell = {
        _background.x() - 474.5f, _background.y() - 62.5f, Z, 0, 0, 35, true};
    _wolframite_sell = {
        _background.x() - 180, _background.y() - 62.5f, Z, 0, 0, 35, true};
    _carneol_sell = {
        _background.x() + 115, _background.y() - 62.5f, Z, 0, 0, 35, true};
    _moldavite_sell = {
        _background.x() - 474.5f, _background.y() + 372.5f, Z, 0, 0, 35, true};
    _ruby_sell = {
        _background.x() - 180, _background.y() + 372.5f, Z, 0, 0, 35, true};
    _sapphire_sell = {
        _background.x() + 115, _background.y() + 372.5f, Z, 0, 0, 35, true};

    image = wze::assets::create_image(std::to_string(50) + " ST",
                                      assets::bold_font());
    _pyrite_price = {_background.x() - 474.5f,
                     _background.y() - 135,
                     Z,
                     0,
                     (float)image->w / (float)image->h * 45,
                     45,
                     true,
                     wze::assets::create_texture(image)};
    image = wze::assets::create_image(std::to_string(100) + " ST",
                                      assets::bold_font());
    _wolframite_price = {_background.x() - 180,
                         _background.y() - 135,
                         Z,
                         0,
                         (float)image->w / (float)image->h * 45,
                         45,
                         true,
                         wze::assets::create_texture(image)};
    image = wze::assets::create_image(std::to_string(150) + " ST",
                                      assets::bold_font());
    _carneol_price = {_background.x() + 115,
                      _background.y() - 135,
                      Z,
                      0,
                      (float)image->w / (float)image->h * 45,
                      45,
                      true,
                      wze::assets::create_texture(image)};
    image = wze::assets::create_image(std::to_string(250) + " ST",
                                      assets::bold_font());
    _moldavite_price = {_background.x() - 474.5f,
                        _background.y() + 300,
                        Z,
                        0,
                        (float)image->w / (float)image->h * 45,
                        45,
                        true,
                        wze::assets::create_texture(image)};
    image = wze::assets::create_image(std::to_string(400) + " ST",
                                      assets::bold_font());
    _ruby_price = {_background.x() - 180,
                   _background.y() + 300,
                   Z,
                   0,
                   (float)image->w / (float)image->h * 45,
                   45,
                   true,
                   wze::assets::create_texture(image)};
    image = wze::assets::create_image(std::to_string(650) + " ST",
                                      assets::bold_font());
    _sapphire_price = {_background.x() + 115,
                       _background.y() + 300,
                       Z,
                       0,
                       (float)image->w / (float)image->h * 45,
                       45,
                       true,
                       wze::assets::create_texture(image)};
}

void gem_trade::update() {
    std::shared_ptr<wze::image> image;
    std::vector<std::tuple<material, wze::sprite, wze::sprite>>::iterator
        iterator;
    size_t i;

    image = wze::assets::create_image(std::to_string(save_data::pyrite_count()),
                                      assets::bold_font());
    _pyrite_count.set_width((float)image->w / (float)image->h * 30);
    _pyrite_count.set_texture(wze::assets::create_texture(image));
    image = wze::assets::create_image(
        std::to_string(save_data::wolframite_count()), assets::bold_font());
    _wolframite_count.set_width((float)image->w / (float)image->h * 30);
    _wolframite_count.set_texture(wze::assets::create_texture(image));
    image = wze::assets::create_image(
        std::to_string(save_data::carneol_count()), assets::bold_font());
    _carneol_count.set_width((float)image->w / (float)image->h * 30);
    _carneol_count.set_texture(wze::assets::create_texture(image));
    image = wze::assets::create_image(
        std::to_string(save_data::moldavite_count()), assets::bold_font());
    _moldavite_count.set_width((float)image->w / (float)image->h * 30);
    _moldavite_count.set_texture(wze::assets::create_texture(image));
    image = wze::assets::create_image(std::to_string(save_data::ruby_count()),
                                      assets::bold_font());
    _ruby_count.set_width((float)image->w / (float)image->h * 30);
    _ruby_count.set_texture(wze::assets::create_texture(image));
    image = wze::assets::create_image(
        std::to_string(save_data::sapphire_count()), assets::bold_font());
    _sapphire_count.set_width((float)image->w / (float)image->h * 30);
    _sapphire_count.set_texture(wze::assets::create_texture(image));

    _pyrite_decrease.update();
    if (_pyrite_decrease.state() & BUTTON_STATE_POSTCLICK &&
        _pyrite_sell_count) {
        if (9 < _pyrite_sell_count) {
            _pyrite_sell_count -= 10;

        } else {
            _pyrite_sell_count = 0;
        }
    }
    _pyrite_increase.update();
    if (_pyrite_increase.state() & BUTTON_STATE_POSTCLICK &&
        _pyrite_sell_count < save_data::pyrite_count()) {
        if (_pyrite_sell_count < save_data::pyrite_count() - 9) {
            _pyrite_sell_count += 10;
        } else {
            _pyrite_sell_count = save_data::pyrite_count();
        }
    }
    _wolframite_decrease.update();
    if (_wolframite_decrease.state() & BUTTON_STATE_POSTCLICK &&
        _wolframite_sell_count) {
        if (9 < _wolframite_sell_count) {
            _wolframite_sell_count -= 10;
        } else {
            _wolframite_sell_count = 0;
        }
    }
    _wolframite_increase.update();
    if (_wolframite_increase.state() & BUTTON_STATE_POSTCLICK &&
        _wolframite_sell_count < save_data::wolframite_count()) {
        if (_wolframite_sell_count < save_data::wolframite_count() - 9) {
            _wolframite_sell_count += 10;
        } else {
            _wolframite_sell_count = save_data::wolframite_count();
        }
    }
    _carneol_decrease.update();
    if (_carneol_decrease.state() & BUTTON_STATE_POSTCLICK &&
        _carneol_sell_count) {
        if (9 < _carneol_sell_count) {
            _carneol_sell_count -= 10;
        } else {
            _carneol_sell_count = 0;
        }
    }
    _carneol_increase.update();
    if (_carneol_increase.state() & BUTTON_STATE_POSTCLICK &&
        _carneol_sell_count < save_data::carneol_count()) {
        if (_carneol_sell_count < save_data::carneol_count() - 9) {
            _carneol_sell_count += 10;
        } else {
            _carneol_sell_count = save_data::carneol_count();
        }
    }
    _moldavite_decrease.update();
    if (_moldavite_decrease.state() & BUTTON_STATE_POSTCLICK &&
        _moldavite_sell_count) {
        if (9 < _moldavite_sell_count) {
            _moldavite_sell_count -= 10;
        } else {
            _moldavite_sell_count = 0;
        }
    }
    _moldavite_increase.update();
    if (_moldavite_increase.state() & BUTTON_STATE_POSTCLICK &&
        _moldavite_sell_count < save_data::moldavite_count()) {
        if (_moldavite_sell_count < save_data::moldavite_count() - 9) {
            _moldavite_sell_count += 10;
        } else {
            _moldavite_sell_count = save_data::moldavite_count();
        }
    }
    _ruby_decrease.update();
    if (_ruby_decrease.state() & BUTTON_STATE_POSTCLICK && _ruby_sell_count) {
        if (9 < _ruby_sell_count) {
            _ruby_sell_count -= 10;
        } else {
            _ruby_sell_count = 0;
        }
    }
    _ruby_increase.update();
    if (_ruby_increase.state() & BUTTON_STATE_POSTCLICK &&
        _ruby_sell_count < save_data::ruby_count()) {
        if (_ruby_sell_count < save_data::ruby_count() - 9) {
            _ruby_sell_count += 10;
        } else {
            _ruby_sell_count = save_data::ruby_count();
        }
    }
    _sapphire_decrease.update();
    if (_sapphire_decrease.state() & BUTTON_STATE_POSTCLICK &&
        _sapphire_sell_count) {
        if (9 < _sapphire_sell_count) {
            _sapphire_sell_count -= 10;
        } else {
            _sapphire_sell_count = 0;
        }
    }
    _sapphire_increase.update();
    if (_sapphire_increase.state() & BUTTON_STATE_POSTCLICK &&
        _sapphire_sell_count < save_data::sapphire_count()) {
        if (_sapphire_sell_count < save_data::sapphire_count() - 9) {
            _sapphire_sell_count += 10;
        } else {
            _sapphire_sell_count = save_data::sapphire_count();
        }
    }

    iterator = std::ranges::find_if(
        _items,
        [](std::tuple<material, wze::sprite, wze::sprite> const& item) -> bool {
            return std::get<0>(item) == MATERIAL_PYRITE;
        });
    if (_pyrite_sell_count) {
        if (iterator == _items.end()) {
            _items.push_back({MATERIAL_PYRITE,
                              {_background.x() + 507.5f, 0, Z, 0, 40, 40, true,
                               assets::asteroids_pyrite_gem_ui_texture()},
                              {_background.x() + 507.5f,
                               0,
                               Z,
                               0,
                               0,
                               40,
                               true,
                               {},
                               0,
                               0,
                               0}});
            iterator = _items.end() - 1;
        }
        image = wze::assets::create_image(
            " x 40 = " + std::to_string(_pyrite_sell_count * 50),
            assets::normal_font());
        std::get<2>(*iterator).set_width((float)image->w / (float)image->h *
                                         40);
        std::get<2>(*iterator).set_texture(wze::assets::create_texture(image));
    } else if (iterator != _items.end()) {
        _items.erase(iterator);
    }

    iterator = std::ranges::find_if(
        _items,
        [](std::tuple<material, wze::sprite, wze::sprite> const& item) -> bool {
            return std::get<0>(item) == MATERIAL_WOLFRAMITE;
        });
    if (_wolframite_sell_count) {
        if (iterator == _items.end()) {
            _items.push_back({MATERIAL_WOLFRAMITE,
                              {_background.x() + 507.5f, 0, Z, 0, 40, 40, true,
                               assets::asteroids_wolframite_gem_ui_texture()},
                              {_background.x() + 507.5f,
                               0,
                               Z,
                               0,
                               0,
                               40,
                               true,
                               {},
                               0,
                               0,
                               0}});
            iterator = _items.end() - 1;
        }
        image = wze::assets::create_image(
            " x 100 = " + std::to_string(_wolframite_sell_count * 100),
            assets::normal_font());
        std::get<2>(*iterator).set_width((float)image->w / (float)image->h *
                                         40);
        std::get<2>(*iterator).set_texture(wze::assets::create_texture(image));
    } else if (iterator != _items.end()) {
        _items.erase(iterator);
    }

    iterator = std::ranges::find_if(
        _items,
        [](std::tuple<material, wze::sprite, wze::sprite> const& item) -> bool {
            return std::get<0>(item) == MATERIAL_CARNEOL;
        });
    if (_carneol_sell_count) {
        if (iterator == _items.end()) {
            _items.push_back({MATERIAL_CARNEOL,
                              {_background.x() + 507.5f, 0, Z, 0, 40, 40, true,
                               assets::asteroids_carneol_gem_ui_texture()},
                              {_background.x() + 507.5f,
                               0,
                               Z,
                               0,
                               0,
                               40,
                               true,
                               {},
                               0,
                               0,
                               0}});
            iterator = _items.end() - 1;
        }
        image = wze::assets::create_image(
            " x 150 = " + std::to_string(_carneol_sell_count * 150),
            assets::normal_font());
        std::get<2>(*iterator).set_width((float)image->w / (float)image->h *
                                         40);
        std::get<2>(*iterator).set_texture(wze::assets::create_texture(image));
    } else if (iterator != _items.end()) {
        _items.erase(iterator);
    }

    iterator = std::ranges::find_if(
        _items,
        [](std::tuple<material, wze::sprite, wze::sprite> const& item) -> bool {
            return std::get<0>(item) == MATERIAL_MOLDAVITE;
        });
    if (_moldavite_sell_count) {
        if (iterator == _items.end()) {
            _items.push_back({MATERIAL_MOLDAVITE,
                              {_background.x() + 507.5f, 0, Z, 0, 40, 40, true,
                               assets::asteroids_moldavite_gem_ui_texture()},
                              {_background.x() + 507.5f,
                               0,
                               Z,
                               0,
                               0,
                               40,
                               true,
                               {},
                               0,
                               0,
                               0}});
            iterator = _items.end() - 1;
        }
        image = wze::assets::create_image(
            " x 250 = " + std::to_string(_moldavite_sell_count * 250),
            assets::normal_font());
        std::get<2>(*iterator).set_width((float)image->w / (float)image->h *
                                         40);
        std::get<2>(*iterator).set_texture(wze::assets::create_texture(image));
    } else if (iterator != _items.end()) {
        _items.erase(iterator);
    }

    iterator = std::ranges::find_if(
        _items,
        [](std::tuple<material, wze::sprite, wze::sprite> const& item) -> bool {
            return std::get<0>(item) == MATERIAL_RUBY;
        });
    if (_ruby_sell_count) {
        if (iterator == _items.end()) {
            _items.push_back({MATERIAL_RUBY,
                              {_background.x() + 507.5f, 0, Z, 0, 40, 40, true,
                               assets::asteroids_ruby_gem_ui_texture()},
                              {_background.x() + 507.5f,
                               0,
                               Z,
                               0,
                               0,
                               40,
                               true,
                               {},
                               0,
                               0,
                               0}});
            iterator = _items.end() - 1;
        }
        image = wze::assets::create_image(
            " x 400 = " + std::to_string(_ruby_sell_count * 400),
            assets::normal_font());
        std::get<2>(*iterator).set_width((float)image->w / (float)image->h *
                                         40);
        std::get<2>(*iterator).set_texture(wze::assets::create_texture(image));
    } else if (iterator != _items.end()) {
        _items.erase(iterator);
    }

    iterator = std::ranges::find_if(
        _items,
        [](std::tuple<material, wze::sprite, wze::sprite> const& item) -> bool {
            return std::get<0>(item) == MATERIAL_SAPPHIRE;
        });
    if (_sapphire_sell_count) {
        if (iterator == _items.end()) {
            _items.push_back({MATERIAL_SAPPHIRE,
                              {_background.x() + 507.5f, 0, Z, 0, 40, 40, true,
                               assets::asteroids_sapphire_gem_ui_texture()},
                              {_background.x() + 507.5f,
                               0,
                               Z,
                               0,
                               0,
                               40,
                               true,
                               {},
                               0,
                               0,
                               0}});
            iterator = _items.end() - 1;
        }
        image = wze::assets::create_image(
            " x 650 = " + std::to_string(_sapphire_sell_count * 650),
            assets::normal_font());
        std::get<2>(*iterator).set_width((float)image->w / (float)image->h *
                                         40);
        std::get<2>(*iterator).set_texture(wze::assets::create_texture(image));
    } else if (iterator != _items.end()) {
        _items.erase(iterator);
    }

    for (i = 0; i != _items.size(); ++i) {
        std::get<1>(_items.at(i)).set_y(_background.y() - 350 + i * 50);
        std::get<2>(_items.at(i)).set_y(std::get<1>(_items.at(i)).y());
    }

    image = wze::assets::create_image(std::to_string(_pyrite_sell_count),
                                      assets::bold_font());
    _pyrite_sell.set_width((float)image->w / (float)image->h * 30);
    _pyrite_sell.set_texture(wze::assets::create_texture(image));
    image = wze::assets::create_image(std::to_string(_wolframite_sell_count),
                                      assets::bold_font());
    _wolframite_sell.set_width((float)image->w / (float)image->h * 30);
    _wolframite_sell.set_texture(wze::assets::create_texture(image));
    image = wze::assets::create_image(std::to_string(_carneol_sell_count),
                                      assets::bold_font());
    _carneol_sell.set_width((float)image->w / (float)image->h * 30);
    _carneol_sell.set_texture(wze::assets::create_texture(image));
    image = wze::assets::create_image(std::to_string(_moldavite_sell_count),
                                      assets::bold_font());
    _moldavite_sell.set_width((float)image->w / (float)image->h * 30);
    _moldavite_sell.set_texture(wze::assets::create_texture(image));
    image = wze::assets::create_image(std::to_string(_ruby_sell_count),
                                      assets::bold_font());
    _ruby_sell.set_width((float)image->w / (float)image->h * 30);
    _ruby_sell.set_texture(wze::assets::create_texture(image));
    image = wze::assets::create_image(std::to_string(_sapphire_sell_count),
                                      assets::bold_font());
    _sapphire_sell.set_width((float)image->w / (float)image->h * 30);
    _sapphire_sell.set_texture(wze::assets::create_texture(image));
}
