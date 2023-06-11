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

// Todo : https://leetcode.com/problems/snapshot-array/

int maxValue(int n, int index, int maxSum)
{
    ll right = n - index - 1;

    ll left = index;

    ll m = 0;

    ll leftstat = m - min(m, left);
}

int main()
{

    return 0;
}

// ॥ जय श्री राम जय श्री कृष्ण ॥