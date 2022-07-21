#include "board/Board.h"

#include <chrono>
#include <thread>
#include <iostream>

#include "display/Display.h"

#include "tiles/BaseTile.h"
#include "tiles/TrapTile.h"
#include "tiles/DegreeTile.h"
#include "tiles/GradeTile.h"

using namespace std;

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
        bool update = false;
        if (map[i][j]->isIntersection()) {
            dir = handleIntersection(dir);
        }

        switch (dir) {
            case Direction::RIGHT: {
                if (j + 1 < map[i].size() && map[i][j + 1]) {
                    ++j;
                    ++moves;
                    update = true;
                } else {
                    dir = Direction::DOWN;
                }
                break;
            }
            case Direction::DOWN: {
                if (i + 1 < map.size() && map[i + 1][j]) {
                    ++i;
                    ++moves;
                    update = true;
                } else {
                    dir = Direction::LEFT;
                }
                break;
            }
            case Direction::LEFT: {
                if (j - 1 >= 0 && map[i][j - 1]) {
                    --j;
                    ++moves;
                    update = true;
                } else {
                    dir = Direction::UP;
                }
                break;
            }
            case Direction::UP: {
                if (i - 1 >= 0 && map[i - 1][j]) {
                    --i;
                    ++moves;
                    update = true;
                } else {
                    dir = Direction::RIGHT;
                }
                break;
            }
        }

        if(i == 0 && (j == 6 || j == 7 || j == 8)) { //TODO: change to if map[i][j] == degreeTile
            map[i][j]->apply(p);
            if(p->claimDegree()) {
                return;
            }
        }

        if (update) {
            display->notify();
            display->print();
            this_thread::sleep_for(chrono::milliseconds(50));
        }
    }

    map[i][j]->apply(p);
}

Direction Board::handleIntersection(Direction dir) {
    cout << "This tile is an intersection. Press 1 to continue on your path, or 2 to take a new path." << endl;
    int op = 0;
    while (op != 1 && op != 2) {
        cin >> op;
    }
    if (op == 2) {
        switch (dir) {
            case Direction::UP:
                return Direction::RIGHT;
            case Direction::RIGHT:
                return Direction::DOWN;
            case Direction::LEFT:
                return Direction::UP;
            case Direction::DOWN:
                return Direction::LEFT;
        }
    }
    return dir;
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
shared_ptr<Tile> baseCell(bool inter = false) {
    return make_shared<BaseTile>(inter);
}

shared_ptr<Tile> degreeTile(bool inter = false) {
    return make_shared<DegreeTile>(inter);
}

shared_ptr<Tile> gradeTile(bool inter = false) {
    return make_shared<GradeTile>(inter);
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
            {baseCell(), baseCell(), baseCell(), baseCell(),     gradeTile(), baseCell(), degreeTile(), degreeTile(), degreeTile(),   baseCell(), baseCell(), baseCell(), baseCell(), baseCell(
                    true),                                                                                                                                                                 baseCell(), baseCell(), baseCell(), baseCell(),},
            {baseCell(), nullptr,    nullptr,    baseCell(),     nullptr,    nullptr,    nullptr,    nullptr,    nullptr,      nullptr,    nullptr,    nullptr,    nullptr,    baseCell(), nullptr,    nullptr,    nullptr,    baseCell(),},
            {baseCell(), nullptr,    nullptr,    baseCell(),     nullptr,    nullptr,    nullptr,    nullptr,    baseCell(),   baseCell(), baseCell(), nullptr,    nullptr,    baseCell(), nullptr,    nullptr,    nullptr,    baseCell(),},
            {baseCell(), nullptr,    nullptr,    baseCell(),     nullptr,    nullptr,    nullptr,    nullptr,    nullptr,      nullptr,    baseCell(), nullptr,    nullptr,    baseCell(), nullptr,    nullptr,    nullptr,    baseCell(),},
            {baseCell(), nullptr,    nullptr,    baseCell(),     nullptr,    nullptr,    nullptr,    nullptr,    nullptr,      nullptr,    baseCell(), nullptr,    nullptr,    baseCell(), nullptr,    nullptr,    nullptr,    baseCell(),},
            {baseCell(), nullptr,    nullptr,    baseCell(),     nullptr,    baseCell(), baseCell(), baseCell(), baseCell(),   baseCell(), baseCell(), nullptr,    nullptr,    baseCell(), nullptr,    nullptr,    nullptr,    baseCell(),},
            {baseCell(), nullptr,    nullptr,    baseCell(),     nullptr,    nullptr,    nullptr,    nullptr,    nullptr,      nullptr,    baseCell(), nullptr,    nullptr,    baseCell(), nullptr,    nullptr,    nullptr,    baseCell(),},
            {baseCell(), nullptr,    nullptr,    baseCell(),     nullptr,    nullptr,    nullptr,    nullptr,    nullptr,      nullptr,    nullptr,    nullptr,    nullptr,    baseCell(), nullptr,    nullptr,    nullptr,    baseCell(),},
            {baseCell(), baseCell(), baseCell(), baseCell(
                    true),                                       baseCell(), baseCell(), baseCell(), baseCell(), degreeTile(), baseCell(), baseCell(), baseCell(), baseCell(), baseCell(), baseCell(), baseCell(), baseCell(), baseCell(),},
    };

    return board;
}

