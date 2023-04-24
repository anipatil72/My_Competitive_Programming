// ॥ श्री गणेशाय नमः ॥

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define ll long long
#define ull unsigned long long
using namespace std;
using namespace __gnu_pbds;

int recur(int index, int weight, vector<int> &siz, vector<int> &value, vector<vector<int>> &dp)
{
    if (index == 0)
    {
        if (siz[0] <= weight)
        {
            return value[0];
        }
        else
        {
            return 0;
        }
    }

    if (weight == 0)
    {
        return 0;
    }

    if (dp[index][weight] != -1)
    {
        return dp[index][weight];
    }

    int take = 0;

    if (siz[index] <= weight)
    {
        take = value[index] + recur(index - 1, weight - siz[index], siz, value, dp);
    }

    int nontake = recur(index - 1, weight, siz, value, dp);

    return dp[index][weight] = max(take, nontake);
}

int solve(vector<int> &siz, vector<int> &price, int weight)
{
    int n = siz.size();

    vector<vector<int>> dp(n, vector<int>(weight, -1));

    return recur(n - 1, weight, siz, price, dp);
}

int main()
{

    return 0;
}

// ॥ जय श्री राम जय श्री कृष्ण ॥