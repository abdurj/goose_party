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

  virtual void GameLoop();
  void endCycle();

  protected:
    virtual bool input(std::string);
  
  public:
    Game();
    void play();
    void init();
    void notifyWinner(Player &);

    std::shared_ptr<Player> getPlayer(const int &id);

    void challenge(std::shared_ptr<Player> challenger, std::shared_ptr<Player> opponent);

    void battle(const std::shared_ptr<Player>& challenger, const std::shared_ptr<Player>& opponent);
};

#endif // GAME_H
