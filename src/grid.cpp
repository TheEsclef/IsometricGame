#include "grid.h"
#include <iostream>
#include <raylib.h>

Grid::Grid()
{
    Initialize();
}

void Grid::Initialize()
{
    for (int row = 0; row < NUM_ROWS; row++)
    {
        for (int column = 0; column < NUM_COLS; column++)
        {
            grid[row][column] = 0;
        }
    }
}

void ::Grid::Print()
{
    for (int row = 0; row < NUM_ROWS; row++)
    {
        for (int column = 0; column < NUM_COLS; column++)
        {
            std::cout << grid[row][column] << " ";
        }
        std::cout << std::endl;
    }
}

void Grid::Draw()
{
    for (int row = 0; row < NUM_ROWS; row++)
    {
        for (int column = 0; column < NUM_COLS; column++)
        {
            Image grass00 = LoadImage("sprites/grass00.png");
            Texture2D texture = LoadTextureFromImage(grass00);
            UnloadImage(grass00);

            DrawTexture(
                texture,
                OFFSET_WIDTH + column * CELL_SIZE,
                OFFSET_HEIGHT + row * CELL_SIZE,
                WHITE);
        }
    }
}
