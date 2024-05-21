#pragma once
#include <vector>

class Grid {
   public:
    Grid(int width, int height, int cellSize);

    void Draw();
    void SetValue(int row,int column,int value);
    int GetValue(int row,int column);
    bool isWithinBounds(int row ,int column);
    void FillRandom();
    void Clear();
    void ToggleCell(int row , int column);

    int getRows() { return rows;}
    int getColumns() { return columns;}
    
   private:
    int rows;
    int columns;
    int cellSize;
    std::vector<std::vector<int>> cells;
};