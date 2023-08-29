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

int recur(int index, int target, vector<int> &nums, vector<int> &dp)
{
    int n = nums.size();

    if (index == n - 1)
    {
        return 0;
    }

    if (dp[index] != -2)
    {
        return dp[index];
    }

    int ans = -1;

    for (int i = index + 1; i < n; i++)
    {
        if (abs(nums[index] - nums[i]) <= target)
        {
            int des = recur(i, target, nums, dp);

            if (des >= 0)
            {
                ans = max(ans, des + 1);
            }
        }
    }

    return dp[index] = ans;
}

int maximumJumps(vector<int> &nums, int target)
{
    int n = nums.size();

    vector<int> dp(n, -2);

    return recur(0, target, nums, dp);
}

int main()
{

    vector<int> nums = {1, 3, 6, 4, 1, 2};

    int target = 0;

    cout << maximumJumps(nums, target) << endl;

    return 0;
}

// ॥ जय श्री राम जय श्री कृष्ण ॥