#include "screen.hpp"

Screen::Screen() {
        try {
            std::ifstream inputFile("../parameters.txt");
            if (!inputFile.is_open()) {
                throw std::runtime_error("Nie można otworzyć pliku parameters.txt");
            }

            std::string text;
            while (inputFile >> text) {
                if (text == "screenWidth:") {
                    inputFile >> Width;
                } else if (text == "screenHeight:") {
                    inputFile >> Height;
                } else {
                    inputFile >> cellSize;
                }
            }
            inputFile.close();
        } catch (const std::exception& e) {
            Width = 800;
            Height = 600;
            cellSize = 10;
        }
}