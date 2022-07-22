#include "player/Player.h"
#include <iostream>
#include <string>

using namespace ftxui;
using namespace std;

Player::Player(PlayerOptions p): degrees{0}, grades{100}, options{p} {
}

//Getters
int Player::Grades() const {return grades;}
int Player::Degrees() const {return degrees;}
string Player::Name() const {return options.playerName;}
int Player::PlayerNum() const {return options.playerNum;}

int Player::getAttack() const {return 0;}
int Player::Attack() const {
    return options.defence + getAttack();
}

int Player::getDefence() const {return 0;}
int Player::Defence() const {
    return options.defence + getDefence();
}

int Player::getLuck() const {return 0;}
int Player::Luck() const {
    return options.luck + getLuck();
}


//Setters
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


