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
        return fir + 1;
    }

    if (fir < 0)
    {
        return sec + 1;
    }

    if (dp[fir][sec] != -1)
    {
        return dp[fir][sec];
    }

    if (a[fir] == b[sec])
    {
        return recur(fir - 1, sec - 1, a, b, dp);
    }

    int del = 1 + recur(fir - 1, sec, a, b, dp);

    int ins = 1 + recur(fir, sec - 1, a, b, dp);

    int replace = 1 + recur(fir - 1, sec - 1, a, b, dp);

    return dp[fir][sec] = min({del, ins, replace});
}

int editDistance(string a, string b)
{
    int n = a.length();

    int m = b.length();

    vector<vector<int>> dp(n, vector<int>(m, -1));

    return recur(n - 1, m - 1, a, b, dp);
}

int main()
{

    string a = "";

    string b = "b";

    cout << editDistance(a, b) << endl;

    return 0;
}

// ॥ जय श्री राम जय श्री कृष्ण ॥