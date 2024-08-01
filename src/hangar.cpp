#include <game/assets.hpp>
#include <game/save_data.hpp>
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
    return {20'000 + x * radius, y * radius, z * radius};
}

void hangar::update_space() {
    for (wze::sprite& asteroid : _asteroids) {
        asteroid.set_x(asteroid.x() + wze::timer::delta_time());
        if (170'000 < asteroid.x()) {
            asteroid.set_x(-130'000);
        }
    }
    for (wze::sprite& particle : _particles) {
        particle.set_x(particle.x() + wze::timer::delta_time());
        if (110'000 < particle.x()) {
            particle.set_x(-90'000);
        }
    }
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

    if (_door_open && !_door_animating && (_door_proxy = distance <= 150)) {
        if (_color != 0) {
            _color = std::max(0.f, _color - 0.2f * wze::timer::delta_time());
        }
    } else if (!_ship_proxy) {
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

scene_type hangar::update_ship() {
    _ship_proxy =
        wze::math::length(_player.x() - 1592.5f, _player.y() - 252.5f) <= 500;

    if (_ship_proxy) {
        if (_color != 0) {
            _color = std::max(0.f, _color - 0.2f * wze::timer::delta_time());
        }
    } else if (!_door_proxy) {
        if (_color != std::numeric_limits<uint8_t>::max()) {
            _color = std::min(_color + 0.2f * wze::timer::delta_time(),
                              (float)std::numeric_limits<uint8_t>::max());
        }
    }
    wze::renderer::set_space_color_r(_color);
    wze::renderer::set_space_color_g(_color);
    wze::renderer::set_space_color_b(_color);

    return !_color ? SCENE_TYPE_SPACE : SCENE_TYPE_HANGAR;
}

void hangar::update_money() {
    std::shared_ptr<wze::image> image;

    image = wze::assets::create_image(std::to_string(save_data::player_money()),
                                      assets::bold_font());
    _money_count.set_width((float)image->w / (float)image->h * 92);
    _money_count.set_x(1180 - _money_count.width() / 2 - 75);
    _money_count.set_texture(wze::assets::create_texture(image));
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
                   assets::hangar_background_texture(),
                   std::numeric_limits<uint8_t>::max(),
                   std::numeric_limits<uint8_t>::max(),
                   std::numeric_limits<uint8_t>::max(),
                   std::numeric_limits<uint8_t>::max(),
                   wze::FLIP_NONE,
                   true,
                   1};
    _rail = {0,
             0,
             wze::camera::focus(),
             0,
             13'105,
             6'380,
             true,
             assets::hangar_rail_texture(),
             std::numeric_limits<uint8_t>::max(),
             std::numeric_limits<uint8_t>::max(),
             std::numeric_limits<uint8_t>::max(),
             std::numeric_limits<uint8_t>::max(),
             wze::FLIP_NONE,
             true};
    _ships = {0,
              0,
              wze::camera::focus(),
              0,
              13'105,
              6'380,
              true,
              assets::hangar_ships_texture(),
              std::numeric_limits<uint8_t>::max(),
              std::numeric_limits<uint8_t>::max(),
              std::numeric_limits<uint8_t>::max(),
              std::numeric_limits<uint8_t>::max(),
              wze::FLIP_NONE,
              true,
              std::numeric_limits<uint8_t>::max() / 2 + 1};

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
    _hitbox1 = {{{{-982.5, 242},
                  {
                      -510,
                      -242,
                  },
                  {982.5, -242},
                  {510, 242}},
                 507.5,
                 -872},
                0,
                0,
                0};
    _hitbox2 = {{{{-982.5, 242},
                  {
                      -510,
                      -242,
                  },
                  {982.5, -242},
                  {510, 242}},
                 -787.5,
                 252.5},
                0,
                0,
                0};
    _hitbox3 = {{{{-982.5, 242},
                  {
                      -510,
                      -242,
                  },
                  {982.5, -242},
                  {510, 242}},
                 1592.5,
                 252.5},
                0,
                0,
                0};
    _hitbox4 = {{{{-982.5, 242},
                  {
                      -510,
                      -242,
                  },
                  {982.5, -242},
                  {510, 242}},
                 -2082.5,
                 1377.5},
                0,
                0,
                0};
    _hitbox5 = {{{{-982.5, 242},
                  {
                      -510,
                      -242,
                  },
                  {982.5, -242},
                  {510, 242}},
                 297.5,
                 1377.5},
                0,
                0,
                0};
    _hitbox6 = {{{{-982.5, 242},
                  {
                      -510,
                      -242,
                  },
                  {982.5, -242},
                  {510, 242}},
                 2790,
                 1377.5},
                0,
                0,
                0};

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
    _door_proxy = false;
    _door_sound = {assets::door_sound(),
                   std::numeric_limits<int8_t>::max(),
                   1500,
                   true,
                   -3837.5,
                   -705};

    _ship_proxy = false;

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

    _money = {1180, -620, 0, 0, 100, 100, false, assets::stellar_token()};
    _money_count = {0, -620, 0, 0, 0, 92, false, {}};
}

hangar::~hangar() {
    wze::renderer::set_space_texture({});
    wze::renderer::set_space_color_r(std::numeric_limits<uint8_t>::max());
    wze::renderer::set_space_color_g(std::numeric_limits<uint8_t>::max());
    wze::renderer::set_space_color_b(std::numeric_limits<uint8_t>::max());
}

scene_type hangar::update() {
    scene_type door;
    scene_type ship;

    _player.update();

    if (_player.y() < -475) {
        _rail.set_priority(std::numeric_limits<uint8_t>::max() / 2 + 1);
    } else {
        _rail.set_priority(std::numeric_limits<uint8_t>::max() / 2 - 1);
    }

    update_space();
    update_money();

    door = update_door();
    if (_door_proxy) {
        return door;
    }

    ship = update_ship();
    if (_ship_proxy) {
        return ship;
    }

    return SCENE_TYPE_HANGAR;
}
