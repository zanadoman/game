#include <game/assets.hpp>

std::shared_ptr<wze::texture> const& assets::placeholder_texture() {
    static auto asset = wze::assets::create_texture(
        wze::assets::load_image("./assets/placeholder.png"));
    return asset;
}

std::shared_ptr<wze::texture> const& assets::laser_texture() {
    static auto asset = wze::assets::create_texture(
        wze::assets::load_image("./assets/laser.png"));
    return asset;
}

std::shared_ptr<wze::texture> const& assets::player_ship_texture() {
    static auto asset = wze::assets::create_texture(
        wze::assets::load_image("./assets/player_ship.png"));
    return asset;
}

std::shared_ptr<wze::texture> const& assets::space_texture() {
    static auto asset = wze::assets::create_texture(
        wze::assets::load_image("./assets/space.png"));
    return asset;
}

std::shared_ptr<wze::texture> const& assets::asteroids_pyrite_texture() {
    static std::vector<std::shared_ptr<wze::texture>> asteroids_pyrite_texture =
        {wze::assets::create_texture(
             wze::assets::load_image("./assets/asteroids/pyrite/1.png")),
         wze::assets::create_texture(
             wze::assets::load_image("./assets/asteroids/pyrite/2.png")),
         wze::assets::create_texture(
             wze::assets::load_image("./assets/asteroids/pyrite/3.png"))};
    return asteroids_pyrite_texture.at(wze::math::random(
        (int64_t)0, (int64_t)asteroids_pyrite_texture.size() - 1));
}

std::shared_ptr<wze::texture> const& assets::asteroids_wolframite_texture() {
    static std::vector<std::shared_ptr<wze::texture>>
        asteroids_wolframite_texture = {
            wze::assets::create_texture(
                wze::assets::load_image("./assets/asteroids/wolframite/1.png")),
            wze::assets::create_texture(
                wze::assets::load_image("./assets/asteroids/wolframite/2.png")),
            wze::assets::create_texture(wze::assets::load_image(
                "./assets/asteroids/wolframite/3.png"))};
    return asteroids_wolframite_texture.at(wze::math::random(
        (int64_t)0, (int64_t)asteroids_wolframite_texture.size() - 1));
}

std::shared_ptr<wze::texture> const& assets::asteroids_carneol_texture() {
    static std::vector<std::shared_ptr<wze::texture>>
        asteroids_carneol_texture = {
            wze::assets::create_texture(
                wze::assets::load_image("./assets/asteroids/carneol/1.png")),
            wze::assets::create_texture(
                wze::assets::load_image("./assets/asteroids/carneol/2.png")),
            wze::assets::create_texture(
                wze::assets::load_image("./assets/asteroids/carneol/3.png"))};
    return asteroids_carneol_texture.at(wze::math::random(
        (int64_t)0, (int64_t)asteroids_carneol_texture.size() - 1));
}

std::shared_ptr<wze::texture> const& assets::asteroids_moldavite_texture() {
    static std::vector<std::shared_ptr<wze::texture>>
        asteroids_moldavite_texture = {
            wze::assets::create_texture(
                wze::assets::load_image("./assets/asteroids/moldavite/1.png")),
            wze::assets::create_texture(
                wze::assets::load_image("./assets/asteroids/moldavite/2.png")),
            wze::assets::create_texture(
                wze::assets::load_image("./assets/asteroids/moldavite/3.png"))};
    return asteroids_moldavite_texture.at(wze::math::random(
        (int64_t)0, (int64_t)asteroids_moldavite_texture.size() - 1));
}

std::shared_ptr<wze::texture> const& assets::asteroids_ruby_texture() {
    static std::vector<std::shared_ptr<wze::texture>> asteroids_ruby_texture = {
        wze::assets::create_texture(
            wze::assets::load_image("./assets/asteroids/ruby/1.png")),
        wze::assets::create_texture(
            wze::assets::load_image("./assets/asteroids/ruby/2.png")),
        wze::assets::create_texture(
            wze::assets::load_image("./assets/asteroids/ruby/3.png"))};
    return asteroids_ruby_texture.at(wze::math::random(
        (int64_t)0, (int64_t)asteroids_ruby_texture.size() - 1));
}

std::shared_ptr<wze::texture> const& assets::asteroids_sapphire_texture() {
    static std::vector<std::shared_ptr<wze::texture>>
        asteroids_sapphire_texture = {
            wze::assets::create_texture(
                wze::assets::load_image("./assets/asteroids/sapphire/1.png")),
            wze::assets::create_texture(
                wze::assets::load_image("./assets/asteroids/sapphire/2.png")),
            wze::assets::create_texture(
                wze::assets::load_image("./assets/asteroids/sapphire/3.png"))};
    return asteroids_sapphire_texture.at(wze::math::random(
        (int64_t)0, (int64_t)asteroids_sapphire_texture.size() - 1));
}

std::vector<std::shared_ptr<wze::texture>> const&
assets::asteroids_iron_explosion_animation() {
    static std::vector<std::shared_ptr<wze::texture>>
        asteroids_iron_explosion_animation = {
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
    return asteroids_iron_explosion_animation;
}
