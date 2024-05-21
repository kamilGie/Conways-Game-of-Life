#pragma once
#include "raylib.h"
#include "simulation.hpp"
#include "border.hpp"

class Game {
   public:
    Game(int width, int height, int cellSize);
    void Update();
    void HandleInput();
    void Draw();

   private:
    int FPS=12;
    int offset =50;
    const int screenWidth;
    const int screenHeight;
    const int cellSize;
    Color grey = {29, 29, 29, 255};
    Simulation simulation;
    Border border;
};