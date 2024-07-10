#ifndef GAME_UPDATEABLE_HPP
#define GAME_UPDATEABLE_HPP

class updateable {
  public:
    virtual void update() = 0;
    virtual ~updateable() = default;
};

#endif
