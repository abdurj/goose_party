#include "player/Player.h"

using namespace ftxui;
using namespace std;

Player::Player(PlayerOptions p): degrees{0}, grades{0}, options{p} {
}


int Player::Grades() const {return grades;}

void Player::addGrades(int amt) {
    grades+=amt;
}

Element Player::getPlayerTile() {
    return text( "P" + to_string(options.playerNum)) | border | center;
}
