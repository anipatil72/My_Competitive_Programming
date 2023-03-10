#include <bits/stdc++.h>
using namespace std;

void recur(vector<vector<int>> &g, int i, int j, int cur, int &M)
{

    int m = g.size();
    int n = g[0].size();

    if (i == n - 1 && j == m - 1)
    {
        M = min(cur, M);

        return;
    }

    if (i < n - 1)
    {
        recur(g, i + 1, j, cur + g[i + 1][j], M);
    }

    if (j < m - 1)
    {
        recur(g, i, j + 1, cur + g[i][j + 1], M);
    }
}

int minPathSum(vector<vector<int>> &grid)
{

    int n = grid.size();

    int m = grid[0].size();

    int cur = grid[0][0];

    int M = INT_MAX;

    int i = 0, j = 0;

    recur(grid, i, j, cur, M);

    return m;
}

int main()
{

    return 0;
}