#ifndef BOARD_H
#define BOARD_H

#include <vector>
#include <memory>
#include <unordered_map>

#include "tiles/Tile.h"
#include "display/Display.h"
#include "player/Player.h"

class Board{
    std::vector<std::vector<std::shared_ptr<Tile>>> map;
    std::unordered_map<std::shared_ptr<Player>, std::pair<int,int>> positions;
    std::unique_ptr<Display> display;
    int x; // x dimension
    int y; // y dimension

  public:
    Board();
    const std::vector<std::vector<std::shared_ptr<Tile>>> getState();
    const std::unordered_map<std::shared_ptr<Player>, std::pair<int,int>> getPositions();

    void addPlayer(std::shared_ptr<Player>);
    void update();
    void print();
};

#endif // BOARD_H;