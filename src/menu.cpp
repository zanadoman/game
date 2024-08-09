#include <game/assets.hpp>
#include <game/menu.hpp>
#include <game/save_data.hpp>
#include <iostream>

std::tuple<float, float, float> menu::sphere_coordinate(float minimum,
                                                        float maximum) const {
    float x;
    float y;
    float z;
    float normalization;
    float radius;

    x = wze::math::random(-1.f, 1.f);
    y = wze::math::random(-1.f, 1.f);
    z = wze::math::random(-1.f, 1.f);

    if ((normalization = sqrt(powf(x, 2) + powf(y, 2) + powf(z, 2)))) {
        x /= normalization;
        y /= normalization;
        z /= normalization;
    }

    radius = wze::math::random(minimum, maximum);
    return {-40'000 + x * radius, y * radius, z * radius};
}

void menu::update_space() {
    for (wze::sprite& asteroid : _asteroids) {
        asteroid.set_x(asteroid.x() + wze::timer::delta_time());
        if (110'000 < asteroid.x()) {
            asteroid.set_x(-190'000);
        }
    }
    for (wze::sprite& particle : _particles) {
        particle.set_x(particle.x() + wze::timer::delta_time());
        if (80'000 < particle.x()) {
            particle.set_x(-120'000);
        }
    }
}

scene_type menu::update_door() {
    float distance;

    distance =
        wze::math::length(968 - _player_sprite.x(), _player_sprite.y() - 475);
    if (!_door_animating && (distance <= 400) != _door_open) {
        _door_animating = true;
        _door_sound.play();
    }

    if (_door_animating && _door_animation.play()) {
        _door->set_texture(_door_animation.frames().back());
        _door_animation.reverse();
        _door_animation.reset();
        _door_open = !_door_open;
        _door_animating = false;
    }

    if (_door_open && !_door_animating) {
        if (_color != 0) {
            _color = std::max(0.f, _color - 0.2f * wze::timer::delta_time());
        }
    } else {
        if (_color != std::numeric_limits<uint8_t>::max()) {
            _color = std::min(_color + 0.2f * wze::timer::delta_time(),
                              (float)std::numeric_limits<uint8_t>::max());
        }
    }

    wze::renderer::set_space_color_r(_color);
    wze::renderer::set_space_color_g(_color);
    wze::renderer::set_space_color_b(_color);
    wze::renderer::set_background_color_r(
        _color / std::numeric_limits<uint8_t>::max() * 18);
    wze::renderer::set_background_color_g(
        _color / std::numeric_limits<uint8_t>::max() * 18);
    wze::renderer::set_background_color_b(
        _color / std::numeric_limits<uint8_t>::max() * 38);
    wze::renderer::set_plane_color_r(_color);
    wze::renderer::set_plane_color_g(_color);
    wze::renderer::set_plane_color_b(_color);

    return _color ? SCENE_TYPE_MENU : SCENE_TYPE_SHOP;
};

menu::menu()
    : _start_button(
          -865, 47, 0, 0, 550, 142, false, std::numeric_limits<uint8_t>::max(),
          {{-275, 71}, {-275, -71}, {275, -71}, {275, 71}},
          assets::button_none_texture(), assets::button_hovered_texture(),
          assets::button_hovered_texture(), "Játék", 0, 0, 0,
          assets::accept_sound(), assets::refuse_sound()),
      _restart_button(
          -865, 275, 0, 0, 550, 142, false, std::numeric_limits<uint8_t>::max(),
          {{-275, 71}, {-275, -71}, {275, -71}, {275, 71}},
          assets::button_none_texture(), assets::button_hovered_texture(),
          assets::button_hovered_texture(), "Alaphelyzet", 0, 0, 0,
          assets::accept_sound(), assets::refuse_sound()),
      _exit_button(
          -865, 503, 0, 0, 550, 142, false, std::numeric_limits<uint8_t>::max(),
          {{-275, 71}, {-275, -71}, {275, -71}, {275, 71}},
          assets::button_none_texture(), assets::button_hovered_texture(),
          assets::button_hovered_texture(), "Kilépés", 0, 0, 0,
          assets::accept_sound(), assets::refuse_sound()),
      _volume_decrease(895 - 89, -623 + 63, -1, 0, 25, 35, false,
                       std::numeric_limits<uint8_t>::max(),
                       {{-15, 15}, {-15, -15}, {15, -15}, {15, 15}},
                       assets::decrease_button(), assets::decrease_button(),
                       assets::decrease_button(), "", 0, 0, 0,
                       assets::accept_sound(), assets::refuse_sound()),
      _sens_decrease(1150 - 90, -623 + 63, -10, 0, 25, 35, false,
                     std::numeric_limits<uint8_t>::max(),
                     {{-15, 15}, {-15, -15}, {15, -15}, {15, 15}},
                     assets::decrease_button(), assets::decrease_button(),
                     assets::decrease_button(), "", 0, 0, 0,
                     assets::accept_sound(), assets::refuse_sound()),
      _volume_increase(895 + 91, -623 + 63, -1, 0, 25, 35, false,
                       std::numeric_limits<uint8_t>::max(),
                       {{-15, 15}, {-15, -15}, {15, -15}, {15, 15}},
                       assets::increase_button(), assets::increase_button(),
                       assets::increase_button(), "", 0, 0, 0,
                       assets::accept_sound(), assets::refuse_sound()),
      _sens_increase(1150 + 91, -623 + 63, -1, 0, 25, 35, false,
                     std::numeric_limits<uint8_t>::max(),
                     {{-15, 15}, {-15, -15}, {15, -15}, {15, 15}},
                     assets::increase_button(), assets::increase_button(),
                     assets::increase_button(), "", 0, 0, 0,
                     assets::accept_sound(), assets::refuse_sound()) {
    size_t i;
    std::shared_ptr<wze::image> image;

    wze::renderer::set_space_texture(assets::space_texture());

    _color = 0.2;
    wze::renderer::set_space_color_r(_color);
    wze::renderer::set_space_color_g(_color);
    wze::renderer::set_space_color_b(_color);
    wze::renderer::set_background_color_r(_color);
    wze::renderer::set_background_color_g(_color);
    wze::renderer::set_background_color_b(_color);

    for (i = 0; i != 500; ++i) {
        std::apply(
            [this](float x, float y, float z) -> void {
                float diameter;
                diameter = wze::math::random(4'000.f, 8'000.f);
                _asteroids.push_back(
                    {x, y, abs(z),
                     wze::math::to_radians(wze::math::random(0.f, 360.f)),
                     diameter, diameter, true,
                     wze::math::random<bool>(0.5)
                         ? assets::asteroids_pyrite_texture()
                         : assets::asteroids_wolframite_texture()});
            },
            sphere_coordinate(50'000, 300'000));
    }

    for (i = 0; i != 200; ++i) {
        std::apply(
            [this](float x, float y, float z) -> void {
                _particles.push_back(
                    {x, y, abs(z),
                     wze::math::to_radians(wze::math::random(0.f, 360.f)),
                     wze::math::random(50.f, 100.f),
                     wze::math::random(50.f, 100.f), true,
                     assets::placeholder_texture()});
            },
            sphere_coordinate(10'000, 100'000));
    }

    _background_texture = {0,
                           0,
                           wze::camera::focus(),
                           0,
                           (float)wze::window::width(),
                           (float)wze::window::height(),
                           false,
                           assets::main_menu_background_texture(),
                           std::numeric_limits<uint8_t>::max(),
                           std::numeric_limits<uint8_t>::max(),
                           std::numeric_limits<uint8_t>::max(),
                           std::numeric_limits<uint8_t>::max(),
                           wze::FLIP_NONE,
                           true,
                           1};

    _player_sprite = {
        -55, 459, 0,     0,
        230, 230, false, assets::player_front_idle_animation().at(0)};

    image = wze::assets::create_image("STELLARION", assets::title_font());
    _title = {-475,
              -477,
              0,
              0,
              (float)image->w / (float)image->h * 175,
              175,
              false,
              wze::assets::create_texture(image)};

    _made_by_sprite = {-1058,
                       685,
                       0,
                       0,
                       163,
                       22,
                       false,
                       wze::assets::create_texture(wze::assets::create_image(
                           "Készítette:", assets::normal_font())),
                       0,
                       0,
                       0};
    _doman_sprite = {
        -556,
        685,
        0,
        0,
        164,
        22,
        false,
        wze::assets::create_texture(
            wze::assets::create_image("Zana Domán", assets::normal_font())),
        0,
        0,
        0,
    };
    _roland_sprite = {-54,
                      685,
                      0,
                      0,
                      164,
                      22,
                      false,
                      wze::assets::create_texture(wze::assets::create_image(
                          "Gunics Roland", assets::normal_font())),
                      0,
                      0,
                      0};
    _franck_sprite = {448,
                      685,
                      0,
                      0,
                      164,
                      22,
                      false,
                      wze::assets::create_texture(wze::assets::create_image(
                          "Furik Franck", assets::normal_font())),
                      0,
                      0,
                      0};
    _lili_sprite = {950,
                    685,
                    0,
                    0,
                    164,
                    22,
                    false,
                    wze::assets::create_texture(wze::assets::create_image(
                        "Polacsek Lili", assets::normal_font())),
                    0,
                    0,
                    0};

    _volume_sprite = {895, -623, 0,     0,
                      205, 160,  false, assets::sound_button_texture()};
    _mouse_sens_sprite = {
        1150, -623, 0, 0, 205, 160, false, assets::mouse_sens_button_texture()};

    _volume = save_data::volume_setting();
    wze::audio::set_volume(_volume);
    _mouse_sens = save_data::mouse_sensitivity();
    wze::input::set_mouse_sensitivity(_mouse_sens);

    image = wze::assets::create_image(
        std::to_string((save_data::volume_setting())), assets::normal_font());
    _volume_value = {895,
                     -623 + 65,
                     0,
                     0,
                     (float)image->w / (float)image->h * 25,
                     25,
                     false,
                     wze::assets::create_texture(image)};
    image = wze::assets::create_image(
        std::to_string((save_data::mouse_sensitivity())),
        assets::normal_font());
    _sens_value = {1150,
                   -623 + 65,
                   0,
                   0,
                   (float)image->w / (float)image->h * 25,
                   25,
                   false,
                   wze::assets::create_texture(image)};

    _door = std::shared_ptr<wze::sprite>(new wze::sprite(
        0, 0, wze::camera::focus(), 0, 2560, 1440, false,
        assets::main_menu_door_animation().front(),
        std::numeric_limits<uint8_t>::max(),
        std::numeric_limits<uint8_t>::max(),
        std::numeric_limits<uint8_t>::max(),
        std::numeric_limits<uint8_t>::max(), wze::FLIP_NONE, true, 0));
    _door_animation = {assets::main_menu_door_animation(), 105, {_door}};
    _door_animating = false;
    _door_open = false;
    _door_sound = {assets::door_sound(),
                   std::numeric_limits<int8_t>::max(),
                   1500,
                   false,
                   0,
                   0};
}

menu::~menu() {
    wze::renderer::set_space_texture({});
    wze::renderer::set_background_color_r(0);
    wze::renderer::set_background_color_g(0);
    wze::renderer::set_background_color_b(0);
    wze::renderer::set_space_color_r(std::numeric_limits<uint8_t>::max());
    wze::renderer::set_space_color_g(std::numeric_limits<uint8_t>::max());
    wze::renderer::set_space_color_b(std::numeric_limits<uint8_t>::max());
    wze::renderer::set_plane_color_r(std::numeric_limits<uint8_t>::max());
    wze::renderer::set_plane_color_g(std::numeric_limits<uint8_t>::max());
    wze::renderer::set_plane_color_b(std::numeric_limits<uint8_t>::max());
}

scene_type menu::update() {
    // std::cout << wze::input::cursor_absolute_x() << std::endl;
    std::cout << _volume << std::endl;
    std::cout << _mouse_sens << std::endl;

    std::shared_ptr<wze::image> image;

    scene_type door;
    bool quit = false;

    update_space();
    _start_button.update();
    if (_start_button.state() & BUTTON_STATE_POSTCLICK) {
        _player_sprite.set_x(1050);
        _restart_button.set_enabled(false);
        _exit_button.set_enabled(false);
    }

    _restart_button.update();
    if (_restart_button.state() & BUTTON_STATE_POSTCLICK) {
        save_data::reset();
        _volume = save_data::volume_setting();
        wze::audio::set_volume(_volume);
        _mouse_sens = save_data::mouse_sensitivity();
        wze::input::set_mouse_sensitivity(_mouse_sens);
    }

    _exit_button.update();
    if (_exit_button.state() & BUTTON_STATE_POSTCLICK) {
        quit = true;
    }

    image = wze::assets::create_image(
        std::to_string((uint8_t)roundf(
            _volume / std::numeric_limits<int8_t>::max() * 100)) +
            '%',
        assets::normal_font());
    _volume_value.set_width((float)image->w / (float)image->h * 25);
    _volume_value.set_texture(wze::assets::create_texture(image));

    image = wze::assets::create_image(
        std::to_string((uint8_t)(_mouse_sens * 100)) + '%',
        assets::normal_font());
    _sens_value.set_width((float)image->w / (float)image->h * 25);
    _sens_value.set_texture(wze::assets::create_texture(image));

    _volume_decrease.update();
    if (_volume_decrease.state() & BUTTON_STATE_POSTCLICK) {
        _volume = std::max(_volume - 12.7f, 0.f);
        save_data::set_volume_setting(roundf(_volume));
        wze::audio::set_volume(roundf(_volume));
    }
    _volume_decrease.set_enabled(0 < _volume);

    _volume_increase.update();
    if (_volume_increase.state() & BUTTON_STATE_POSTCLICK &&
        _volume < std::numeric_limits<int8_t>::max()) {
        _volume = std::min(_volume + 12.7f,
                           (float)std::numeric_limits<int8_t>::max());
        save_data::set_volume_setting(roundf(_volume));
        wze::audio::set_volume(roundf(_volume));
    }
    _volume_increase.set_enabled(_volume < std::numeric_limits<int8_t>::max());

    _sens_decrease.update();
    if (_sens_decrease.state() & BUTTON_STATE_POSTCLICK) {
        _mouse_sens = std::max(_mouse_sens - 0.1f, 0.1f);
        save_data::set_mouse_sensitivity(_mouse_sens);
        wze::input::set_mouse_sensitivity(_mouse_sens);
    }
    _sens_decrease.set_enabled(0.1f < _mouse_sens);

    _sens_increase.update();
    if (_sens_increase.state() & BUTTON_STATE_POSTCLICK) {
        _mouse_sens = std::min(_mouse_sens + 0.1f, 2.f);
        save_data::set_mouse_sensitivity(_mouse_sens);
        wze::input::set_mouse_sensitivity(_mouse_sens);
    }
    _sens_increase.set_enabled(_mouse_sens < 2);

    door = update_door();
    if (quit) {
        return SCENE_TYPE_QUIT;
    }
    return door;
}
