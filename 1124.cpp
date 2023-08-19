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

int recur(int index, vector<int> &dp)
{
    // cout << "I am here! " << index << endl;

    if (index <= dp.size() && dp[index] != -1)
    {
        return dp[index];
    }

    int worth = index & (index - 1);

    // cout << "This is worth it : " << worth << endl;

    if (worth == 0)
    {
        // cout << "I am here! " << index << endl;

        // cout << "Special" << endl;

        int fin = (int)(log2(index));

        return fin + 1;
    }

    if (index & 1)
    {
        if (index < dp.size())
        {
            return dp[index] = 1 + recur(3 * index + 1, dp);
        }
        else
        {
            return 1 + recur(3 * index + 1, dp);
        }
    }

    if (index < dp.size())
    {
        return dp[index] = 1 + recur(index / 2, dp);
    }
    else
    {
        return 1 + recur(index / 2, dp);
    }
}

int collatzLength(int N)
{
    vector<int> dp(4 * N + 1, -1);

    dp[1] = 1, dp[2] = 2, dp[4] = 3;

    int ans = 1;

    for (int i = 3; i <= N; i++)
    {
        int des = recur(i, dp);

        ans = max(ans, des);
    }

    // for (int i = 0; i < dp.size(); i++)
    // {
    //     cout << dp[i] << " ";
    // }

    // cout << endl;

    return ans;

    // return 0;
}

int main()
{

    int n = 3;

    cout << collatzLength(n) << endl;

    // int des = 32;

    // cout << (int)log2(des) << endl;

    // cout << (des & (des - 1)) << endl;

    // int des = 32;

    return 0;
}

// ॥ जय श्री राम जय श्री कृष्ण ॥