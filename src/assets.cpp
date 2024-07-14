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

std::shared_ptr<wze::texture> const& assets::asteroids_iron_texture() {
    static std::vector<std::shared_ptr<wze::texture>> asteroids_iron_texture = {
        wze::assets::create_texture(
            wze::assets::load_image("./assets/asteroids/iron/1.png")),
        wze::assets::create_texture(
            wze::assets::load_image("./assets/asteroids/iron/2.png")),
        wze::assets::create_texture(
            wze::assets::load_image("./assets/asteroids/iron/3.png"))};
    return asteroids_iron_texture.at(wze::math::random(
        (int64_t)0, (int64_t)asteroids_iron_texture.size() - 1));
}

std::vector<std::shared_ptr<wze::texture>> const&
assets::asteroids_iron_explosion_animation() {
    static std::vector<std::shared_ptr<wze::texture>>
        asteroids_iron_explosion_animation = {
            wze::assets::create_texture(wze::assets::load_image(
                "./assets/asteroids/iron/explosion/1.png")),
            wze::assets::create_texture(wze::assets::load_image(
                "./assets/asteroids/iron/explosion/2.png")),
            wze::assets::create_texture(wze::assets::load_image(
                "./assets/asteroids/iron/explosion/3.png")),
            wze::assets::create_texture(wze::assets::load_image(
                "./assets/asteroids/iron/explosion/4.png")),
            wze::assets::create_texture(wze::assets::load_image(
                "./assets/asteroids/iron/explosion/5.png")),
            wze::assets::create_texture(wze::assets::load_image(
                "./assets/asteroids/iron/explosion/6.png")),
            wze::assets::create_texture(wze::assets::load_image(
                "./assets/asteroids/iron/explosion/7.png")),
            wze::assets::create_texture(wze::assets::load_image(
                "./assets/asteroids/iron/explosion/8.png")),
            wze::assets::create_texture(wze::assets::load_image(
                "./assets/asteroids/iron/explosion/9.png")),
            wze::assets::create_texture(wze::assets::load_image(
                "./assets/asteroids/iron/explosion/10.png")),
            wze::assets::create_texture(wze::assets::load_image(
                "./assets/asteroids/iron/explosion/11.png")),
            wze::assets::create_texture(wze::assets::load_image(
                "./assets/asteroids/iron/explosion/12.png")),
            wze::assets::create_texture(wze::assets::load_image(
                "./assets/asteroids/iron/explosion/13.png")),
            wze::assets::create_texture(wze::assets::load_image(
                "./assets/asteroids/iron/explosion/14.png")),
            wze::assets::create_texture(wze::assets::load_image(
                "./assets/asteroids/iron/explosion/15.png"))};
    return asteroids_iron_explosion_animation;
}
