#include <memory>
#include <vector>
#include <iostream>

#include "game/Game.h"
#include "board/Board.h"
#include "player/Player.h"
#include "utils/Utils.h"

using namespace std;

void Game::play(){
    Board b;
    b.print();
    
    vector<shared_ptr<Player>> players;
    players.emplace_back(make_shared<Player>(PlayerOptions{PlayerClass::FIGHTER, "Abdur", 1}));
    b.addPlayer(players[0]);

    unsigned int curTurn = 0;
    char c;
    while (cin >> c) {
        cout << "It is Player " << curTurn + 1 << "'s turn.";
        if (c == 'm') {
            cout << "Moving Player: " << curTurn + 1 << "." << endl;
            cout << "Rolling..." << endl;

            int moves = utils::roll(players[curTurn]);
            b.move(players[curTurn], moves);

            curTurn = (curTurn + 1) % players.size();
        }

        if (c == 'q') {
            break;
        }

        b.update();
        b.print();
    }
    
}