#ifndef TRAP_TILE_H
#define TRAP_TILE_H

#include "tiles/TileDecorator.h"
#include "ftxui/dom/elements.hpp"

class TrapTile : public TileDecorator{
  ftxui::Element stylize(ftxui::Element) override;
  public:
    void apply(std::shared_ptr<Player> &) override;
    TrapTile(std::shared_ptr<Tile>);
};

#endif