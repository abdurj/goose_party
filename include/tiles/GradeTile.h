#ifndef GRADE_TILE_H
#define GRADE_TILE_H

#include "tiles/Tile.h"
#include "ftxui/dom/elements.hpp"

class GradeTile : public Tile {
  public:
    GradeTile(int);
    void apply(std::shared_ptr<Player> &) override;
    ftxui::Element tileElement() override;
    ftxui::Element getElement() override;
};

#endif // GRADE_TILE_H
