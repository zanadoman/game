#include <game/assets.hpp>
#include <game/hangar.hpp>
#include <game/menu.hpp>
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
    bool run = true;

    assets::initialize();
    save_data::load();

    // wze::timer::set_frame_time(50);

    scene = std::unique_ptr<class scene>(new menu);
    current_scene = SCENE_TYPE_MENU;

    wze_while(run) {
        wze::timer::set_delta_time(std::min(16.f, wze::timer::delta_time()));
        next_scene = scene->update();
        if (current_scene != next_scene) {
            switch (next_scene) {
            case SCENE_TYPE_SHOP:
                scene.reset();
                if (current_scene == SCENE_TYPE_MENU) {
                    scene.reset(new shop(-1615, -397.5));
                } else {
                    scene.reset(new shop(1615, -397.5));
                }
                break;
            case SCENE_TYPE_SPACE:
                scene.reset();
                scene.reset(new space);
                break;
            case SCENE_TYPE_HANGAR:
                scene.reset();
                if (current_scene == SCENE_TYPE_SHOP) {
                    scene.reset(new hangar(-3637.5, -705));
                } else {
                    scene.reset(new hangar(800, 200));
                }
                break;
            case SCENE_TYPE_MENU:
                scene.reset();
                scene.reset(new menu);
                break;
            case SCENE_TYPE_QUIT:
                scene.reset();
                run = false;
                break;
            }
            current_scene = next_scene;
        }
        std::cout << wze::timer::delta_time() << std::endl;
    };

    save_data::save();

    return 0;
}
