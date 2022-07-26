#include "game/DebugGame.h"
#include "beacon/Beacon.h"
#include "utils/Utils.h"
#include <iostream>

using namespace std;


DebugGame::DebugGame() {};

bool DebugGame::input(string c){
    if(!Game::input(c)){
        debugInput(c);
    }
    return true;
}

void DebugGame::debugInput(string c) {
    int player, amt;
    if(c == "move") {
        cin >> player;
        cin >> amt;
        b.move(players.at(player), amt);

        vector<int> potentialBattles = b.checkCollision(players.at(player));
        if (!potentialBattles.empty()) {
            for (const int &id: potentialBattles) {
                shared_ptr<Player> opponent = getPlayer(id);
                if (opponent) {
                    challenge(getPlayer(player), opponent);
                }
            }
            b.print();
        }
    } else if (c == "cycle") {
        endCycle();
    } else if (c == "add") {
        cin >> c;
        cin >> player;
        
        if(c == "grades") {
            cin >> amt;
            players.at(player)->modifyGrades(amt);
        } else if (c == "degrees") {
            cin >> amt;
            for(int i = 0; i < amt; ++i) {
                players.at(player)->modifyGrades(30);
                players.at(player)->claimDegree();
            }
        } else if (c == "card") {
            players.at(player)->addCard(utils::generateCard());
        }
    } else if (c == "damage"){
        cin >> player;
        cin >> amt;
        players.at(player)->modifyHP(amt);
    } else if (c == "show") {
        cin >> c;
        cin >> player;
        if(c == "grades") {
            cout << players.at(player)->Options()->name << "'s Grades: "
            << players.at(player)->Grades() << endl;
        } else if (c == "hp") {
            cout << players.at(player)->Options()->name << "'s HP: "
            << players.at(player)->getHP() << endl;
        } else if (c == "abilities") {
            players.at(player)->ListAbilities();
        }
    } else if(c == "beacons") {
        for(auto &beacon : beacons) {
            beacon->Desc();
        }
    } else if(c == "clear") {
        system("clear");
    } else if(c == "ordering") {
        cout << "Player Ordering:" << endl;
        for(int i = 0; i < players.size(); i++) {
            cout << i << ": " << players.at(i)->Options()->name << endl;
        }
    } else if(c == "inspect") {
        cin >> player;
        players.at(player)->info();
    }
}
