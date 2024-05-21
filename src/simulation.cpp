#include "simulation.hpp"

#include <utility>
#include <vector>

void Simulation::Draw() {
    grid.Draw();
}

void Simulation::SetCellValue(int row, int column, int value) {
    grid.SetValue(row, column, value);
}

int Simulation::CountLiveNeighbors(int row, int column ) {
    int liveNeighbors = 0;
    std::vector<std::pair<int, int>> neighborsOffsets =
        {
            {-1, 0},
            {1, 0},
            {0, -1},
            {0, 1},
            {-1, -1},
            {-1, 1},
            {1, -1},
            {1, 1},
        };

    for (const auto& offset : neighborsOffsets) {
        int neighborRow = (row + offset.first +grid.getRows())%grid.getRows();
        int neighborColumn = (column + offset.second+grid.getColumns())%grid.getColumns();
        liveNeighbors += grid.GetValue(neighborRow,neighborColumn);
    }
    return liveNeighbors;
}

void Simulation::Update() {

    if(!isRunning()){ return; }

    for(int row = 0 ;row<grid.getRows();row++){
        for(int column = 0 ; column<grid.getColumns();column++){
            int liveNeighbors = CountLiveNeighbors(row,column);
            int cellValue = grid.GetValue(row,column);

            if(cellValue == 1){
                if(liveNeighbors>3  || liveNeighbors<2){
                    tempGrid.SetValue(row,column,0);
                }
                else{
                    tempGrid.SetValue(row,column,1);
                }
            }
            else{
                if(liveNeighbors==3){
                    tempGrid.SetValue(row,column,1);
                }
                else{
                    tempGrid.SetValue(row,column,0);
                }
            }
        }
    }
    grid =  tempGrid;
}

void Simulation::ClearGrid() {
    if(!isRunning()){
        grid.Clear();
    }
}

void Simulation::CreateRandomState() {
    if(!isRunning()){
        grid.FillRandom();
    }
}

void Simulation::ToggleCell(int row, int column) {
    if(!isRunning()){
        grid.ToggleCell(row,column);
    }
}
