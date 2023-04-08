// ॥ श्री गणेशाय नमः ॥

#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
#define ll long long
#define ull unsigned long long
using namespace std;

void dfs(vector<vector<int>> &grid, vector<vector<int>> &vis, int row, int col, int &count)
{
    int n = grid.size();

    int m = grid[0].size();

    vis[row][col] = 0;

    count++;

    if (row > 0 && vis[row - 1][col] && grid[row - 1][col])
    {
        dfs(grid, vis, row - 1, col, count);
    }

    if (col > 0 && vis[row][col - 1] && grid[row][col - 1])
    {
        dfs(grid, vis, row, col - 1, count);
    }

    if (row < n - 1 && vis[row + 1][col] && grid[row + 1][col])
    {
        dfs(grid, vis, row + 1, col, count);
    }

    if (col < m - 1 && vis[row][col + 1] && grid[row][col + 1])
    {
        dfs(grid, vis, row, col + 1, count);
    }
}

int numEnclaves(vector<vector<int>> &grid)
{
    int n = grid.size();

    int m = grid[0].size();

    int tot = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            tot += (grid[i][j]);
        }
    }

    vector<vector<int>> vis(n, vector<int>(m, 1));

    int corner = 0;

    for (int i = 0; i < n; i++)
    {
        if (grid[i][0] && vis[i][0])
        {
            int tem = 0;

            dfs(grid, vis, i, 0, tem);

            corner += (tem);
        }

        if (grid[i][m - 1] && vis[i][m - 1])
        {
            int tem = 0;

            dfs(grid, vis, i, m - 1, tem);

            corner += (tem);
        }
    }

    for (int i = 0; i < m; i++)
    {
        if (grid[0][i] && vis[0][i])
        {
            int tem = 0;

            dfs(grid, vis, 0, i, tem);

            corner += (tem);
        }

        if (grid[n - 1][i] && vis[n - 1][i])
        {
            int tem = 0;

            dfs(grid, vis, n - 1, i, tem);

            corner += (tem);
        }
    }

    return tot - corner;
}

int main()
{

    return 0;
}

// ॥ जय श्री राम जय श्री कृष्ण ॥