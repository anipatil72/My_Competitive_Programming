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

int balancedStringSplit(string s)
{
    int n = s.length();

    if (n == 2)
    {
        return 0;
    }

    int right = 0, left = 0;

    right += (s[0] == 'R');
    left += (s[0] == 'L');

    int count = 0;

    for (int i = 1; i < n; i++)
    {

        right += (s[i] == 'R');
        left += (s[i] == 'L');

        if (left == right)
        {
            count++;
        }
    }

    return count;
}

int main()
{

    return 0;
}

// ॥ जय श्री राम जय श्री कृष्ण ॥