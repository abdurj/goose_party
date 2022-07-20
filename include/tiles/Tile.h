#ifndef TILE_H
#define TILE_H

#include "ftxui/dom/elements.hpp"

class Tile{
  bool intersection;
  public:
    Tile(bool);
    bool isIntersection();
    virtual ftxui::Element tileElement() = 0;
    virtual ftxui::Element getElement() = 0;
    ~Tile();
};

#endif //TILE_H
