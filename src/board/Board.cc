#include "board/Board.h"

#include <chrono>
#include <thread>
#include <iostream>
#include <queue>
#include <climits>
#include <algorithm>

#include "tiles/TrapTile.h"

#include "display/Display.h"
#include "utils/Utils.h"
#include "game/Game.h"

#define DIRECTION_RIGHT 0
#define DIRECTION_DOWN 1
#define DIRECTION_LEFT 2
#define DIRECTION_UP 3

#define TYPE_INTERSECTION 1
#define TYPE_ELBOW 2

using namespace std;

Board::Board() : degreeSpot{0, 6}, beaconSpot{3,6}, game{nullptr} {
    map = Board::getMapTwo();

    x = map.at(0).size();
    y = map.size();
    // set a marker for the degreetile (hard coded initially for now)
    display = make_unique<Display>(this, x, y);
}

void Board::attach(Game *g) { game = g; }

void Board::addPlayer(std::shared_ptr<Player> &p) {
    positions[p->Options()->id] = {DIRECTION_RIGHT, {0, 0}};
    display->notify();
}

void Board::move(std::shared_ptr<Player> &p, int roll) {
    if (roll == 0) {
        return;
    }

    auto &[dir, pos] = positions[p->Options()->id];
    auto &[i, j] = pos;

    int moves = 0;
    display->clear();
    while (moves < roll) {
        bool update = false;
        if (map[i][j]->Type() == TYPE_INTERSECTION) {
            dir = handleIntersection(dir);
        }
        if(map[i][j]->Type() == TYPE_ELBOW){
            dir = (4 + (dir-1)) % 4;
        }

        switch (dir) {
            case DIRECTION_RIGHT: {
                if (j + 1 < map[i].size() && map[i][j + 1]) {
                    ++j;
                    ++moves;
                    update = true;
                } else {
                    dir = DIRECTION_DOWN;
                }
                break;
            }
            case DIRECTION_DOWN: {
                if (i + 1 < map.size() && map[i + 1][j]) {
                    ++i;
                    ++moves;
                    update = true;
                } else {
                    dir = DIRECTION_LEFT;
                }
                break;
            }
            case DIRECTION_LEFT: {
                if (j - 1 >= 0 && map[i][j - 1]) {
                    --j;
                    ++moves;
                    update = true;
                } else {
                    dir = DIRECTION_UP;
                }
                break;
            }
            case DIRECTION_UP: {
                if (i - 1 >= 0 && map[i - 1][j]) {
                    --i;
                    ++moves;
                    update = true;
                } else {
                    dir = DIRECTION_RIGHT;
                }
                break;
            }
        }

        if (pos == degreeSpot) {
            map[i][j]->apply(p);
            if (p->claimDegree()) {
                if (p->Degrees() >= 3) {
                    game->notifyWinner(*p);
                } else {
                    generateNewDegree();
                }
                display->notify();
                print();
                return;
            }
        }

        if (pos == beaconSpot) {
            map[i][j]->apply(p);
            game->activateBeacon(p);
            display->notify();
            print();
            return;
        }

        if (update) {
            cout << "\x1B[2K" << "\x1B[1A" << "\x1B[1A";  // CLEAR_LINE, MOVE_UP, MOVE_UP
            display->notify();
            display->print();
            cout << endl;
            cout << p->Options()->name << " rolled a: " << roll << endl;
            this_thread::sleep_for(chrono::milliseconds(50));
        }
    }

    cout << endl;
    map[i][j]->apply(p);
}


void Board::generateNewDegree() {
    using intPair = pair<int, int>;

    intPair oldDegree = degreeSpot;

    vector<vector<int>> dist{y, vector<int>(x, INT_MAX)};
    vector<vector<bool>> visited;
    for (int i = 0; i < y; ++i) {
        for (int j = 0; j < x; ++j) {
            if (map[i][j] == nullptr) {
                dist[i][j] = -1;
            }
        }
    }

    queue<pair<intPair, int>> q; // coord, depth

    const vector<intPair> dirs = {{0,  -1},
                                  {-1, 0},
                                  {1,  0},
                                  {0,  1}};

    for (const auto &[p, playerPos]: positions) {
        visited.clear();
        visited.resize(y, vector<bool>(x, false));
        const auto &[p_i, p_j] = playerPos.second;
        dist[p_i][p_j] = 0;

        q.push({{p_i, p_j}, 0});
        while (!q.empty()) {
            const auto [pos, depth] = q.front();
            q.pop();
            const auto [pos_i, pos_j] = pos;
            for (auto [dir_i, dir_j]: dirs) {
                int ii = pos_i + dir_i;
                int jj = pos_j + dir_j;
                if (ii < 0 || ii >= y || jj < 0 || jj >= x || visited.at(ii).at(jj) ||
                    dist.at(ii).at(jj) < depth + 1) {
                    continue;
                }
                visited.at(ii).at(jj) = true;
                dist.at(ii).at(jj) = depth + 1;
                q.push({{ii, jj}, depth + 1});
            }
        }
    }

    int maxDist = -1;
    for (int i = 0; i < y; ++i) {
        for (int j = 0; j < x; ++j) {
            if (dist[i][j] > maxDist) {
                maxDist = dist[i][j];
                degreeSpot = {i, j};
            }
        }
    }

    auto [old_y, old_x] = oldDegree;
    map[old_y][old_x] = utils::baseCell(map[old_y][old_x]->Type());
    auto [new_y, new_x] = degreeSpot;
    map[new_y][new_x] = utils::degreeTile(map[new_y][new_x]->Type());
}

