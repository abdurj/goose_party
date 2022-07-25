#ifndef HEALTH_TILE_H
#define HEALTH_TILE_H

#include "tiles/Tile.h"
#include "ftxui/dom/elements.hpp"

class HealthTile : public Tile{
  public:
    HealthTile(int);
    void apply(std::shared_ptr<Player> &) override;
    ftxui::Element tileElement() override;
    ftxui::Element getElement() override;
};

#endif
