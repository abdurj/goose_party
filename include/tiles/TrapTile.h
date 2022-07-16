#ifndef TRAP_TILE_H
#define TRAP_TILE_H

#include "tiles/TileDecorator.h"
#include "ftxui/dom/elements.hpp"

class TrapTile : public TileDecorator{
  ftxui::Element stylize(ftxui::Element) override;
  public:
    TrapTile(Tile*);
};

#endif