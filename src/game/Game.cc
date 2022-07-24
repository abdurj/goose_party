#include <memory>
#include <vector>
#include <iostream>

#include "game/Game.h"
#include "board/Board.h"
#include "player/Player.h"
#include "player/BasePlayer.h"
#include "utils/Utils.h"
#include "beacon/Beacon.h"
#include "beacon/TutionBeacon.h"

using namespace std;

void Game::notifyWinner(Player &p) {
    cout << p.Options()->name << " has won the game!" << endl;
    playing = false;
}

Game::Game() : b{Board()} {
    b.attach(this);
}

void Game::setup() {
    bool settingUp = true;
    string name;
    int id = 1;
    while(settingUp) {
        if(id == 9) break; //8 players max
        cout << 
        "To add a player to the game, enter the player's name. To finish setup, type \"done\"." 
        << endl;
        try{
            cin >> name;
            if(name == "done") break;

            cout << "What class is " << name << "?"<<endl;
            PlayerClass playerClass;
            cout << "1. Fighter" << endl << "2. Defender" << endl
            << "3. Messenger" << endl << "4. Rogue" << endl;

            int i = 0;
            cin >> i;
            if(i == 1) {
                playerClass = PlayerClass::FIGHTER;
            } else if( i == 2) {
                playerClass = PlayerClass::DEFENDER;
            } else if( i == 3) {
                playerClass = PlayerClass::MESSENGER;
            } else if( i == 4) {
                playerClass = PlayerClass::ROGUE;
            }

            if(i >= 1 && i <= 4) {
                players.emplace_back(
                make_shared<BasePlayer>(
                    make_shared<PlayerOptions>(playerClass, name, id++)
                    )
                );
            } else {
                cout << "Invalid class." << endl;
            }
            
        } catch (...) {
            cerr << "An error occured when adding a player." << endl;
        }
    }
}

void Game::init() {
    setup();
/*     auto abdur = make_shared<BasePlayer>(make_shared<PlayerOptions>(PlayerClass::FIGHTER, "Abdur", 1));
    auto fei = make_shared<BasePlayer>(make_shared<PlayerOptions>(PlayerClass::DEFENDER, "Fei", 2));
    auto kev = make_shared<BasePlayer>(make_shared<PlayerOptions>(PlayerClass::MESSENGER, "Kev", 3));
    auto kp = make_shared<BasePlayer>(make_shared<PlayerOptions>(PlayerClass::ROGUE, "KP", 4));
    players.insert(players.end(), {abdur, fei, kev, kp}); */

    // randomize player order
    utils::shufflePlayers(players);
    // add all the players.
    for (auto &i : players) {
        b.addPlayer(i);
    }
    
    beacons.emplace_back(make_shared<TutionBeacon>());
    playing = true;
}

void Game::endCycle() {
    for(auto &p : players) {
        p->endCycle();
    }
    for(auto &beacon : beacons) {
        if(beacon->period() == PeriodType::Cycle && beacon->Duration() > 0) {
            beacon->effect(players, b);
            beacon->decrementDuration();
        }
    }
}

bool Game::input(string c) { //Returns false when command (c) is an invalid command. Returns true otherwise
    if(c == "m") {
        cout << "Moving Player: " << curTurn + 1 << "." << endl;
        cout << "Rolling..." << endl;

        int moves = utils::roll(players[curTurn]);

        b.move(players[curTurn], moves);
        players[curTurn]->endTurn();

        if(((curTurn + 1) % players.size())==0) {
            endCycle();
        }

        curTurn = (curTurn + 1) % players.size();

    } else if(c == "c") {
        int size = players[curTurn]->listCards();
        if(size == 0) {
            cout << "There are no cards in the player's deck!" << endl;
            return true;
        }
        cout << "Enter a number from 0 to " << size - 1 << " to use a card, -1 to not use anything" << endl;

        int index;
        cin >> index;

        if(index < 0) {
            return true;
        }
        if (!(index >= size || size <= 0)) {
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
                }
                players[curTurn]->useCard(index, players[i], &b);
                b.update();
                b.print();
            } else {
                players[curTurn]->useCard(index, players[curTurn], &b); 
                b.update();
                b.print();
            }
        } 
        else {
            cout << "Chosen card index is out of range / doesn't exist." << endl;
        }
    } else if (c == "q") {
        playing = false;
    } else {
        return false;
    }

    return true;
}

void Game::GameLoop() {
    string c = "";
    cin.exceptions(ios::eofbit|ios::failbit);

    while (playing) {
        cout << "It is " << players[curTurn]->Options()->name << "'s turn." << " (Player " << players[curTurn]->Options()->id << ")" << endl;
        cout << "Enter 'm' to roll. Note that this would mark the end of your turn." << endl;
        cout << "Enter 'c' to list the cards you have." << endl; // TODO: allow player to print card description if given an i first, tell them
        try {
            cin >> c; 
            if(!input(c)) cout << "Invalid move. If you want a list of possible commands, type \"h\"" << endl;
        } catch (...) {
            cerr << "An error occured when processing command. Ending game." << endl;
            playing = false;
            break;
        }
    }
}

void Game::activateBeacon(int i, shared_ptr<Player> &p) {
    beacons[i]->activate(p);
}

void Game::play() {
    init();
    if (players.size() < 2) {
        cerr << "Not enough players to start the game. At least 2 player are required." << endl;
        return;
    }
    b.print();
    curTurn = 0;
    GameLoop();
}



