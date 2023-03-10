// ॥ श्री गणेशाय नमः ॥

#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define M 1000000007
using namespace std;

int minSumPath(vector<vector<int>> &grid)
{
    int n = grid.size();

    int m = grid[0].size();

    vector<vector<int>> mat(n, vector<int>(m));

    // mat[0][0] = grid[0][0];

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (i == 0 && j == 0)
            {
                mat[0][0] = grid[0][0];
            }
            else
            {
                int left = (j == 0 ? INT_MAX : mat[i][j - 1]);

                int right = (i == 0 ? INT_MAX : mat[i - 1][j]);

                mat[i][j] = grid[i][j] + min(left, right);
            }
        }
    }

    return mat[n - 1][m - 1];
}

int main()
{

    return 0;
}

// ॥ जय श्री राम जय श्री कृष्ण ॥