#include <iostream>
#include <raylib.h>
#include "definitions.h"
#include "grid.h"

using namespace std;

int main()
{
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, WINDOW_TITLE);
    SetTargetFPS(TARGET_FPS);

    Grid grid = Grid();
    grid.Print();

    while (WindowShouldClose() == false)
    {
        // 1. Updates
        grid.Draw();
        
        // 2. Drawing
        BeginDrawing();
        ClearBackground(BACKGROUND_COLOR);
        EndDrawing();
    }

    CloseWindow();
}