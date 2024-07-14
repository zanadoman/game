#include <game/assets.hpp>
#include <game/player_ship.hpp>

void player_ship::update_movement() {
    if (wze::input::key(wze::KEY_W) && !wze::input::key(wze::KEY_S)) {
        set_z(z() + wze::timer::delta_time() * 5);
    } else if (wze::input::key(wze::KEY_S)) {
        set_z(z() - wze::timer::delta_time() * 5);
    }

    if (wze::input::key(wze::KEY_A) && !wze::input::key(wze::KEY_D)) {
        set_angle(angle() - 0.001f * wze::timer::delta_time());
    } else if (wze::input::key(wze::KEY_D)) {
        set_angle(angle() + 0.001f * wze::timer::delta_time());
    }

    _joy_stick.update();
    set_x(x() + 0.075f *
                    wze::math::move_x(_joy_stick.value(),
                                      _joy_stick.direction() + angle()) *
                    wze::timer::delta_time());
    set_y(y() + 0.075f *
                    wze::math::move_y(_joy_stick.value(),
                                      _joy_stick.direction() + angle()) *
                    wze::timer::delta_time());
}

void player_ship::update_cannons_x() {
    _left_cannon.first =
        x() + wze::math::transform_x(-_cannons_x_offset, _cannons_y_offset,
                                     transformation_matrix());
    _right_cannon.first =
        x() + wze::math::transform_x(_cannons_x_offset, _cannons_y_offset,
                                     transformation_matrix());
}

void player_ship::update_cannons_y() {
    _left_cannon.second =
        y() + wze::math::transform_y(-_cannons_x_offset, _cannons_y_offset,
                                     transformation_matrix());
    _right_cannon.second =
        y() + wze::math::transform_y(_cannons_x_offset, _cannons_y_offset,
                                     transformation_matrix());
}

void player_ship::shoot(std::vector<laser>& lasers) {
    std::pair<float, float> cannon;

    cannon = (_active_cannon = !_active_cannon) ? _left_cannon : _right_cannon;
    lasers.push_back({cannon.first, cannon.second, z(),
                      wze::math::to_radians(0), wze::math::to_radians(90)});
}

void player_ship::set_x(float x) {
    entity::set_x(x);
    update_cannons_x();
    wze::camera::set_x(this->x());
}

void player_ship::set_y(float y) {
    entity::set_y(y);
    update_cannons_y();
    wze::camera::set_y(this->y());
}

float player_ship::z() const {
    return _z;
}

void player_ship::set_z(float z) {
    _z = z;
    wze::camera::set_z(this->z());
}

void player_ship::set_angle(float angle) {
    entity::set_angle(angle);
    update_cannons_x();
    update_cannons_y();
    wze::camera::set_angle(this->angle());
}

player_ship::player_ship() {
    _z = 0;
    _cockpit = {0,
                0,
                0,
                0,
                (float)wze::window::width(),
                (float)wze::window::height(),
                false,
                assets::player_ship_texture()};
    _left_cannon = {x() - _cannons_x_offset, y() + _cannons_y_offset};
    _left_cannon = {x() + _cannons_x_offset, y() + _cannons_y_offset};
    _active_cannon = false;
    _last_shot = 0;
}

void player_ship::update(std::vector<laser>& lasers) {
    update_movement();

    if (wze::input::key(wze::key::KEY_MOUSE_LEFT) &&
        _last_shot + _reload_time <= wze::timer::current_time()) {
        shoot(lasers);
        _last_shot = wze::timer::current_time();
    }
}
