#include <cstring>
#include <memory>

#include "game/Game.h"
#include "game/DebugGame.h"

int main(int argc, char* argv[]) {
    // DebugGame G{};
    std::unique_ptr<Game> G;
    if(argc > 1){
        if(strcmp(argv[1], "-g") == 0){
            G = std::make_unique<DebugGame>();
        }else{
            G = std::make_unique<Game>();
        }
    } else {
        G = std::make_unique<Game>();
    }
    G->play();
    return 0;
}
