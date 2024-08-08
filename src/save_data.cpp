#include <fstream>
#include <game/save_data.hpp>
#include <ios>

int16_t save_data::_pyrite_count;
int16_t save_data::_wolframite_count;
int16_t save_data::_carneol_count;
int16_t save_data::_moldavite_count;
int16_t save_data::_ruby_count;
int16_t save_data::_sapphire_count;

uint8_t save_data::_player_ship_speed_tier;
uint8_t save_data::_player_ship_damage_tier;
uint8_t save_data::_player_ship_hitpoints_tier;
uint8_t save_data::_player_ship_storage_tier;

uint64_t save_data::_player_money;

bool save_data::_tutorial_completed;
bool save_data::_final_boss_completed;

int16_t save_data::pyrite_count() {
    return _pyrite_count;
}

void save_data::set_pyrite_count(int16_t pyrite_count) {
    _pyrite_count = pyrite_count;
}

int16_t save_data::wolframite_count() {
    return _wolframite_count;
}

void save_data::set_wolframite_count(int16_t wolframite_count) {
    _wolframite_count = wolframite_count;
}

int16_t save_data::carneol_count() {
    return _carneol_count;
}

void save_data::set_carneol_count(int16_t carneol_count) {
    _carneol_count = carneol_count;
}

int16_t save_data::moldavite_count() {
    return _moldavite_count;
}

void save_data::set_moldavite_count(int16_t moldavite_count) {
    _moldavite_count = moldavite_count;
}

int16_t save_data::ruby_count() {
    return _ruby_count;
}

void save_data::set_ruby_count(int16_t ruby_count) {
    _ruby_count = ruby_count;
}

int16_t save_data::sapphire_count() {
    return _sapphire_count;
}

void save_data::set_sapphire_count(int16_t sapphire_count) {
    _sapphire_count = sapphire_count;
}

uint8_t save_data::player_ship_speed_tier() {
    return _player_ship_speed_tier;
}

void save_data::set_player_ship_speed_tier(uint8_t player_ship_speed_tier) {
    _player_ship_speed_tier = player_ship_speed_tier;
}

uint8_t save_data::player_ship_damage_tier() {
    return _player_ship_damage_tier;
}

void save_data::set_player_ship_damage_tier(uint8_t player_ship_damage_tier) {
    _player_ship_damage_tier = player_ship_damage_tier;
}

uint8_t save_data::player_ship_hitpoints_tier() {
    return _player_ship_hitpoints_tier;
}

void save_data::set_player_ship_hitpoints_tier(
    uint8_t player_ship_hitpoints_tier) {
    _player_ship_hitpoints_tier = player_ship_hitpoints_tier;
}

uint8_t save_data::player_ship_storage_tier() {
    return _player_ship_storage_tier;
}

void save_data::set_player_ship_storage_tier(uint8_t player_ship_storage_tier) {
    _player_ship_storage_tier = player_ship_storage_tier;
}

uint64_t save_data::player_money() {
    return _player_money;
}

void save_data::set_player_money(uint64_t player_money) {
    _player_money = player_money;
}

bool save_data::tutorial_completed() {
    return _tutorial_completed;
}

void save_data::set_tutorial_completed(bool tutorial_completed) {
    _tutorial_completed = tutorial_completed;
}

bool save_data::final_boss_completed() {
    return _final_boss_completed;
}

void save_data::set_final_boss_completed(bool final_boss_completed) {
    _final_boss_completed = final_boss_completed;
}

void save_data::load() {
    std::ifstream file;

    file.open("./save_data.bin", std::ios::binary);

    if (!file) {
        reset();
    } else {
        file.read((char*)&_pyrite_count, sizeof(_pyrite_count));
        file.read((char*)&_wolframite_count, sizeof(_wolframite_count));
        file.read((char*)&_carneol_count, sizeof(_carneol_count));
        file.read((char*)&_moldavite_count, sizeof(_moldavite_count));
        file.read((char*)&_ruby_count, sizeof(_ruby_count));
        file.read((char*)&_sapphire_count, sizeof(_sapphire_count));
        file.read((char*)&_player_ship_speed_tier,
                  sizeof(_player_ship_speed_tier));
        file.read((char*)&_player_ship_damage_tier,
                  sizeof(_player_ship_damage_tier));
        file.read((char*)&_player_ship_hitpoints_tier,
                  sizeof(_player_ship_hitpoints_tier));
        file.read((char*)&_player_ship_storage_tier,
                  sizeof(_player_ship_storage_tier));
        file.read((char*)&_player_money, sizeof(_player_money));
        file.read((char*)&_tutorial_completed, sizeof(_tutorial_completed));
        file.read((char*)&_final_boss_completed, sizeof(_final_boss_completed));
    }

    file.close();
}

void save_data::reset() {

    _pyrite_count = 2;
    _wolframite_count = 16;
    _carneol_count = 34;
    _moldavite_count = 2;
    _ruby_count = 1;
    _sapphire_count = 150;

    _player_ship_speed_tier = 0;
    _player_ship_damage_tier = 0;
    _player_ship_hitpoints_tier = 0;
    _player_ship_storage_tier = 0;

    _player_money = 0;

    _tutorial_completed = false;
    _final_boss_completed = false;
}

void save_data::save() {
    std::ofstream file;

    file.open("./save_data.bin", std::ios::binary);

    if (file) {
        file.write((char const*)&_pyrite_count, sizeof(_pyrite_count));
        file.write((char const*)&_wolframite_count, sizeof(_wolframite_count));
        file.write((char const*)&_carneol_count, sizeof(_carneol_count));
        file.write((char const*)&_moldavite_count, sizeof(_moldavite_count));
        file.write((char const*)&_ruby_count, sizeof(_ruby_count));
        file.write((char const*)&_sapphire_count, sizeof(_sapphire_count));
        file.write((char const*)&_player_ship_speed_tier,
                   sizeof(_player_ship_speed_tier));
        file.write((char const*)&_player_ship_damage_tier,
                   sizeof(_player_ship_damage_tier));
        file.write((char const*)&_player_ship_hitpoints_tier,
                   sizeof(_player_ship_hitpoints_tier));
        file.write((char const*)&_player_ship_storage_tier,
                   sizeof(_player_ship_storage_tier));
        file.write((char const*)&_player_money, sizeof(_player_money));
        file.write((char const*)&_tutorial_completed,
                   sizeof(_tutorial_completed));
        file.write((char const*)&_final_boss_completed,
                   sizeof(_final_boss_completed));
    }
    file.close();
}
