#include "wizard_engine/math.hpp"
#include <game/assets.hpp>
#include <game/enemy_ship.hpp>

float enemy_ship::z() const {
    return _z;
}

void enemy_ship::set_z(float z) {
    _z = z;
    _appearance->set_z(this->z());
}

bool enemy_ship::dodge_asteroids(std::vector<asteroid> const& asteroids) {
    float x_distance;
    float y_distance;
    float normalization;

    for (asteroid const& asteroid : asteroids) {
        x_distance = x() - asteroid.x();
        y_distance = y() - asteroid.y();
        if (asteroid.z() - 5000 < z() && z() < asteroid.z() + 5000 &&
            wze::math::length(x_distance, y_distance) < 10000) {
            if (!x_distance && !y_distance) {
                x_distance = wze::math::random(-1.f, 1.f);
                y_distance = wze::math::random(-1.f, 1.f);
            }
            normalization = wze::math::length(x_distance, y_distance);
            _x_speed = x_distance / normalization * _speed;
            _y_speed = y_distance / normalization * _speed;
            return true;
        }
    }

    return false;
}

void enemy_ship::update_appearance() {
    float speed_length;
    float speed_angle;
    float x_speed;
    float y_speed;

    speed_length = wze::math::length(_x_speed, _y_speed);
    speed_angle = wze::math::angle(_x_speed, _y_speed) + angle();
    x_speed = wze::math::move_x(speed_length, speed_angle);
    y_speed = wze::math::move_y(speed_length, speed_angle);

    if (abs(x_speed) < abs(y_speed)) {
        _appearance->set_texture(
            0 < y_speed ? _ready ? assets::enemy_front_down_texture()
                                 : assets::enemy_rear_down_texture()
            : _ready ? assets::enemy_front_up_texture()
                        : assets::enemy_rear_up_texture());
    } else if (abs(y_speed) < abs(x_speed)) {
        _appearance->set_texture(
            0 < x_speed ? _ready ? assets::enemy_front_right_texture()
                                 : assets::enemy_rear_right_texture()
            : _ready ? assets::enemy_front_left_texture()
                        : assets::enemy_rear_left_texture());
    } else {
        _appearance->set_texture(_ready ? assets::enemy_front_texture()
                                        : assets::enemy_rear_texture());
    }
}

enemy_ship::enemy_ship(float x, float y, float z) : entity({}, x, y) {
    _appearance = std::shared_ptr<wze::sprite>(new wze::sprite(
        this->x(), this->y(), z, 0, 8000, 8000, true,
        assets::placeholder_texture(), std::numeric_limits<uint8_t>::max(),
        std::numeric_limits<uint8_t>::max(),
        std::numeric_limits<uint8_t>::max(),
        std::numeric_limits<uint8_t>::max(), wze::FLIP_NONE, true,
        std::numeric_limits<uint8_t>::max(), true, 0, 0, 0, true, true, true,
        false, false));
    set_z(z);
    _speed = 10;
    _x_speed = 0;
    _y_speed = 0;
    _z_speed = 0;
    _ready = false;
    _last_attack = 0;
    _attacking = false;
    _loop = {{assets::enemy_loop1_texture(), assets::enemy_loop2_texture(),
              assets::enemy_loop3_texture()},
             150,
             {_appearance}};
    components().push_back(_appearance);
}

bool enemy_ship::update(player_ship& player_ship,
                        std::vector<asteroid> const& asteroids) {
    float x_distance;
    float y_distance;
    float z_distance;
    float normalization;
    bool attack;

    x_distance = player_ship.x() - x();
    y_distance = player_ship.y() - y();
    z_distance = player_ship.z() - z();
    attack = true;

    if (-20000 < z_distance) {
        _z_speed = _speed;
        attack = false;
    } else if (z_distance < -50000) {
        _z_speed = -_speed;
        attack = false;
    }

    if (!dodge_asteroids(asteroids)) {
        if (10000 <
            (normalization = wze::math::length(x_distance, y_distance))) {
            _x_speed = x_distance / normalization * _speed;
            _y_speed = y_distance / normalization * _speed;
            attack = false;
        }
    } else {
        attack = false;
    }

    set_x(x() + _x_speed * wze::timer::delta_time());
    set_y(y() + _y_speed * wze::timer::delta_time());
    set_z(z() + _z_speed * wze::timer::delta_time());
    if (angle() < player_ship.angle() - wze::math::to_radians(10)) {
        set_angle(angle() + 0.01f * wze::timer::delta_time());
    } else if (player_ship.angle() + wze::math::to_radians(10) < angle()) {
        set_angle(angle() - 0.01f * wze::timer::delta_time());
    }

    if (_attacking && _last_attack + 2500 < wze::timer::current_time()) {
        _attacking = false;
    } else if (attack && _last_attack + 5000 < wze::timer::current_time()) {
        _last_attack = wze::timer::current_time();
        _attacking = true;
    }

    if ((!_attacking && _ready) || (_attacking && !_ready)) {
        if (_loop.play()) {
            set_angle(angle() + wze::math::to_radians(180));
            _ready = !_ready;
            _loop.reset();
        }
    } else {
        update_appearance();
    }

    return true;
}
