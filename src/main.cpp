#include <raylib.h>
#include "game.hpp"
#include "screen.hpp"

int main() {
    Screen screen;

    SetTargetFPS(12);
    InitWindow(screen.Width, screen.Height, "Game of life");
    Game game(screen.Width, screen.Height, screen.cellSize);

    while (!WindowShouldClose()) {
        game.HandleInput();
        game.Update();
        game.Draw();
    }

    CloseWindow();
}