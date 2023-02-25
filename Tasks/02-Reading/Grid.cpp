#include "Grid.h"

#include <fstream>
using namespace std;

Grid::Grid()
{ }

Grid::~Grid()
{ }

void Grid::LoadGrid(const char filename[])
{
    ifstream gridFile(filename);
    if (!gridFile)
        return;

    int grid[9][9];
    for (int i = 0; i < 9; i++)
        for (int j = 0; j < 9; j++)
        {
            if (gridFile.peek() == EOF)
                return;
            
            gridFile >> m_Grid[i][j];
        }
}