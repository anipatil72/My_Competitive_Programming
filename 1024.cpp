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

int findLengthOfLCIS(vector<int> &nums)
{
    int n = nums.size();

    int maxi = 1;

    if (n == 1)
    {
        return 1;
    }

    int prev = 1;

    bool flag = true;

    for (int i = 0; i < n - 1; i++)
    {
        if (nums[i] < nums[i + 1])
        {
            // if (flag)
            // {
            //     // prev = i;

            //     flag = false;
            // }

            prev++;
        }
        else
        {
            maxi = max(maxi, prev);

            prev = 1;
        }
    }

    maxi = max(maxi, prev);

    return maxi;
}

int main()
{

    return 0;
}

// ॥ जय श्री राम जय श्री कृष्ण ॥