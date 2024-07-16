#include <game/assets.hpp>

std::shared_ptr<wze::texture> assets::_placeholder_texture;
std::shared_ptr<wze::texture> assets::_laser_texture;
std::shared_ptr<wze::texture> assets::_player_ship_texture;
std::shared_ptr<wze::texture> assets::_space_texture;

std::vector<std::shared_ptr<wze::texture>> assets::_asteroids_pyrite_textures;
std::vector<std::shared_ptr<wze::texture>>
    assets::_asteroids_wolframite_textures;
std::vector<std::shared_ptr<wze::texture>> assets::_asteroids_carneol_textures;
std::vector<std::shared_ptr<wze::texture>>
    assets::_asteroids_moldavite_textures;
std::vector<std::shared_ptr<wze::texture>> assets::_asteroids_ruby_textures;
std::vector<std::shared_ptr<wze::texture>> assets::_asteroids_sapphire_textures;

std::vector<std::shared_ptr<wze::texture>>
    assets::_asteroids_pyrite_explosion_animation;
std::vector<std::shared_ptr<wze::texture>>
    assets::_asteroids_wolframite_explosion_animation;
std::vector<std::shared_ptr<wze::texture>>
    assets::_asteroids_carneol_explosion_animation;
std::vector<std::shared_ptr<wze::texture>>
    assets::_asteroids_moldavite_explosion_animation;
std::vector<std::shared_ptr<wze::texture>>
    assets::_asteroids_ruby_explosion_animation;
std::vector<std::shared_ptr<wze::texture>>
    assets::_asteroids_sapphire_explosion_animation;

std::shared_ptr<wze::texture> assets::_enemy_rear_texture;
std::shared_ptr<wze::texture> assets::_enemy_rear_up_texture;
std::shared_ptr<wze::texture> assets::_enemy_rear_down_texture;
std::shared_ptr<wze::texture> assets::_enemy_rear_left_texture;
std::shared_ptr<wze::texture> assets::_enemy_rear_right_texture;
std::shared_ptr<wze::texture> assets::_enemy_front_texture;
std::shared_ptr<wze::texture> assets::_enemy_front_up_texture;
std::shared_ptr<wze::texture> assets::_enemy_front_down_texture;
std::shared_ptr<wze::texture> assets::_enemy_front_left_texture;
std::shared_ptr<wze::texture> assets::_enemy_front_right_texture;
std::shared_ptr<wze::texture> assets::_enemy_loop1_texture;
std::shared_ptr<wze::texture> assets::_enemy_loop2_texture;
std::shared_ptr<wze::texture> assets::_enemy_loop3_texture;

std::shared_ptr<wze::texture> const& assets::placeholder_texture() {
    return _placeholder_texture;
}

std::shared_ptr<wze::texture> const& assets::laser_texture() {
    return _laser_texture;
}

std::shared_ptr<wze::texture> const& assets::player_ship_texture() {
    return _player_ship_texture;
}

std::shared_ptr<wze::texture> const& assets::space_texture() {
    return _space_texture;
}

std::shared_ptr<wze::texture> const& assets::asteroids_pyrite_texture() {
    return _asteroids_pyrite_textures.at(
        wze::math::random<size_t>(0, _asteroids_pyrite_textures.size() - 1));
}

std::shared_ptr<wze::texture> const& assets::asteroids_wolframite_texture() {
    return _asteroids_wolframite_textures.at(wze::math::random<size_t>(
        0, _asteroids_wolframite_textures.size() - 1));
}

std::shared_ptr<wze::texture> const& assets::asteroids_carneol_texture() {
    return _asteroids_carneol_textures.at(
        wze::math::random<size_t>(0, _asteroids_carneol_textures.size() - 1));
}

std::shared_ptr<wze::texture> const& assets::asteroids_moldavite_texture() {
    return _asteroids_moldavite_textures.at(
        wze::math::random<size_t>(0, _asteroids_moldavite_textures.size() - 1));
}

std::shared_ptr<wze::texture> const& assets::asteroids_ruby_texture() {
    return _asteroids_ruby_textures.at(
        wze::math::random<size_t>(0, _asteroids_ruby_textures.size() - 1));
}

std::shared_ptr<wze::texture> const& assets::asteroids_sapphire_texture() {
    return _asteroids_sapphire_textures.at(
        wze::math::random<size_t>(0, _asteroids_sapphire_textures.size() - 1));
}

std::vector<std::shared_ptr<wze::texture>> const&
assets::asteroids_pyrite_explosion_animation() {
    return _asteroids_pyrite_explosion_animation;
}

