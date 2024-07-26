#include <game/assets.hpp>
#include <game/hangar.hpp>

hangar::hangar() {
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
}

hangar::~hangar() {
    wze::renderer::set_space_texture({});
}

scene_type hangar::update() {
    _player.update();
    return SCENE_TYPE_HANGAR;
}
