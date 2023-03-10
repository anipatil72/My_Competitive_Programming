#include <bits/stdc++.h>
using namespace std;

int knapsack(vector<int> &v, vector<int> &w, int capacity)
{
    int n = v.size();

    vector<vector<int>> dp(n+1,vector<int>(capacity + 1,0));

    // int dp[n + 1][capacity + 1] = {0};

    // for (int i = 0; i <= n; i++)
    // {
    //     dp[i][0] = 0;
    // }

    // for (int i = 0; i <= capacity; i++)
    // {
    //     dp[0][i] = 0;
    // }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= capacity; j++)
        {
            if (w[i - 1] > j)
            {
                dp[i][j] = dp[i - 1][j];
            }
            else
            {
                dp[i][j] = max(dp[i - 1][j - w[i - 1]] + v[i - 1], dp[i][j - 1]);
            }
        }
    }

    // for (int i = 0; i <= n; i++)
    // {

    //     for (int j = 0; j <= capacity; j++)
    //     {
    //            cout<<dp[i][j]<<" ";
    //     }

    //     cout<<endl;

    // }

    return dp[n][capacity];
}

int main()
{

    vector<int> v = {60,100,120};
    vector<int> w = {10,20,30};

    cout << knapsack(v, w, 50);

    return 0;
}