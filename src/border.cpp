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
    const char* controlsText = "controls:";
    int fontSize = 15;
    DrawText(controlsText, width / 2 - MeasureText(controlsText, fontSize) / 2, height - 45, fontSize, GREEN);

    int controlsGrid = width/12;
    int controlsHeightUpPos=height-25;
    int controlsHeightDownPos=height-15;

    DrawText("start",controlsGrid+40,controlsHeightUpPos,5,GREEN);
    DrawText("ENTER",controlsGrid,controlsHeightUpPos,10,WHITE);

    DrawText("stop",controlsGrid+40,controlsHeightDownPos,5,GREEN);
    DrawText("SPACE",controlsGrid,controlsHeightDownPos,10,WHITE);

    DrawText("Incrase max fps",controlsGrid*3+10,controlsHeightUpPos,5,GREEN);
    DrawText("F",controlsGrid*3,controlsHeightUpPos,10,WHITE);

    DrawText("Decrase max fps",controlsGrid*3+10,controlsHeightDownPos,5,GREEN);
    DrawText("S",controlsGrid*3,controlsHeightDownPos,10,WHITE);

    DrawText("Fill Board",controlsGrid*6+10,controlsHeightUpPos,5,GREEN);
    DrawText("R",controlsGrid*6,controlsHeightUpPos,10,WHITE);

    DrawText("Clear Board",controlsGrid*6+10,controlsHeightDownPos,5,GREEN);
    DrawText("C",controlsGrid*6,controlsHeightDownPos,10,WHITE);

    DrawText("Quit",controlsGrid*8+68,controlsHeightUpPos,5,GREEN);
    DrawText("ESC",controlsGrid*8,controlsHeightUpPos,10,WHITE);

    DrawText("Toggle cell",controlsGrid*8+68,controlsHeightDownPos,5,GREEN);
    DrawText("LEFT CLICK",controlsGrid*8,controlsHeightDownPos,10,WHITE);
}