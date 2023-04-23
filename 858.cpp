// ॥ श्री गणेशाय नमः ॥

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define ll long long
#define ull unsigned long long
using namespace std;
using namespace __gnu_pbds;

int recur(int fir, int sec, string &a, string &b, vector<vector<int>> &dp)
{
    if (sec < 0)
    {
        return 1;
    }

    if (fir < 0)
    {
        return 0;
    }

    if (dp[fir][sec] != -1)
    {
        return dp[fir][sec];
    }

    int ans = 0;

    if (a[fir] == b[sec])
    {
        ans += recur(fir - 1, sec - 1, a, b, dp);
    }

    ans += recur(fir - 1, sec, a, b, dp);

    return dp[fir][sec] = ans;
}

int numDistinct(string s, string t)
{
    int n = s.length();

    int m = t.length();

    vector<vector<int>> dp(n, vector<int>(m, -1));

    return recur(n - 1, m - 1, s, t, dp);
}

int main()
{

    return 0;
}

// ॥ जय श्री राम जय श्री कृष्ण ॥