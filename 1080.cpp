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

long long putMarbles(vector<int> &weights, int k)
{
    int n = weights.size();

    vector<long long> pref(n - 1);

    for (int i = 0; i < n - 1; i++)
    {
        pref[i] = weights[i] + 0LL + weights[i + 1];
    }

    sort(pref.begin(), pref.end());

    int64_t fron = accumulate(pref.begin(), pref.begin() + k - 1, 0LL);

    int64_t back = accumulate(pref.begin() + n - k + 1, pref.end(), 0LL);

    return abs(back - fron);
}

int main()
{

    return 0;
}

// ॥ जय श्री राम जय श्री कृष्ण ॥