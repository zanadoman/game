#include <game/laser.hpp>
#include <wizard_engine/wizard_engine.hpp>

wze_main(2560, 1440) {
    std::vector<laser> lasers;
    uint64_t last_time;

    wze::timer::set_frame_time(10);
    last_time = 0;

    wze_while(true) {
        if (wze::input::key(wze::KEY_MOUSE_LEFT) &&
            last_time + 200 < wze::timer::current_time()) {
            std::apply(
                [&lasers](float x, float y) -> void {
                    lasers.push_back({x, y, wze::camera::z()});
                },
                wze::input::cursor_spatial(wze::camera::z() +
                                           wze::camera::focus()));
            last_time = wze::timer::current_time();
        }

        for (laser& laser : lasers) {
            laser.update();
        }
    };

    return 0;
}
