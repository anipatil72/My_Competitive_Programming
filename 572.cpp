#include <bits/stdc++.h>
using namespace std;

#define ll long long

bool checkSubarraySum(vector<int> &nums, int k)
{
    int n = nums.size();

    if (n == 1)
    {
        return false;
    }

    vector<ll> prefix(n, 0);

    prefix[0] = nums[0];

    for (int i = 1; i < n; i++)
    {
        prefix[i] = prefix[i - 1] + nums[i];

        if (prefix[i] % k == 0)
        {
            return true;
        }
    }

    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < i - 1; j++)
        {
            if ((prefix[i] - prefix[j]) % k == 0)
            {
                return true;
            }
        }
    }

    return false;
}

int main()
{

    return 0;
}