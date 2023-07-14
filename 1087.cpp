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

bool isFrequencyUnique(int n, int arr[])
{
    unordered_map<int, int> m;

    for (int i = 0; i < n; i++)
    {
        m[arr[i]]++;
    }

    unordered_map<int, int> nex;

    for (auto &x : m)
    {
        if (nex.count(x.second) > 0)
        {
            return false;
        }

        nex[x.second]++;
    }

    return true;
}

int main()
{

    return 0;
}

// ॥ जय श्री राम जय श्री कृष्ण ॥