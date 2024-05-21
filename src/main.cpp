#include <raylib.h>
#include "game.hpp"

int main() {
    const int screenWidth = 1200;
    const int screenHeight = 800;
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