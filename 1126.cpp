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

int count(int arr[], int n, int x)
{
    // code here

    auto low = lower_bound(arr, arr + n, x);
    auto up = upper_bound(arr, arr + n, x);

    return (int)(up - low);
}

int main()
{

    return 0;
}

// ॥ जय श्री राम जय श्री कृष्ण ॥