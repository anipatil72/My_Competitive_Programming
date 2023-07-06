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

int minimizeXor(int num1, int num2)
{
    int tot = __builtin_popcount(num1);

    int x = 0, count = 0;

    for (int i = 31; i >= 0 && count < tot; i--)
    {
        if (num2 & (1 << i))
        {
            x |= (1 << i);

            count++;
        }
    }

    for (int i = 0; i < 32 && count < tot; i++)
    {
        if (num2 & (1 << i))
        {
        }
        else
        {
            x |= (1 << i);

            count++;
        }
    }

    return x;
}

int main()
{

    return 0;
}

// ॥ जय श्री राम जय श्री कृष्ण ॥