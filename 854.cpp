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

int LongestCommonSubsequence(string &a, string &b)
{
    int na = a.length();

    int nb = b.length();

    if (na == 0 || nb == 0)
        return 0;

    vector<vector<int>> dp(na, vector<int>(nb, 0));

    for (int i = 0; i < nb; i++)
    {
        if (a[0] == b[i])
        {
            dp[0][i] = 1;
        }
    }

    for (int i = 0; i < na; i++)
    {
        if (b[0] == a[i])
        {
            dp[i][0] = 1;
        }
    }

    for (int i = 1; i < na; i++)
    {
        for (int j = 1; j < nb; j++)
        {
            if (a[i] == b[j])
            {
                dp[i][j] = 1 + dp[i - 1][j - 1];
            }
            else
            {
                dp[i][j] = max({dp[i - 1][j], dp[i][j - 1]});
            }
        }
    }

    return dp[na - 1][nb - 1];
}

int LongestCS(string a, string b)
{
    int na = a.length();

    int nb = b.length();

    vector<vector<int>> dp(na, vector<int>(nb, -1));

    return recur(a, b, na - 1, nb - 1, dp);
}

int minInsertion(string &s)
{
    string tem = s;

    reverse(tem.begin(), tem.end());

    int n = s.length();

    int ans = n - LongestCS(s, tem);

    return ans;
}

int canYouMake(string &str, string &ptr)
{
    int na = str.length();

    int nb = ptr.length();

    return na + nb - 2 * LongestCS(str, ptr);
}

int main()
{

    return 0;
}

// ॥ जय श्री राम जय श्री कृष्ण ॥