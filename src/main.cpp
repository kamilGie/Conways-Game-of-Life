#include <raylib.h>
#include "game.hpp"

int main() {
    const int screenWidth = 500;
    const int screenHeight = 500;
    const int cellSize = 4;

    SetTargetFPS(12);
    InitWindow(screenWidth, screenHeight, "Game of life");
    Game game(screenWidth,screenHeight,cellSize);

    while (!WindowShouldClose()) {
        game.HandleInput();
        game.Update();
        game.Draw();
    }

    CloseWindow();
}