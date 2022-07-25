#include "board/Board.h"

#include <chrono>
#include <thread>
#include <iostream>
#include <queue>
#include <climits>

#include "tiles/TrapTile.h"

#include "display/Display.h"
#include "utils/Utils.h"
#include "game/Game.h"

using namespace std;

Board::Board() {
    map = Board::getMapTwo();

    x = map.at(0).size();
    y = map.size();
    // set a marker for the degreetile (hard coded initially for now)
    degreeSpot = {0, 6};
    game = nullptr;
    display = make_unique<Display>(this, x, y);
}

void Board::attach(Game *g) { game = g; }

void Board::addPlayer(std::shared_ptr<Player> &p) {
    positions[p->Options()->id] = {::Direction::RIGHT, {0, 0}};
    display->notify();
}

void Board::move(std::shared_ptr<Player> &p, int roll) {
    if (roll == 0) {
        return;
    }

    std::cout << "\x1B[2J\x1B[H";
    auto &[dir, pos] = positions[p->Options()->id];
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

        if (pos == degreeSpot) {
            map[i][j]->apply(p);
            if (p->claimDegree()) {
                if (p->Degrees() >= 3) {
                    game->notifyWinner(*p);
                } else {
                    generateNewDegree();
                }
                return;
            }
        }

        if (update) {
            display->notify();
            display->print();
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
            const auto &[pos, depth] = q.front();
            q.pop();
            const auto &[pos_i, pos_j] = pos;
            for (auto &[dir_i, dir_j]: dirs) {
                int ii = pos_i + dir_i;
                int jj = pos_j + dir_j;
                if (ii < 0 || ii >= y || jj < 0 || jj >= x || map[ii][jj] == nullptr || visited[ii][jj] ||
                    dist[ii][jj] < depth + 1) {
                    continue;
                }
                visited[ii][jj] = true;
                dist[ii][jj] = depth + 1;
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
    map[old_y][old_x] = utils::baseCell(map[old_y][old_x]->isIntersection());
    auto [new_y, new_x] = degreeSpot;
    map[new_y][new_x] = utils::degreeTile(map[new_y][new_x]->isIntersection());
}

Direction Board::handleIntersection(Direction dir) {
    cout << endl;
    cout << "This tile is an intersection. Press 1 to continue on your path, or 2 to take a new path." << endl;
    int op = 0;
    while (op != 1 && op != 2) {
        cin >> op;
    }
    cout << "\x1B[2J\x1B[H";
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

void Board::resurrect(std::shared_ptr<Player> player) {
    player->reset();
    positions[player->Options()->id] = {Direction::RIGHT, {0,0}};
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
    map[0][2] = make_shared<TrapTile>(std::move(map[0][2]));
    display->notify();
}

void Board::print() {
    std::cout << "\x1B[2J\x1B[H";
    display->print();
}

// Getters
vector<vector<shared_ptr<Tile>>> Board::getState() {
    return map;
}

unordered_map<int, pair<::Direction, pair<int, int>>> Board::getPositions() {
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
            {baseCell(), cardTile(), baseCell(), baseCell(),     gradeTile(), baseCell(), degreeTile(), baseCell(), baseCell(),baseCell(), baseCell(), baseCell(), baseCell(), baseCell(true),  baseCell(), baseCell(), baseCell(), baseCell(),},
            {baseCell(), nullptr,    nullptr,    baseCell(),     nullptr,    nullptr,    nullptr,    nullptr,    nullptr,      nullptr,    nullptr,    nullptr,    nullptr,    baseCell(),      nullptr,    nullptr,    nullptr,    baseCell(),},
            {baseCell(), nullptr,    nullptr,    baseCell(),     nullptr,    nullptr,    nullptr,    nullptr,    nullptr,      nullptr,    nullptr,    nullptr,    nullptr,    baseCell(),      nullptr,    nullptr,    nullptr,    baseCell(),},
            {baseCell(), nullptr,    nullptr,    baseCell(),     nullptr,    nullptr,    nullptr,    nullptr,    nullptr,      nullptr,    nullptr,    nullptr,    nullptr,    baseCell(),      nullptr,    nullptr,    nullptr,    baseCell(),},
            {baseCell(), nullptr,    nullptr,    baseCell(),     nullptr,    nullptr,    nullptr,    nullptr,    nullptr,      nullptr,    nullptr,    nullptr,    nullptr,    baseCell(),      nullptr,    nullptr,    nullptr,    baseCell(),},
            {baseCell(), nullptr,    nullptr,    baseCell(),     nullptr,    nullptr,    nullptr,    nullptr,    nullptr,      nullptr,    nullptr,    nullptr,    nullptr,    baseCell(),      nullptr,    nullptr,    nullptr,    baseCell(),},
            {baseCell(), nullptr,    nullptr,    baseCell(),     nullptr,    nullptr,    nullptr,    nullptr,    nullptr,      nullptr,    nullptr,    nullptr,    nullptr,    baseCell(),      nullptr,    nullptr,    nullptr,    baseCell(),},
            {baseCell(), nullptr,    nullptr,    baseCell(),     nullptr,    nullptr,    nullptr,    nullptr,    nullptr,      nullptr,    nullptr,    nullptr,    nullptr,    baseCell(),      nullptr,    nullptr,    nullptr,    baseCell(),},
            {baseCell(), baseCell(), baseCell(), baseCell(true), baseCell(), baseCell(), baseCell(), baseCell(), baseCell(),   beaconTile(), healthTile(), cardTile(), abilityTile(), baseCell(), baseCell(), baseCell(), baseCell(), baseCell(),},
    };

    return board;
}

