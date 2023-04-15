// ॥ श्री गणेशाय नमः ॥

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define ll long long
#define ull unsigned long long
using namespace std;
using namespace __gnu_pbds;

template <typename T_vector>
void print_2D(vector<T_vector> &v)
{
    for (int i = 0; i < v.size(); i++)
    {
        for (int j = 0; j < v[i].size(); j++)
        {
            cout << v[i][j] << " ";
        }
        cout << endl;
    }
}

// Tabulation

int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight)
{
    vector<vector<int>> dp(n, vector<int>(maxWeight + 1, 0));

    for (int i = 0; i <= maxWeight; i++)
    {
        if (i >= weight[0])
        {
            dp[0][i] = value[0];
        }
        else
        {
            dp[0][i] = 0;
        }
    }

    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j <= maxWeight; j++)
        {
            int notTake = dp[i - 1][j];

            int take = (int)(-1e9);

            if (j >= weight[i])
            {
                take = value[i] + dp[i - 1][j - weight[i]];
            }

            dp[i][j] = max(take, notTake);
        }
    }

    return dp[n - 1][maxWeight];
}

// Tabulation using only one row

int knapSackSpaceOpt(vector<int> weight, vector<int> value, int n, int maxWeight)
{

    vector<int> prev(maxWeight + 1, 0);

    for (int i = 0; i <= maxWeight; i++)
    {
        if (i >= weight[0])
        {
            prev[i] = value[0];
        }
        else
        {
            prev[i] = 0;
        }
    }

    for (int i = 1; i < n; i++)
    {
        for (int j = maxWeight; j >= 0; j--)
        {
            prev[j] = max((j >= weight[i] ? prev[j - weight[i]] : (int)-1e9), prev[j]);
        }
    }

    return prev.back();
}

int main()
{

    return 0;
}

// ॥ जय श्री राम जय श्री कृष्ण ॥