std::vector<std::shared_ptr<wze::texture>> const&
assets::asteroids_wolframite_explosion_animation() {
    return _asteroids_wolframite_explosion_animation;
}

std::vector<std::shared_ptr<wze::texture>> const&
assets::asteroids_carneol_explosion_animation() {
    return _asteroids_carneol_explosion_animation;
}

std::vector<std::shared_ptr<wze::texture>> const&
assets::asteroids_moldavite_explosion_animation() {
    return _asteroids_moldavite_explosion_animation;
}

std::vector<std::shared_ptr<wze::texture>> const&
assets::asteroids_ruby_explosion_animation() {
    return _asteroids_ruby_explosion_animation;
}

std::vector<std::shared_ptr<wze::texture>> const&
assets::asteroids_sapphire_explosion_animation() {
    return _asteroids_sapphire_explosion_animation;
}

std::shared_ptr<wze::texture> assets::enemy_rear_texture() {
    return _enemy_rear_texture;
}

std::shared_ptr<wze::texture> assets::enemy_rear_up_texture() {
    return _enemy_rear_up_texture;
}

std::shared_ptr<wze::texture> assets::enemy_rear_down_texture() {
    return _enemy_rear_down_texture;
}

std::shared_ptr<wze::texture> assets::enemy_rear_left_texture() {
    return _enemy_rear_left_texture;
}

std::shared_ptr<wze::texture> assets::enemy_rear_right_texture() {
    return _enemy_rear_right_texture;
}

std::shared_ptr<wze::texture> assets::enemy_front_texture() {
    return _enemy_front_texture;
}

std::shared_ptr<wze::texture> assets::enemy_front_up_texture() {
    return _enemy_front_up_texture;
}

std::shared_ptr<wze::texture> assets::enemy_front_down_texture() {
    return _enemy_front_down_texture;
}

std::shared_ptr<wze::texture> assets::enemy_front_left_texture() {
    return _enemy_front_left_texture;
}

std::shared_ptr<wze::texture> assets::enemy_front_right_texture() {
    return _enemy_front_right_texture;
}

std::shared_ptr<wze::texture> assets::enemy_loop1_texture() {
    return _enemy_loop1_texture;
}

std::shared_ptr<wze::texture> assets::enemy_loop2_texture() {
    return _enemy_loop2_texture;
}

std::shared_ptr<wze::texture> assets::enemy_loop3_texture() {
    return _enemy_loop3_texture;
}

