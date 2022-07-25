#ifndef TRAP_TILE_H
#define TRAP_TILE_H

#include "tiles/TileDecorator.h"
#include "ftxui/dom/elements.hpp"

class TrapTile : public TileDecorator{
  std::unique_ptr<TrapCard> trap;
  bool activated;
  ftxui::Element stylize(ftxui::Element) override;
  public:
    void apply(std::shared_ptr<Player> &) override;
    TrapTile(std::shared_ptr<Tile>);
    TrapTile(std::shared_ptr<Tile>, std::unique_ptr<TrapCard>);
};

#endif
