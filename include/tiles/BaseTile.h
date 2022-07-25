#ifndef BASE_TILE_H
#define BASE_TILE_H

#include "tiles/Tile.h"
#include "ftxui/dom/elements.hpp"

class BaseTile : public Tile{
  public:
    BaseTile(int);
    void apply(std::shared_ptr<Player> &) override;
    ftxui::Element tileElement() override;
    ftxui::Element getElement() override;
};

#endif // BASE_TILE_H
