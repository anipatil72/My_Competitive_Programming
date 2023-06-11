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

void update(int a[], int n, int updates[], int k)
{

    for (int i = 0; i < k; i++)
    {
        a[updates[i] - 1] += 1;
    }

    for (int i = 1; i < n; i++)
    {
        a[i] = a[i] + a[i - 1];
    }
}

int main()
{

    return 0;
}

// ॥ जय श्री राम जय श्री कृष्ण ॥