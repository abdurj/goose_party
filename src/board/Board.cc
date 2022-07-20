#include "board/Board.h"

#include "display/Display.h"

#include "tiles/BaseTile.h"
#include "tiles/TrapTile.h"
#include "tiles/DegreeTile.h"
using namespace std;
using namespace ftxui;

Board::Board() {
    map = Board::getMapTwo();
    
    x = map.at(0).size();
    y = map.size();

    display = make_unique<Display>(this, x, y);
}

void Board::addPlayer(std::shared_ptr<Player> p){
    positions[p] = {::Direction::RIGHT, {0, 0}};
    display->notify();
}

void Board::move(std::shared_ptr<Player> p, int roll) {
    auto &[dir, pos] = positions[p];
    auto &[i, j] = pos;

    int moves = 0;
    while (moves < roll) {
        switch (dir) {
            case ::Direction::RIGHT: {
                if (j + 1 < map[i].size() && map[i][j + 1]) {
                    ++j;
                    ++moves;
                } else {
                    dir = ::Direction::UP;
                }
                break;
            }
            case ::Direction::UP: {
                if (i - 1 >= 0 && map[i - 1][j]) {
                    --i;
                    ++moves;
                } else {
                    dir = ::Direction::LEFT;
                }
                break;
            }
            case ::Direction::LEFT: {
                if (j - 1 >= 0 && map[i][j - 1]) {
                    --j;
                    ++moves;
                } else {
                    dir = ::Direction::DOWN;
                }
                break;
            }
            case ::Direction::DOWN: {
                if (i + 1 < map.size() && map[i + 1][j]) {
                    ++i;
                    ++moves;
                }
            }
        }
    }
}

void Board::update() {
    map[0][2] = make_shared<TrapTile>(std::move(map[0][2]));
    display->notify();
}

void Board::print() {
    display->print();
}

// Getters
vector<vector<shared_ptr<Tile>>> Board::getState() {
    return map;
}

unordered_map<shared_ptr<Player>, pair<::Direction, pair<int, int>>> Board::getPositions() {
    return positions;
}

// static
shared_ptr<Tile> Board::baseCell() {
    return make_shared<BaseTile>();
}

shared_ptr<Tile> Board::degreeTile() {
    return make_shared<DegreeTile>();
}

vector<vector<shared_ptr<Tile>>> Board::getMapOne() {
    vector<vector<shared_ptr<Tile>>> board = {
            {baseCell(), baseCell(), baseCell(), baseCell(), baseCell(), baseCell(), baseCell(), baseCell(), baseCell(), nullptr,    nullptr},
            {baseCell(), nullptr,    nullptr,    nullptr,    nullptr,    nullptr,    nullptr,    nullptr,    baseCell(), nullptr,    nullptr},
            {baseCell(), baseCell(), baseCell(), baseCell(), baseCell(), baseCell(), baseCell(), baseCell(), baseCell(), nullptr,    nullptr},
            {baseCell(), nullptr,    nullptr,    nullptr,    nullptr,    nullptr,    nullptr,    nullptr,    baseCell(), nullptr,    nullptr},
            {baseCell(), baseCell(), baseCell(), baseCell(), baseCell(), baseCell(), baseCell(), baseCell(), baseCell(), baseCell(), baseCell()},
            {baseCell(), nullptr,    nullptr,    nullptr,    nullptr,    nullptr,    nullptr,    nullptr,    baseCell(), nullptr,    baseCell()},
            {baseCell(), nullptr,    nullptr,    nullptr,    nullptr,    nullptr,    nullptr,    nullptr,    baseCell(), nullptr,    baseCell()},
            {baseCell(), nullptr,    nullptr,    nullptr,    nullptr,    nullptr,    nullptr,    nullptr,    baseCell(), nullptr,    baseCell()},
            {baseCell(), baseCell(), baseCell(), baseCell(), nullptr,    nullptr,    baseCell(), baseCell(), baseCell(), nullptr,    baseCell()},
            {nullptr,    nullptr,    nullptr,    baseCell(), nullptr,    nullptr,    baseCell(), nullptr,    baseCell(), nullptr,    baseCell()},
            {nullptr,    nullptr,    nullptr,    baseCell(), nullptr,    nullptr,    baseCell(), nullptr,    baseCell(), baseCell(), baseCell()},
            {nullptr,    nullptr,    nullptr,    baseCell(), nullptr,    nullptr,    baseCell(), nullptr,    nullptr,    nullptr,    baseCell()},
            {nullptr,    nullptr,    nullptr,    baseCell(), nullptr,    nullptr,    baseCell(), nullptr,    nullptr,    nullptr,    baseCell()},
            {nullptr,    nullptr,    nullptr,    baseCell(), baseCell(), baseCell(), baseCell(), baseCell(), baseCell(), baseCell(), baseCell()},
    };
    return board;
}

vector<vector<shared_ptr<Tile>>> Board::getMapTwo() {
    vector<vector<shared_ptr<Tile>>> board = {
            {baseCell(), baseCell(), baseCell(), baseCell(), baseCell(), baseCell(), baseCell(), baseCell(), baseCell(),   baseCell(), baseCell(), baseCell(), baseCell(), baseCell(), baseCell(), baseCell(), baseCell(), baseCell(),},
            {baseCell(), nullptr,    nullptr,    baseCell(), nullptr,    nullptr,    nullptr,    nullptr,    baseCell(),   nullptr,    baseCell(), nullptr,    nullptr,    nullptr,    nullptr,    baseCell(), nullptr,    baseCell(),},
            {baseCell(), nullptr,    nullptr,    baseCell(), nullptr,    nullptr,    nullptr,    nullptr,    baseCell(),   baseCell(), baseCell(), nullptr,    nullptr,    nullptr,    nullptr,    baseCell(), nullptr,    baseCell(),},
            {baseCell(), nullptr,    nullptr,    baseCell(), nullptr,    nullptr,    nullptr,    nullptr,    nullptr,      nullptr,    baseCell(), nullptr,    nullptr,    baseCell(), baseCell(), baseCell(), nullptr,    baseCell(),},
            {baseCell(), nullptr,    nullptr,    baseCell(), nullptr,    nullptr,    nullptr,    nullptr,    nullptr,      nullptr,    baseCell(), nullptr,    nullptr,    baseCell(), nullptr,    nullptr,    nullptr,    baseCell(),},
            {baseCell(), nullptr,    nullptr,    baseCell(), baseCell(), baseCell(), baseCell(), baseCell(), baseCell(),   baseCell(), baseCell(), nullptr,    nullptr,    baseCell(), nullptr,    nullptr,    nullptr,    baseCell(),},
            {baseCell(), nullptr,    nullptr,    baseCell(), nullptr,    nullptr,    nullptr,    nullptr,    nullptr,      nullptr,    baseCell(), nullptr,    nullptr,    baseCell(), nullptr,    nullptr,    nullptr,    baseCell(),},
            {baseCell(), nullptr,    nullptr,    baseCell(), nullptr,    nullptr,    nullptr,    nullptr,    nullptr,      nullptr,    baseCell(), nullptr,    nullptr,    baseCell(), nullptr,    nullptr,    nullptr,    baseCell(),},
            {baseCell(), baseCell(), baseCell(), baseCell(), baseCell(), baseCell(), baseCell(), baseCell(), degreeTile(), baseCell(), baseCell(), baseCell(), baseCell(), baseCell(), baseCell(), baseCell(), baseCell(), baseCell(),},
    };
    return board;
}

