#include <raylib.h>
#include "grid.hpp"

Grid::Grid(int width, int height, int cellSize) 
    : rows((height-100) / cellSize), columns(width / cellSize), cellSize(cellSize), cells(rows, std::vector<int>(columns, 0)){}

void Grid::Draw() {
    for(int row=0;row<rows;row ++){
        for(int column = 0 ; column<columns;column++){
            Color color = cells[row][column] ? Color{0,255,0,255} : Color{55,55,55,255};
            DrawRectangle(column*cellSize,row*cellSize+offset,cellSize-1,cellSize-1,color);
        }
    }
}

void Grid::SetValue(int row, int column, int value) {
    if(isWithinBounds(row,column)){ cells[row][column]=value; }
}

int Grid::GetValue(int row, int column) {
    return (isWithinBounds(row,column))? cells[row][column] : 0;
}

bool Grid::isWithinBounds(int row, int column) {
     return (row>= 0 && row< rows && column >=0 && column< columns)? true: false;
}

void Grid::FillRandom() {
    for(int row = 0 ;row<rows;row++){
        for(int column = 0 ; column<columns;column++){
            int randomValue = GetRandomValue(0,4);
            cells[row][column] = randomValue==4;
        }
    }
}

void Grid::Clear() {
    for(int row = 0 ;row<rows;row++){
        for(int column = 0 ; column<columns;column++){
            cells[row][column] =0;
        }
    }
}

void Grid::ToggleCell(int row, int column) {
    if(isWithinBounds(row,column)) { cells[row][column]=!cells[row][column]; }
}
