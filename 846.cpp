// ॥ श्री गणेशाय नमः ॥

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define ll long long
#define ull unsigned long long
using namespace std;
using namespace __gnu_pbds;

int recur(int index, int len, vector<int> &price, vector<vector<int>> &dp)
{
    int n = price.size();

    if (index == 0)
    {
        return len * price[0];
    }

    if (len == 0)
    {
        return 0;
    }

    if (dp[index][len] != -1)
    {
        return dp[index][len];
    }

    int nontake = recur(index - 1, len, price, dp);

    int take = 0;

    if (len >= index + 1)
    {
        take = price[index] + recur(index, len - index - 1, price, dp);
    }

    return dp[index][len] = max(take, nontake);
}

int cutRod(vector<int> &price, int n)
{
    int len = price.size();

    vector<vector<int>> dp(len, vector<int>(n + 1, -1));

    return recur(len - 1, n, price, dp);
}

int main()
{

    return 0;
}

// ॥ जय श्री राम जय श्री कृष्ण ॥