// ॥ श्री गणेशाय नमः ॥

#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define M 1000000007
using namespace std;

int maximumProduct(vector<int> &nums)
{
    int n = nums.size();

    sort(nums.begin(), nums.end());

    if (n == 3)
    {
        int p = 1;

        p *= nums[0];
        p *= nums[1];
        p *= nums[2];

        return p;
    }
    else if (n == 4)
    {
        int p = 1, q = 1;

        p *= nums[0];
        p *= nums[1];
        p *= nums[3];

        q *= nums[1];
        q *= nums[2];
        q *= nums[3];

        return max(p, q);
    }

    int p = 1, q = 1;

    p *= nums[0];
    p *= nums[1];
    p *= nums[n - 1];

    q *= nums[n - 1];
    q *= nums[n - 2];
    q *= nums[n - 3];

    return max(p, q);
}

int main()
{

    return 0;
}

// ॥ जय श्री राम जय श्री कृष्ण ॥