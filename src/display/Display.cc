#include "display/Display.h"

#include <iostream>

#include "ftxui/dom/elements.hpp"
#include "ftxui/screen/screen.hpp"

#include "board/Board.h"

using namespace std;
using namespace ftxui;

Display::Display(Board* b, int x, int y) : board{b}, x{x}, y{y} {
    grid.resize(y, vector<Element>(x));
    Display::notify();
};

void Display::notify(){
    const auto tiles = board->getState();
    for(int i = 0; i < y; ++i){
        for(int j = 0; j < x; ++j){
            auto tile = tiles[i][j];
            if(tile){
                grid[i][j] = tile->getElement();
            }else{
                grid[i][j] = filler();
            }
        }
    }

    const auto positions = board->getPositions();
    for (auto [player, pos] : positions){
        auto [i, j] = pos.second;
        grid[i][j] = dbox({
            grid[i][j],
            player->getPlayerTile()
        });
    }

    setSize();
}

void Display::setSize(){
    for(int i = 0; i < grid.size(); ++i){
        for(int j = 0; j < grid[0].size(); ++j){
            grid[i][j] |=  size(WIDTH, EQUAL, 8) | size(HEIGHT, EQUAL, 5);
        }
    }
}

void Display::print(){
    auto gridElement = gridbox(grid) | border;
    auto screen = Screen::Create(Dimension::Fit(gridElement));
    Render(screen, gridElement);
    screen.Print();
    cout << endl;
}

