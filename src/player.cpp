#include <game/assets.hpp>
#include <game/player.hpp>

player::player(float x, float y)
    : collider({{{-40, 0}, {0, -40}, {40, 0}, {0, 40}}, x, y}, 0, 0, 0) {
    _appearance = std::shared_ptr<wze::sprite>(new wze::sprite(
        this->x(), this->y(), wze::camera::focus(), 0, 160, 160, true,
        assets::placeholder_texture(), std::numeric_limits<uint8_t>::max() / 2,
        std::numeric_limits<uint8_t>::max() / 2,
        std::numeric_limits<uint8_t>::max() / 2,
        std::numeric_limits<uint8_t>::max(), wze::FLIP_NONE, true,
        std::numeric_limits<uint8_t>::max() / 2, true, 0, -80, 0, true, true,
        false, false, false));

    _step_sounds = {
        {},
    };

    wze::camera::set_x(this->x());
    wze::camera::set_y(this->y() - 80);
    wze::camera::set_z(0);

    components().push_back(_appearance);
    recompose();
}

void player::update() {
    bool moved = false;

    if ((wze::input::key(wze::KEY_W) || wze::input::key(wze::KEY_UP)) &&
        !(wze::input::key(wze::KEY_S) || wze::input::key(wze::KEY_DOWN))) {
        set_y(y() - 0.75f * wze::timer::delta_time());
        moved = true;
    } else if ((wze::input::key(wze::KEY_S) ||
                wze::input::key(wze::KEY_DOWN)) &&
               !(wze::input::key(wze::KEY_W) || wze::input::key(wze::KEY_UP))) {
        set_y(y() + 0.75f * wze::timer::delta_time());
        moved = true;
    }

    if ((wze::input::key(wze::KEY_A) || wze::input::key(wze::KEY_LEFT)) &&
        !(wze::input::key(wze::KEY_D) || wze::input::key(wze::KEY_RIGHT))) {
        set_x(x() - 0.75f * wze::timer::delta_time());
        moved = true;
    } else if ((wze::input::key(wze::KEY_D) ||
                wze::input::key(wze::KEY_RIGHT)) &&
               !(wze::input::key(wze::KEY_A) ||
                 wze::input::key(wze::KEY_LEFT))) {
        set_x(x() + 0.75f * wze::timer::delta_time());
        moved = true;
    }

    if (moved && !_step_sounds.playing()) {
        _step_sounds.set_sound(assets::player_step_sounds());
        _step_sounds.play();
    }

    wze::camera::set_x(x());
    wze::camera::set_y(y() - 80);

    printf("%f, %f\n", (double)x(), (double)y());
}
