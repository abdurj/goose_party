#ifndef BASE_TILE_H
#define BASE_TILE_H

#include "tiles/Tile.h"
#include "ftxui/dom/elements.hpp"

class BaseTile : public Tile{
    ftxui::Element tileElement() override;
    ftxui::Element getElement() override;
};

#endif // BASE_TILE_H
