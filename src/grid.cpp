#include "grid.h"
#include <iostream>
#include <vector>

Grid::Grid()
{
    Initialize();
    textures = InitializeTiles();
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
            int posX = SCREEN_WIDTH / 2 + (column - row) * (CELL_WIDTH / 2);
            int posY = SCREEN_HEIGHT / 4 + (column + row) * (CELL_HEIGHT / 2);
            DrawTexture(
                textures[0],
                posX,
                posY,
                WHITE);
        }
    }
}

Tile Grid::onTileHover()
{
    Tile tile = {-1, -1};

    Vector2 mouse = GetMousePosition();

    for (int row = 0; row < NUM_ROWS; row++)
    {
        for (int column = 0; column < NUM_COLS; column++)
        {
            int posX = SCREEN_WIDTH / 2 +
                       (column - row) * (CELL_WIDTH / 2);

            int posY = SCREEN_HEIGHT / 4 +
                       (column + row) * (CELL_HEIGHT / 2);

            Rectangle bounds = {
                (float)posX,
                (float)posY,
                (float)CELL_WIDTH,
                (float)CELL_HEIGHT
            };

            if (CheckCollisionPointRec(mouse, bounds))
            {
                tile.row = row;
                tile.column = column;
            }
        }
    }

    return tile;
}

void Grid::DrawHoveredTile()
{
    Tile tile = onTileHover();

    if (tile.row < 0 || tile.row >= NUM_ROWS ||
        tile.column < 0 || tile.column >= NUM_COLS)
    {
        return;
    }

    int posX = SCREEN_WIDTH / 2 +
               (tile.column - tile.row) * (CELL_WIDTH / 2);

    int posY = SCREEN_HEIGHT / 4 +
               (tile.column + tile.row) * (CELL_HEIGHT / 2);

    Vector2 top    = { posX + CELL_WIDTH / 2.0f, float(posY) };
    Vector2 right  = { float(posX) + CELL_WIDTH, posY + CELL_HEIGHT / 2.0f };
    Vector2 bottom = { float(posX) + CELL_WIDTH / 2.0f, float(posY) + CELL_HEIGHT };
    Vector2 left   = { float(posX), posY + CELL_HEIGHT / 2.0f };

    DrawLineEx(top, right, 2, YELLOW);
    DrawLineEx(right, bottom, 2, YELLOW);
    DrawLineEx(bottom, left, 2, YELLOW);
    DrawLineEx(left, top, 2, YELLOW);
}