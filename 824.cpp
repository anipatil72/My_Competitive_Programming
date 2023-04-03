// ॥ श्री गणेशाय नमः ॥

#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
#define ll long long
#define ull unsigned long long
using namespace std;

// Single Number Leetcode

int singleNumber(vector<int> &nums)
{
    int n = nums.size();

    vector<int> pos(32, 0);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 32; j++)
        {
            if ((nums[i] & (1 << j)))
            {
                pos[j]++;
            }
        }
    }

    int ans = 0;

    for (int i = 0; i < 32; i++)
    {
        pos[i] %= 3;

        ans |= (pos[i] << i);
    }

    return ans;
}

int main()
{

    vector<int> nums = {0, 1, 0, 1, 0, 1, 99};

    cout << singleNumber(nums);

    return 0;
}

// ॥ जय श्री राम जय श्री कृष्ण ॥