// ॥ श्री गणेशाय नमः ॥

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define ll long long
#define ull unsigned long long
using namespace std;
using namespace __gnu_pbds;

const int MOD = 1000000007;

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
// typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_multiset;

int solve(string &s, int k)
{

    int n = s.length();

    // Using a DP array of size n+1

    vector<ll> dp(n + 1, 1);

    string des = to_string(k);

    int m = des.length();

    for (int i = 1; i <= n; i++)
    {
        int xav = min(i, m);

        for (int j = 1; j <= xav; j++)
        {
            ll y = stoll(s.substr(i - j, j));

            if (y <= k)
            {

                if (s[i - j] != '0')
                {
                    dp[i] = (dp[i] + dp[i - j]) % MOD;
                }
            }
        }
    }

    return ((dp.back()) % MOD);
}

int main()
{

    int n, k;

    cin >> n >> k;

    string des;

    cin >> des;

    cout << solve(des, k);

    return 0;
}

// ॥ जय श्री राम जय श्री कृष्ण ॥