#include "player/Player.h"

using namespace ftxui;
using namespace std;

Player::Player(PlayerOptions p): degrees{0}, grades{0}, options{p} {
    
}

Element Player::getPlayerTile() {
    return text( "P" + to_string(options.playerNum)) | border | center;
}
