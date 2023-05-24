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

int getMaximum(int N, vector<int> &arr)
{
    int n = N;
    int64_t sum = accumulate(arr.begin(), arr.end(), 0LL);

    for (int i = n; i > 0; i--)
    {
        if (sum % i == 0)
        {
            return i;
        }
    }

    return 0;
}

int main()
{

    return 0;
}

// ॥ जय श्री राम जय श्री कृष्ण ॥