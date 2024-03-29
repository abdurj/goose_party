#include "display/Display.h"

#include <iostream>

#include "ftxui/dom/elements.hpp"
#include "ftxui/screen/screen.hpp"

#include "board/Board.h"

using namespace std;
using namespace ftxui;

namespace {
    Element getPlayerTile(int id) {
        return text( "P" + to_string(id)) | border | center;
    }
}

Display::Display(Board* b, int x, int y) : board{b}, x{x}, y{y}, screen{0,0} {
    grid.resize(y, vector<Element>(x));
    Display::notify();
    screen = Screen::Create(Dimension::Fit(gridElement));
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
            getPlayerTile(player)
        });
    }

    setSize();

    gridElement = gridbox(grid) | border;
}

void Display::setSize(){
    for(int i = 0; i < grid.size(); ++i){
        for(int j = 0; j < grid[0].size(); ++j){
            grid[i][j] |=  size(WIDTH, EQUAL, 8) | size(HEIGHT, EQUAL, 5);
        }
    }
}

void Display::clear(){
    std::cout << "\x1B[2J\x1B[H";
}

void Display::print(){
    screen.Clear();
    auto reset = screen.ResetPosition();
    Render(screen, gridElement);
    cout << reset;
    screen.Print();
}

