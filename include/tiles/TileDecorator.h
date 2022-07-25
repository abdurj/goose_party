#ifndef TILE_DECORATOR_H
#define TILE_DECORATOR_H

#include "tiles/Tile.h"
#include "ftxui/dom/elements.hpp"
#include "cards/TrapCard.h"

class TileDecorator : public Tile{
  
  virtual ftxui::Element stylize(ftxui::Element) = 0;
  protected:
    std::shared_ptr<Tile> tile;


  public:
    TileDecorator(std::shared_ptr<Tile>);
    void apply(std::shared_ptr<Player> &) override;
    ftxui::Element tileElement() override;
    ftxui::Element getElement() override;
    virtual ~TileDecorator();
};

#endif // TILE_DECORATOR_H
