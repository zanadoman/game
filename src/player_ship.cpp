#include <cmath>
#include <game/player_ship.hpp>

void player_ship::update_cannons_x() {
    _left_cannon.first =
        x() + wze::math::transform_x(-_cannons_x_offset, _cannons_y_offset,
                                     transformation_matrix());
    _right_cannon.first =
        x() + wze::math::transform_x(-_cannons_x_offset, _cannons_y_offset,
                                     transformation_matrix());
}

void player_ship::update_cannons_y() {
    _left_cannon.second =
        y() + wze::math::transform_y(_cannons_x_offset, _cannons_y_offset,
                                     transformation_matrix());
    _right_cannon.second =
        y() + wze::math::transform_y(_cannons_x_offset, _cannons_y_offset,
                                     transformation_matrix());
}

void player_ship::set_x(float x) {
    entity::set_x(x);
    update_cannons_x();
}

void player_ship::set_y(float y) {
    entity::set_y(y);
    update_cannons_y();
}

void player_ship::set_angle(float angle) {
    entity::set_angle(angle);
    update_cannons_x();
    update_cannons_y();
}

void player_ship::shoot() {
    if ((_active_cannon = !_active_cannon)) {
        /* left cannon */
    } else {
        /* right cannon */
    }
}

player_ship::player_ship() {
    _left_cannon = {x() - _cannons_x_offset, y() + _cannons_y_offset};
    _left_cannon = {x() + _cannons_x_offset, y() + _cannons_y_offset};
    _active_cannon = false;
    _last_shot = 0;
}

void player_ship::update() {
    if (_last_shot + _reload_time <= wze::timer::current_time()) {
        shoot();
    }

    std::ranges::for_each(_lasers,
                          [](std::unique_ptr<laser> const& laser) -> void {
                              laser->update();
                              ;
                          });
}
