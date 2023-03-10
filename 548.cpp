#include <bits/stdc++.h>
using namespace std;

int rob(vector<int> &nums)
{
    int n = nums.size();

    int evensum = 0, oddsum = 0;

    for (int i = 0; i < n; i++)
    {
        if (i % 2 == 0)
        {
            evensum += nums[i];
        }
        else
        {
            oddsum += nums[i];
        }
    }

    return max(evensum, oddsum);
}

int main()
{

    return 0;
}