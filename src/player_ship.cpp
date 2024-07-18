#include <game/assets.hpp>
#include <game/laser.hpp>
#include <game/player_ship.hpp>
#include <game/save_data.hpp>

void player_ship::update_hud() {
    std::shared_ptr<wze::image> image;

    if (_pyrite_icon.width() != 60) {
        _pyrite_icon.set_width(std::max(
            60.f, _pyrite_icon.width() - 0.05f * wze::timer::delta_time()));
        _pyrite_icon.set_height(std::max(
            60.f, _pyrite_icon.width() - 0.05f * wze::timer::delta_time()));
    }
    image = wze::assets::create_image(std::to_string(save_data::pyrite_count()),
                                      assets::bold_font());
    _pyrite_count.set_width(_pyrite_count.height() * image->w / image->h);
    _pyrite_count.set_texture(wze::assets::create_texture(image));

    if (_wolframite_icon.width() != 60) {
        _wolframite_icon.set_width(std::max(
            60.f, _wolframite_icon.width() - 0.05f * wze::timer::delta_time()));
        _wolframite_icon.set_height(std::max(
            60.f, _wolframite_icon.width() - 0.05f * wze::timer::delta_time()));
    }
    image = wze::assets::create_image(
        std::to_string(save_data::wolframite_count()), assets::bold_font());
    _wolframite_count.set_width(_wolframite_count.height() * image->w /
                                image->h);
    _wolframite_count.set_texture(wze::assets::create_texture(image));

    if (_carneol_icon.width() != 60) {
        _carneol_icon.set_width(std::max(
            60.f, _carneol_icon.width() - 0.05f * wze::timer::delta_time()));
        _carneol_icon.set_height(std::max(
            60.f, _carneol_icon.width() - 0.05f * wze::timer::delta_time()));
    }
    image = wze::assets::create_image(
        std::to_string(save_data::carneol_count()), assets::bold_font());
    _carneol_count.set_width(_carneol_count.height() * image->w / image->h);
    _carneol_count.set_texture(wze::assets::create_texture(image));

    if (_moldavite_icon.width() != 60) {
        _moldavite_icon.set_width(std::max(
            60.f, _moldavite_icon.width() - 0.05f * wze::timer::delta_time()));
        _moldavite_icon.set_height(std::max(
            60.f, _moldavite_icon.width() - 0.05f * wze::timer::delta_time()));
    }
    image = wze::assets::create_image(
        std::to_string(save_data::moldavite_count()), assets::bold_font());
    _moldavite_count.set_width(_moldavite_count.height() * image->w / image->h);
    _moldavite_count.set_texture(wze::assets::create_texture(image));

    if (_ruby_icon.width() != 60) {
        _ruby_icon.set_width(std::max(
            60.f, _ruby_icon.width() - 0.05f * wze::timer::delta_time()));
        _ruby_icon.set_height(std::max(
            60.f, _ruby_icon.width() - 0.05f * wze::timer::delta_time()));
    }
    image = wze::assets::create_image(std::to_string(save_data::ruby_count()),
                                      assets::bold_font());
    _ruby_count.set_width(_ruby_count.height() * image->w / image->h);
    _ruby_count.set_texture(wze::assets::create_texture(image));

    if (_sapphire_icon.width() != 60) {
        _sapphire_icon.set_width(std::max(
            60.f, _sapphire_icon.width() - 0.05f * wze::timer::delta_time()));
        _sapphire_icon.set_height(std::max(
            60.f, _sapphire_icon.width() - 0.05f * wze::timer::delta_time()));
    }
    image = wze::assets::create_image(
        std::to_string(save_data::sapphire_count()), assets::bold_font());
    _sapphire_count.set_width(_sapphire_count.height() * image->w / image->h);
    _sapphire_count.set_texture(wze::assets::create_texture(image));

    _hitpoints_count.set_texture(assets::player_ship_hitpoints_textures().at(
        ceilf(_current_hitpoints / _max_hitpoints * 10)));
    _hitpoints_count.set_color_r(228 -
                                 _current_hitpoints / _max_hitpoints * 91);
    _hitpoints_count.set_color_g(44 +
                                 _current_hitpoints / _max_hitpoints * 177);
    _hitpoints_count.set_color_b(56 + _current_hitpoints / _max_hitpoints * 14);

    _storage_count.set_texture(assets::player_ship_storage_textures().at(
        floorf((save_data::pyrite_count() + save_data::wolframite_count() +
                save_data::carneol_count() + save_data::moldavite_count() +
                save_data::ruby_count() + save_data::sapphire_count()) /
               (float)_storage * 10)));
}

