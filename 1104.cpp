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

// int minimumDeleteSum(string s1, string s2)
// {
//     return 0;
// }

int main()
{

    // char d = 's';

    // int value = (d);

    // cout << value << endl;

    int x, y, z;

    z = 4, x = 5, y = 9;

    while (--x)
    {
        x = z + 1;

        y = x - z;

        z = y / 2;
    }

    cout << z << endl;

    return 0;
}

// ॥ जय श्री राम जय श्री कृष्ण ॥