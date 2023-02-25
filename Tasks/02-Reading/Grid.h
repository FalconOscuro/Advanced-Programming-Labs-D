#ifndef GRID_H
#define GRID_H

class Grid
{
public:
    Grid();
    ~Grid();

    void LoadGrid(const char filename[]);
    void SaveGrid(const char filename[]);

private:
    int m_Grid[9][9];
};

#endif // GRID_H