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

void Game::setup() {
    string name;
    int id = 1;
    while (true) {
        if (id == 9) break; //8 players max
        cout <<
             "To add a player to the game, enter the player's name. To finish setup, type \"done\"."
             << endl;
        try {
            cin >> name;
            if (name == "done") break;

            cout << "What class is " << name << "?" << endl;
            PlayerClass playerClass;
            cout << "1. Fighter" << endl << "2. Defender" << endl
                 << "3. Messenger" << endl << "4. Rogue" << endl;

            int i = 0;
            cin >> i;
            if (i == 1) {
                playerClass = PlayerClass::FIGHTER;
            } else if (i == 2) {
                playerClass = PlayerClass::DEFENDER;
            } else if (i == 3) {
                playerClass = PlayerClass::MESSENGER;
            } else if (i == 4) {
                playerClass = PlayerClass::ROGUE;
            }

            if (i >= 1 && i <= 4) {
                players.emplace_back(
                        make_shared<BasePlayer>(
                                make_shared<PlayerOptions>(playerClass, name, id++)
                        )
                );
            } else {
                cout << "Invalid class." << endl;
            }

        } catch (...) {
            cerr << "An error occurred when adding a player." << endl;
            cin.clear();
            cin.ignore(10000, '\n');
        }
    }
    cin.clear();
    cin.ignore(10000, '\n');
}

void Game::init() {
    setup();

    // randomize player order
    utils::shufflePlayers(players);

    beacons.emplace_back(make_shared<TuitionBeacon>());
    beacons.emplace_back(make_shared<ExamBeacon>());

    playing = true;
}

void Game::endCycle() {
    for (auto &p: players) {
        p->endCycle(players);
    }
    for (auto &beacon: beacons) {
        if (beacon->period() == PeriodType::Cycle && beacon->Duration() > 0) {
            beacon->effect(players, b);
            beacon->decrementDuration();
        }
    }
}

bool Game::input(string c) {
    auto currPlayer = players[curTurn];
    if (c == "m") {

        cout << "Rolling..." << endl;
        int moves = utils::roll(currPlayer->Rolls());

        b.move(currPlayer, moves);

        vector<int> potentialBattles = b.checkCollision(currPlayer);
        if (!potentialBattles.empty()) {
            for (const int &id: potentialBattles) {
                challenge(currPlayer, getPlayer(id));
            }
            b.print();
        }
        currPlayer->endTurn(players);

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
        if (!(cin >> index)) {
            cout << "Invalid cmd" << endl;
            cin.clear();
            cin.ignore(10000, '\n');
            return true;
        }
        if (index < 0) {
            return true;
        }
        if (!(index >= size || size <= 0)) {
            if (currPlayer->requiresTarget(index)) {
                cout << "Available Players: ";
                for (const auto &i: players) {
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
        } else {
            cout << "Chosen card index is out of range / doesn't exist." << endl;
        }
    } else if (c == "ci") {
        currPlayer->cardDescriptions();
    } else if(c == "beacons") {
        for(auto &beacon : beacons) {
            beacon->Desc();
        }
    } else if(c == "inspect") {
        int player;
        cin >> player;
        if(player > 0 && player <= players.size()) {
            getPlayer(player)->info();
            getPlayer(player)->ListAbilities();
        } else {
            cout << "Invalid Player" << endl;
        }
    } else if (c == "q") {
        playing = false;
    } else {
        return false;
    }
    return true;
}

void Game::challenge(const std::shared_ptr<Player> &challenger, const std::shared_ptr<Player> &opponent) {
    if (!challenger || !opponent || !challenger->alive() || !opponent->alive()) {
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

void Game::battle(const std::shared_ptr<Player> &challenger, const std::shared_ptr<Player> &opponent) {
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
    int attack = utils::roll() + challenger->Options()->attack;
    this_thread::sleep_for(chrono::milliseconds(750));
    if (option == 'd') {
        cout << opponentName << " chose to defend! " << endl;
        int defend = utils::roll() + opponent->Options()->defence;
        this_thread::sleep_for(chrono::milliseconds(500));
        int damage = max(0, attack - defend);
        opponent->modifyHP(-damage);
    } else {
        cout << opponentName << " chose to evade! " << endl;
        int evade = utils::roll() + opponent->Options()->luck;
        this_thread::sleep_for(chrono::milliseconds(500));
        int damage = attack;
        if (evade >= attack) {
            damage = 0;
        }
        opponent->modifyHP(-damage);
    }
    this_thread::sleep_for(chrono::milliseconds(500));
}

void Game::GameLoop() {
    string c;

    while (playing) {
        auto currPlayer = players[curTurn];
        if (!currPlayer->alive()) {
            b.resurrect(currPlayer);
            b.update();
            b.print();
            cout << endl << currPlayer->Options()->name << " is being resurrected. " << endl;
            curTurn = (curTurn + 1) % players.size();
        } else {
            auto name = currPlayer->Options()->name;
            auto id = currPlayer->Options()->id;
            cout << endl;
            cout << "It is " << name << "'s turn." << " (Player "
                 << id << ")" << endl;
            cout << name << " you have " << currPlayer->getHP() << "hp a " << currPlayer->Grades() << "% average."
                 << endl;
            cout << "Enter 'm' to roll. Note that this would mark the end of your turn." << endl;
            cout << "Enter 'c' to list the cards you have."
                 << endl;
            cout << "Enter 'ci' to list the cards you have and their descriptions." << endl;
            try {
                cin >> c;
                input(c);
            } catch (...) {
                cerr << "An error occured when processing command" << endl;
                cin.clear();
                cin.ignore(10000, '\n');
            }
        }
    }
}

void Game::activateBeacon(shared_ptr<Player> &p) {
    int i = utils::rng(beacons.size() - 1);
    beacons.at(i)->activate(p);
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

shared_ptr<Player> Game::getPlayer(const int &id) {
    for (const auto &player: players) {
        if (player->Options()->id == id) {
            return player;
        }
    }
    return nullptr;
}




