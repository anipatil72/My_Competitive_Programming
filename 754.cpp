// ॥ श्री गणेशाय नमः ॥

#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define M 1000000007
using namespace std;

int maximumNonAdjacentSum(vector<int> &nums)
{

    int n = nums.size();

    vector<int> dp(n, 0);

    dp[0] = nums[0];

    dp[1] = max(dp[0], nums[1]);

    for (int i = 2; i < n; i++)
    {

        dp[i] = max(dp[i - 2] + nums[i], dp[i - 1]);
    }

    return dp[n - 1];
}

int main()
{

    vector<int> nums = {};

    cout<<maximumNonAdjacentSum(nums);

    return 0;
}

// ॥ जय श्री राम जय श्री कृष्ण ॥