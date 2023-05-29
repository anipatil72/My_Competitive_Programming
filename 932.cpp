// ॥ श्री गणेशाय नमः ॥

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define ll long long
#define ull unsigned long long
using namespace std;
using namespace __gnu_pbds;

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
// typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_multiset;

bool isAllStars(string &S1, int i)
{
    for (int j = 0; j <= i; j++)
    {
        if (S1[j] != '*')
        {
            return false;
        }
    }
    return true;
}

bool wildcardMatchingUtil(string &S1, string &S2, int i, int j, vector<vector<bool>> &dp)
{

    // Base Conditions
    if (i < 0 && j < 0)
    {
        return true;
    }
    if (i < 0 && j >= 0)
    {
        return false;
    }
    if (j < 0 && i >= 0)
    {
        return isAllStars(S1, i);
    }

    if (dp[i][j] != -1)
    {
        return dp[i][j];
    }

    if (S1[i] == S2[j] || S1[i] == '?')
    {
        return dp[i][j] = wildcardMatchingUtil(S1, S2, i - 1, j - 1, dp);
    }

    else
    {
        if (S1[i] == '*')
            return wildcardMatchingUtil(S1, S2, i - 1, j, dp) || wildcardMatchingUtil(S1, S2, i, j - 1, dp);
        else
            return false;
    }
}

bool wildcardMatching(string &S1, string &S2)
{

    int n = S1.size();
    int m = S2.size();

    vector<vector<bool>> dp(n, vector<bool>(m, -1));
    return wildcardMatchingUtil(S1, S2, n - 1, m - 1, dp);
}

int main()
{

    return 0;
}

// ॥ जय श्री राम जय श्री कृष्ण ॥