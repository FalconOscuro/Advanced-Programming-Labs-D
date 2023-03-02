#include "Grid.h"

#include <iostream>
using namespace std;

int main(int argn, char* argv[])
{
    Grid grid;
    grid.LoadGrid("Grid1.txt");

    cout << grid << endl;
}