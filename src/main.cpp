#include <wizard_engine/wizard_engine.hpp>

struct assets {
    std::shared_ptr<wze::texture> laser;

    assets() {
        laser = wze::assets::create_texture(
            wze::assets::load_image("./assets/laser.png"));
    }
};

assets* ASSETS;

class laser : public wze::entity {
  private:
    float _z;
    std::vector<std::shared_ptr<wze::sprite>> _sprites;

  public:
    float z() const {
        return _z;
    }

    void set_z(float z) {
        _z = z;
    }

    laser(float x, float y, float z) {
        set_x(x);
        set_y(y);
        set_z(z);

        for (float i = z; i < z + 2; i += 0.1f) {
            _sprites.push_back(std::shared_ptr<wze::sprite>(
                new wze::sprite(x, y, z + i, 0, 15, 15, true, ASSETS->laser, 0,
                                std::numeric_limits<uint8_t>::max(), 0)));
        }

        for (std::shared_ptr<wze::sprite> const& sprite : _sprites) {
            components().push_back(sprite);
        }

        recompose();
    }

    void update() {
        size_t i;

        set_z(z() + 1 * wze::timer::delta_time());
        for (i = 0; i < _sprites.size(); ++i) {
            _sprites.at(i)->set_z(_sprites.at(i)->z() + 10 + i * 0.1f);
        }
    }
};

wze_main(2560, 1440) {
    std::vector<laser> lasers;
    uint64_t last_time;

    wze::timer::set_frame_time(10);
    ASSETS = new assets;
    last_time = 0;

    wze_while(true) {
        if (wze::input::key(wze::KEY_MOUSE_LEFT) &&
            last_time + 200 < wze::timer::current_time()) {
            std::apply(
                [&lasers](float x, float y) -> void {
                    lasers.push_back({x, y, wze::camera::z()});
                },
                wze::input::cursor_spatial(wze::camera::z() + 512));
            last_time = wze::timer::current_time();
        }

        for (laser& laser : lasers) {
            laser.update();
        }
    };

    delete ASSETS;

    return 0;
}
