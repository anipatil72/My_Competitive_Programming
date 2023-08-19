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

const int MOD = 1000000007;

int findCatalan(int n)
{
    vector<int> dp(n + 1);

    dp[0] = 1, dp[1] = 1;

    for (int i = 2; i <= n; i++)
    {
        int des = 0;

        for (int j = 0; j < i; j++)
        {
            des += (dp[j] * 1LL * dp[i - 1 - j]) % MOD;

            des %= MOD;
        }

        dp[i] = des;
    }

    return dp[n];
}

int main()
{

    int n = 5;

    cout << findCatalan(n) << endl;

    return 0;
}

// ॥ जय श्री राम जय श्री कृष्ण ॥