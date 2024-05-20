#include <raylib.h>

#include <iostream>

#include "simulation.hpp"

int main() {
    Color grey = {29, 29, 29, 255};
    const int screenWidth = 1200;
    const int screenHeight = 800;
    const int cellSize = 4;
    int FPS = 12;

    InitWindow(screenWidth, screenHeight, "Game of life");
    SetTargetFPS(FPS);
    Simulation simulation(screenWidth, screenHeight, cellSize);

    while (WindowShouldClose() == false) {
        if (IsKeyPressed(KEY_ENTER)) {
            simulation.Start();
            SetWindowTitle("Game of life is running ...");
        } else if (IsKeyPressed(KEY_SPACE)) {
            simulation.Stop();
            SetWindowTitle("Game of life has stopped.");
        } else if (IsKeyPressed(KEY_F)) {
            FPS += 2;
            SetTargetFPS(FPS);
        } else if (IsKeyPressed(KEY_S) && FPS > 5) {
            FPS -= 2;
            SetTargetFPS(FPS);
        }

        simulation.Update();

        BeginDrawing();
        ClearBackground(grey);
        simulation.Draw();

        EndDrawing();
    }

    CloseWindow();
    return 0;
}