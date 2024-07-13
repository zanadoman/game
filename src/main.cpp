#include <game/space.hpp>
#include <wizard_engine/wizard_engine.hpp>

wze_main(2560, 1440) {
    space space;

    wze_while(true) {
        space.update();
        // printf("%f\n", (double)wze::timer::delta_time());
    };

    return 0;
}
