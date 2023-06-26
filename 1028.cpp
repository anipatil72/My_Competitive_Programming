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

int longestMountain(vector<int> &nums)
{
    int n = nums.size();

    vector<int> dp1(n, 1);

    for (int i = 0; i < n; i++)
    {
        int tem = 0;

        for (int j = 0; j < i; j++)
        {
            if (nums[j] < nums[i])
            {
                tem = max(tem, dp1[j]);
            }
        }

        dp1[i] = 1 + tem;
    }

    vector<int> dp2(n, 1);

    for (int i = n - 1; i >= 0; i--)
    {
        int tem = 0;

        for (int j = n - 1; j > i; j--)
        {
            if (nums[j] < nums[i])
            {
                tem = max(tem, dp2[j]);
            }
        }

        dp2[i] = 1 + tem;
    }

    int ans = 0;

    for (int i = 0; i < n; i++)
    {
        if (dp1[i] > 1 && dp2[i] > 1)
        {
            int x = dp1[i] + dp2[i] - 1;
            ans = max(ans, x);
        }
    }

    return ans;
}

int main()
{

    return 0;
}

// ॥ जय श्री राम जय श्री कृष्ण ॥