int Board::handleIntersection(int dir) {
    cout << endl;
    cout << "This tile is an intersection. Press 1 to continue on your path, or 2 to take a new path." << endl;
    int op = 0;
    int count = 1;
    while (op != 1 && op != 2) {
        if(!(cin >> op)){
            ++count;
            cin.clear();
            cin.ignore(10000, '\n');
        }
    }
    for(int i = 0; i < count; ++i){
        cout << "\x1B[2K" << "\x1B[1A";
    }
    if (op == 2) {
        switch (dir) {
            case DIRECTION_UP:
                return DIRECTION_RIGHT;
            case DIRECTION_RIGHT:
                return DIRECTION_DOWN;
            case DIRECTION_LEFT:
                return DIRECTION_UP;
            case DIRECTION_DOWN:
                return DIRECTION_LEFT;
            default:
                return dir;
        }
    }
    return dir;
}

void Board::resurrect(const std::shared_ptr<Player>& player) {
    player->reset();
    positions[player->Options()->id] = {DIRECTION_RIGHT, {0,0}};
}

vector<int> Board::checkCollision(const std::shared_ptr<Player>& player) const {
    const int id = player->Options()->id;
    const auto &[i, j] = positions.at(id).second;

    vector<int> ids;
    for (const auto &[pid, pos]: positions) {
        if (pid == id) {
            continue;
        }
        const auto &[ii, jj] = pos.second;
        if (ii == i && jj == j) {
            ids.emplace_back(pid);
        }
    }

    return ids;
}

void Board::update() {
    display->notify();
}

void Board::placeTrap(int ID, unique_ptr<TrapCard> trap) {
    auto[row, col] = positions.at(ID).second;
    map[row][col] = make_shared<TrapTile>(std::move(map[row][col]), std::move(trap));
}

void Board::print() {
    display->clear();
    display->print();
}

void Board::swapPositions(int p1, int p2) {
    std::swap(positions[p1], positions[p2]);
}

// Getters
vector<vector<shared_ptr<Tile>>> Board::getState() {
    return map;
}

unordered_map<int, pair<int, pair<int, int>>> Board::getPositions() {
    return positions;
}

// static

vector<vector<shared_ptr<Tile>>> Board::getMapOne() {
    using namespace utils;
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
    using namespace utils;
    vector<vector<shared_ptr<Tile>>> board = {
            {cardTile(), abilityTile(), cardTile(), baseCell(),    gradeTile(),baseCell(), degreeTile(),   cardTile(), baseCell(), gradeTile(),     baseCell(1),    cardTile(), baseCell(1),    baseCell(), healthTile(), baseCell(), cardTile(), baseCell(),},
            {baseCell(), nullptr,    nullptr,    baseCell(),    nullptr,    nullptr,    nullptr,        nullptr,    baseCell(), nullptr,        gradeTile(),     nullptr,    baseCell(),     nullptr,    nullptr,    nullptr,    nullptr,    gradeTile(),},
            {cardTile(), nullptr,    nullptr,    abilityTile(),    nullptr,    nullptr,    nullptr,        nullptr,    cardTile(), nullptr,        baseCell(),     nullptr,    cardTile(),     nullptr,    nullptr,    nullptr,    nullptr,    healthTile(),},
            {gradeTile(), nullptr,    nullptr,    cardTile(1),   abilityTile(), baseCell(), beaconTile(),   baseCell(), baseCell(2),nullptr,        cardTile(),     nullptr,    abilityTile(),     nullptr,    nullptr,    nullptr,    nullptr,    cardTile(),},
            {baseCell(), nullptr,    nullptr,    baseCell(),    nullptr,    nullptr,    nullptr,        nullptr,    nullptr,    nullptr,        cardTile(),     nullptr,    baseCell(2),    gradeTile(), baseCell(), abilityTile(), baseCell(), baseCell(),},
            {healthTile(), nullptr,    nullptr,  healthTile(),    nullptr,    nullptr,    nullptr,        nullptr,    nullptr,    nullptr,        healthTile(),     nullptr,    nullptr,        nullptr,    nullptr,    nullptr,    nullptr,    cardTile(),},
            {baseCell(), nullptr,    nullptr,    baseCell(),    nullptr,    nullptr,    nullptr,        nullptr,    nullptr,    nullptr,        baseCell(),     nullptr,    nullptr,        nullptr,    nullptr,    nullptr,    nullptr,    gradeTile(),},
            {baseCell(), nullptr,    nullptr,    baseCell(),    nullptr,    nullptr,    nullptr,        nullptr,    nullptr,    nullptr,        cardTile(),     nullptr,    nullptr,        nullptr,    nullptr,    nullptr,    nullptr,    baseCell(),},
            {cardTile(), cardTile(), baseCell(), gradeTile(1),   baseCell(), gradeTile(), baseCell(),     cardTile(), baseCell(), cardTile(),   baseCell(),   cardTile(), abilityTile(),  baseCell(), cardTile(), baseCell(), cardTile(), baseCell(),},
    };

    return board;
}

