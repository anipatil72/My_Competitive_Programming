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

int singleNumber(vector<int> &nums)
{
    int n = nums.size();

    vector<int> sum(32, 0);

    int sign = 0;

    for (int j = 0; j < n; j++)
    {
        for (int i = 0; i < 32; i++)
        {
            if ((nums[j] & (1 << (i))))
            {
                sum[i]++;
            }
        }
    }

    int ans = 0;

    for (int i = 0; i < 32; i++)
    {
        int des = sum[i] % 3;

        ans |= (des << i);
    }

    return ans;
}

int main()
{

    return 0;
}

// ॥ जय श्री राम जय श्री कृष्ण ॥