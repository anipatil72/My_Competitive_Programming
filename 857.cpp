// ॥ श्री गणेशाय नमः ॥

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define ll long long
#define ull unsigned long long
using namespace std;
using namespace __gnu_pbds;

string shortestSupersequence(string a, string b)
{
    int n = a.length();

    int m = b.length();

    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (a[i - 1] == b[j - 1])
            {
                dp[i][j] = 1 + dp[i - 1][j - 1];
            }
            else
            {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    string ams = "";

    int left = n, right = m;

    while (left > 0 && right > 0)
    {
        if (a[left - 1] == b[right - 1])
        {
            ams += a[left - 1];

            left--;

            right--;
        }
        else if (dp[left - 1][right] > dp[left][right - 1])
        {
            ams += a[left - 1];

            left--;
        }
        else
        {
            ams += b[right - 1];
            right--;
        }
    }

    while (left > 0)
    {
        ams += a[left - 1];

        left--;
    }

    while (right > 0)
    {
        ams += b[right - 1];

        right--;
    }

    reverse(ams.begin(), ams.end());

    return ams;
}

int main()
{

    return 0;
}

// ॥ जय श्री राम जय श्री कृष्ण ॥