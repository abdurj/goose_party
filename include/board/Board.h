#ifndef BOARD_H
#define BOARD_H

#include <vector>
#include <memory>
#include <unordered_map>

#include "tiles/Tile.h"
#include "display/Display.h"
#include "player/Player.h"

class Game;

enum class Direction{
    UP,
    RIGHT,
    LEFT,
    DOWN
};

class Board{
    static Direction handleIntersection(Direction);
    static std::vector<std::vector<std::shared_ptr<Tile>>> getMapOne();
    static std::vector<std::vector<std::shared_ptr<Tile>>> getMapTwo();

    std::vector<std::vector<std::shared_ptr<Tile>>> map;
    std::unordered_map<int, std::pair<Direction, std::pair<int, int>>> positions;
    std::unique_ptr<Display> display;
    std::pair<int, int> degreeSpot;
    size_t x; // x dimension
    size_t y; // y dimension
    Game *game;
    
    void generateNewDegree();
public:
    Board();
    void attach(Game*);
    std::vector<std::vector<std::shared_ptr<Tile>>> getState();

    std::unordered_map<int, std::pair<Direction, std::pair<int, int>>> getPositions();

    void move(std::shared_ptr<Player> &, int);

    void resetPlayer(int);
    
    void addPlayer(std::shared_ptr<Player> &);

    void update();

    void print();
};

#endif // BOARD_H;
