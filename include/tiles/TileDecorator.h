#ifndef TILE_DECORATOR_H
#define TILE_DECORATOR_H

#include "tiles/Tile.h"
#include "ftxui/dom/elements.hpp"

class TileDecorator : public Tile{
  Tile* tile;
  
  virtual ftxui::Element stylize(ftxui::Element) = 0;

  public:
    TileDecorator(Tile*);

    ftxui::Element tileElement() override;
    ftxui::Element getElement() override;

    virtual ~TileDecorator();
};

#endif // TILE_DECORATOR_H
