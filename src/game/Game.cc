#include <memory>
#include <vector>
#include <iostream>

#include "game/Game.h"
#include "board/Board.h"
#include "player/Player.h"

using namespace std;

void Game::play(){
    Board b;
    b.print();
    
    vector<shared_ptr<Player>> players;
    players.emplace_back(make_shared<Player>(PlayerClass::FIGHTER));
    b.addPlayer(players[0]);
    char c;
    while (cin >> c) {
        
        if (c == 'q') {
            break;
        }
        b.update();
        b.print();
    }
    
}
