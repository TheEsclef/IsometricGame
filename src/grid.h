#pragma once
#include "definitions.h"
#include <raylib.h>
#include "tiles.h"

struct Tile
{
    int row;
    int column;
};

class Grid{
public:
    Grid();
    void Initialize();
    void Draw();
    Tile onTileHover();
    void DrawHoveredTile();
    void Print();
    int grid[NUM_ROWS][NUM_COLS];

private:
    std::vector<Texture2D> textures;
};