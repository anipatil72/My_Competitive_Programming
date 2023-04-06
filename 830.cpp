// ॥ श्री गणेशाय नमः ॥

#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
#define ll long long
#define ull unsigned long long
using namespace std;

void dfs(vector<vector<int>> &grid, vector<vector<int>> &vis, int row, int col)
{
    int n = grid.size();

    int m = grid[0].size();

    vis[row][col] = 0;

    if (row > 0)
    {
        if (vis[row - 1][col] && grid[row - 1][col] == 0)
        {
            dfs(grid, vis, row - 1, col);
        }
    }

    if (col > 0)
    {
        if (vis[row][col - 1] && grid[row][col - 1] == 0)
        {
            dfs(grid, vis, row, col - 1);
        }
    }

    if (row < n - 1)
    {
        if (vis[row + 1][col] && grid[row + 1][col] == 0)
        {
            dfs(grid, vis, row + 1, col);
        }
    }

    if (col < m - 1)
    {
        if (vis[row][col + 1] && grid[row][col + 1] == 0)
        {
            dfs(grid, vis, row, col + 1);
        }
    }
}

int closedIsland(vector<vector<int>> &grid)
{
    int n = grid.size();

    int m = grid[0].size();

    vector<vector<int>> vis(n, vector<int>(m, 1));

    for (int i = 0; i < n; i++)
    {
        if (grid[i][0] == 0)
        {
            dfs(grid, vis, i, 0);
        }
    }

    for (int i = 0; i < n; i++)
    {
        if (grid[i][m - 1] == 0)
        {
            dfs(grid, vis, i, m - 1);
        }
    }

    for (int i = 0; i < m; i++)
    {
        if (grid[0][i] == 0)
        {
            dfs(grid, vis, 0, i);
        }
    }

    for (int i = 0; i < m; i++)
    {
        if (grid[n - 1][i] == 0)
        {
            dfs(grid, vis, n - 1, i);
        }
    }

    int ans = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (grid[i][j] == 0 && vis[i][j])
            {
                dfs(grid, vis, i, j);

                ans++;
            }
        }
    }

    return ans;
}

int main()
{

    return 0;
}

// ॥ जय श्री राम जय श्री कृष्ण ॥