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

hangar::hangar() {
    size_t i;

    wze::renderer::set_space_texture(assets::space_texture());

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
}

scene_type hangar::update() {
    _player.update();
    return SCENE_TYPE_HANGAR;
}
