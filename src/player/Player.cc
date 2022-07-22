#include "player/Player.h"
#include <iostream>
#include <string>
#include <utility>

using namespace ftxui;
using namespace std;

Player::Player(shared_ptr<PlayerOptions> p): degrees{0}, grades{100}, options{std::move(p)} {
}

//Getters
shared_ptr<PlayerOptions> Player::Options() const {
    return options;
}
int Player::Grades() const {return grades;}
int Player::Degrees() const {return degrees;}

//Setters
int Player::modifyGrades(int amt) { //Returns int because we can re-use this for "stealing" grades
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
    return text( "P" + to_string(options->id)) | border | center;
}


