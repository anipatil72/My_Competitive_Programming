// ॥ श्री गणेशाय नमः ॥

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define ll long long
#define ull unsigned long long
using namespace std;
using namespace __gnu_pbds;

#define MOD 1000000007

int countPartitions(int n, int d, vector<int> &a)
{
    // int n = a.size();

    int sum = accumulate(a.begin(), a.end(), 0);

    vector<vector<bool>> dp(n, vector<bool>(sum + 1, false));

    for (int i = 0; i < n; i++)
    {
        dp[i][0] = true;
    }

    dp[0][a[0]] = true;

    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j <= sum; j++)
        {
            dp[i][j] = (dp[i - 1][j] | (j >= a[i] ? dp[i - 1][j - a[i]] : false));
        }
    }

    long long ans = 0;

    for (int i = 0; i <= sum; i++)
    {

        int cur = i, left = sum - i;

        if (cur <= left)
        {
            if (1)
            {
            }
        }
    }
}

int main()
{

    return 0;
}

// ॥ जय श्री राम जय श्री कृष्ण ॥