// ॥ श्री गणेशाय नमः ॥

#include <bits/stdc++.h>
#define ll long long
#define M 1000000007
using namespace std;

void dfs(int row, int col, vector<vector<int>> &visited, vector<vector<int>> &grid, vector<pair<int, int>> &temp, int row0, int col0)
{

    visited[row][col] = 0;

    temp.push_back({row - row0, col - col0});

    int n = grid.size();

    int m = grid[0].size();

    vector<int> delrow = {-1, 0, 1, 0};

    vector<int> delcol = {0, -1, 0, 1};

    for (int i = 0; i < 4; i++)
    {
        int nrow = row + delrow[i];

        int ncol = col + delcol[i];

        if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && visited[nrow][ncol] && grid[nrow][ncol] == 1)
        {
            dfs(nrow, ncol, visited, grid, temp, row0, col0);
        }
    }
}

int countDistinctIslands(vector<vector<int>> &grid)
{

    int n = grid.size();

    int m = grid[0].size();

    vector<vector<int>> visited(n, vector<int>(m, 1));

    set<vector<pair<int, int>>> s;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {

            if (visited[i][j] && grid[i][j])
            {
                vector<pair<int, int>> temp;

                dfs(i, j, visited, grid, temp, i, j);

                s.insert(temp);
            }
        }
    }

    return s.size();
}

int main()
{

    return 0;
}

// ॥ जय श्री राम जय श्री कृष्ण ॥