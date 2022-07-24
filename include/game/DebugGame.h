#ifndef DEBUGGAME_H
#define DEBUGGAME_H
#include "game/Game.h"
#include <string>

class DebugGame : public Game {
    bool debugInput(std::string);
    void GameLoop() override;
    public:
        DebugGame();
};

#endif
