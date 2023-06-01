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

int LargButMinFreq(int arr[], int n)
{
    unordered_map<int, int> m;

    int sizz = 1000000;

    for (int i = 0; i < n; i++)
    {
        m[arr[i]]++;

        // sizz = min(sizz, m[arr[i]]);
    }

    for (auto x : m)
    {
        sizz = min(sizz, x.second);
    }

    int ans = 0;

    for (auto x : m)
    {

        if (x.second == sizz)
        {
            ans = max(ans, x.first);
        }
    }

    return ans;
}

int main()
{

    return 0;
}

// ॥ जय श्री राम जय श्री कृष्ण ॥