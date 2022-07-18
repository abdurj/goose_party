#include "board/Board.h"

#include "display/Display.h"

#include "tiles/BaseTile.h"
#include "tiles/TrapTile.h"
#include "tiles/DegreeTile.h"
using namespace std;
using namespace ftxui;
vector<vector<shared_ptr<Tile>>> Board::getMapOne() {
    vector<vector<shared_ptr<Tile>>> board = {
        {baseCell(), baseCell(), baseCell(), baseCell(), baseCell(), baseCell(), baseCell(), baseCell(), baseCell(), nullptr, nullptr },
        {baseCell(), nullptr,    nullptr,    nullptr   , nullptr   , nullptr   , nullptr   , nullptr   , baseCell(), nullptr, nullptr },
        {baseCell(), baseCell(), baseCell(), baseCell(), baseCell(), baseCell(), baseCell(), baseCell(), baseCell(), nullptr, nullptr },
        {baseCell(), nullptr,    nullptr,    nullptr   , nullptr   , nullptr   , nullptr   , nullptr   , baseCell(), nullptr, nullptr },
        {baseCell(), baseCell(), baseCell(), baseCell(), baseCell(), baseCell(), baseCell(), baseCell(), baseCell(), baseCell(), baseCell()},
        {baseCell(), nullptr,    nullptr,    nullptr   , nullptr   , nullptr   , nullptr   , nullptr   , baseCell(), nullptr   , baseCell()},
        {baseCell(), nullptr,    nullptr,    nullptr   , nullptr   , nullptr   , nullptr   , nullptr   , baseCell(), nullptr   , baseCell()},
        {baseCell(), nullptr,    nullptr,    nullptr   , nullptr   , nullptr   , nullptr   , nullptr   , baseCell(), nullptr   , baseCell()},
        {baseCell(), baseCell(), baseCell(), baseCell(), nullptr   , nullptr   , baseCell(), baseCell(), baseCell(), nullptr   , baseCell()},
        {nullptr   , nullptr   , nullptr   , baseCell(), nullptr   , nullptr   , baseCell(), nullptr   , baseCell(), nullptr   , baseCell()},
        {nullptr   , nullptr   , nullptr   , baseCell(), nullptr   , nullptr   , baseCell(), nullptr   , baseCell(), baseCell(), baseCell()},
        {nullptr   , nullptr   , nullptr   , baseCell(), nullptr   , nullptr   , baseCell(), nullptr   , nullptr   , nullptr   , baseCell()},
        {nullptr   , nullptr   , nullptr   , baseCell(), nullptr   , nullptr   , baseCell(), nullptr   , nullptr   , nullptr   , baseCell()},
        {nullptr   , nullptr   , nullptr   , baseCell(), baseCell(), baseCell(), baseCell(), baseCell(), baseCell(), baseCell(), baseCell()},
    };
    return board;
}

vector<vector<shared_ptr<Tile>>> Board::getMapTwo() {
    vector<vector<shared_ptr<Tile>>> board = {
        {baseCell(), baseCell(), baseCell(), baseCell(), baseCell(), baseCell(), baseCell(), baseCell(), baseCell(), baseCell(), baseCell(), baseCell(), baseCell(), baseCell(), baseCell(), baseCell(), baseCell(), baseCell(), },
        {baseCell(), nullptr   , nullptr   , baseCell(), nullptr   , nullptr   , nullptr   , nullptr   , baseCell(), nullptr   , baseCell(), nullptr   , nullptr   , nullptr   , nullptr   , baseCell(), nullptr   , baseCell(), },
        {baseCell(), nullptr   , nullptr   , baseCell(), nullptr   , nullptr   , nullptr   , nullptr   , baseCell(), baseCell(), baseCell(), nullptr   , nullptr   , nullptr   , nullptr   , baseCell(), nullptr   , baseCell(), },
        {baseCell(), nullptr   , nullptr   , baseCell(), nullptr   , nullptr   , nullptr   , nullptr   , nullptr   , nullptr   , baseCell(), nullptr   , nullptr   , baseCell(), baseCell(), baseCell(), nullptr   , baseCell(), },
        {baseCell(), nullptr   , nullptr   , baseCell(), nullptr   , nullptr   , nullptr   , nullptr   , nullptr   , nullptr   , baseCell(), nullptr   , nullptr   , baseCell(), nullptr   , nullptr   , nullptr   , baseCell(), },
        {baseCell(), nullptr   , nullptr   , baseCell(), baseCell(), baseCell(), baseCell(), baseCell(), baseCell(), baseCell(), baseCell(), nullptr   , nullptr   , baseCell(), nullptr   , nullptr   , nullptr   , baseCell(), },
        {baseCell(), nullptr   , nullptr   , baseCell(), nullptr   , nullptr   , nullptr   , nullptr   , nullptr   , nullptr   , baseCell(), nullptr   , nullptr   , baseCell(), nullptr   , nullptr   , nullptr   , baseCell(), },
        {baseCell(), nullptr   , nullptr   , baseCell(), nullptr   , nullptr   , nullptr   , nullptr   , nullptr   , nullptr   , baseCell(), nullptr   , nullptr   , baseCell(), nullptr   , nullptr   , nullptr   , baseCell(), },
        {baseCell(), baseCell(), baseCell(), baseCell(), baseCell(), baseCell(), baseCell(), baseCell(), degreeTile(), baseCell(), baseCell(), baseCell(), baseCell(), baseCell(), baseCell(), baseCell(), baseCell(), baseCell(), },
    };
    return board;
}


Board::Board() {
    // vector<vector<shared_ptr<Tile>>> tiles;
    // for(int i = 0; i < 5; ++i){
    //     vector<shared_ptr<Tile>> row;
    //     for(int j = 0; j < 5; ++j){
    //         if( (i % 2 == 0 && j % 2 == 0) || (i % 2 == 1 && j % 2 == 1) ){
    //             row.emplace_back(make_shared<BaseTile>());
    //         }else{
    //             row.emplace_back(nullptr);
    //         }
    //     }
    //     tiles.emplace_back(row);
    // }
    map = Board::getMapTwo();
    //int g = 0;
    // for (auto i : map) {
    //     cout << "row: " << g++ << " ";
    //     int h = 0;
    //     for (auto j : i) {
    //         if (j == nullptr) {
    //             cout << "null ";
    //         } else {
    //             cout << "column: " << h++ << " ";
    //         }
    //     }
    //     cout << endl;

    // }
    //    map = tiles;
    x = map.at(0).size();
    y = map.size();

    display = make_unique<Display>(this, x, y);
}

shared_ptr<Tile> Board::baseCell() {
    return make_shared<BaseTile>();
}

shared_ptr<Tile> Board::degreeTile() {
    return make_shared<DegreeTile>();
}



void Board::addPlayer(std::shared_ptr<Player> p){
    positions[p] = {2,2};
    display->notify();
}


const vector<vector<shared_ptr<Tile>>> Board::getState(){
    return map;
}

const unordered_map<shared_ptr<Player>, pair<int,int>> Board::getPositions(){
    return positions;
}

void Board::update(){
    map[0][2] = make_shared<TrapTile>(move(map[0][2]));
    display->notify();
}

void Board::print(){
    display->print();
}

