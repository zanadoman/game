#include <game/assets.hpp>
#include <game/player.hpp>

player::player(float x, float y)
    : collider({{{-20, 0}, {0, -20}, {20, 0}, {0, 20}}, x, y}, 0, 0, 0) {
    _appearance = std::shared_ptr<wze::sprite>(
        new wze::sprite(this->x(), this->y(), wze::camera::focus(), 0, 160, 160,
                        true, assets::player_front_idle_animation().at(0),
                        std::numeric_limits<uint8_t>::max(),
                        std::numeric_limits<uint8_t>::max(),
                        std::numeric_limits<uint8_t>::max(),
                        std::numeric_limits<uint8_t>::max(), wze::FLIP_NONE,
                        true, std::numeric_limits<uint8_t>::max() / 2, true, 0,
                        -80, 0, true, true, false, false, false));

    _front_idle = {assets::player_front_idle_animation(), 200, {_appearance}};
    _front_walk = {assets::player_front_walk_animation(), 125, {_appearance}};
    _back_idle = {assets::player_back_idle_animation(), 200, {_appearance}};
    _back_walk = {assets::player_back_walk_animation(), 125, {_appearance}};
    _left_idle = {assets::player_left_idle_animation(), 400, {_appearance}};
    _left_walk = {assets::player_left_walk_animation(), 125, {_appearance}};
    _right_idle = {assets::player_right_idle_animation(), 400, {_appearance}};
    _right_walk = {assets::player_right_walk_animation(), 125, {_appearance}};
    _direction = DIRECTION_FRONT;

    /* -- GUNICS ROLAND, 2024 -- */
    /**
     * @author Gunics Roland
     * @brief Initializes nothing to the literal thing of none.
     * @param thing No-thing.
     * @return Pure antimatter.
     */
    _step_sounds = {
        {}, /* "An idiot admires complexity, a genius admires simplicity" */
    };
    /*  (-_•)╦̵̵̿╤─ | ⁽⁽(੭ꐦ •̀Д•́ )੭*⁾⁾ | ▬▬ι═══════ﺤ | ╾━╤デ╦︻*/
    /* Decorated by Zana Domán */

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
        _direction = DIRECTION_BACK;
    } else if ((wze::input::key(wze::KEY_S) ||
                wze::input::key(wze::KEY_DOWN)) &&
               !(wze::input::key(wze::KEY_W) || wze::input::key(wze::KEY_UP))) {
        set_y(y() + 0.75f * wze::timer::delta_time());
        moved = true;
        _direction = DIRECTION_FRONT;
    }

    if ((wze::input::key(wze::KEY_A) || wze::input::key(wze::KEY_LEFT)) &&
        !(wze::input::key(wze::KEY_D) || wze::input::key(wze::KEY_RIGHT))) {
        set_x(x() - 0.75f * wze::timer::delta_time());
        moved = true;
        _direction = DIRECTION_LEFT;
    } else if ((wze::input::key(wze::KEY_D) ||
                wze::input::key(wze::KEY_RIGHT)) &&
               !(wze::input::key(wze::KEY_A) ||
                 wze::input::key(wze::KEY_LEFT))) {
        set_x(x() + 0.75f * wze::timer::delta_time());
        moved = true;
        _direction = DIRECTION_RIGHT;
    }

    if (moved && !_step_sounds.playing()) {
        _step_sounds.set_sound(assets::player_step_sounds());
        _step_sounds.play();
    }

    switch (_direction) {
    case DIRECTION_FRONT:
        if (moved) {
            _front_walk.play();
        } else {
            _front_idle.play();
        }
        break;
    case DIRECTION_BACK:
        if (moved) {
            _back_walk.play();
        } else {
            _back_idle.play();
        }
        break;
    case DIRECTION_LEFT:
        if (moved) {
            _left_walk.play();
        } else {
            _left_idle.play();
        }
        break;
    case DIRECTION_RIGHT:
        if (moved) {
            _right_walk.play();
        } else {
            _right_idle.play();
        }
    }

    wze::camera::set_x(x());
    wze::camera::set_y(y() - 80);

    printf("%f %f\n", (double)x(), (double)y());
}
