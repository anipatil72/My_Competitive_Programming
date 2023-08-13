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

int recur(int sum, int index, vector<int> &coins, vector<vector<int>> &dp)
{
    if (sum < 0)
    {
        return 0;
    }

    if (sum == 0)
    {
        return 1;
    }

    // cout << "This is sum : " << sum << " and this is index : " << index << endl;

    if (dp[sum][index] != -1)
    {
        return dp[sum][index];
    }

    int n = coins.size();

    int tot = 0;

    for (int i = index; i < n; i++)
    {
        int des = recur(sum - coins[i], i, coins, dp);

        // cout << des << endl;

        // cout << i << endl;

        tot += des;
    }

    return dp[sum][index] = tot;
}

int change(int amount, vector<int> &coins)
{
    int n = coins.size();

    vector<vector<int>> dp(amount + 1, vector<int>(n, -1));

    int ans = recur(amount, 0, coins, dp);

    // for (int i = 0; i < amount; i++)
    // {
    //     for (int j = 0; j < n; j++)
    //     {
    //         cout << dp[i][j] << " ";
    //     }

    //     cout << endl;
    // }

    return ans;
}

int main()
{

    vector<int> coins = {2, 1, 5};

    int amount = 5;

    cout << change(amount, coins) << endl;

    return 0;
}

// ॥ जय श्री राम जय श्री कृष्ण ॥