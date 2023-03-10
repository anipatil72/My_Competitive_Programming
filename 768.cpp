// ॥ श्री गणेशाय नमः ॥

#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define M 1000000007
using namespace std;

int minimumPathSum(vector<vector<int>> &triangle, int n)
{
    vector<vector<int>> dp(n, vector<int>(n));

    // dp[0][0] = triangle[0][0];

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            if (i == 0 && j == 0)
            {
                dp[i][j] = triangle[0][0];
            }
            else if (j == 0)
            {
                dp[i][j] = triangle[i][j] + dp[i - 1][j];
            }
            else if (j == i)
            {
                dp[i][j] = triangle[i][j] + dp[i - 1][j - 1];
            }
            else
            {
                dp[i][j] = triangle[i][j] + min(dp[i - 1][j], dp[i - 1][j - 1]);
            }
        }
    }

    return *min_element(dp[n-1].begin(), dp[n-1].end());
}

int main()
{

    return 0;
}

// ॥ जय श्री राम जय श्री कृष्ण ॥