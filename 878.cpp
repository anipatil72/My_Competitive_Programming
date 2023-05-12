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

int subarrayWithMaxProduct(vector<int> &arr)
{
    int n = arr.size();

    int ans = INT_MIN;

    int pref = 1, suff = 1;
    int prod = 1;

    for (int i = 0; i < n; i++)
    {

        if (pref == 0)
        {
            pref = 1;
        }
        else if (suff == 0)
        {
            suff = 1;
        }

        pref = pref * arr[i];

        suff = suff * arr[n - 1 - i];

        ans = max({ans, pref, suff});
    }

    return ans;
}

// achha sawal tha

int main()
{

    return 0;
}

// ॥ जय श्री राम जय श्री कृष्ण ॥