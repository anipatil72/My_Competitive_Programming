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

bool subsetSumToK(int n, int k, vector<int> &arr)
{

    vector<vector<bool>> dp(n, vector<bool>(k + 1, 0));

    for (int i = 0; i < n; i++)
        dp[i][0] = true;

    dp[0][arr[0]] = 1;

    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j <= k; j++)
        {
            dp[i][j] = ((j >= arr[i] ? dp[i - 1][j - arr[i]] : false) | (dp[i - 1][j]));
        }
    }

    // return recur(n-1, k, dp, arr);

    return dp[n - 1][k];
}

int tallestBillboard(vector<int> &rods)
{
    return 0;
}

int main()
{

    return 0;
}

// ॥ जय श्री राम जय श्री कृष्ण ॥