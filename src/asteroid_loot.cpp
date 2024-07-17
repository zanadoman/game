#include <game/assets.hpp>
#include <game/asteroid_loot.hpp>
#include <game/player_ship.hpp>

float asteroid_loot::z() const {
    return _appearance->z();
}

void asteroid_loot::set_z(float z) {
    _appearance->set_z(z);
}

asteroid_loot::asteroid_loot(float x, float y, float z, material material)
    : entity({}, x, y) {
    std::shared_ptr<wze::texture> texture;

    switch (_material = material) {
    case MATERIAL_PYRITE:
        texture = assets::asteroids_pyrite_texture();
        break;
    case MATERIAL_WOLFRAMITE:
        texture = assets::asteroids_wolframite_texture();
        break;
    case MATERIAL_CARNEOL:
        texture = assets::asteroids_carneol_texture();
        break;
    case MATERIAL_MOLDAVITE:
        texture = assets::asteroids_moldavite_texture();
        break;
    case MATERIAL_RUBY:
        texture = assets::asteroids_ruby_texture();
        break;
    case MATERIAL_SAPPHIRE:
        texture = assets::asteroids_sapphire_texture();
        break;
    }

    _appearance = std::shared_ptr<wze::sprite>(new wze::sprite(
        this->x(), this->y(), z,
        wze::math::to_radians(wze::math::random(0.f, 360.f)), 1000, 1000, true,
        texture, std::numeric_limits<uint8_t>::max(),
        std::numeric_limits<uint8_t>::max(),
        std::numeric_limits<uint8_t>::max(),
        std::numeric_limits<uint8_t>::max(), wze::FLIP_NONE, true,
        std::numeric_limits<uint8_t>::max(), false, 0, 0, 0, true, true, true,
        false, false));

    components().push_back(_appearance);
}

bool asteroid_loot::update(player_ship const& player_ship) {
    float x_distance;
    float y_distance;
    float z_distance;
    float distance;

    x_distance = player_ship.x() - x();
    y_distance = player_ship.y() - y();
    z_distance = player_ship.z() - z();
    distance =
        sqrtf(powf(x_distance, 2) + powf(y_distance, 2) + powf(z_distance, 2));

    if (distance < 4'000) {
        return false;
    }

    if (distance < 50'000) {
        set_x(x() + x_distance / distance * 50 * wze::timer::delta_time());
        set_y(y() + y_distance / distance * 50 * wze::timer::delta_time());
        set_z(z() + z_distance / distance * 50 * wze::timer::delta_time());
        set_angle(angle() + 0.01f * wze::timer::delta_time());
    }

    return true;
}
