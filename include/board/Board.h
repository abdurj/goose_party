#ifndef BOARD_H
#define BOARD_H

#include <vector>
#include <memory>

#include "tiles/Tile.h"
#include "display/Display.h"

class Board{
    std::vector<std::vector<std::shared_ptr<Tile>>> map;
    std::unique_ptr<Display> display;
    int x; // x dimension
    int y; // y dimension

  public:
    Board();
    const std::vector<std::vector<std::shared_ptr<Tile>>> getState();

    void update();
    void print();
};

#endif // BOARD_H;