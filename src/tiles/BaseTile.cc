#include "tiles/BaseTile.h"

using namespace ftxui;

Element BaseTile::tileElement(){
    return text(" ");
}

Element BaseTile::getElement(){
    return tileElement() | border;
};
