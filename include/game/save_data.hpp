#ifndef GAME_SAVE_HPP
#define GAME_SAVE_HPP

#include <wizard_engine/wizard_engine.hpp>

class save_data final {
  private:
    static int16_t _pyrite_count;
    static int16_t _wolframite_count;
    static int16_t _carneol_count;
    static int16_t _moldavite_count;
    static int16_t _ruby_count;
    static int16_t _sapphire_count;

    static uint8_t _player_ship_speed_tier;
    static uint8_t _player_ship_damage_tier;
    static uint8_t _player_ship_hitpoints_tier;
    static uint8_t _player_ship_storage_tier;

    static uint64_t _player_money;

    static bool _tutorial_completed;
    static bool _final_boss_completed;

    save_data() = default;

  public:
    static int16_t pyrite_count();
    static void set_pyrite_count(int16_t pyrite_count);

    static int16_t wolframite_count();
    static void set_wolframite_count(int16_t wolframite_count);

    static int16_t carneol_count();
    static void set_carneol_count(int16_t carneol_count);

    static int16_t moldavite_count();
    static void set_moldavite_count(int16_t moldavite_count);

    static int16_t ruby_count();
    static void set_ruby_count(int16_t ruby_count);

    static int16_t sapphire_count();
    static void set_sapphire_count(int16_t sapphire_count);

    static uint8_t player_ship_speed_tier();
    static void set_player_ship_speed_tier(uint8_t player_ship_speed_tier);

    static uint8_t player_ship_damage_tier();
    static void set_player_ship_damage_tier(uint8_t player_ship_damage_tier);

    static uint8_t player_ship_hitpoints_tier();
    static void
    set_player_ship_hitpoints_tier(uint8_t player_ship_hitpoints_tier);

    static uint8_t player_ship_storage_tier();
    static void set_player_ship_storage_tier(uint8_t player_ship_storage_tier);

    static uint64_t player_money();
    static void set_player_money(uint64_t player_money);

    static bool tutorial_completed();
    static void set_tutorial_completed(bool tutorial_completed);

    static bool final_boss_completed();
    static void set_final_boss_completed(bool final_boss_completed);

    static void load();
    static void save();
    static void reset();
};

#endif
