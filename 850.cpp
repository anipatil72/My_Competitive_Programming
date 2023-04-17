// ॥ श्री गणेशाय नमः ॥

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define ll long long
#define ull unsigned long long
using namespace std;
using namespace __gnu_pbds;

int recur(int row, int col, vector<vector<int>> &grid, vector<vector<int>> &dp)
{
    int n = grid.size();

    int m = grid[0].size();

    if (row < 0 || col < 0)
    {
        return 0;
    }

    if (dp[row][col] != -1)
    {
        return dp[row][col];
    }

    int left = 0;

    if (row > 0)
    {

        if (grid[row - 1][col] > grid[row][col])
        {
            if (dp[row - 1][col] != -1)
            {
                left = dp[row - 1][col];
            }
            else
            {
                left = recur(row - 1, col, grid, dp);
            }
        }
    }

    int right = 0;

    if (row < n - 1)
    {
        if (grid[row + 1][col] > grid[row][col])
        {
            if (dp[row + 1][col] != -1)
            {
                right = dp[row + 1][col];
            }
            else
            {
                right = recur(row + 1, col, grid, dp);
            }
        }
    }

    int up = 0;

    if (col > 0)
    {
        if (grid[row][col - 1] > grid[row][col])
        {
            if (dp[row][col - 1] != -1)
            {
                up = dp[row][col - 1];
            }
            else
            {
                up = recur(row, col - 1, grid, dp);
            }
        }
    }

    int down = 0;
    if (col < m - 1)
    {
        if (grid[row][col + 1] > grid[row][col])
        {
            if (dp[row][col + 1] != -1)
            {
                down = dp[row][col + 1];
            }
            else
            {
                down = recur(row, col + 1, grid, dp);
            }
        }
    }

    return dp[row][col] = 1 + max({left, right, up, down});
}

int longestIncreasingPath(vector<vector<int>> &matrix)
{
    int n = matrix.size();

    int m = matrix[0].size();

    vector<vector<int>> dp(n, vector<int>(m, -1));

    int ans = 1;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (dp[i][j] == -1)
            {
                int there = recur(i, j, matrix, dp);

                ans = max(ans, there);
            }
            else
            {
                ans = max(ans, dp[i][j]);
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