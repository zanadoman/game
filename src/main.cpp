#include <game/assets.hpp>
#include <game/hangar.hpp>
#include <game/save_data.hpp>
#include <game/scene.hpp>
#include <game/shop.hpp>
#include <game/space.hpp>
#include <iostream>
#include <wizard_engine/wizard_engine.hpp>

wze_main(2560, 1440) {
    std::unique_ptr<scene> scene;
    scene_type current_scene;
    scene_type next_scene;

    assets::initialize();
    save_data::load();

    // wze::timer::set_frame_time(50);
    wze::audio::set_volume(std::numeric_limits<int8_t>::max() / 2);

    scene = std::unique_ptr<class scene>(new shop);
    current_scene = SCENE_TYPE_SHOP;

    wze_while(true) {
        next_scene = scene->update();
        if (current_scene != next_scene) {
            switch (current_scene = next_scene) {
            case SCENE_TYPE_SHOP:
                scene.reset();
                scene.reset(new shop);
                break;
            case SCENE_TYPE_SPACE:
                scene.reset();
                scene.reset(new space);
                break;
            case SCENE_TYPE_HANGAR:
                scene.reset();
                scene.reset(new hangar);
                break;
            }
        }
        std::cout << wze::timer::delta_time() << std::endl;
    };

    save_data::save();

    return 0;
}
