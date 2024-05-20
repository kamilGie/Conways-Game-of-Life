#include <raylib.h>
#include "simulation.hpp"
#include <iostream>

int main () {

    Color grey= { 29,29,29,255};
    const int screenWidth = 750;
    const int screenHeight = 750;
    const int cellSize =25;
    int FPS=12;

    InitWindow(screenWidth, screenHeight, "Game of life");
    SetTargetFPS(FPS);
    Simulation simulation(screenWidth, screenHeight,cellSize);
    simulation.SetCellValue(5,29,1);
    simulation.SetCellValue(6,0,1);
    simulation.SetCellValue(5,0,1);
    simulation.SetCellValue(4,0,1);


    std::cout<< simulation.CountLiveNeighbors(5,29)<<std::endl;

    while (WindowShouldClose() == false){


        BeginDrawing();
        ClearBackground(grey);
        simulation.Draw();

        EndDrawing();
    }

    CloseWindow();
    return 0;
}