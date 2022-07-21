#include <memory>
#include <vector>
#include <iostream>

#include "game/Game.h"
#include "board/Board.h"
#include "player/Player.h"
#include "utils/Utils.h"


using namespace std;

void Game::notifyWinner(Player &p) {
    cout << p.Name() << " has won the game!" << endl;
    playing = false;
}

Game::Game() : b{Board()} {
    b.attach(this);
}

void Game::init() {
    // TODO: On init, prompt the game maker to enter the number of players, the name of each player. 
    // int n = 0;
    // while (n < 2 || n > 8) {
    //     cout << "Enter the number of players (2-8):" << endl;
    //     cin >> n;
    // }
    // for (int i = 0; i < n; ++i) {
    //     cout << "Player " << i + 1 << " , please enter your name" << endl;
    // }

    players.emplace_back(make_shared<Player>(PlayerOptions{PlayerClass::FIGHTER, "Abdur", 1}));
    //players.emplace_back(make_shared<Player>(PlayerOptions{PlayerClass::DEFENDER, "Fei", 2}));
    //players.emplace_back(make_shared<Player>(PlayerOptions{PlayerClass::ROGUE, "sussybaka123", 3}));
    //players.emplace_back(make_shared<Player>(PlayerOptions{PlayerClass::MESSENGER, "messenger", 4}));

    // randomize player order
    utils::shufflePlayers(players);
    // add all the players.
    for (auto i : players) {
        b.addPlayer(i);
    }
    
    playing = true;
}

void Game::play() {
    init();
    b.print();
    if (players.empty()) {
        cerr << "Somehow we have 0 players, terminate" << endl;
        return;
    }
    unsigned int curTurn = 0;
    char c = '0';
    cin.exceptions(ios::eofbit|ios::failbit);

    while (playing) {
        try {
            cout << "It is " << players[curTurn]->Name() << "'s turn." << " (Player " << players[curTurn]->PlayerNum() << ")" << endl;
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
