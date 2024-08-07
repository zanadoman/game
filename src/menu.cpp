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

menu::menu()
    : _start_button(
          -865, 47, 0, 0, 550, 142, false, std::numeric_limits<uint8_t>::max(),
          {{-1139, 113}, {-1139, -27}, {-589, -27}, {-589, 113}},
          assets::button_none_texture(), assets::button_hovered_texture(),
          assets::button_hovered_texture(), "Játék", 0, 0, 0, {}, {}),
      _restart_button(
          -865, 275, 0, 0, 550, 142, false, std::numeric_limits<uint8_t>::max(),
          {{-1139, 347}, {-1139, 205}, {-589, 205}, {-589, 347}},
          assets::button_none_texture(), assets::button_hovered_texture(),
          assets::button_hovered_texture(), "Alaphelyzet", 0, 0, 0, {}, {}),
      _exit_button(
          -865, 503, 0, 0, 550, 142, false, std::numeric_limits<uint8_t>::max(),
          {{-1139, 575}, {-1139, 433}, {-589, 433}, {-589, 575}},
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
        200, -100, 0,     0,
        160, 160,  false, assets::player_front_idle_animation().at(0)};
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
    update_space();
    _start_button.update();
    _restart_button.update();
    _exit_button.update();
    _volume_button.update();
    _mouse_sens_button.update();

    return SCENE_TYPE_MENU;
}
