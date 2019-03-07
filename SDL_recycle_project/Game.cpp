#include "Game.h"
#include <iostream>

const int tickness = 15;

Game::Game() :
    gameWindow(nullptr),
    ticksCount(0),
    isRunning(true) {
}

bool Game::Initialize() {
    int sdlResult = SDL_Init(SDL_INIT_VIDEO);
    if (sdlResult != 0) {
        SDL_Log("SDL を初期化できません：%s", SDL_GetError());
        return false;
    }

    gameWindow = SDL_CreateWindow(
        "Shooter-1",
        100,
        100,
        1024,
        768,
        0
    );

    if (!gameWindow) { // gameWindow != nullptr
        SDL_Log("ウィンドウの作成に失敗しました：%s", SDL_GetError());
        return false;
    }
}

void Game::GameLoop() {
    while (isRunning) {
        ProcessInput();
        UpdateGame();
       // GenerateOutput();
    }
}

void Game::ProcessInput() {
    SDL_Event event;
    SDL_PollEvent(&event);

    // 閉じるボタンの処理
    while (SDL_PollEvent(&event)) {
        switch (event.type) {
        case SDL_QUIT:
            isRunning = false;
            break;
        }
    }

    // キーボードの状態を取得
    const Uint8 *state = SDL_GetKeyboardState(NULL);
    if (state[SDL_SCANCODE_ESCAPE]) {
        isRunning = false;
    }
}
void Game::Shutdown() {
    SDL_DestroyWindow(gameWindow);
    SDL_Quit();
}

void Game::UpdateGame() {
    while (!SDL_TICKS_PASSED(SDL_GetTicks(), ticksCount + 16))
        ;

    // deltatime = currentime - previoustime
    float dt = (SDL_GetTicks() - ticksCount) / 1000.0f;

    if (dt > 0.05f) {
        dt = 0.05f;
    }

    ticksCount = SDL_GetTicks();

}

void Game::GenerateOutput() {
}
