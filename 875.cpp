// ॥ श्री गणेशाय नमः ॥

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define ll long long
#define ull unsigned long long
using namespace std;
using namespace chrono;
using namespace __gnu_pbds;

// mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

ll monnaNumber(ll a, ll b)
{
    return a + (ull)rng() % (b - a + 1);
}

// typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
typedef tree<ll, null_type, less_equal<ll>, rb_tree_tag, tree_order_statistics_node_update> ordered_multiset;

int reversePairs(vector<int> &nums)
{
    int n = nums.size();

    long long ans = 0;

    ordered_multiset s;

    for (int i = 0; i < n; i++)
    {
        ans += (s.size() - s.order_of_key(2 * nums[i] + 1));

        s.insert(nums[i]);
    }

    return ans;
}

int main()
{

    cout << monnaNumber(1, 200) << endl;

    return 0;
}

// ॥ जय श्री राम जय श्री कृष्ण ॥