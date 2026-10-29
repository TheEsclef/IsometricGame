#pragma once
#include "definitions.h"

class Grid{
public:
    Grid();
    void Initialize();
    void Draw();
    void Print();
    int grid[NUM_ROWS][NUM_COLS];

private:
};