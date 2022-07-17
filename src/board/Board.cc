#include "board/Board.h"

#include "display/Display.h"

#include "tiles/BaseTile.h"
#include "tiles/TrapTile.h"

using namespace std;
using namespace ftxui;

Board::Board(){
    vector<vector<shared_ptr<Tile>>> tiles;
    for(int i = 0; i < 5; ++i){
        vector<shared_ptr<Tile>> row;
        for(int j = 0; j < 5; ++j){
            if( (i % 2 == 0 && j % 2 == 0) || (i % 2 == 1 && j % 2 == 1) ){
                row.emplace_back(make_shared<BaseTile>());
            }else{
                row.emplace_back(nullptr);
            }
        }
        tiles.emplace_back(row);
    }

    map = tiles;
    x = 5;
    y = 5;

    display = make_unique<Display>(this, x, y);
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