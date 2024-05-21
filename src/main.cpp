#include <raylib.h>

#include <fstream>

#include "game.hpp"

struct Screen {
    Screen() {
        std::ifstream inputFile("parameters.txt");
        std::string napis;
        while (inputFile >> napis) {
            if (napis == "screenWidth:") {
                inputFile >> Width;
            } else if (napis == "screenHeight:") {
                inputFile >> Height;
            } else {
                inputFile >> cellSize;
            }
        }
        inputFile.close();
    }

    int Width;
    int Height;
    int cellSize;
};

int main() {
    Screen screen;

    SetTargetFPS(12);
    InitWindow(screen.Width, screen.Height, "Game of life");
    Game game(screen.Width, screen.Height, screen.cellSize);

    while (!WindowShouldClose()) {
        game.HandleInput();
        game.Update();
        game.Draw();
    }

    CloseWindow();
}