#include "border.hpp"

Border::Border(int width, int height, int cellSize) : width(width), height(height), cellSize(cellSize) {}

void Border::Draw() {
    UpperBorderDraw();
    LowerBorderDraw();
}

void Border::UpperBorderDraw() {
    DrawText("CURENTLY FPS:",10,10,10,GREEN);
    std::string curerentlyFPS = std::to_string(GetFPS());
    DrawText(curerentlyFPS.c_str(),100,10,10,WHITE);

    DrawText("MAX FPS:",10,30,10,GREEN);
    std::string maxFPS = std::to_string(maxFps);
    DrawText(maxFPS.c_str(),100,30,10,WHITE);
}

void Border::LowerBorderDraw() {
    const char* controlsText = "controls";
    int fontSize = 15;
    DrawText(controlsText, width / 2 - MeasureText(controlsText, fontSize) / 2, height - 45, fontSize, GREEN);
    /* todo add all controls 
    enter start
    space stop 
    F   FPS+2;
    S   FPS -2
    R randomState
    C clear Grid
    left button toogleCell
    */

}