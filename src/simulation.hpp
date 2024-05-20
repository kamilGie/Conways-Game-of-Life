#pragma once
#include "grid.hpp"

class Simulation {
   public:
    Simulation(int width, int height, int cellSize)
    : grid(width,height,cellSize),tempGrid(width,height,cellSize),run(false) {grid.FillRandom();};
    void Draw();
    void SetCellValue(int row,int column,int value);
    int CountLiveNeighbors(int row,int column);
    void Update();
    bool isRunning() { return  run;};
    void Start() {run = true;}
    void Stop() {run = false;}
   private:
    Grid grid;
    Grid tempGrid;
    bool run;
};