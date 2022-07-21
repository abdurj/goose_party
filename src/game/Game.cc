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
    // TODO: Dynamically prompt to choose some number of players on init. Could do this outside of game.play(), maybe game.init()? 
    players.emplace_back(make_shared<Player>(PlayerOptions{PlayerClass::FIGHTER, "Abdur", 1}));
    players.emplace_back(make_shared<Player>(PlayerOptions{PlayerClass::DEFENDER, "Fei", 2}));
    players.emplace_back(make_shared<Player>(PlayerOptions{PlayerClass::ROGUE, "sussybaka123", 3}));
    players.emplace_back(make_shared<Player>(PlayerOptions{PlayerClass::MESSENGER, "messenger", 4}));
    //b.addPlayer(players[0]);
    for (auto i : players) {
        b.addPlayer(i);
    }
    unsigned int curTurn = 0;
    char c = '0';
    cin.exceptions(ios::eofbit|ios::failbit);

    bool playing = true;
    while (playing) {
        try {
            cout << "It is Player " << curTurn + 1 << "'s turn." << endl;
            cout << "Enter 'm' to roll. Note that this would mark the end of your turn." << endl;
            cin >> c; 

            switch (c) {
                case 'm':
                    {                
                    cout << "Moving Player: " << curTurn + 1 << "." << endl;
                    cout << "Rolling..." << endl;

                    int moves = utils::roll(players[curTurn]);

                    b.move(players[curTurn], moves);
                    curTurn = (curTurn + 1) % players.size();
                    
                    b.update();
                    b.print();
                    break;
                    }
                case 'q':
                    playing = false;
                    break;
                default:
                    cout << "Invalid move. If you want a list of possible commands, type \"h\"" << endl;
            }

        } catch (...) {
            break;
        }
    }
    
}
