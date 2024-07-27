#include <game/assets.hpp>
#include <game/hangar.hpp>

std::tuple<float, float, float> hangar::sphere_coordinate(float minimum,
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
    return {x * radius, y * radius, z * radius};
}

scene_type hangar::update_door() {
    float distance;

    distance = wze::math::length(_player.x() + 3837.5f, _player.y() + 705);

    if (!_door_animating && (distance <= 500) != _door_open) {
        _door_animating = true;
        _door_sound.play();
        // if (!_door_animation.reversed()) {
        //     _door_light.set_color_r(137);
        //     _door_light.set_color_g(221);
        //     _door_light.set_color_b(70);
        // } else {
        //     _door_light.set_color_r(228);
        //     _door_light.set_color_g(44);
        //     _door_light.set_color_b(56);
        // }
    }

    if (_door_animating && _door_animation.play()) {
        _door->set_texture(_door_animation.frames().back());
        _door_animation.reverse();
        _door_animation.reset();
        _door_open = !_door_open;
        _door_animating = false;
    }

    if (_door_open && !_door_animating && distance <= 150) {
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

    return !_color ? SCENE_TYPE_SHOP : SCENE_TYPE_HANGAR;
}

hangar::hangar() : _player(-3637.5, -705) {
    size_t i;

    wze::renderer::set_space_texture(assets::space_texture());

    _color = 0.2;
    wze::renderer::set_space_color_r(_color);
    wze::renderer::set_space_color_g(_color);
    wze::renderer::set_space_color_b(_color);

    _background = {0,
                   0,
                   wze::camera::focus(),
                   0,
                   13'105,
                   6'380,
                   true,
                   assets::hangar_background_texture()};

    _top_hitbox = {
        {{{-850, 100}, {-850, 0}, {850, 0}, {850, 100}}, 447.5, -1850},
        0,
        0,
        0};
    _bottom_hitbox = {
        {{{-4097.5, 0}, {-4097.5, -100}, {4097.5, -100}, {4097.5, 0}},
         570,
         2595},
        0,
        0,
        0};
    _left_hitbox = {{{{0, 0}, {390, 0}, {0, 390}}, -4037.5, -880}, 0, 0, 0};
    _right_hitbox = {
        {{{-100, 120}, {-100, -120}, {0, -120}, {0, 120}}, 5087.5, 2055},
        0,
        0,
        0};
    _top_right_hitbox = {
        {{{-3690, 0}, {0, 0}, {0, 3685}}, 4987.5, -1750}, 0, 0, 0};
    _bottom_left_hitbox = {
        {{{0, 0}, {0, -560}, {555, 0}}, -4082.5, 2495}, 0, 0, 0};
    _bottom_right_hitbox = {
        {{{-320, 0}, {0, -320}, {0, 0}}, 4987.5, 2495}, 0, 0, 0};
    _boss_hitbox = {
        {{{-870, 870}, {0, 0}, {2375, 0}, {1510, 870}}, -2775, -1750}, 0, 0, 0};
    _ornament_hitbox = {
        {{{0, 0}, {2375, 0}, {0, 2425}}, -4037.5, -490}, 0, 0, 0};

    _door = std::shared_ptr<wze::sprite>(new wze::sprite(
        0, 0, wze::camera::focus(), 0, 13'105, 6'380, true,
        assets::hangar_door_animation().back(),
        std::numeric_limits<uint8_t>::max(),
        std::numeric_limits<uint8_t>::max(),
        std::numeric_limits<uint8_t>::max(),
        std::numeric_limits<uint8_t>::max(), wze::FLIP_NONE, true, 0));
    _door_animation = {assets::hangar_door_animation(), 100, {_door}};
    _door_animation.reverse();
    _door_animating = false;
    _door_open = true;
    _door_sound = {assets::door_sound(),
                   std::numeric_limits<int8_t>::max(),
                   1500,
                   true,
                   -3837.5,
                   -705};

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
}

hangar::~hangar() {
    wze::renderer::set_space_texture({});
    wze::renderer::set_space_color_r(std::numeric_limits<uint8_t>::max());
    wze::renderer::set_space_color_g(std::numeric_limits<uint8_t>::max());
    wze::renderer::set_space_color_b(std::numeric_limits<uint8_t>::max());
}

scene_type hangar::update() {
    _player.update();
    return update_door();
}
