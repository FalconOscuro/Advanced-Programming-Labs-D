#include "Grid.h"

#include <fstream>
#include <iostream>
#include <algorithm>
using namespace std;

Grid::Grid()
{ }

Grid::~Grid()
{ }

/**
 * @brief Load grid from a file
 * 
 * @param filename Read in file
 * @return Load success state
 */
bool Grid::LoadGrid(const char filename[])
{
    ifstream gridFile(filename);
    if (!gridFile)
        return false;

    // Temp array in case read fails due to improperly formatted file
    int grid[9][9];
    for (int i = 0; i < 9; i++)
        for (int j = 0; j < 9; j++)
        {
            // Ensure end of file has not been reached yet
            if (gridFile.peek() == EOF)
            {
                gridFile.close();
                return false;
            }
            
            gridFile >> grid[i][j];
        }
    
    if (gridFile.peek() != EOF)
    {
        gridFile.close();
        return false;
    }
    gridFile.close();

    // Copy temp array
    copy(&grid[0][0], &grid[0][0] + (9 * 9), &m_Grid[0][0]);
    return true;
}

/**
 * @brief Format grid for output stream
 */
ostream& operator<<(ostream& os, const Grid& grid)
{
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            os << grid.m_Grid[i][j];

            if (j < 8)
                os << ' ';
        }

        if (i < 8)
            os << '\n';
    }
    return os;
}