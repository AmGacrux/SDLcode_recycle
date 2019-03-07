#pragma once
#include "SDL.h"
#include <stdio.h>

class Game {
public:
    Game();
    // ゲームの初期化
    bool Initialize();
    // ゲームループ
    void GameLoop();
    // ゲーム終了
    void Shutdown();

private:
    // ゲームループの補助関数
    void ProcessInput();
    void UpdateGame();
    void GenerateOutput();

    // ゲームウィンドウと続行フラグ
    SDL_Window *gameWindow;
    bool isRunning;

    // 時間計測用
    Uint32 ticksCount;
};
