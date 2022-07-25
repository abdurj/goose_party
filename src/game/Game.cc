#include <memory>
#include <vector>
#include <iostream>
#include <chrono>
#include <thread>


#include "game/Game.h"
#include "board/Board.h"
#include "player/Player.h"
#include "player/BasePlayer.h"
#include "utils/Utils.h"
#include "beacon/Beacon.h"
#include "beacon/TuitionBeacon.h"
#include "beacon/ExamBeacon.h"

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
    shared_ptr<Player> abdur = make_shared<BasePlayer>(make_shared<PlayerOptions>(PlayerClass::FIGHTER, "Abdur", 1));
    shared_ptr<Player> fei = make_shared<BasePlayer>(make_shared<PlayerOptions>(PlayerClass::DEFENDER, "Fei", 2));
    shared_ptr<Player> kev = make_shared<BasePlayer>(make_shared<PlayerOptions>(PlayerClass::MESSENGER, "Kev", 3));
    shared_ptr<Player> kp = make_shared<BasePlayer>(make_shared<PlayerOptions>(PlayerClass::ROGUE, "KP", 4));
    players.insert(players.end(), {abdur, fei, kev, kp});

    // randomize player order
    utils::shufflePlayers(players);
    // add all the players.
    for (auto &i: players) {
        b.addPlayer(i);
    }
    
    beacons.emplace_back(make_shared<TuitionBeacon>());
    beacons.emplace_back(make_shared<ExamBeacon>());
    //beacons[0]->activate(fei);
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

bool Game::input(string c) {
    auto currPlayer = players[curTurn];
    if (c == "m") {

        cout << "Rolling..." << endl;
        int moves = utils::roll();

        b.move(currPlayer, moves);

        vector<int> potentialBattles = b.checkCollision(currPlayer);
        if (!potentialBattles.empty()) {
            for (const int &id: potentialBattles) {
                shared_ptr<Player> opponent = getPlayer(id);
                if (opponent) {
                    challenge(currPlayer, opponent);
                }
            }
            b.print();
        }
        currPlayer->endTurn();

        curTurn = (curTurn + 1) % players.size();
        if (curTurn == 0) {
            endCycle();
        }
    } else if (c == "c") {
        int size = currPlayer->listCards();
        if (size == 0) {
            cout << "There are no cards in the player's deck!" << endl;
            return true;
        }
        cout << "Enter a number from 0 to " << size - 1 << " to use a card, -1 to not use anything" << endl;

        int index;
        cin >> index;

        if (index < 0) {
            return true;
        }
        if (!(index >= size || size <= 0)) {
            if (currPlayer->requiresTarget(index)) {
                cout << "Available Players: ";
                for (const auto& i: players) {
                    cout << " " << i->Options()->name << ",";
                }
                cout << endl;
                cout << "Enter a number from 0 to " << players.size() - 1 << " to pick a player, or -1 to exit" << endl;
                int i = 0;
                cin >> i;
                if (i < 0 || i >= players.size()) {
                    return true;
                }
                currPlayer->useCard(index, players[i], &b);
                std::cout << "\x1B[2J\x1B[H";
                b.update();
                b.print();
                cout << endl;
            } else {
                currPlayer->useCard(index, currPlayer, &b); 
                std::cout << "\x1B[2J\x1B[H";
                b.update();
                b.print();
                cout << endl;
            }
        } 
        else {
            cout << "Chosen card index is out of range / doesn't exist." << endl;
        }
    } else if (c == "ci") {
        currPlayer->cardDescriptions();
    } else if (c == "q") {
        playing = false;
    } else {
        return false;
    }

    return true;
}

void Game::challenge(std::shared_ptr<Player> challenger, std::shared_ptr<Player> opponent) {
    if (!challenger->alive() || !opponent->alive()) {
        return;
    }
    auto challengerName = challenger->Options()->name;
    auto opponentName = opponent->Options()->name;
    cout << challengerName << " would you like to challenge " << opponentName
         << " to a battle? (y/n)";
    char option;
    cin >> option;
    if (option == 'y') {
        battle(challenger, opponent);
        battle(opponent, challenger);
        char _;
        cout << "Enter any character to continue" << endl;
        cin >> _;
    }
}

void Game::battle(const std::shared_ptr<Player>& challenger, const std::shared_ptr<Player>& opponent){
    if (!challenger->alive() || !opponent->alive()) {
        return;
    }
    auto challengerName = challenger->Options()->name;
    auto opponentName = opponent->Options()->name;

    cout << challengerName << " challenges " << opponentName << " to a battle!" << endl;
    cout << opponentName << " would you like to defend (d) or evade (e)? " << endl;
    char option;
    cin >> option;

    cout << challengerName << " is attacking. " << endl;
    int attack = utils::roll(challenger->Options()->attack);
    if(option == 'd'){
        cout << opponentName << " chose to defend! " << endl;
        int defend = utils::roll(opponent->Options()->defence);
        int damage = max(0, attack-defend);
        opponent->modifyHP(-damage);
    }else{
        cout << opponentName << " chose to evade! " << endl;
        int evade = utils::roll(opponent->Options()->luck);
        int damage = attack;
        if(evade >= attack){
            damage = 0;
        }
        opponent->modifyHP(-damage);
    }
}

void Game::GameLoop() {
    string c = "";
    cin.exceptions(ios::eofbit | ios::failbit);

    while (playing) {
        auto currPlayer = players[curTurn];
        if(!currPlayer->alive()){
            b.resurrect(currPlayer);
            b.update();
            b.print();
            cout << endl << currPlayer->Options()->name << " is being resurrected. " << endl;
            curTurn = curTurn + 1 % players.size();
        }else{
            auto name = currPlayer->Options()->name;
            auto id = currPlayer->Options()->id;
            cout << "It is " << name << "'s turn." << " (Player "
                << id << ")" << endl;
            cout << name << " you have " << currPlayer->getHP() << "hp a " << currPlayer->Grades() << "\% average." << endl;
            cout << "Enter 'm' to roll. Note that this would mark the end of your turn." << endl;
            cout << "Enter 'c' to list the cards you have."
                << endl; 
            cout << "Enter 'ci' to list the cards you have and their descriptions." << endl;
            try {
                cin >> c;
                input(c);
            } catch (...) {
                cerr << "An error occured when processing command. Ending game." << endl;
                playing = false;
                break;
            }
        }
    }
}

void Game::activateBeacon(shared_ptr<Player> &p) {
    //int i = chrono::system_clock::now().time_since_epoch().count() % beacons.size();
    beacons[1]->activate(p);
}

void Game::play() {
    init();
    b.print();
    if (players.empty()) {
        cerr << "Somehow we have 0 players, terminate" << endl;
        return;
    }
    curTurn = 0;
    GameLoop();
}

shared_ptr<Player> Game::getPlayer(const int &id) {
    for (const auto &player: players) {
        if (player->Options()->id == id) {
            return player;
        }
    }
    return nullptr;
}




