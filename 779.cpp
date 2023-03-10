// ॥ श्री गणेशाय नमः ॥

#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define M 1000000007
using namespace std;

int maximumDifference(vector<int> &nums)
{

    int mini = nums[0];

    int n = nums.size();

    int ans = -1;

    for (int i = 0; i < n; i++)
    {
        ans = max(ans, nums[i] - mini);

        mini = min(nums[i], mini);
    }

    return ans;
}

int main()
{

    return 0;
}

// ॥ जय श्री राम जय श्री कृष्ण ॥