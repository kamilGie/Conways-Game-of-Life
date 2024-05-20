#include <raylib.h>
#include"grid.hpp"

int main () {

    Color grey= { 29,29,29,255};
    const int screenWidth = 750;
    const int screenHeight = 750;
    const int cellSize =25;
    int FPS=12;

    InitWindow(screenWidth, screenHeight, "Game of life");
    SetTargetFPS(FPS);
    Grid grid{screenWidth,screenHeight,cellSize};

    while (WindowShouldClose() == false){


        BeginDrawing();
        ClearBackground(grey);
        grid.Draw();
        EndDrawing();
    }

    CloseWindow();
    return 0;
}