// ॥ श्री गणेशाय नमः ॥

#include <bits/stdc++.h>
#define ll long long
#define M 1000000007
using namespace std;

void dfs(vector<vector<int>> &grid, vector<vector<int>> &visited, int n, int m, int x, int y)
{
    visited[x][y] = 0;

    // tobe.push_back({x, y});

    // bool one = true, two = true, three = true, four = true;

    if (x > 0 && grid[x - 1][y] == 1 && visited[x - 1][y])
    {

        dfs(grid, visited, n, m, x - 1, y);
    }

    if (x + 1 < n && grid[x + 1][y] == 1 && visited[x + 1][y])
    {
        dfs(grid, visited, n, m, x + 1, y);
    }

    if (y > 0 && grid[x][y - 1] == 1 && visited[x][y - 1])
    {
        dfs(grid, visited, n, m, x, y - 1);
    }

    if (y + 1 < m && grid[x][y + 1] == 1 && visited[x][y + 1])
    {
        dfs(grid, visited, n, m, x, y + 1);
    }

    // return one && two && three && four;
}

int numberOfEnclaves(vector<vector<int>> &grid)
{

    int n = grid.size();

    int m = grid[0].size();

    vector<vector<int>> visited(n, vector<int>(m, 1));

    // vector<pair<int, int>> tobe;

    for (int i = 0; i < n; i++)
    {
        if (grid[i][0] == 1 && visited[i][0])
        {

            dfs(grid, visited, n, m, i, 0);
        }
    }

    for (int i = 0; i < n; i++)
    {
        if (grid[i][m - 1] == 1 && visited[i][m - 1])
        {

            dfs(grid, visited, n, m, i, m - 1);
        }
    }

    for (int i = 0; i < m; i++)
    {
        if (grid[0][i] == 1 && visited[0][i])
        {

            dfs(grid, visited, n, m, 0, i);
        }
    }

    for (int i = 0; i < m; i++)
    {
        if (grid[n - 1][i] == 1 && visited[n - 1][i])
        {

            dfs(grid, visited, n, m, n - 1, i);
        }
    }

    int count = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (grid[i][j] == 1 && visited[i][j])
            {
                // grid[i][j] = 'X';

                count++;
            }
        }
    }

    // return mat;

    return count;
}

int main()
{

    return 0;
}

// ॥ जय श्री राम जय श्री कृष्ण ॥