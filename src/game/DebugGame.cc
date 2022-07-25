#include "game/DebugGame.h"
#include "beacon/Beacon.h"
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
        try {
            cin >> player;
            cin >> amt;
            b.move(players.at(player), amt);
        } catch(...) {
            cerr << "an error occured" << endl;
        }
    } else if (c == "cycle") {
        endCycle();
    } else if (c == "add") {
        //going to assume that if someone types add, they provide all params
        cin >> c;
        cin >> player;
        cin >> amt;
        if(c == "grades") {
            players.at(player)->modifyGrades(amt);
        } else if (c == "degrees") {
            for(int i = 0; i < amt; ++i) {
                players.at(player)->modifyGrades(30);
                players.at(player)->claimDegree();
            }
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
    }
}
