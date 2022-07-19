#include <memory>
#include <vector>
#include <iostream>
#include <cstdlib>

#include "game/Game.h"
#include "board/Board.h"
#include "player/Player.h"

using namespace std;

void Game::play(){
    Board b;
    b.print();
    
    vector<shared_ptr<Player>> players;
    players.emplace_back(make_shared<Player>(PlayerOptions{PlayerClass::FIGHTER, "Abdur", 1}));
    b.addPlayer(players[0]);

    int curTurn = 0;
    char c;
    while (cin >> c) {
        cout << "It is Player " << curTurn + 1 << "'s turn.";
        if (c == 'm') {
            cout << "Moving Player: " << curTurn + 1 << "." << endl;
            cout << "Rolling..." << endl;
            int moves = roll(players[curTurn]);
            // b.move(players[curTurn], moves);
            ++curTurn;
            if (curTurn > players.size()) {
                curTurn = 0;
            }
        }
        if (c == 'q') {
            break;
        }
        b.update();
        b.print();
        
    }
    
}

/**
 * @brief Makes a dice roll for a given player
 * 
 * @param p the Player class 
 * @return int The dice roll the player got
 */
int roll(shared_ptr<Player> p) {
    // for now, we will just generate a random number from 0 to 12
    return rand() % 12;
}