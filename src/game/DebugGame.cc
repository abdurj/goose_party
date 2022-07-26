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
            auto p = getPlayer(player);
            b.move(p, amt);
        } else if (c == "battle") {
            string cmd;
            cin >> cmd;
            if (cmd == "check") {
                cin >> player;
                auto p = getPlayer(player);
                vector<int> potentialBattles = b.checkCollision(p);
                if (!potentialBattles.empty()) {
                    for (const int &id: potentialBattles)
                        challenge(p, getPlayer(id));
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
            auto p = getPlayer(player);
            if (c == "grades") {
                cin >> amt;
                p->modifyGrades(amt);
            } else if (c == "degrees") {
                cin >> amt;
                for (int i = 0; i < amt; ++i) {
                    p->modifyGrades(30);
                    p->claimDegree();
                }
            } else if (c == "card") {
                int card;
                cin >> card;
                p->addCard(utils::generateCard(card));
            } else if (c == "abilities") {
                int ability;
                cin >> ability;
                utils::generateAbility(p, ability);
            } else {
                cin.clear();
                cin.ignore();
            }
        } else if (c == "damage") {
            cin >> player;
            cin >> amt;
            auto p = getPlayer(player);
            p->modifyHP(amt);
        } else if (c == "show") {
            cin >> c;
            cin >> player;
            auto p = getPlayer(player);
            if (c == "grades") {
                cout << p->Options()->name << "'s Grades: "
                     << p->Grades() << endl;
            } else if (c == "hp") {
                cout << p->Options()->name << "'s HP: "
                     << p->getHP() << endl;
            } else if (c == "abilities") {
                p->ListAbilities();
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
        }
    } catch (...) {
        cerr << "Invalid debug command." << endl;
        cin.clear();
        cin.ignore(10000, '\n');
    }
}
