// ॥ श्री गणेशाय नमः ॥

#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define M 1000000007
using namespace std;

vector<int> productExceptSelf(vector<int> &nums)
{
    int n = nums.size();

    vector<int> ans(n);

    int count = 0;

    int index = -1;

    for (int i = 0; i < n; i++)
    {
        if (nums[i] == 0)
        {
            count++;

            index = i;
        }
    }

    int left = 1, right = 1;

    ll anss = 1;

    for (int i = 0; i < n; i++)
    {

        if (i == index)
        {

            left = anss;

            continue;
        }

        anss *= nums[i];
    }

    if (count >= 2)
    {
        return ans;
    }
    else if (count == 1)
    {
        ans[index] = anss;
    }
    else
    {

        for (int i = 0; i < n; i++)
        {
            ans[i] = anss / nums[i];
        }
    }

    return ans;
}

int main()
{

    return 0;
}

// ॥ जय श्री राम जय श्री कृष्ण ॥