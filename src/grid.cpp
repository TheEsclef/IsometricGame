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
            DrawRectangle(
                OFFSET_WIDTH + column * CELL_SIZE + 1,
                OFFSET_HEIGHT + row * CELL_SIZE + 1,
                CELL_SIZE - 1,
                CELL_SIZE - 1,
                WHITE);
        }
    }
}
