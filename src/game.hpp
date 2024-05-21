#pragma once
#include "raylib.h"
#include "simulation.hpp"

class Game {
   public:
    Game(int width, int height, int cellSize);
    void Update();
    void HandleInput();
    void Draw();

   private:
    int FPS;
    const int screenWidth;
    const int screenHeight;
    const int cellSize;
    Color grey = {29, 29, 29, 255};
    Simulation simulation;
};