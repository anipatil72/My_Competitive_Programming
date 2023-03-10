#include <bits/stdc++.h>
using namespace std;

int missingNumber(vector<int> &nums)
{

    int n = nums.size();

    nums.push_back(INT_MAX);

    for (int i = 0; i < n + 1; i++)
    {
        if (nums[i] != INT_MAX && nums[i] != i)
        {
            swap(nums[i], nums[nums[i]]);
        }
    }

    for (int i = 0; i < n + 1; i++)
    {
        if (nums[i] == INT_MAX)
        {
            return i;
        }
    }

    return -1;
}

int main()
{

    return 0;
}