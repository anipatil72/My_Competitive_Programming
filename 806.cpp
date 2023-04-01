// ॥ श्री गणेशाय नमः ॥

#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
#define ll long long
#define ull unsigned long long
using namespace std;

int minPathSum(vector<vector<int>> &grid)
{
    int n = grid.size();

    int rows = grid[0].size();

    vector<vector<int>> dp(n, vector<int>(rows));

    // dp[0][0] = grid[0][0];

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < rows; j++)
        {

            if (i == 0 && j == 0)
            {
                dp[i][j] = grid[0][0];

                continue;
            }

            int m = (int)1e6;

            if (i > 0)
            {

                m = dp[i - 1][j];
            }

            if (j > 0)
            {
                m = min(m, dp[i][j - 1]);
            }

            dp[i][j] = grid[i][j] + m;
        }
    }

    return dp[n - 1][rows - 1];
}

int main()
{

    return 0;
}

// ॥ जय श्री राम जय श्री कृष्ण ॥