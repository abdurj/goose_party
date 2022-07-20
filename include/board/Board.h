#ifndef BOARD_H
#define BOARD_H

#include <vector>
#include <memory>
#include <unordered_map>

#include "tiles/Tile.h"
#include "display/Display.h"
#include "player/Player.h"

enum class Direction {
    UP,
    RIGHT,
    LEFT,
    DOWN
};

class Board {
    static std::shared_ptr<Tile> baseCell(bool);

    static std::shared_ptr<Tile> degreeTile(bool);

    static std::vector<std::vector<std::shared_ptr<Tile>>> getMapOne();

    static std::vector<std::vector<std::shared_ptr<Tile>>> getMapTwo();

    std::vector<std::vector<std::shared_ptr<Tile>>> map;
    std::unordered_map<std::shared_ptr<Player>, std::pair<Direction, std::pair<int, int>>> positions;
    std::unique_ptr<Display> display;
    int x; // x dimension
    int y; // y dimension

public:
    Board();

    std::vector<std::vector<std::shared_ptr<Tile>>> getState();

    std::unordered_map<std::shared_ptr<Player>, std::pair<Direction, std::pair<int, int>>> getPositions();

    void move(std::shared_ptr<Player>, int);

    void addPlayer(std::shared_ptr<Player>);

    void update();

    void print();
};

#endif // BOARD_H;
