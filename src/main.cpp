#include <game/assets.hpp>
#include <game/button.hpp>
#include <game/laser.hpp>
#include <game/updateable.hpp>
#include <wizard_engine/wizard_engine.hpp>

/* egyenlőre test kód */
wze_main(2560, 1440) {
    std::vector<std::shared_ptr<updateable>> updateables;
    std::shared_ptr<button> btn;
    uint64_t last_time;

    wze::timer::set_frame_time(10);
    btn.reset(new button(500, 0, 100, 100, assets::placeholder_texture()));
    updateables.push_back(btn);
    last_time = 0;

    wze_while(true) {
        if (wze::input::key(wze::KEY_MOUSE_LEFT) &&
            last_time + 200 < wze::timer::current_time()) {
            std::apply(
                [&updateables](float x, float y) -> void {
                    updateables.push_back(std::shared_ptr<laser>(
                        new laser(x, y, wze::camera::z())));
                },
                wze::input::cursor_spatial(wze::camera::z() +
                                           wze::camera::focus()));
            last_time = wze::timer::current_time();
        }

        for (std::shared_ptr<updateable> const& instance : updateables) {
            instance->update();
        }

        printf("%u\n", btn->state());
    };

    return 0;
}
