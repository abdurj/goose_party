#include <memory>
#include <vector>
#include <iostream>

#include "game/Game.h"
#include "board/Board.h"
#include "player/Player.h"
#include "player/BasePlayer.h"
#include "utils/Utils.h"


using namespace std;

void Game::notifyWinner(Player &p) {
    cout << p.Options()->name << " has won the game!" << endl;
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
    auto abdur = make_shared<BasePlayer>(make_shared<PlayerOptions>(PlayerClass::FIGHTER, "Abdur", 1));
    // auto fei = make_shared<BasePlayer>(make_shared<PlayerOptions>(PlayerClass::DEFENDER, "Fei", 2));
    // auto kev = make_shared<BasePlayer>(make_shared<PlayerOptions>(PlayerClass::MESSENGER, "Kev", 3));
    // auto kp = make_shared<BasePlayer>(make_shared<PlayerOptions>(PlayerClass::ROGUE, "KP", 4));
    players.insert(players.end(), {abdur});

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
            cout << "It is " << players[curTurn]->Options()->name << "'s turn." << " (Player " << players[curTurn]->Options()->id << ")" << endl;
            cout << "Enter 'm' to roll. Note that this would mark the end of your turn." << endl;
            cout << "Enter 'c' to list the cards you have." << endl; // TODO: allow player to print card description if given an i first, tell them 
            cin >> c; 

            switch (c) {
                case 'm':
                    {                
                    cout << "Moving Player: " << curTurn + 1 << "." << endl;
                    cout << "Rolling..." << endl;

                    int moves = utils::roll(players[curTurn]);

                    b.move(players[curTurn], 1);
                    players[curTurn]->endTurn();
                    
                    break;
                    }
                case 'c':
                    {
                        int size = players[curTurn]->listCards();
                        if (size <= 0) break;
                        cout << "Enter a number from 0 to " << size - 1 << " to use a card, -1 to not use anything" << endl;
                        int index;
                        
                        cin >> index;
                        if (index < 0 || index >= size) {
                            break;
                        }
                        if (players[curTurn]->requiresTarget(index)) {
                            cout << "Available Players: ";
                            for (auto i : players) {
                                cout << " " << i->Options()->name << ",";
                            }
                            cout << endl;
                            cout << "Enter a number from 0 to " << players.size() - 1 << " to pick a player, or -1 to exit" << endl;
                            int i = 0;
                            cin >> i;
                            if (i < 0 || i >= players.size()) {
                                break;
                            }
                            players[curTurn]->useCard(index, players[i], &b);
                            

                        }
                        players[curTurn]->useCard(index, players[curTurn], &b);
                            
                        

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

        if(((curTurn + 1) % players.size())==0) {
            for(auto p : players) {
                p->endCycle();
            }
        }

        curTurn = (curTurn + 1) % players.size();
    }
    
}



