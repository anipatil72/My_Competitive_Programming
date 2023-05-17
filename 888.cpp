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

bool increasingTriplet(vector<int> &nums)
{
    int n = nums.size();

    bool flag = false;

    long long maxi = (long long)-1e15;

    long long cur = maxi;

    for (int i = 0; i < n - 1; i++)
    {
        if (flag && (cur <= nums[i]))
        {
            return true;
        }

        if ((!flag) && (nums[i] < nums[i + 1]))
        {
            cur = nums[i + 1] + 1;

            flag = true;
        }
        else if (nums[i] < nums[i + 1])
        {
            if (cur > (nums[i + 1] + 1))
            {
                cur = nums[i + 1] + 1;
            }
        }
    }

    if (flag && (cur <= nums[n - 1]))
    {
        return true;
    }

    return false;
}

int main()
{

    vector<int> v = {20, 100, 10, 12, 5, 13};

    cout << increasingTriplet(v);

    return 0;
}

// ॥ जय श्री राम जय श्री कृष्ण ॥