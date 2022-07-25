#include "tiles/TrapTile.h"
#include <iostream>
using namespace ftxui;
using namespace std;

TrapTile::TrapTile(std::shared_ptr<Tile> t) : TileDecorator(t), activated{false} {};

TrapTile::TrapTile(std::shared_ptr<Tile> t, std::unique_ptr<TrapCard> trap) : TileDecorator(t), trap{std::move(trap)}, activated{false} {}


void TrapTile::apply(shared_ptr<Player> &p) {
    if (!activated) {
        cout << "landed on trap tile, trap activated" << endl;
        trap->activate(p.get());
        activated = true;
    }

}

Element TrapTile::stylize(Element e){
    if (!activated) {
        return e | borderHeavy | color(Color::MediumPurple2Bis);
    }
    return e | border;
}

