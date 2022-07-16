#ifndef DISPLAY_H
#define DISPLAY_H

#include <memory>
#include <vector>

#include "ftxui/dom/elements.hpp"

#include "utils/Observer.h"

class Board;

class Display : public Observer{
    Board* board;
    int x;
    int y;

    std::vector<std::vector<ftxui::Element>> grid;
    ftxui::Element gridElement;

    void setSize();

  public:
    Display(Board*, int, int);
    void notify() override;
    void print();
};

#endif // DISPLAY_H
