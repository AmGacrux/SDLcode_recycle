#include "Game.h"
#include <SDL.h>

int main(int argc, char** argv) {
    Game game;
    bool isSuccess = game.Initialize();
    if (isSuccess) {
        game.GameLoop();
    }
    game.Shutdown();
    return 0;
}