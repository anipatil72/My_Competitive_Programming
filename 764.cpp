// ॥ श्री गणेशाय नमः ॥

#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define M 1000000007
using namespace std;

int maxi(int a, int b, int c)
{
    // return max(a, max(b, c));

    return max({a, b, c});
}

int ninjaTraining(int n, vector<vector<int>> &points)
{
    // parameters are days and activities

    vector<vector<int>> dp(n, vector<int>(4));

    dp[0][0] = points[0][0];
    dp[0][1] = points[0][1];
    dp[0][2] = points[0][2];
    dp[0][3] = 0;

    for (int i = 1; i < n; i++)
    {
        dp[i][0] = points[i][0] + maxi(dp[i - 1][1], dp[i - 1][2], dp[i - 1][3]);
        dp[i][1] = points[i][1] + maxi(dp[i - 1][0], dp[i - 1][2], dp[i - 1][3]);
        dp[i][2] = points[i][2] + maxi(dp[i - 1][1], dp[i - 1][0], dp[i - 1][3]);
        dp[i][3] = maxi(dp[i - 1][1], dp[i - 1][0], dp[i - 1][2]);
    }

    // cout << endl;

    // debug(dp);

    // cout << endl;

    return maxi(dp[n - 1][0], dp[n - 1][1], max(dp[n - 1][2], dp[n - 1][3]));
}

int uniquePaths(int m, int n, vector<vector<int>> &mat)
{
    vector<vector<int>> dp(m, vector<int>(n));

    dp[0][0] = 1;

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == 0 && j == 0)
            {
                dp[i][j] = 1;

                continue;
            }

            int left = (j == 0) ? 0 : (mat[i][j - 1] == -1 ? 0 : dp[i][j - 1]);

            int top = (i == 0) ? 0 : (mat[i - 1][j] == -1 ? 0 : dp[i - 1][j]);

            left %= M;

            top %= M;

            dp[i][j] = (left + 0LL + top) % M;
        }
    }

    if (mat[m - 1][n - 1] == -1)
    {
        return 0;
    }

    return dp[m - 1][n - 1] % M;
}

int main()
{

    int t;

    cin >> t;

    for (int i = 0; i < t; i++)
    {
        int n, m;

        cin >> m >> n;

        vector<vector<int>> mat(n, vector<int>(3));

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cin >> mat[i][j];
            }
        }

        cout << endl;

        cout << "The answer is : " << endl;

        uniquePaths(m, n, mat);

        // cout << ninjaTraining(n, mat) << endl;

        cout << endl;
    }

    return 0;
}

// ॥ जय श्री राम जय श्री कृष्ण ॥