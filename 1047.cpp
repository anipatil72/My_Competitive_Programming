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

int isDivisible(string s)
{
    int n = s.length();

    int cur = 0;

    for (int i = 0; i < n; i++)
    {
        if (s[i] == '0')
        {
            cur += cur;

            cur %= 3;
        }
        else
        {
            cur += (cur + 1);

            cur %= 3;
        }
    }

    return cur == 0;
}

int main()
{

    return 0;
}

// ॥ जय श्री राम जय श्री कृष्ण ॥