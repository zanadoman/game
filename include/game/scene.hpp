#ifndef GAME_GAME_HPP
#define GAME_GAME_HPP

#include <game/enums.hpp>

class scene {
  public:
    virtual scene_type update() = 0;
    virtual ~scene() = default;
};

#endif