void player_ship::update_joy_stick() {
    _joy_stick.update();
    _joy_stick_x =
        wze::math::move_x(_joy_stick.value(), _joy_stick.direction() + angle());
    _joy_stick_y =
        wze::math::move_y(_joy_stick.value(), _joy_stick.direction() + angle());
}

void player_ship::update_movement() {
    if (wze::input::key(wze::KEY_W) && !wze::input::key(wze::KEY_S)) {
        set_z(z() + _speed * wze::timer::delta_time());
    } else if (wze::input::key(wze::KEY_S) && !wze::input::key(wze::KEY_W)) {
        set_z(z() - _speed * wze::timer::delta_time());
    }

    if (wze::input::key(wze::KEY_A) && !wze::input::key(wze::KEY_D)) {
        set_angle(angle() - 0.001f * wze::timer::delta_time());
    } else if (wze::input::key(wze::KEY_D) && !wze::input::key(wze::KEY_A)) {
        set_angle(angle() + 0.001f * wze::timer::delta_time());
    }

    update_joy_stick();
    if (50 < _joy_stick.value()) {
        set_x(x() + _joy_stick_x * _speed / 75 * wze::timer::delta_time());
        set_y(y() + _joy_stick_y * _speed / 75 * wze::timer::delta_time());
    }
}

void player_ship::update_cannons_x() {
    _left_cannon.first =
        x() + wze::math::transform_x(-300, 500, transformation_matrix());
    _right_cannon.first =
        x() + wze::math::transform_x(300, 500, transformation_matrix());
}

void player_ship::update_cannons_y() {
    _left_cannon.second =
        y() + wze::math::transform_y(-300, 500, transformation_matrix());
    _right_cannon.second =
        y() + wze::math::transform_y(300, 500, transformation_matrix());
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
                      wze::camera::focus() / normalization * _laser_speed, 1000,
                      300, 0, 155, 255, _damage});
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
    return wze::camera::z();
}

