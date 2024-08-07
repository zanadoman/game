#include <game/assets.hpp>
#include <game/menu.hpp>

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

    _color = std::min(_color + 0.2f * wze::timer::delta_time(),
                      (float)std::numeric_limits<uint8_t>::max());

    wze::renderer::set_space_color_r(_color);
    wze::renderer::set_space_color_g(_color);
    wze::renderer::set_space_color_b(_color);
    wze::renderer::set_background_color_r(
        _color / std::numeric_limits<uint8_t>::max() * 18);
    wze::renderer::set_background_color_g(
        _color / std::numeric_limits<uint8_t>::max() * 18);
    wze::renderer::set_background_color_b(
        _color / std::numeric_limits<uint8_t>::max() * 38);
}

scene_type menu::update_door() {
    float distance;

    distance = wze::math::length(_player_sprite.x() - 1815,
                                 _player_sprite.y() + 397.5f);
    if (!_door_animating && (distance <= 500) != _door_open) {
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

    _door_proxy = distance <= 150;
    if (_door_open && !_door_animating && _door_proxy) {
        if (_color != 0) {
            _color = std::max(0.f, _color - 0.2f * wze::timer::delta_time());
        }
    } else if (!_door_proxy) {
        if (_color != std::numeric_limits<uint8_t>::max()) {
            _color = std::min(_color + 0.2f * wze::timer::delta_time(),
                              (float)std::numeric_limits<uint8_t>::max());
        }
    }

    return !_color ? SCENE_TYPE_MENU : SCENE_TYPE_SHOP;
};

menu::menu()
    : _start_button(
          -865, 47, 0, 0, 550, 142, false, std::numeric_limits<uint8_t>::max(),
          {{-275, 71}, {-275, -71}, {275, -71}, {275, 71}},
          assets::button_none_texture(), assets::button_hovered_texture(),
          assets::button_hovered_texture(), "Játék", 0, 0, 0, {}, {}),
      _restart_button(
          -865, 275, 0, 0, 550, 142, false, std::numeric_limits<uint8_t>::max(),
          {{-275, 71}, {-275, -71}, {275, -71}, {275, 71}},
          assets::button_none_texture(), assets::button_hovered_texture(),
          assets::button_hovered_texture(), "Alaphelyzet", 0, 0, 0, {}, {}),
      _exit_button(
          -865, 503, 0, 0, 550, 142, false, std::numeric_limits<uint8_t>::max(),
          {{-275, 71}, {-275, -71}, {275, -71}, {275, 71}},
          assets::button_none_texture(), assets::button_hovered_texture(),
          assets::button_hovered_texture(), "Kilépés", 0, 0, 0, {}, {}),
      _volume_button(1074, -643, 0, 0, 85, 67, false,
                     std::numeric_limits<uint8_t>::max(), {{}, {}, {}, {}},
                     assets::sound_button_texture(),
                     assets::sound_button_texture(),
                     assets::sound_button_texture(), "", 0, 0, 0, {}, {}),
      _mouse_sens_button(
          1202, -643, 0, 0, 85, 67, false, std::numeric_limits<uint8_t>::max(),
          {{}, {}, {}, {}}, assets::mouse_sens_button_texture(),
          assets::mouse_sens_button_texture(),
          assets::mouse_sens_button_texture(), "", 0, 0, 0, {}, {}) {
    size_t i;

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
                    {x, y, abs(z), 0, diameter, diameter, true,
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
                           0,
                           0,
                           (float)wze::window::width(),
                           (float)wze::window::height(),
                           false,
                           assets::main_menu_background_texture()};

    _player_sprite = {
        -55,   248,   0,     0,
        180.5, 180.5, false, assets::player_front_idle_animation().at(0)};

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
    _doman_sprite = {-556,
                     685,
                     0,
                     0,
                     164,
                     22,
                     false,
                     wze::assets::create_texture(wze::assets::create_image(
                         "Zana Domán", assets::normal_font())),
                     0,
                     0,
                     0};
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
                          "Kiruf Franck", assets::normal_font())),
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

    _door = std::shared_ptr<wze::sprite>(
        new wze::sprite(0, 0, wze::camera::focus(), 0, 2560, 1440, false,
                        assets::main_menu_door_animation().front()));
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
}

scene_type menu::update() {
    scene_type door;
    bool quit = false;

    update_space();
    _start_button.update();

    _restart_button.update();

    _exit_button.update();
    if (_exit_button.state() & BUTTON_STATE_POSTCLICK) {
        quit = true;
    }

    _volume_button.update();
    _mouse_sens_button.update();

    door = update_door();
    if (_door_proxy)
        return door;
    if (quit) {
        return SCENE_TYPE_QUIT;
    }

    return SCENE_TYPE_MENU;
}
