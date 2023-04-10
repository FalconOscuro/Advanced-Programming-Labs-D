#include "Grid.h"

#include <iostream>
using namespace std;

int main()
{
    Grid grid;
    grid.LoadGrid("Grid1.txt");

    cout << grid << endl;
}