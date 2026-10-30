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
    grid.GenerateMap();

    while (WindowShouldClose() == false)
    {
        // 1. Updates
        grid.ChangeTile();
        grid.ResetMap();

        // 2. Drawing
        BeginDrawing();
        ClearBackground(BACKGROUND_COLOR);
        
        grid.ShowHoveredTile();
        grid.Draw();

        EndDrawing();
    }
    CloseWindow();
}