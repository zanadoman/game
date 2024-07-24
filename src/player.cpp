#include <game/assets.hpp>
#include <game/player.hpp>

player::player() : collider({{{-16, 0}, {0, 16}, {16, 0}, {0, -16}}}) {
    _appearance = std::shared_ptr<wze::sprite>(
        new wze::sprite(x(), y(), wze::camera::focus(), 0, 160, 160, true,
                        assets::placeholder_texture()));

    components().push_back(_appearance);
}

void player::update() {
    if ((wze::input::key(wze::KEY_W) || wze::input::key(wze::KEY_UP)) &&
        !(wze::input::key(wze::KEY_S) || wze::input::key(wze::KEY_DOWN))) {
        set_y(y() - wze::timer::delta_time());
    } else if ((wze::input::key(wze::KEY_S) ||
                wze::input::key(wze::KEY_DOWN)) &&
               !(wze::input::key(wze::KEY_W) || wze::input::key(wze::KEY_UP))) {
        set_y(y() + wze::timer::delta_time());
    }

    if ((wze::input::key(wze::KEY_A) || wze::input::key(wze::KEY_LEFT)) &&
        !(wze::input::key(wze::KEY_D) || wze::input::key(wze::KEY_RIGHT))) {
        set_x(x() - wze::timer::delta_time());
    } else if ((wze::input::key(wze::KEY_D) ||
                wze::input::key(wze::KEY_RIGHT)) &&
               !(wze::input::key(wze::KEY_A) ||
                 wze::input::key(wze::KEY_LEFT))) {
        set_x(x() + wze::timer::delta_time());
    }

    wze::camera::set_x(x());
    wze::camera::set_y(y());
}
