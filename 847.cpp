// ॥ श्री गणेशाय नमः ॥

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define ll long long
#define ull unsigned long long
using namespace std;
using namespace __gnu_pbds;

int recur(string &a, string &b, int ai, int bi, vector<vector<int>> &dp)
{
    int na = a.length();

    int nb = b.length();

    if (ai < 0 || bi < 0)
    {
        return 0;
    }

    if (dp[ai][bi] != -1)
    {
        return dp[ai][bi];
    }

    int take = 0;

    int nontake = 0;

    if (a[ai] == b[bi])
    {
        // There will be two cases

        take = 1 + recur(a, b, ai - 1, bi - 1, dp);
    }
    else
    {
        int fir = recur(a, b, ai - 1, bi, dp);

        int sec = recur(a, b, ai, bi - 1, dp);

        nontake = max(fir, sec);
    }

    return dp[ai][bi] = max(take, nontake);
}

int LongestCS(string a, string b)
{
    int na = a.length();

    int nb = b.length();

    vector<vector<int>> dp(na, vector<int>(nb, -1));

    return recur(a, b, na - 1, nb - 1, dp);
}

int main()
{

    return 0;
}

// ॥ जय श्री राम जय श्री कृष्ण ॥