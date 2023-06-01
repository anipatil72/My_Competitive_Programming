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

int recur(int index, int buy, vector<int> &a, vector<vector<int>> &dp, int cap)
{

    // cout << "I am here : at index = " << index << endl;

    int n = a.size();

    if (index == n - 1)
    {
        if (buy == 1)
        {
            return a[n - 1];
        }

        return 0;
    }

    if (dp[index][buy] != -1)
    {
        return dp[index][buy];
    }

    if (buy == 1)
    {
        int sell = a[index] + recur(index + 1, 0, a, dp, cap);

        int notsell = recur(index + 1, 1, a, dp, cap);

        return dp[index][buy] = max(sell, notsell);
    }

    int boy = -a[index] + recur(index + 1, 1, a, dp, cap - 1);

    int notbuy = recur(index + 1, 0, a, dp, cap);

    return dp[index][buy] = max(boy, notbuy);
}

int maxProfit(vector<int> &a)
{
    int n = a.size();

    int cap = 2;

    if (n == 1)
    {
        return 0;
    }

    vector<vector<int>> dp(n, vector<int>(2, -1));

    return max(-a[0] + recur(1, 1, a, dp, 1), recur(1, 0, a, dp, 2));
}

int main()
{

    vector<int> prices = {3, 3, 5, 0, 0, 3, 1, 4};

    // int tt;

    // cin >> tt;

    // while (tt--)
    // {

    //     int n;

    //     cin >> n;

    //     vector<int> prices(n);

    //     for (int i = 0; i < n; i++)
    //     {
    //         cin >> prices[i];
    //     }

    cout << maxProfit(prices) << endl;
    // }

    return 0;
}

// ॥ जय श्री राम जय श्री कृष्ण ॥