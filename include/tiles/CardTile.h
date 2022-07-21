#ifndef CARD_TILE_H
#define CARD_TILE_H

#include "tiles/Tile.h"
#include "ftxui/dom/elements.hpp"

class CardTile : public Tile{
  public:
    CardTile(bool);
    void apply(std::shared_ptr<Player>) override;
    ftxui::Element tileElement() override;
    ftxui::Element getElement() override;
};

#endif
