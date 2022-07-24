#include "game/DebugGame.h"
#include <iostream>

using namespace std;


DebugGame::DebugGame() {};

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
    }
}

void DebugGame::GameLoop() {
    string c = "";
    cin.exceptions(ios::eofbit|ios::failbit);

    while (playing) {
        cout << "It is " << players[curTurn]->Options()->name << "'s turn." << " (Player " << players[curTurn]->Options()->id << ")" << endl;
        cout << "Enter 'm' to roll. Note that this would mark the end of your turn." << endl;
        cout << "Enter 'c' to list the cards you have." << endl; // TODO: allow player to print card description if given an i first, tell them
        try {
            cin >> c; 
            if(!input(c)) {
                debugInput(c);
            }
            
        } catch (...) {
            cerr << "An error occured when processing command. Ending game." << endl;
            playing = false;
            break;
        }
    }
}
