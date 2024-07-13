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

std::shared_ptr<wze::texture> const& assets::asteroid_texture() {
    static auto asset = wze::assets::create_texture(
        wze::assets::load_image("./assets/asteroid.png"));
    return asset;
}

std::shared_ptr<wze::texture> const& assets::space_texture() {
    static auto asset = wze::assets::create_texture(
        wze::assets::load_image("./assets/space.png"));
    return asset;
}
