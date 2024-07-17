#include <game/assets.hpp>
#include <game/player_ship.hpp>

void player_ship::update_joy_stick() {
    _joy_stick.update();
    _joy_stick_x =
        wze::math::move_x(_joy_stick.value(), _joy_stick.direction() + angle());
    _joy_stick_y =
        wze::math::move_y(_joy_stick.value(), _joy_stick.direction() + angle());
}

void player_ship::update_movement() {
    if (wze::input::key(wze::KEY_W) && !wze::input::key(wze::KEY_S)) {
        set_z(z() + _movement_speed * wze::timer::delta_time());
    } else if (wze::input::key(wze::KEY_S) && !wze::input::key(wze::KEY_W)) {
        set_z(z() - _movement_speed * wze::timer::delta_time());
    }

    if (wze::input::key(wze::KEY_A) && !wze::input::key(wze::KEY_D)) {
        set_angle(angle() - _rotation_speed * wze::timer::delta_time());
    } else if (wze::input::key(wze::KEY_D) && !wze::input::key(wze::KEY_A)) {
        set_angle(angle() + _rotation_speed * wze::timer::delta_time());
    }

    update_joy_stick();
    if (50 < _joy_stick.value()) {
        set_x(x() +
              _joy_stick_x * _movement_speed / 75 * wze::timer::delta_time());
        set_y(y() +
              _joy_stick_y * _movement_speed / 75 * wze::timer::delta_time());
    }
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
    float normalization;

    cannon = (_active_cannon = !_active_cannon) ? _left_cannon : _right_cannon;
    normalization = sqrtf(powf(_joy_stick_x, 2) + powf(_joy_stick_y, 2) +
                          powf(wze::camera::focus(), 2));

    lasers.push_back({cannon.first, cannon.second, z(),
                      _joy_stick_x / normalization * _laser_speed,
                      _joy_stick_y / normalization * _laser_speed,
                      wze::camera::focus() / normalization * _laser_speed,
                      _laser_length, _laser_diameter, _laser_color_r,
                      _laser_color_g, _laser_color_b});
    _last_shot = wze::timer::current_time();
}

std::shared_ptr<wze::polygon> const& player_ship::hitbox() const {
    return _hitbox;
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
    _cockpit = {0,
                0,
                0,
                0,
                (float)wze::window::width(),
                (float)wze::window::height(),
                false,
                assets::player_ship_texture()};
    _hitbox = std::shared_ptr<wze::polygon>(new wze::polygon(
        {{-1280, -720}, {-1280, 720}, {1280, 720}, {1280, -720}}));
    _joy_stick = {};
    _joy_stick_x = 0;
    _joy_stick_y = 0;
    _z = 0;
    _left_cannon = {x() - _cannons_x_offset, y() + _cannons_y_offset};
    _right_cannon = {x() + _cannons_x_offset, y() + _cannons_y_offset};
    _active_cannon = false;
    _last_shot = 0;
    _last_damage = 0;

    components().push_back(_hitbox);
}

void player_ship::update(std::vector<laser>& lasers) {
    update_movement();

    if (_last_damage + 200 < wze::timer::current_time()) {
        _cockpit.set_color_g(std::numeric_limits<uint8_t>::max());
        _cockpit.set_color_b(std::numeric_limits<uint8_t>::max());
    }

    if (wze::input::key(wze::key::KEY_MOUSE_LEFT) &&
        _last_shot + _reload_time <= wze::timer::current_time()) {
        shoot(lasers);
    }
}

void player_ship::damage([[maybe_unused]] float hitpoints) {
    _cockpit.set_color_g(std::numeric_limits<uint8_t>::max() / 2);
    _cockpit.set_color_b(std::numeric_limits<uint8_t>::max() / 2);
    _last_damage = wze::timer::current_time();
}
