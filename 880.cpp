// ॥ श्री गणेशाय नमः ॥

#include <bits/stdc++.h>
#include <chrono>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define ll long long
#define ull unsigned long long
using namespace std;
using namespace __gnu_pbds;

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

ll MyNum(ll a, ll b)
{
    return a + rng() % (b - a + 1);
}

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
// typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_multiset;

int recur(int index, int zero, int one, vector<int> &dp)
{
    if (index < 0)
    {
        return -1e9;
    }

    if (index == 0)
    {
        return 1;
    }

    if (dp[index] != -1)
    {

        return dp[index];
    }

    int fir = recur(index - one, zero, one, dp);

    int sec = recur(index - zero, zero, one, dp);

    int ans = 0;

    if (sec == (int)-1e9 && fir == (int)-1e9)
    {
        return dp[index] = (int)-1e9;
    }

    if (fir != (int)-1e9)
    {
        ans += (fir + 1);
    }

    if (sec != (int)-1e9)
    {
        ans += (sec + 1);
    }

    return dp[index] = ans;
}

int countGoodStrings(int low, int high, int zero, int one)
{
    vector<int> dp(high + 1, -1);

    int firr = recur(high, zero, one, dp);

    int secc = recur(low - 1, zero, one, dp);
}

int main()
{
    cout << MyNum(1, 100) << endl;

    return 0;
}

// ॥ जय श्री राम जय श्री कृष्ण ॥