#ifndef TILE_H
#define TILE_H

#include "ftxui/dom/elements.hpp"

class Player;

class Tile{
  const int type;
  public:
    Tile(int);
    int Type() const;
    virtual void apply(std::shared_ptr<Player> &) = 0;
    virtual ftxui::Element tileElement() = 0;
    virtual ftxui::Element getElement() = 0;
    ~Tile();
};

#endif //TILE_H
