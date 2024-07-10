#include <game/assets.hpp>

std::shared_ptr<wze::texture> const& assets::placeholder_texture() {
    static std::shared_ptr<wze::texture> placeholder_texture =
        wze::assets::create_texture(
            wze::assets::load_image("./assets/placeholder.png"));
    return placeholder_texture;
}

std::shared_ptr<wze::texture> const& assets::laser_texture() {
    static std::shared_ptr<wze::texture> laser_texture =
        wze::assets::create_texture(
            wze::assets::load_image("./assets/laser.png"));
    return laser_texture;
}
