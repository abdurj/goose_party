#include "game/DebugGame.h"
#include "beacon/Beacon.h"
#include "utils/Utils.h"
#include <iostream>

using namespace std;


DebugGame::DebugGame() {
    cout << "******* IN DEBUG MODE *******" << endl;
};

bool DebugGame::input(string c) {
    if (!Game::input(c)) {
        debugInput(c);
    }
    return true;
}

void DebugGame::debugInput(string c) {
    int player, amt;
    try {
        if (c == "move") {
            cin >> player;
            cin >> amt;
            int index = getPlayerIndex(player);
            if (index == - 1) return;
            b.move(players.at(index), amt);
        } else if (c == "battle") {
            string cmd;
            cin >> cmd;
            if (cmd == "check") {
                cin >> player;
                int index = getPlayerIndex(player);
                if (index == - 1) return;
                vector<int> potentialBattles = b.checkCollision(players.at(index));
                if (!potentialBattles.empty()) {
                    for (const int &id: potentialBattles)
                        challenge(players.at(index), getPlayer(id));
                }
                b.print();
            } else if (cmd == "force") {
                int id1 = 0;
                int id2 = 0;
                cin >> id1 >> id2;
                challenge(getPlayer(id1), getPlayer(id2));
            }
        } else if (c == "cycle") {
            endCycle();
        } else if (c == "add") {
            cin >> c;
            cin >> player;
            int index = getPlayerIndex(player);
            if (index == - 1) return;
            if (c == "grades") {
                cin >> amt;
                players.at(index)->modifyGrades(amt);
            } else if (c == "degrees") {
                cin >> amt;
                for (int i = 0; i < amt; ++i) {
                    players.at(index)->modifyGrades(30);
                    players.at(index)->claimDegree();
                }
            } else if (c == "card") {
                int card;
                cin >> card;
                players.at(index)->addCard(utils::generateCard(card));
            } else if (c == "abilities") {
                int ability;
                cin >> ability;
                utils::generateAbility(players.at(index), ability);
            } else {
                cin.clear();
                cin.ignore();
            }
        } else if (c == "damage") {
            cin >> player;
            cin >> amt;
            int index = getPlayerIndex(player);
            if (index == - 1) return;
            players.at(index)->modifyHP(amt);
        } else if (c == "show") {
            cin >> c;
            cin >> player;
            int index = getPlayerIndex(player);
            if (index == - 1) return;
            if (c == "grades") {
                cout << players.at(index)->Options()->name << "'s Grades: "
                     << players.at(index)->Grades() << endl;
            } else if (c == "hp") {
                cout << players.at(index)->Options()->name << "'s HP: "
                     << players.at(index)->getHP() << endl;
            } else if (c == "abilities") {
                players.at(index)->ListAbilities();
            } else {
                cin.clear();
                cin.ignore();
            }
        } else if(c == "clear") {
            cout << "\x1B[2J\x1B[H";
        } else if (c == "ordering") {
            cout << "Player Ordering:" << endl;
            for (int i = 0; i < players.size(); i++) {
                cout << i << ": " << getPlayer(i)->Options()->name << endl;
            }
        } else if (c == "turn") {
            try {
                cin >> player;
                int index = getPlayerIndex(player);
                players.at(index)->endTurn(players);
            } catch (...) {
                cout << "invalid player" << endl;
                cin.clear();
                cin.ignore(10000, '\n');
            }
            
        }
    } catch (...) {
        cerr << "Invalid debug command." << endl;
        cin.clear();
        cin.ignore(10000, '\n');
    }
}
