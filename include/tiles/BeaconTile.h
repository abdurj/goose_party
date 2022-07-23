#ifndef BEACON_TILE_H
#define BEACON_TILE_H

#include "tiles/Tile.h"
#include "ftxui/dom/elements.hpp"

class BeaconTile : public Tile{
  public:
    BeaconTile(bool);
    void apply(std::shared_ptr<Player> &) override;
    ftxui::Element tileElement() override;
    ftxui::Element getElement() override;
};

#endif
