#include <game/assets.hpp>
#include <game/save_data.hpp>
#include <game/space.hpp>
#include <iostream>
#include <wizard_engine/wizard_engine.hpp>
#include <game/shop.hpp>

wze_main(2560, 1440) {
    assets::initialize();
    save_data::load();

    shop shop;
    // space space;

    // wze::timer::set_frame_time(50);
    wze::audio::set_volume(std::numeric_limits<int8_t>::max() / 2);

    wze_while(true) {
        shop.update();
        // space.update();
        std::cout << wze::timer::delta_time() << std::endl;
    };

    save_data::save();

    return 0;
}
