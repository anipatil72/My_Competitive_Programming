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

double findMaxAverage(vector<int> &nums, int k)
{
    int n = nums.size();

    int tot = accumulate(nums.begin(), nums.begin() + k, 0);

    double ans = 1.0 * tot / k;

    for (int i = k; i < n; i++)
    {
        tot -= nums[i - k];

        tot += nums[i];

        ans = max(ans, 1.0 * tot / k);
    }

    return ans;
}

int main()
{

    return 0;
}

// ॥ जय श्री राम जय श्री कृष्ण ॥