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

int maximumCount(vector<int> &nums)
{
    int n = nums.size();

    int pos = (int)(nums.end() - upper_bound(nums.begin(), nums.end(), 0));

    int neg = (int)(lower_bound(nums.begin(), nums.end(), 0) - nums.begin());

    return max(pos, neg);
}

int main()
{

    return 0;
}

// ॥ जय श्री राम जय श्री कृष्ण ॥