void player_ship::set_z(float z) {
    wze::camera::set_z(z);
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
                assets::player_ship_base_texture(),
                std::numeric_limits<uint8_t>::max(),
                std::numeric_limits<uint8_t>::max(),
                std::numeric_limits<uint8_t>::max(),
                std::numeric_limits<uint8_t>::max(),
                wze::FLIP_NONE,
                true,
                0};

    _pyrite_icon = {-70, 492, 0,     0,
                    60,  60,  false, assets::asteroids_pyrite_gem_ui_texture()};
    _pyrite_count = {-70, 534, 0, 0, 90, 35, false, {}, 14, 12, 21};
    _wolframite_icon = {
        0,  492, 0,     0,
        60, 60,  false, assets::asteroids_wolframite_gem_ui_texture()};
    _wolframite_count = {0, 534, 0, 0, 90, 35, false, {}, 14, 12, 21};
    _carneol_icon = {
        70, 492, 0,     0,
        60, 60,  false, assets::asteroids_carneol_gem_ui_texture()};
    _carneol_count = {70, 534, 0, 0, 90, 35, false, {}, 14, 12, 21};
    _moldavite_icon = {
        -70, 588, 0,     0,
        60,  60,  false, assets::asteroids_moldavite_gem_ui_texture()};
    _moldavite_count = {-70, 630, 0, 0, 90, 35, false, {}, 14, 12, 21};
    _ruby_icon = {0,  588, 0,     0,
                  60, 60,  false, assets::asteroids_ruby_gem_ui_texture()};
    _ruby_count = {0, 630, 0, 0, 90, 35, false, {}, 14, 12, 21};
    _sapphire_icon = {
        70, 588, 0,     0,
        60, 60,  false, assets::asteroids_sapphire_gem_ui_texture()};
    _sapphire_count = {70, 630, 0, 0, 90, 35, false, {}, 14, 12, 21};

    _hitpoints_count = {0,
                        0,
                        0,
                        0,
                        (float)wze::window::width(),
                        (float)wze::window::height(),
                        false,
                        assets::player_ship_hitpoints_textures().back(),
                        137,
                        221,
                        70};

    _storage_count = {0,
                      0,
                      0,
                      0,
                      (float)wze::window::width(),
                      (float)wze::window::height(),
                      false,
                      assets::player_ship_hitpoints_textures().front()};

    _hitbox = std::shared_ptr<wze::polygon>(new wze::polygon(
        {{-1'280, -720}, {-1'280, 720}, {1'280, 720}, {1'280, -720}}));

    _joy_stick = {};
    _joy_stick_x = 0;
    _joy_stick_y = 0;

    _speed = 5;

    _left_cannon = {x() - 300, y() + 500};
    _right_cannon = {x() + 300, y() + 500};

    _active_cannon = false;
    _laser_speed = 100;
    _last_shot = 0;
    _reload_time = 300;
    _damage = 10;

    _current_hitpoints = _max_hitpoints = 300;

    _storage = 50;

    components().push_back(_hitbox);
}

void player_ship::update(std::vector<laser>& lasers) {
    update_movement();

    if (wze::input::key(wze::key::KEY_MOUSE_LEFT) &&
        _last_shot + _reload_time < wze::timer::current_time()) {
        shoot(lasers);
        _last_shot = wze::timer::current_time();
    }

    update_hud();
}

void player_ship::damage(float hitpoints) {
    if (0 < _current_hitpoints) {
        _current_hitpoints = std::max(0.f, _current_hitpoints - hitpoints);
    }
}

void player_ship::asteroid_loot(material material) {
    if (save_data::pyrite_count() + save_data::wolframite_count() +
            save_data::carneol_count() + save_data::moldavite_count() +
            save_data::ruby_count() + save_data::sapphire_count() ==
        _storage) {
        return;
    }

    switch (material) {
    case MATERIAL_PYRITE:
        save_data::set_pyrite_count(save_data::pyrite_count() + 1);
        _pyrite_icon.set_width(80);
        _pyrite_icon.set_height(80);
        break;
    case MATERIAL_WOLFRAMITE:
        save_data::set_wolframite_count(save_data::wolframite_count() + 1);
        _wolframite_icon.set_width(80);
        _wolframite_icon.set_height(80);
        break;
    case MATERIAL_CARNEOL:
        save_data::set_carneol_count(save_data::carneol_count() + 1);
        _carneol_icon.set_width(80);
        _carneol_icon.set_height(80);
        break;
    case MATERIAL_MOLDAVITE:
        save_data::set_moldavite_count(save_data::moldavite_count() + 1);
        _moldavite_icon.set_width(80);
        _moldavite_icon.set_height(80);
        break;
    case MATERIAL_RUBY:
        save_data::set_ruby_count(save_data::ruby_count() + 1);
        _ruby_icon.set_width(80);
        _ruby_icon.set_height(80);
        break;
    case MATERIAL_SAPPHIRE:
        save_data::set_sapphire_count(save_data::sapphire_count() + 1);
        _sapphire_icon.set_width(80);
        _sapphire_icon.set_height(80);
        break;
    }
}
