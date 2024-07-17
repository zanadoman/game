#include <game/assets.hpp>
#include <game/space.hpp>
#include <iostream>
#include <wizard_engine/wizard_engine.hpp>

wze_main(2560, 1440) {
    assets::initialize();
    space space;

    wze::timer::set_frame_time(50);

    wze_while(true) {
        space.update();
        std::cout << wze::timer::delta_time() << std::endl;
    };

    return 0;
}
