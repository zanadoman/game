#include <game/assets.hpp>
#include <game/button.hpp>
#include <game/laser.hpp>
#include <game/player_ship.hpp>
#include <game/updateable.hpp>
#include <wizard_engine/wizard_engine.hpp>

wze_main(2560, 1440) {
    player_ship player_ship;
    wze::sprite joy_stick_head;
    wze::sprite joy_stick_center;
    float joy_stick_value;
    float joy_stick_angle;
    std::vector<wze::sprite> asteroids;

    joy_stick_head = {0, 0, 0, 0, 20, 20, false, assets::placeholder_texture()};
    joy_stick_center = {0, 0, 0, 0, 5, 5, false, assets::placeholder_texture()};

    for (size_t i = 0; i != 10000; ++i) {
        asteroids.push_back({(float)wze::math::random(-10000, 10000),
                             (float)wze::math::random(-10000, 10000),
                             (float)wze::math::random(-10000, 10000),
                             (float)wze::math::random(0, 360),
                             (float)wze::math::random(50, 200),
                             (float)wze::math::random(50, 200), true,
                             assets::asteroid_texture()});
    }

    wze_while(true) {
        joy_stick_value =
            std::min(wze::math::length(wze::input::cursor_absolute_x(),
                                       wze::input::cursor_absolute_y()),
                     150.f);
        joy_stick_angle = wze::math::angle(wze::input::cursor_absolute_x(),
                                           wze::input::cursor_absolute_y());
        joy_stick_head.set_x(
            wze::math::move_x(joy_stick_value, joy_stick_angle));
        joy_stick_head.set_y(
            wze::math::move_y(joy_stick_value, joy_stick_angle));

        if (wze::input::key(wze::KEY_W)) {
            player_ship.set_z(player_ship.z() + wze::timer::delta_time());
        }
        if (wze::input::key(wze::KEY_S)) {
            player_ship.set_z(player_ship.z() - wze::timer::delta_time());
        }
        if (wze::input::key(wze::KEY_A)) {
            player_ship.set_angle(player_ship.angle() -
                                  0.001f * wze::timer::delta_time());
        }
        if (wze::input::key(wze::KEY_D)) {
            player_ship.set_angle(player_ship.angle() +
                                  0.001f * wze::timer::delta_time());
        }

        if (20 < joy_stick_value) {
            player_ship.set_x(
                player_ship.x() +
                0.01f *
                    wze::math::move_x(joy_stick_value,
                                      joy_stick_angle + wze::camera::angle()) *
                    wze::timer::delta_time());
            player_ship.set_y(
                player_ship.y() +
                0.01f *
                    wze::math::move_y(joy_stick_value,
                                      joy_stick_angle + wze::camera::angle()) *
                    wze::timer::delta_time());
        }

        player_ship.update();
    };

    return 0;
}
