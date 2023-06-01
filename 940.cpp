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

int recur(int index, int buy, int cap, vector<int> &prices, vector<vector<vector<int>>> &dp)
{
    int n = prices.size();

    if (index == n || cap == 0)
    {
        return 0;
    }

    if (dp[index][buy][cap] != -1)
    {
        return dp[index][buy][cap];
    }

    if (buy == 1)
    {
        return dp[index][buy][cap] = max(-prices[index] + recur(index + 1, 0, cap, prices, dp), recur(index + 1, 1, cap, prices, dp));
    }

    return dp[index][buy][cap] = max(prices[index] + recur(index + 1, 1, cap - 1, prices, dp), recur(index + 1, 0, cap, prices, dp));
}

int maxProfit(vector<int> &prices)
{
    int n = prices.size();

    vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(3, -1)));

    int cap = 2;

    return recur(0, 1, cap, prices, dp);
}

int main()
{

    return 0;
}

// ॥ जय श्री राम जय श्री कृष्ण ॥