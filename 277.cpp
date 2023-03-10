#include <bits/stdc++.h>
using namespace std;

int Recur(vector<vector<int>> &grid, int x, int y, int &count)
{
    count++;

    grid[x][y] = -1;

    if (x - 1 >= 0 && grid[x - 1][y] == 1)
    {
        int a = Recur(grid, x - 1, y, count);
    }

    if (y - 1 >= 0 && grid[x][y - 1] == 1)
    {

        int b = Recur(grid, x, y - 1, count);
    }

    if ((x + 1 < grid.size()) && grid[x + 1][y] == 1)
    {

        int c = Recur(grid, x + 1, y, count);
    }

    if ((y + 1 < grid[0].size()) && grid[x][y + 1] == 1)
    {

        int d = Recur(grid, x, y + 1, count);
    }

    return count;
}

int maxAreaOfIsland(vector<vector<int>> &grid)
{

    int m = grid.size();
    int n = grid[0].size();

    int M = 0;

    for (int i = 0; i < m; i++)
    {

        for (int j = 0; j < n; j++)
        {
            if (grid[i][j] == 1)
            {
                int d = 0;

                int count = Recur(grid, i, j, d);

                M = max(M, count);
            }
        }
    }

    return M;
}

int main()
{

    vector<vector<int>> v = {{0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0},
                             {0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0},
                             {0, 1, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0},
                             {0, 1, 0, 0, 1, 1, 0, 0, 1, 0, 1, 0, 0},
                             {0, 1, 0, 0, 1, 1, 0, 0, 1, 1, 1, 0, 0},
                             {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0},
                             {0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0},
                             {0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0}};

    cout << maxAreaOfIsland(v);

    return 0;
}