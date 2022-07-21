#ifndef GAME_H
#define GAME_H
#include <vector>
#include "player/Player.h"
#include "board/Board.h"

class Game{
  Board b;
  std::vector<std::shared_ptr<Player>> players;
  public:
    Game();
    void play();
    void init();

};

#endif // GAME_H
