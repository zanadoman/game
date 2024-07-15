#include <game/assets.hpp>

std::shared_ptr<wze::texture> assets::_placeholder_texture;
std::shared_ptr<wze::texture> assets::_laser_texture;
std::shared_ptr<wze::texture> assets::_player_ship_texture;
std::shared_ptr<wze::texture> assets::_space_texture;

std::vector<std::shared_ptr<wze::texture>> assets::_asteroids_pyrite_texture;
std::vector<std::shared_ptr<wze::texture>> assets::_asteroids_wolframite_texture;
std::vector<std::shared_ptr<wze::texture>> assets::_asteroids_carneol_texture;
std::vector<std::shared_ptr<wze::texture>> assets::_asteroids_moldavite_texture;
std::vector<std::shared_ptr<wze::texture>> assets::_asteroids_ruby_texture;
std::vector<std::shared_ptr<wze::texture>> assets::_asteroids_sapphire_texture;

std::vector<std::shared_ptr<wze::texture>> assets::_asteroids_wolframite_explosion_animation;

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
    return _asteroids_pyrite_texture.at(wze::math::random(
        (int64_t)0, (int64_t)_asteroids_pyrite_texture.size() - 1));
}

std::shared_ptr<wze::texture> const& assets::asteroids_wolframite_texture() {
    return _asteroids_wolframite_texture.at(wze::math::random(
        (int64_t)0, (int64_t)_asteroids_wolframite_texture.size() - 1));
}

std::shared_ptr<wze::texture> const& assets::asteroids_carneol_texture() {
    return _asteroids_carneol_texture.at(wze::math::random(
        (int64_t)0, (int64_t)_asteroids_carneol_texture.size() - 1));
}

std::shared_ptr<wze::texture> const& assets::asteroids_moldavite_texture() {
    return _asteroids_moldavite_texture.at(wze::math::random(
        (int64_t)0, (int64_t)_asteroids_moldavite_texture.size() - 1));
}

std::shared_ptr<wze::texture> const& assets::asteroids_ruby_texture() {
    return _asteroids_ruby_texture.at(wze::math::random(
        (int64_t)0, (int64_t)_asteroids_ruby_texture.size() - 1));
}

std::shared_ptr<wze::texture> const& assets::asteroids_sapphire_texture() {
    return _asteroids_sapphire_texture.at(wze::math::random(
        (int64_t)0, (int64_t)_asteroids_sapphire_texture.size() - 1));
}

std::vector<std::shared_ptr<wze::texture>> const&
assets::asteroids_wolframite_explosion_animation() {
    return _asteroids_wolframite_explosion_animation;
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

    _asteroids_pyrite_texture = {
        wze::assets::create_texture(
            wze::assets::load_image("./assets/asteroids/pyrite/1.png")),
        wze::assets::create_texture(
            wze::assets::load_image("./assets/asteroids/pyrite/2.png")),
        wze::assets::create_texture(
            wze::assets::load_image("./assets/asteroids/pyrite/3.png"))};

    _asteroids_wolframite_texture = {
        wze::assets::create_texture(
            wze::assets::load_image("./assets/asteroids/wolframite/1.png")),
        wze::assets::create_texture(
            wze::assets::load_image("./assets/asteroids/wolframite/2.png")),
        wze::assets::create_texture(
            wze::assets::load_image("./assets/asteroids/wolframite/3.png"))};

    _asteroids_carneol_texture = {
        wze::assets::create_texture(
            wze::assets::load_image("./assets/asteroids/carneol/1.png")),
        wze::assets::create_texture(
            wze::assets::load_image("./assets/asteroids/carneol/2.png")),
        wze::assets::create_texture(
            wze::assets::load_image("./assets/asteroids/carneol/3.png"))};

    _asteroids_moldavite_texture = {
        wze::assets::create_texture(
            wze::assets::load_image("./assets/asteroids/moldavite/1.png")),
        wze::assets::create_texture(
            wze::assets::load_image("./assets/asteroids/moldavite/2.png")),
        wze::assets::create_texture(
            wze::assets::load_image("./assets/asteroids/moldavite/3.png"))};

    _asteroids_ruby_texture = {
        wze::assets::create_texture(
            wze::assets::load_image("./assets/asteroids/ruby/1.png")),
        wze::assets::create_texture(
            wze::assets::load_image("./assets/asteroids/ruby/2.png")),
        wze::assets::create_texture(
            wze::assets::load_image("./assets/asteroids/ruby/3.png"))};

    _asteroids_sapphire_texture = {
        wze::assets::create_texture(
            wze::assets::load_image("./assets/asteroids/sapphire/1.png")),
        wze::assets::create_texture(
            wze::assets::load_image("./assets/asteroids/sapphire/2.png")),
        wze::assets::create_texture(
            wze::assets::load_image("./assets/asteroids/sapphire/3.png"))};

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
}
