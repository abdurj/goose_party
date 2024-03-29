#ifndef BOARD_H
#define BOARD_H

#include <vector>
#include <memory>
#include <unordered_map>

#include "tiles/Tile.h"
#include "display/Display.h"
#include "player/Player.h"
#include "cards/Card.h"

class Game;
class TrapCard;

class Board{
    static int handleIntersection(int);
    static std::vector<std::vector<std::shared_ptr<Tile>>> getMapOne();
    static std::vector<std::vector<std::shared_ptr<Tile>>> getMapTwo();

    std::vector<std::vector<std::shared_ptr<Tile>>> map;
    std::unordered_map<int, std::pair<int, std::pair<int, int>>> positions;
    std::unique_ptr<Display> display;
    std::pair<int, int> degreeSpot;
    std::pair<int, int> beaconSpot;
    size_t x; // x dimension
    size_t y; // y dimension
    Game *game;
    
    void generateNewDegree();
public:
    Board();
    void attach(Game*);
    std::vector<std::vector<std::shared_ptr<Tile>>> getState() const;

    std::unordered_map<int, std::pair<int, std::pair<int, int>>> getPositions() const;

    void move(std::shared_ptr<Player> &, int);

    void addPlayer(const std::shared_ptr<Player> &);

    void update();

    void placeTrap(int, std::unique_ptr<TrapCard>);

    void print();

    std::vector<int> checkCollision(const std::shared_ptr<Player>&) const;

    void resurrect(const std::shared_ptr<Player>&);
    // Swap the positions of two players. yt
    void swapPositions(int, int);
};

#endif // BOARD_H;
