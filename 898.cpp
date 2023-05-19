// ॥ श्री गणेशाय नमः ॥

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define ll long long
#define ull unsigned long long
using namespace std;
using namespace __gnu_pbds;

// https://leetcode.com/problems/minimize-maximum-of-array/

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
// typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_multiset;

int minimizeArrayValue(vector<int> &nums)
{
    int n = nums.size();

    if (n == 1)
    {
        return nums[0];
    }

    int miz = -1;
}

int main()
{

    vector<int> v = {1, 10};

    cout << minimizeArrayValue(v);

    return 0;
}

// ॥ जय श्री राम जय श्री कृष्ण ॥