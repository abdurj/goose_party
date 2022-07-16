#ifndef TILE_H
#define TILE_H

#include "ftxui/dom/elements.hpp"

class Tile{
  public:
    virtual ftxui::Element tileElement() = 0;
    virtual ftxui::Element getElement() = 0;
    ~Tile();
};

#endif //TILE_H