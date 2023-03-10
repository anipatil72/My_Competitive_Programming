// ॥ श्री गणेशाय नमः ॥

#include <bits/stdc++.h>
#define ll long long
#define M 1000000007
using namespace std;

int maxSubArraySum(vector<int> &a)
{
    int max_so_far = INT_MIN, max_ending_here = 0;

    int n = a.size();

    // int x = 2*n;

    for (int i = 0; i < 2 * n; i++)
    {
        max_ending_here = max_ending_here + a[(i - 1 + n) % n];
        if (max_so_far < max_ending_here)
        {
            max_so_far = max_ending_here;
        }

        if (max_ending_here < 0)
        {
            max_ending_here = 0;
        }
    }
    return max_so_far;
}

int maxSubarraySumCircular(vector<int> &nums)
{

    int n = nums.size();

    ll ans = maxSubArraySum(nums);

    return ans;
}

int main()
{

    // vector<int> a = {1, 2, 3, 4, 5};

    // vector<int> b = a;

    // for (int i = 0; i < 5; i++)
    // {

    //     b.push_back(a[i]);
    // }

    // for (int i = 0; i < 10; i++)
    // {

    //     cout << b[i] << " ";
    // }

    // cout << endl;

    return 0;
}

// ॥ जय श्री राम जय श्री कृष्ण ॥