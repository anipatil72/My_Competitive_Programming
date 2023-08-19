// ॥ श्री गणेशाय नमः ॥

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define ll long long
#define ull unsigned long long
using namespace std;
using namespace __gnu_pbds;

vector<int> leaders(int a[], int n)
{
    vector<int> lead;

    int cur = -1;

    for (int i = n - 1; i >= 0; i--)
    {

        if (a[i] >= cur)
        {
            lead.push_back(a[i]);

            cur = a[i];
        }
    }

    reverse(lead.begin(), lead.end());

    return lead;
}

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
// typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_multiset;

int main()
{

    return 0;
}

// ॥ जय श्री राम जय श्री कृष्ण ॥