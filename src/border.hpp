#pragma once
#include <raylib.h>
#include <string>


class Border {
   public:
    Border(int width, int height,int cellSize);
    void Draw();
    void UpperBorderDraw();
    void LowerBorderDraw();
    void Update();
    
    void SetMaxFps(int newFps) {maxFps=newFps;}

   private:
    const int width;
    const int height;
    const int cellSize;
    int maxFps=12;
};