#include <iostream>
#include <raylib.h>
#include "definitions.h"

using namespace std;

int main()
{
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, WINDOW_TITLE);
    SetTargetFPS(TARGET_FPS);

    
    while (WindowShouldClose() == false)
    {
        // 1. Updates
        

        // 2. Drawing
        BeginDrawing();
        ClearBackground(BACKGROUND_COLOR);
        EndDrawing();
    }

    CloseWindow();
}