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
    auto fei = make_shared<BasePlayer>(make_shared<PlayerOptions>(PlayerClass::DEFENDER, "Fei", 2));
    auto kev = make_shared<BasePlayer>(make_shared<PlayerOptions>(PlayerClass::MESSENGER, "Kev", 3));
    auto kp = make_shared<BasePlayer>(make_shared<PlayerOptions>(PlayerClass::ROGUE, "KP", 4));
    players.insert(players.end(), {abdur, fei, kev, kp});

    // randomize player order
    utils::shufflePlayers(players);
    // add all the players.
    for (auto &i: players) {
        b.addPlayer(i);
    }

    playing = true;
}

void Game::endCycle() {
    for (auto p: players) {
        p->endCycle();
    }
}

bool Game::input(string c) {
    auto currPlayer = players[curTurn];
    if (c == "m") {
        if(!currPlayer->alive()){
            cout << currPlayer->Options()->name << " is being resurrected. " << endl;
            b.resurrect(currPlayer);
        }
        cout << "Moving Player: " << curTurn + 1 << "." << endl;
        cout << "Rolling..." << endl;

        int moves = utils::roll();

        b.move(currPlayer, moves);

        vector<int> potentialBattles = b.checkCollision(currPlayer);
        if (!potentialBattles.empty()) {
            for (const auto &id: potentialBattles) {
                shared_ptr<Player> opponent = getPlayer(id);
                if (opponent) {
                    challenge(currPlayer, opponent);
                }
            }
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
                }
                currPlayer->useCard(index, players[i], &b);
            }
            currPlayer->useCard(index, currPlayer, &b);
        } else {
            cout << "Chosen card index is out of range / doesn't exist." << endl;
        }

    } else if (c == "q") {
        playing = false;
    } else {
        cout << "Invalid move. If you want a list of possible commands, type \"h\"" << endl;
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
    }
}

void Game::battle(std::shared_ptr<Player> challenger, std::shared_ptr<Player> opponent){
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
        cout << opponentName << " took " << damage << " damage!" << endl;
        opponent->takeDamage(damage);
    }else{
        cout << opponentName << " chose to evade! " << endl;
        int evade = utils::roll(opponent->Options()->luck);
        int damage = attack;
        if(evade >= attack){
            damage = 0;
        }
        cout << opponentName << " took " << damage << " damage!" << endl;
        opponent->takeDamage(damage);
    }
}

void Game::GameLoop() {
    string c = "";
    cin.exceptions(ios::eofbit | ios::failbit);

    while (playing) {
        cout << "It is " << players[curTurn]->Options()->name << "'s turn." << " (Player "
             << players[curTurn]->Options()->id << ")" << endl;
        cout << "Enter 'm' to roll. Note that this would mark the end of your turn." << endl;
        cout << "Enter 'c' to list the cards you have."
             << endl; // TODO: allow player to print card description if given an i first, tell them
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




