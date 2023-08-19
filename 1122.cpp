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

int maxOnes(int a[], int n)
{
    int ones = 0, zeros = 0;

    for (int i = 0; i < n; i++)
    {
        ones += a[i];

        if (a[i] == 1)
        {
            a[i] = -1;
        }
        else
        {
            a[i] = 1;
        }
    }

    int good = -1, best = -1;

    for (int i = 0; i < n; i++)
    {
        good = max(a[i], a[i] + good);

        best = max(best, good);
    }

    return ones + best;
}

int main()
{

    return 0;
}

// ॥ जय श्री राम जय श्री कृष्ण ॥