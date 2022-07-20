#ifndef DEGREE_TILE_H
#define DEGREE_TILE_H

#include "tiles/Tile.h"
#include "ftxui/dom/elements.hpp"

class DegreeTile : public Tile{
  public:
    DegreeTile(bool);
    void apply(Player* p) override;
    ftxui::Element tileElement() override;
    ftxui::Element getElement() override;
};

#endif // DEGREE_TILE_H
