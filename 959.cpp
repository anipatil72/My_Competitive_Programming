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

bool canMakeArithmeticProgression(vector<int> &a)
{
    int n = a.size();

    sort(a.begin(), a.end());

    int tem = a[1] - a[0];

    for (int i = 0; i < n - 1; i++)
    {
        if (tem != a[i + 1] - a[i])
        {
            return false;
        }
    }

    return true;
}

int main()
{

    return 0;
}

// ॥ जय श्री राम जय श्री कृष्ण ॥