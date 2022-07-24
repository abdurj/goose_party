#ifndef GAME_H
#define GAME_H
#include <vector>
#include <string>
#include "player/Player.h"
#include "board/Board.h"

class Game{
  protected:
  Board b;
  bool playing;
  int curTurn;
  std::vector<std::shared_ptr<Player>> players;

  bool input(std::string);
  virtual void GameLoop();
  void endCycle();

  public:
    Game();
    void play();
    void init();
    void notifyWinner(Player &);
};

#endif // GAME_H
