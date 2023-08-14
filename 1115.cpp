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

bool validPartition(vector<int> &nums)
{
    int n = nums.size();

    vector<int> dp(n);

    // dp[0] = 0;

    if (nums[0] == nums[1])
    {
        dp[1] = 1;
    }

    if (n <= 2)
    {
        return dp[n - 1];
    }

    if ((nums[0] == nums[1] && nums[0] == nums[2]) || ((nums[0] + 1 == nums[1]) && (nums[0] + 2 == nums[2])))
    {
        dp[2] = 1;
    }

    for (int i = 3; i < n; i++)
    {
        int ans = 0;

        if ((nums[i] == nums[i - 1]) && (dp[i - 2] == 1))
        {
            dp[i] = 1;

            continue;
        }
        else if (((nums[i] == nums[i - 1]) && (nums[i - 1] == nums[i - 2])) && dp[i - 3] == 1)
        {
            dp[i] = 1;

            continue;
        }
        else if ((nums[i - 2] + 1 == nums[i - 1]) && (nums[i - 2] + 2 == nums[i]) && dp[i - 3] == 1)
        {
            dp[i] = 1;

            continue;
        }
    }

    return dp[n - 1];
}

int main()
{

    return 0;
}

// ॥ जय श्री राम जय श्री कृष्ण ॥