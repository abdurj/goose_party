#ifndef ABILITY_TILE_H
#define ABILITY_TILE_H

#include "tiles/Tile.h"
#include "ftxui/dom/elements.hpp"

class AbilityTile : public Tile{
  public:
    AbilityTile(bool,bool);
    void apply(std::shared_ptr<Player> &) override;
    ftxui::Element tileElement() override;
    ftxui::Element getElement() override;
};

#endif
