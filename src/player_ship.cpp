#include <game/assets.hpp>
#include <game/asteroid.hpp>
#include <game/laser.hpp>
#include <game/player_ship.hpp>
#include <game/save_data.hpp>

bool player_ship::dodge(float x, float y, float z, float near) {
    float x_distance;
    float y_distance;
    float distance;

    if (z - near < this->z() && this->z() < z + near &&
        (distance = wze::math::length(x_distance = this->x() - x,
                                      y_distance = this->y() - y)) < near) {
        if (!x_distance && !y_distance) {
            x_distance = wze::math::random(-1.f, 1.f);
            y_distance = wze::math::random(-1.f, 1.f);
            distance = wze::math::length(x_distance, y_distance);
        }
        set_x(this->x() + x_distance / distance * 50);
        set_y(this->y() + y_distance / distance * 50);
        return true;
    }

    return false;
}

void player_ship::update_hud(uint8_t difficulty) {
    std::shared_ptr<wze::image> image;

    if (_warning_opacity != 0) {
        _warning.set_color_a(
            _warning_opacity = std::max(
                0.f, _warning_opacity - 0.1f * wze::timer::delta_time()));
    }

    if (_pyrite_icon.width() != 60 && _pyrite_icon.height() != 60) {
        _pyrite_icon.set_width(std::max(
            60.f, _pyrite_icon.width() - 0.05f * wze::timer::delta_time()));
        _pyrite_icon.set_height(std::max(
            60.f, _pyrite_icon.width() - 0.05f * wze::timer::delta_time()));
    }
    image = wze::assets::create_image(std::to_string(save_data::pyrite_count()),
                                      assets::bold_font());
    _pyrite_count.set_width(_pyrite_count.height() * image->w / image->h);
    _pyrite_count.set_texture(wze::assets::create_texture(image));

    if (_wolframite_icon.width() != 60 && _wolframite_icon.height() != 60) {
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

    if (_carneol_icon.width() != 60 && _carneol_icon.height() != 60) {
        _carneol_icon.set_width(std::max(
            60.f, _carneol_icon.width() - 0.05f * wze::timer::delta_time()));
        _carneol_icon.set_height(std::max(
            60.f, _carneol_icon.width() - 0.05f * wze::timer::delta_time()));
    }
    image = wze::assets::create_image(
        std::to_string(save_data::carneol_count()), assets::bold_font());
    _carneol_count.set_width(_carneol_count.height() * image->w / image->h);
    _carneol_count.set_texture(wze::assets::create_texture(image));

    if (_moldavite_icon.width() != 60 && _moldavite_icon.height() != 60) {
        _moldavite_icon.set_width(std::max(
            60.f, _moldavite_icon.width() - 0.05f * wze::timer::delta_time()));
        _moldavite_icon.set_height(std::max(
            60.f, _moldavite_icon.width() - 0.05f * wze::timer::delta_time()));
    }
    image = wze::assets::create_image(
        std::to_string(save_data::moldavite_count()), assets::bold_font());
    _moldavite_count.set_width(_moldavite_count.height() * image->w / image->h);
    _moldavite_count.set_texture(wze::assets::create_texture(image));

    if (_ruby_icon.width() != 60 && _ruby_icon.height() != 60) {
        _ruby_icon.set_width(std::max(
            60.f, _ruby_icon.width() - 0.05f * wze::timer::delta_time()));
        _ruby_icon.set_height(std::max(
            60.f, _ruby_icon.width() - 0.05f * wze::timer::delta_time()));
    }
    image = wze::assets::create_image(std::to_string(save_data::ruby_count()),
                                      assets::bold_font());
    _ruby_count.set_width(_ruby_count.height() * image->w / image->h);
    _ruby_count.set_texture(wze::assets::create_texture(image));

    if (_sapphire_icon.width() != 60 && _sapphire_icon.height() != 60) {
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
        ceilf((float)_current_hitpoints / _max_hitpoints * 10)));
    _hitpoints_count.set_color_r(228 - (float)_current_hitpoints /
                                           _max_hitpoints * 91);
    _hitpoints_count.set_color_g(44 + (float)_current_hitpoints /
                                          _max_hitpoints * 177);
    _hitpoints_count.set_color_b(56 + (float)_current_hitpoints /
                                          _max_hitpoints * 14);

    _storage_count.set_texture(assets::player_ship_storage_textures().at(
        floorf((save_data::pyrite_count() + save_data::wolframite_count() +
                save_data::carneol_count() + save_data::moldavite_count() +
                save_data::ruby_count() + save_data::sapphire_count()) /
               (float)_storage * 10)));

    _difficulty_count.set_texture(
        assets::player_ship_difficulty_textures().at(difficulty));
}

