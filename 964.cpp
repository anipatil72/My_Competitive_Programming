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

int minFlips(int a, int b, int c)
{

    if ((a | b) == c)
    {
        return 0;
    }

    int ans = 0;

    for (int i = 0; i < 31; i++)
    {
        if ((c & (1 << i)) != ((a | b) & (1 << i)))
        {

            if ((c & (1 << i)) > 0)
            {

                ans++;
            }
            else
            {
                ans += ((a & (1 << i)) > 0) + ((b & (1 << i)) > 0);
            }
        }
    }

    return ans;
}

int main()
{

    return 0;
}

// ॥ जय श्री राम जय श्री कृष्ण ॥