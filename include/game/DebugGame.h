#ifndef DEBUGGAME_H
#define DEBUGGAME_H
#include "game/Game.h"
#include <string>

class DebugGame : public Game {
    void debugInput(std::string);
    bool input(std::string) override;
    public:
        DebugGame();
};

#endif
