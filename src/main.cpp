#include "wizard_engine/camera.hpp"
#include "wizard_engine/sprite.hpp"
#include "wizard_engine/window.hpp"
#include <game/assets.hpp>
#include <game/button.hpp>
#include <game/laser.hpp>
#include <game/updateable.hpp>
#include <wizard_engine/wizard_engine.hpp>

/* egyenlőre teszt kód */
wze_main(2560, 1440) {
    std::vector<std::shared_ptr<updateable>> updateables;
    std::vector<wze::sprite> asteroids;
    uint64_t last_time;
    float cursor_x;
    float cursor_y;
    float gun_switch;

    wze::sprite player_ship(0, 0, 0, 0, 2560, 1440, false,
                            assets::player_ship_texture());

    wze::timer::set_frame_time(10);
    last_time = 0;

    wze::sprite joystick(0, 0, 0, 0, 20, 20, false,
                         assets::placeholder_texture());
    float joylength;
    float joyangle;

    wze::sprite joystick_center(0, 0, 0, 0, 5, 5, false,
                                assets::placeholder_texture(), 255, 0, 0);

    for (size_t i = 0; i != 10000; ++i) {
        asteroids.push_back({(float)wze::math::random(-10000, 10000),
                             (float)wze::math::random(-10000, 10000),
                             (float)wze::math::random(-10000, 10000),
                             (float)wze::math::random(0, 360),
                             (float)wze::math::random(50, 200),
                             (float)wze::math::random(50, 200), true,
                             assets::asteroid_texture()});
    }

    gun_switch = 1;

    wze_while(true) {
        /* lövés */
        if (wze::input::key(wze::KEY_MOUSE_LEFT) &&
            last_time + 200 < wze::timer::current_time()) {
            std::tie(cursor_x, cursor_y) = wze::input::cursor_spatial(
                wze::camera::z() + wze::camera::focus());

            updateables.push_back(std::shared_ptr<laser>(new laser(
                wze::camera::x() +
                    wze::math::move_x(100, wze::camera::angle() +
                                               wze::math::to_radians(45) *
                                                   gun_switch) *
                        gun_switch,
                wze::camera::y() +
                    wze::math::move_y(100, wze::camera::angle() +
                                               wze::math::to_radians(45) *
                                                   gun_switch) *
                        gun_switch,
                wze::camera::z(),
                wze::math::angle(wze::camera::focus(),
                                 cursor_y - wze::camera::y()),
                wze::math::angle(cursor_x - wze::camera::x(),
                                 wze::camera::focus()))));

            gun_switch *= -1;
            last_time = wze::timer::current_time();
        }

        joylength =
            std::clamp(0.f, 150.f,
                       wze::math::length(wze::input::cursor_absolute_x(),
                                         wze::input::cursor_absolute_y()));
        joyangle = wze::math::angle(wze::input::cursor_absolute_x(),
                                    wze::input::cursor_absolute_y());
        joystick.set_x(wze::math::move_x(joylength, joyangle));
        joystick.set_y(wze::math::move_y(joylength, joyangle));

        /* kamera mozgatás */
        if (wze::input::key(wze::KEY_W)) {
            wze::camera::set_z(wze::camera::z() + wze::timer::delta_time());
        }
        if (wze::input::key(wze::KEY_S)) {
            wze::camera::set_z(wze::camera::z() - wze::timer::delta_time());
        }
        if (wze::input::key(wze::KEY_A)) {
            wze::camera::set_angle(wze::camera::angle() -
                                   0.001f * wze::timer::delta_time());
        }
        if (wze::input::key(wze::KEY_D)) {
            wze::camera::set_angle(wze::camera::angle() +
                                   0.001f * wze::timer::delta_time());
        }

        if (joylength > 20) {
            wze::camera::set_x(
                wze::camera::x() +
                0.01f *
                    wze::math::move_x(joylength,
                                      joyangle + wze::camera::angle()) *
                    wze::timer::delta_time());
            wze::camera::set_y(
                wze::camera::y() +
                0.01f *
                    wze::math::move_y(joylength,
                                      joyangle + wze::camera::angle()) *
                    wze::timer::delta_time());
        }

        /* frissítés */
        for (std::shared_ptr<updateable> const& updateable : updateables) {
            updateable->update();
        }
    };

    return 0;
}
