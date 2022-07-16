#include <iostream>
#include <vector>

#include "game/Game.h"

#include "board/Board.h"

void Game::play(){
    Board b;
    b.print();
    int x;
    std::cin >> x;
    b.update();
    b.print();
}