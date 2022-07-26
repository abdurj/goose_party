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
  void setup();
  void init();

  virtual void GameLoop();
  void endCycle();

  protected:
    virtual bool input(std::string);

    void challenge(const std::shared_ptr<Player>& challenger, const std::shared_ptr<Player>& opponent);
    void battle(const std::shared_ptr<Player>& challenger, const std::shared_ptr<Player>& opponent);

public:
    Game();
    void play();
    void notifyWinner(const std::shared_ptr<Player> &);
    void activateBeacon(const std::shared_ptr<Player> &);

    std::shared_ptr<Player> getPlayer(const int &id);
    int getPlayerIndex(const int id); // returns player index in order
};

#endif // GAME_H
