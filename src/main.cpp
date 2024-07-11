#include <game/assets.hpp>
#include <game/button.hpp>
#include <game/laser.hpp>
#include <game/updateable.hpp>
#include <wizard_engine/wizard_engine.hpp>

/* egyenlőre teszt kód */
wze_main(2560, 1440) {
    std::vector<std::shared_ptr<updateable>> updateables;
    uint64_t last_time;
    float cursor_x;
    float cursor_y;

    wze::timer::set_frame_time(10);
    last_time = 0;

    wze_while(true) {
        /* lövés */
        if (wze::input::key(wze::KEY_MOUSE_LEFT) &&
            last_time + 200 < wze::timer::current_time()) {
            std::tie(cursor_x, cursor_y) = wze::input::cursor_spatial(
                wze::camera::z() + wze::camera::focus());

            updateables.push_back(std::shared_ptr<laser>(
                new laser(wze::camera::x(), wze::camera::y(), wze::camera::z(),
                          wze::math::angle(wze::camera::focus(),
                                           cursor_y - wze::camera::y()),
                          wze::math::angle(cursor_x - wze::camera::x(),
                                           wze::camera::focus()))));

            last_time = wze::timer::current_time();
        }

        /* kamera mozgatás */
        if (wze::input::key(wze::KEY_W)) {
            wze::camera::set_z(wze::camera::z() + wze::timer::delta_time());
        }
        if (wze::input::key(wze::KEY_S)) {
            wze::camera::set_z(wze::camera::z() - wze::timer::delta_time());
        }
        if (wze::input::key(wze::KEY_A)) {
            wze::camera::set_x(wze::camera::x() - wze::timer::delta_time());
        }
        if (wze::input::key(wze::KEY_D)) {
            wze::camera::set_x(wze::camera::x() + wze::timer::delta_time());
        }

        /* frissítés */
        for (std::shared_ptr<updateable> const& updateable : updateables) {
            updateable->update();
        }
    };

    return 0;
}
