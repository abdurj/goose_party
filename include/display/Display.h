#ifndef DISPLAY_H
#define DISPLAY_H

#include <memory>
#include <vector>

#include "ftxui/dom/elements.hpp"

class Board;

class Display{
    Board* board;
    int x;
    int y;

    std::vector<std::vector<ftxui::Element>> grid;
    ftxui::Element gridElement;
    
    ftxui::Screen screen;

    void setSize();

  public:
    Display(Board*, int, int);
    void notify() override;
    void print();

    void clear();
};

#endif // DISPLAY_H
