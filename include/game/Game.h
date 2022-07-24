#ifndef GAME_H
#define GAME_H
#include <vector>
#include <string>
#include "board/Board.h"

class Player;
class Beacon;

class Game{
  protected:
  Board b;
  bool playing;
  int curTurn;
  std::vector<std::shared_ptr<Player>> players;
  std::vector<std::shared_ptr<Beacon>> beacons;
  bool input(std::string);
  virtual void GameLoop();
  void endCycle();
  void setup();
  public:
    Game();
    void play();
    void init();
    void notifyWinner(Player &);
    void activateBeacon(int, std::shared_ptr<Player> &);
};

#endif // GAME_H