void player_ship::update_crosshair() {
    float value;

    _crosshair.set_x(_crosshair.x() + wze::input::cursor_relative_x());
    _crosshair.set_y(_crosshair.y() + wze::input::cursor_relative_y());

    if (200 < (value = wze::math::length(_crosshair.x(), _crosshair.y()))) {
        _crosshair.set_x(_crosshair.x() / value * 200);
        _crosshair.set_y(_crosshair.y() / value * 200);
    }

    _crosshair_x = wze::math::transform_x(_crosshair.x(), _crosshair.y(),
                                          transformation_matrix());
    _crosshair_y = wze::math::transform_y(_crosshair.x(), _crosshair.y(),
                                          transformation_matrix());
}

void player_ship::update_movement() {
    bool moved;

    moved = false;

    if (wze::input::key(wze::KEY_S)) {
        set_z(z() - _speed * wze::timer::delta_time());
        moved = true;
    } else {
        set_z(z() + _speed * wze::timer::delta_time());
        moved = true;
    }

    if ((wze::input::key(wze::KEY_A) || wze::input::key(wze::KEY_LEFT)) &&
        !(wze::input::key(wze::KEY_D) || wze::input::key(wze::KEY_RIGHT))) {
        set_angle(angle() - _speed / 7'500 * wze::timer::delta_time());
        moved = true;
    } else if ((wze::input::key(wze::KEY_D) ||
                wze::input::key(wze::KEY_RIGHT)) &&
               !(wze::input::key(wze::KEY_A) ||
                 wze::input::key(wze::KEY_LEFT))) {
        set_angle(angle() + _speed / 7'500 * wze::timer::delta_time());
        moved = true;
    }

    update_crosshair();
    if (50 < wze::math::length(_crosshair_x, _crosshair_y)) {
        set_x(x() + _crosshair_x * _speed / 75 * wze::timer::delta_time());
        set_y(y() + _crosshair_y * _speed / 75 * wze::timer::delta_time());
        moved = true;
    }

    _sound.set_volume(std::numeric_limits<int8_t>::max() / (moved ? 3 : 4));
}

void player_ship::update_cannons_x() {
    _left_cannon.first =
        x() + wze::math::transform_x(-500, 300, transformation_matrix());
    _right_cannon.first =
        x() + wze::math::transform_x(500, 300, transformation_matrix());
}

void player_ship::update_cannons_y() {
    _left_cannon.second =
        y() + wze::math::transform_y(-500, 300, transformation_matrix());
    _right_cannon.second =
        y() + wze::math::transform_y(500, 300, transformation_matrix());
}

void player_ship::shoot(std::vector<laser>& lasers,
                        std::vector<wze::speaker>& speakers) {
    std::pair<float, float> cannon;
    float normalization;
    float speed;

    cannon = (_active_cannon = !_active_cannon) ? _left_cannon : _right_cannon;
    normalization = sqrtf(powf(_crosshair_x, 2) + powf(_crosshair_y, 2) +
                          powf(wze::camera::focus(), 2));
    speed = _speed * 20;

    lasers.push_back({cannon.first, cannon.second, z(),
                      _crosshair_x / normalization * speed,
                      _crosshair_y / normalization * speed,
                      wze::camera::focus() / normalization * speed, 1'000, 300,
                      137, 221, 71, _damage, speakers});
}

bool player_ship::dodge_asteroids(std::vector<asteroid> const& asteroids) {
    for (asteroid const& asteroid : asteroids) {
        if (dodge(asteroid.x(), asteroid.y(), asteroid.z(), 7'000)) {
            return true;
        }
    }

    return false;
}

std::shared_ptr<wze::polygon> const& player_ship::hitbox() const {
    return _hitbox;
}

void player_ship::set_x(float x) {
    entity::set_x(x);
    wze::camera::set_x(this->x());
    update_cannons_x();
}

void player_ship::set_y(float y) {
    entity::set_y(y);
    wze::camera::set_y(this->y());
    update_cannons_y();
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

    _warning = {0,
                0,
                0,
                0,
                (float)wze::window::width(),
                (float)wze::window::height(),
                false,
                assets::player_ship_warning_texture(),
                std::numeric_limits<uint8_t>::max(),
                std::numeric_limits<uint8_t>::max(),
                std::numeric_limits<uint8_t>::max(),
                0};
    _warning_opacity = 0;

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

    _difficulty_count = {0,
                         0,
                         0,
                         0,
                         (float)wze::window::width(),
                         (float)wze::window::height(),
                         false,
                         assets::player_ship_difficulty_textures().front()};

    _hitbox = std::shared_ptr<wze::polygon>(new wze::polygon(
        {{-1'280, -720}, {-1'280, 720}, {1'280, 720}, {1'280, -720}}));

    _crosshair = {0,  0,  0,     0,
                  36, 36, false, assets::player_ship_crosshair_texture()};
    _crosshair_x = 0;
    _crosshair_y = 0;

    switch (save_data::player_ship_speed_tier()) {
    case 0:
        _speed = 5;
        break;
    case 1:
        _speed = 6.5;
        break;
    case 2:
        _speed = 8.5;
        break;
    default:
        _speed = 10;
        break;
    }

    _left_cannon = {x() - 500, y() + 300};
    _right_cannon = {x() + 500, y() + 300};

    _active_cannon = false;
    _last_shot = 0;
    _reload_time = 300;
    switch (save_data::player_ship_damage_tier()) {
    case 0:
        _damage = 10;
        break;
    case 1:
        _damage = 17;
        break;
    case 2:
        _damage = 23;
        break;
    default:
        _damage = 30;
        break;
    }

    switch (save_data::player_ship_hitpoints_tier()) {
    case 0:
        _max_hitpoints = 300;
        break;
    case 1:
        _max_hitpoints = 500;
        break;
    case 2:
        _max_hitpoints = 700;
        break;
    default:
        _max_hitpoints = 900;
        break;
    }
    _current_hitpoints = _max_hitpoints;

    switch (save_data::player_ship_storage_tier()) {
    case 0:
        _storage = 50;
        break;
    case 1:
        _storage = 80;
        break;
    case 2:
        _storage = 120;
        break;
    default:
        _storage = 150;
        break;
    }

    _warning_sound = {assets::player_ship_warning_sound(),
                      std::numeric_limits<int8_t>::max() / 2};
    _asteroid_loot_sound = {assets::player_ship_asteroid_loot_accepted_sound(),
                            std::numeric_limits<int8_t>::max()};
    _sound = {assets::ship_sound(), std::numeric_limits<int8_t>::max() / 4};
    _sound.play(0, std::numeric_limits<uint16_t>::max());

    components().push_back(_hitbox);
}

bool player_ship::update(uint8_t difficulty, std::vector<laser>& lasers,
                         std::vector<wze::speaker>& speakers) {
    if (!_current_hitpoints) {
        return false;
    }

    update_movement();

    if (wze::input::key(wze::key::KEY_MOUSE_LEFT) &&
        _last_shot + _reload_time < wze::timer::current_time()) {
        shoot(lasers, speakers);
        _last_shot = wze::timer::current_time();
    }

    update_hud(difficulty);

    return true;
}

void player_ship::damage(uint16_t hitpoints) {
    if (_current_hitpoints) {
        _current_hitpoints = std::max(0, _current_hitpoints - hitpoints);
        _warning.set_color_a(_warning_opacity =
                                 std::numeric_limits<uint8_t>::max());
        if (!_warning_sound.playing()) {
            _warning_sound.play();
        }
    }
}

void player_ship::asteroid_loot(material material) {
    if (save_data::pyrite_count() + save_data::wolframite_count() +
            save_data::carneol_count() + save_data::moldavite_count() +
            save_data::ruby_count() + save_data::sapphire_count() ==
        _storage) {
        if (!_asteroid_loot_sound.playing()) {
            _asteroid_loot_sound.set_sound(
                assets::player_ship_asteroid_loot_rejected_sound());
            _asteroid_loot_sound.play();
        }
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

    if (!_asteroid_loot_sound.playing()) {
        _asteroid_loot_sound.play();
    }
}
