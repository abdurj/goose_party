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

const vector<vector<shared_ptr<Tile>>> Board::getState(){
    return map;
}

void Board::update(){
    map[0][2] = make_shared<TrapTile>(map[0][0].get());
    display->notify();
}

void Board::print(){
    display->print();
}