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

int recur(int index, int jindex, vector<int> &nums, int64_t sum, vector<vector<int64_t>> &dp)
{
    if (index + 1 == jindex)
    {
        return max(nums[index], nums[jindex]);
    }

    if (dp[index][jindex] != -1)
    {
        return dp[index][jindex];
    }

    int64_t fir = sum - recur(index + 1, jindex, nums, sum - nums[index], dp);

    int64_t las = sum - recur(index, jindex - 1, nums, sum - nums[jindex], dp);

    return dp[index][jindex] = max(fir, las);
}

bool PredictTheWinner(vector<int> &nums)
{
    int n = nums.size();

    if (n == 1 || n % 2 == 0)
    {
        return 1;
    }

    int64_t sum = accumulate(nums.begin(), nums.end(), 0LL);

    vector<vector<int64_t>> dp(n, vector<int64_t>(n, -1));

    int64_t x = recur(0, n - 1, nums, sum, dp);

    return x >= (sum - x);
}

int main()
{

    return 0;
}

// ॥ जय श्री राम जय श्री कृष्ण ॥