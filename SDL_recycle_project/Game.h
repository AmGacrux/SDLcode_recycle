#pragma once
#include "SDL.h"
#include <stdio.h>

class Game {
public:
    Game();
    // �Q�[���̏�����
    bool Initialize();
    // �Q�[�����[�v
    void GameLoop();
    // �Q�[���I��
    void Shutdown();

private:
    // �Q�[�����[�v�̕⏕�֐�
    void ProcessInput();
    void UpdateGame();
    void GenerateOutput();

    // �Q�[���E�B���h�E�Ƒ��s�t���O
    SDL_Window *gameWindow;
    bool isRunning;

    // ���Ԍv���p
    Uint32 ticksCount;
};
