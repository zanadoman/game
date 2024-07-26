#include <game/assets.hpp>
#include <game/hangar.hpp>

hangar::hangar() {
    wze::renderer::set_space_texture(assets::space_texture());

    _background = {0,
                   0,
                   wze::camera::focus(),
                   0,
                   14'215,
                   6'380,
                   true,
                   assets::hangar_background_texture()};

    _top = {{{{-2038.75, 100}, {-2038.75, 0}, {2038.75, 0}, {2038.75, 100}},
             -740,
             -1850}, 0, 0, 0};
}

hangar::~hangar() {
    wze::renderer::set_space_texture({});
}

scene_type hangar::update() {
    _player.update();
    return SCENE_TYPE_HANGAR;
}
