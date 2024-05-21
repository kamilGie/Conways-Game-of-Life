#include "simulation.hpp"

#include <utility>
#include <vector>

Simulation::Simulation(int width, int height, int cellSize)
    : grid(width,height,cellSize),tempGrid(width,height,cellSize),run(false) {}

void Simulation::Draw() {
    grid.Draw();
}

void Simulation::SetCellValue(int row, int column, int value) {
    grid.SetValue(row, column, value);
}

int Simulation::CountLiveNeighbors(int row, int column) {
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
        int neighborRow = (row + offset.first + grid.getRows()) % grid.getRows();
        int neighborColumn = (column + offset.second + grid.getColumns()) % grid.getColumns();
        liveNeighbors += grid.GetValue(neighborRow, neighborColumn);
    }
    return liveNeighbors;
}

void Simulation::Update() {
    if (!isRunning()) { return; }

    for (int row = 0; row < grid.getRows(); row++) {
        for (int column = 0; column < grid.getColumns(); column++) {
            int liveNeighbors = CountLiveNeighbors(row, column);
            int cellValue = grid.GetValue(row, column);

            if (cellValue == 1) {
                int value = (liveNeighbors > 3 || liveNeighbors < 2) ? 0 : 1;
                tempGrid.SetValue(row, column, value);
            } else {
                int value = (liveNeighbors == 3) ? 1 : 0;
                tempGrid.SetValue(row, column, value);
            }
        }
    }
    grid = tempGrid;
}

void Simulation::ClearGrid() {
    if (!isRunning()) { grid.Clear(); }
}

void Simulation::CreateRandomState() {
    if (!isRunning()) { grid.FillRandom(); }
}

void Simulation::ToggleCell(int row, int column) {
    if (!isRunning()) { grid.ToggleCell(row, column); }
}