void assets::initialize() {
    _placeholder_texture = wze::assets::create_texture(
        wze::assets::load_image("./assets/placeholder.png"));

    _laser_texture = wze::assets::create_texture(
        wze::assets::load_image("./assets/laser.png"));

    _player_ship_texture = wze::assets::create_texture(
        wze::assets::load_image("./assets/player_ship.png"));

    _space_texture = wze::assets::create_texture(
        wze::assets::load_image("./assets/space.png"));

    _asteroids_pyrite_textures = {
        wze::assets::create_texture(
            wze::assets::load_image("./assets/asteroids/pyrite/1.png")),
        wze::assets::create_texture(
            wze::assets::load_image("./assets/asteroids/pyrite/2.png")),
        wze::assets::create_texture(
            wze::assets::load_image("./assets/asteroids/pyrite/3.png"))};

    _asteroids_wolframite_textures = {
        wze::assets::create_texture(
            wze::assets::load_image("./assets/asteroids/wolframite/1.png")),
        wze::assets::create_texture(
            wze::assets::load_image("./assets/asteroids/wolframite/2.png")),
        wze::assets::create_texture(
            wze::assets::load_image("./assets/asteroids/wolframite/3.png"))};

    _asteroids_carneol_textures = {
        wze::assets::create_texture(
            wze::assets::load_image("./assets/asteroids/carneol/1.png")),
        wze::assets::create_texture(
            wze::assets::load_image("./assets/asteroids/carneol/2.png")),
        wze::assets::create_texture(
            wze::assets::load_image("./assets/asteroids/carneol/3.png"))};

    _asteroids_moldavite_textures = {
        wze::assets::create_texture(
            wze::assets::load_image("./assets/asteroids/moldavite/1.png")),
        wze::assets::create_texture(
            wze::assets::load_image("./assets/asteroids/moldavite/2.png")),
        wze::assets::create_texture(
            wze::assets::load_image("./assets/asteroids/moldavite/3.png"))};

    _asteroids_ruby_textures = {
        wze::assets::create_texture(
            wze::assets::load_image("./assets/asteroids/ruby/1.png")),
        wze::assets::create_texture(
            wze::assets::load_image("./assets/asteroids/ruby/2.png")),
        wze::assets::create_texture(
            wze::assets::load_image("./assets/asteroids/ruby/3.png"))};

    _asteroids_sapphire_textures = {
        wze::assets::create_texture(
            wze::assets::load_image("./assets/asteroids/sapphire/1.png")),
        wze::assets::create_texture(
            wze::assets::load_image("./assets/asteroids/sapphire/2.png")),
        wze::assets::create_texture(
            wze::assets::load_image("./assets/asteroids/sapphire/3.png"))};

    _asteroids_pyrite_explosion_animation = {
        wze::assets::create_texture(wze::assets::load_image(
            "./assets/asteroids/pyrite/explosion/1.png")),
        wze::assets::create_texture(wze::assets::load_image(
            "./assets/asteroids/pyrite/explosion/2.png")),
        wze::assets::create_texture(wze::assets::load_image(
            "./assets/asteroids/pyrite/explosion/3.png")),
        wze::assets::create_texture(wze::assets::load_image(
            "./assets/asteroids/pyrite/explosion/4.png")),
        wze::assets::create_texture(wze::assets::load_image(
            "./assets/asteroids/pyrite/explosion/5.png")),
        wze::assets::create_texture(wze::assets::load_image(
            "./assets/asteroids/pyrite/explosion/6.png")),
        wze::assets::create_texture(wze::assets::load_image(
            "./assets/asteroids/pyrite/explosion/7.png")),
        wze::assets::create_texture(wze::assets::load_image(
            "./assets/asteroids/pyrite/explosion/8.png")),
        wze::assets::create_texture(wze::assets::load_image(
            "./assets/asteroids/pyrite/explosion/9.png")),
        wze::assets::create_texture(wze::assets::load_image(
            "./assets/asteroids/pyrite/explosion/10.png")),
        wze::assets::create_texture(wze::assets::load_image(
            "./assets/asteroids/pyrite/explosion/11.png")),
        wze::assets::create_texture(wze::assets::load_image(
            "./assets/asteroids/pyrite/explosion/12.png")),
        wze::assets::create_texture(wze::assets::load_image(
            "./assets/asteroids/pyrite/explosion/13.png")),
        wze::assets::create_texture(wze::assets::load_image(
            "./assets/asteroids/pyrite/explosion/14.png")),
        wze::assets::create_texture(wze::assets::load_image(
            "./assets/asteroids/pyrite/explosion/15.png"))};

    _asteroids_wolframite_explosion_animation = {
        wze::assets::create_texture(wze::assets::load_image(
            "./assets/asteroids/wolframite/explosion/1.png")),
        wze::assets::create_texture(wze::assets::load_image(
            "./assets/asteroids/wolframite/explosion/2.png")),
        wze::assets::create_texture(wze::assets::load_image(
            "./assets/asteroids/wolframite/explosion/3.png")),
        wze::assets::create_texture(wze::assets::load_image(
            "./assets/asteroids/wolframite/explosion/4.png")),
        wze::assets::create_texture(wze::assets::load_image(
            "./assets/asteroids/wolframite/explosion/5.png")),
        wze::assets::create_texture(wze::assets::load_image(
            "./assets/asteroids/wolframite/explosion/6.png")),
        wze::assets::create_texture(wze::assets::load_image(
            "./assets/asteroids/wolframite/explosion/7.png")),
        wze::assets::create_texture(wze::assets::load_image(
            "./assets/asteroids/wolframite/explosion/8.png")),
        wze::assets::create_texture(wze::assets::load_image(
            "./assets/asteroids/wolframite/explosion/9.png")),
        wze::assets::create_texture(wze::assets::load_image(
            "./assets/asteroids/wolframite/explosion/10.png")),
        wze::assets::create_texture(wze::assets::load_image(
            "./assets/asteroids/wolframite/explosion/11.png")),
        wze::assets::create_texture(wze::assets::load_image(
            "./assets/asteroids/wolframite/explosion/12.png")),
        wze::assets::create_texture(wze::assets::load_image(
            "./assets/asteroids/wolframite/explosion/13.png")),
        wze::assets::create_texture(wze::assets::load_image(
            "./assets/asteroids/wolframite/explosion/14.png")),
        wze::assets::create_texture(wze::assets::load_image(
            "./assets/asteroids/wolframite/explosion/15.png"))};

    _asteroids_carneol_explosion_animation = {
        wze::assets::create_texture(wze::assets::load_image(
            "./assets/asteroids/carneol/explosion/1.png")),
        wze::assets::create_texture(wze::assets::load_image(
            "./assets/asteroids/carneol/explosion/2.png")),
        wze::assets::create_texture(wze::assets::load_image(
            "./assets/asteroids/carneol/explosion/3.png")),
        wze::assets::create_texture(wze::assets::load_image(
            "./assets/asteroids/carneol/explosion/4.png")),
        wze::assets::create_texture(wze::assets::load_image(
            "./assets/asteroids/carneol/explosion/5.png")),
        wze::assets::create_texture(wze::assets::load_image(
            "./assets/asteroids/carneol/explosion/6.png")),
        wze::assets::create_texture(wze::assets::load_image(
            "./assets/asteroids/carneol/explosion/7.png")),
        wze::assets::create_texture(wze::assets::load_image(
            "./assets/asteroids/carneol/explosion/8.png")),
        wze::assets::create_texture(wze::assets::load_image(
            "./assets/asteroids/carneol/explosion/9.png")),
        wze::assets::create_texture(wze::assets::load_image(
            "./assets/asteroids/carneol/explosion/10.png")),
        wze::assets::create_texture(wze::assets::load_image(
            "./assets/asteroids/carneol/explosion/11.png")),
        wze::assets::create_texture(wze::assets::load_image(
            "./assets/asteroids/carneol/explosion/12.png")),
        wze::assets::create_texture(wze::assets::load_image(
            "./assets/asteroids/carneol/explosion/13.png")),
        wze::assets::create_texture(wze::assets::load_image(
            "./assets/asteroids/carneol/explosion/14.png")),
        wze::assets::create_texture(wze::assets::load_image(
            "./assets/asteroids/carneol/explosion/15.png"))};

    _asteroids_moldavite_explosion_animation = {
        wze::assets::create_texture(wze::assets::load_image(
            "./assets/asteroids/moldavite/explosion/1.png")),
        wze::assets::create_texture(wze::assets::load_image(
            "./assets/asteroids/moldavite/explosion/2.png")),
        wze::assets::create_texture(wze::assets::load_image(
            "./assets/asteroids/moldavite/explosion/3.png")),
        wze::assets::create_texture(wze::assets::load_image(
            "./assets/asteroids/moldavite/explosion/4.png")),
        wze::assets::create_texture(wze::assets::load_image(
            "./assets/asteroids/moldavite/explosion/5.png")),
        wze::assets::create_texture(wze::assets::load_image(
            "./assets/asteroids/moldavite/explosion/6.png")),
        wze::assets::create_texture(wze::assets::load_image(
            "./assets/asteroids/moldavite/explosion/7.png")),
        wze::assets::create_texture(wze::assets::load_image(
            "./assets/asteroids/moldavite/explosion/8.png")),
        wze::assets::create_texture(wze::assets::load_image(
            "./assets/asteroids/moldavite/explosion/9.png")),
        wze::assets::create_texture(wze::assets::load_image(
            "./assets/asteroids/moldavite/explosion/10.png")),
        wze::assets::create_texture(wze::assets::load_image(
            "./assets/asteroids/moldavite/explosion/11.png")),
        wze::assets::create_texture(wze::assets::load_image(
            "./assets/asteroids/moldavite/explosion/12.png")),
        wze::assets::create_texture(wze::assets::load_image(
            "./assets/asteroids/moldavite/explosion/13.png")),
        wze::assets::create_texture(wze::assets::load_image(
            "./assets/asteroids/moldavite/explosion/14.png")),
        wze::assets::create_texture(wze::assets::load_image(
            "./assets/asteroids/moldavite/explosion/15.png"))};

    _asteroids_ruby_explosion_animation = {
        wze::assets::create_texture(
            wze::assets::load_image("./assets/asteroids/ruby/explosion/1.png")),
        wze::assets::create_texture(
            wze::assets::load_image("./assets/asteroids/ruby/explosion/2.png")),
        wze::assets::create_texture(
            wze::assets::load_image("./assets/asteroids/ruby/explosion/3.png")),
        wze::assets::create_texture(
            wze::assets::load_image("./assets/asteroids/ruby/explosion/4.png")),
        wze::assets::create_texture(
            wze::assets::load_image("./assets/asteroids/ruby/explosion/5.png")),
        wze::assets::create_texture(
            wze::assets::load_image("./assets/asteroids/ruby/explosion/6.png")),
        wze::assets::create_texture(
            wze::assets::load_image("./assets/asteroids/ruby/explosion/7.png")),
        wze::assets::create_texture(
            wze::assets::load_image("./assets/asteroids/ruby/explosion/8.png")),
        wze::assets::create_texture(
            wze::assets::load_image("./assets/asteroids/ruby/explosion/9.png")),
        wze::assets::create_texture(wze::assets::load_image(
            "./assets/asteroids/ruby/explosion/10.png")),
        wze::assets::create_texture(wze::assets::load_image(
            "./assets/asteroids/ruby/explosion/11.png")),
        wze::assets::create_texture(wze::assets::load_image(
            "./assets/asteroids/ruby/explosion/12.png")),
        wze::assets::create_texture(wze::assets::load_image(
            "./assets/asteroids/ruby/explosion/13.png")),
        wze::assets::create_texture(wze::assets::load_image(
            "./assets/asteroids/ruby/explosion/14.png")),
        wze::assets::create_texture(wze::assets::load_image(
            "./assets/asteroids/ruby/explosion/15.png"))};

    _asteroids_sapphire_explosion_animation = {
        wze::assets::create_texture(wze::assets::load_image(
            "./assets/asteroids/sapphire/explosion/1.png")),
        wze::assets::create_texture(wze::assets::load_image(
            "./assets/asteroids/sapphire/explosion/2.png")),
        wze::assets::create_texture(wze::assets::load_image(
            "./assets/asteroids/sapphire/explosion/3.png")),
        wze::assets::create_texture(wze::assets::load_image(
            "./assets/asteroids/sapphire/explosion/4.png")),
        wze::assets::create_texture(wze::assets::load_image(
            "./assets/asteroids/sapphire/explosion/5.png")),
        wze::assets::create_texture(wze::assets::load_image(
            "./assets/asteroids/sapphire/explosion/6.png")),
        wze::assets::create_texture(wze::assets::load_image(
            "./assets/asteroids/sapphire/explosion/7.png")),
        wze::assets::create_texture(wze::assets::load_image(
            "./assets/asteroids/sapphire/explosion/8.png")),
        wze::assets::create_texture(wze::assets::load_image(
            "./assets/asteroids/sapphire/explosion/9.png")),
        wze::assets::create_texture(wze::assets::load_image(
            "./assets/asteroids/sapphire/explosion/10.png")),
        wze::assets::create_texture(wze::assets::load_image(
            "./assets/asteroids/sapphire/explosion/11.png")),
        wze::assets::create_texture(wze::assets::load_image(
            "./assets/asteroids/sapphire/explosion/12.png")),
        wze::assets::create_texture(wze::assets::load_image(
            "./assets/asteroids/sapphire/explosion/13.png")),
        wze::assets::create_texture(wze::assets::load_image(
            "./assets/asteroids/sapphire/explosion/14.png")),
        wze::assets::create_texture(wze::assets::load_image(
            "./assets/asteroids/sapphire/explosion/15.png"))};

    _enemy_rear_texture = wze::assets::create_texture(
        wze::assets::load_image("./assets/enemies/easy/rear.png"));
    _enemy_rear_up_texture = wze::assets::create_texture(
        wze::assets::load_image("./assets/enemies/easy/rear_up.png"));
    _enemy_rear_down_texture = wze::assets::create_texture(
        wze::assets::load_image("./assets/enemies/easy/rear_down.png"));
    _enemy_rear_left_texture = wze::assets::create_texture(
        wze::assets::load_image("./assets/enemies/easy/rear_left.png"));
    _enemy_rear_right_texture = wze::assets::create_texture(
        wze::assets::load_image("./assets/enemies/easy/rear_right.png"));
    _enemy_front_texture = wze::assets::create_texture(
        wze::assets::load_image("./assets/enemies/easy/front.png"));
    _enemy_front_up_texture = wze::assets::create_texture(
        wze::assets::load_image("./assets/enemies/easy/front_up.png"));
    _enemy_front_down_texture = wze::assets::create_texture(
        wze::assets::load_image("./assets/enemies/easy/front_down.png"));
    _enemy_front_left_texture = wze::assets::create_texture(
        wze::assets::load_image("./assets/enemies/easy/front_left.png"));
    _enemy_front_right_texture = wze::assets::create_texture(
        wze::assets::load_image("./assets/enemies/easy/front_right.png"));
    _enemy_loop1_texture = wze::assets::create_texture(
        wze::assets::load_image("./assets/enemies/easy/loop1.png"));
    _enemy_loop2_texture = wze::assets::create_texture(
        wze::assets::load_image("./assets/enemies/easy/loop2.png"));
    _enemy_loop3_texture = wze::assets::create_texture(
        wze::assets::load_image("./assets/enemies/easy/loop3.png"));
}
