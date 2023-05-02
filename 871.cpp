// ॥ श्री गणेशाय नमः ॥

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define ll long long
#define ull unsigned long long
using namespace std;
using namespace __gnu_pbds;

int arraySign(vector<int> &nums)
{
    int even = 0, odd = 0, iszero = 0;

    int n = nums.size();

    for (int i = 0; i < n; i++)
    {
        if (nums[i] == 0)
        {
            return 0;
        }
        else if (nums[i] > 0)
        {
            even++;
        }
        else
        {
            odd++;
        }
    }

    if (odd % 2 == 0)
    {
        return 1;
    }

    return -1;
}

int main()
{

    return 0;
}

// ॥ जय श्री राम जय श्री कृष्ण ॥