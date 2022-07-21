#include "player/Player.h"
#include <iostream>

using namespace ftxui;
using namespace std;

Player::Player(PlayerOptions p): degrees{0}, grades{0}, options{p} {
}


int Player::Grades() const {return grades;}

void Player::addGrades(int amt) {
    grades+=amt;
}

int Player::deductGrades(int amt) { //Returns int because we can re-use this for "stealing" grades
    grades = max(0, grades - amt);
    return amt;
}

bool Player::claimDegree() { //Returns true if a degree was claimed
    if(grades >= 30) {
        grades = max(0, grades - 30);
        cout << "degree claimed" << endl;
        degrees++;

        if(degrees >= 3) {
            cout << "W player" << endl;
        }
        
        return true;
    }

    return false;
}

Element Player::getPlayerTile() {
    return text( "P" + to_string(options.playerNum)) | border | center;
}

string Player::getName() {
    return options.playerName;
}

int Player::getNum() {
    return options.playerNum;
}
