#include <game/assets.hpp>
#include <game/button.hpp>
#include <game/laser.hpp>
#include <game/player_ship.hpp>
#include <game/updateable.hpp>
#include <wizard_engine/wizard_engine.hpp>

wze_main(2560, 1440) {
    player_ship player_ship;
    std::vector<wze::sprite> asteroids;

    for (size_t i = 0; i != 10000; ++i) {
        asteroids.push_back({(float)wze::math::random(-10000, 10000),
                             (float)wze::math::random(-10000, 10000),
                             (float)wze::math::random(-10000, 10000),
                             (float)wze::math::random(0, 360),
                             (float)wze::math::random(50, 200),
                             (float)wze::math::random(50, 200), true,
                             assets::asteroid_texture()});
    }

    wze_while(true) {
        player_ship.update();
    };

    return 0;
}
