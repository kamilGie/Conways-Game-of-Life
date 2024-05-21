#include "game.hpp"

Game::Game(int width, int height, int cellSize) 
    :FPS(12),screenWidth(width),screenHeight(height),cellSize(cellSize),simulation(screenWidth, screenHeight, cellSize){}


void Game::HandleInput() {
    if (IsMouseButtonDown(MOUSE_BUTTON_LEFT)) {
        Vector2 mousePosition = GetMousePosition();
        simulation.ToggleCell(mousePosition.y / cellSize, mousePosition.x / cellSize);
    }

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
    } else if (IsKeyPressed(KEY_R)) {
        simulation.CreateRandomState();
    } else if (IsKeyPressed(KEY_C)) {
        simulation.ClearGrid();
    }
}

void Game::Update() {
    simulation.Update();
}

void Game::Draw() {
    BeginDrawing();
    ClearBackground(grey);
    simulation.Draw();
    EndDrawing();
}