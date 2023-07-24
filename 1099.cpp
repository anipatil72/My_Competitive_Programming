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

int recur(int n)
{
    if (n == 1)
    {
        return 2;
    }

    if (n & 1)
    {
        long long ans = 2 * (recur(n - 1));

        return ans % MOD;
    }

    long long ans = recur(n / 2);

    long long tem = ans * ans % MOD;

    return tem % MOD;
}

int monkeyMove(int n)
{
    int ans = recur(n) - 2;

    ans = (ans + MOD) % MOD;

    return ans;
}

int main()
{

    return 0;
}

// ॥ जय श्री राम जय श्री कृष्ण ॥