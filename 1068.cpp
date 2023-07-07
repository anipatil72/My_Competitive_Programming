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

int maximumScore(vector<int> &nums, int k)
{
    int n = nums.size(), ans = nums[k], x;
    int mi = nums[k];
    for (int i = k, j = k; i >= 0 || j < n;)
    {

        while (j < n && nums[j] >= mi)
        {
            ++j;
        }
        while (i >= 0 && nums[i] >= mi)
        {
            --i;
        }

        ans = max(ans, mi * (j - i - 1));
        if (i >= 0 && j < n)
        {

            mi = (nums[i] > nums[j] ? nums[i] : nums[j]);
        }
        else if (j < n)
        {
            mi = nums[j];
        }
        else if (i >= 0)
        {
            mi = nums[i];
        }
    }
    return ans;
}

int main()
{

    return 0;
}

// ॥ जय श्री राम जय श्री कृष्ण ॥