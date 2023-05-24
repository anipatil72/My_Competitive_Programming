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

vector<int> rearrangeArray(vector<int> &nums)
{
    int n = nums.size();

    vector<int> v(n);

    int pos = 0, neg = 1;

    for (int i = 0; i < n; i++)
    {
        if (nums[i] > 0)
        {
            v[pos] = nums[i];

            pos += 2;
        }
        else
        {
            v[neg] = nums[i];

            neg += 2;
        }
    }

    nums = v;

    return nums;
}

int main()
{

    return 0;
}

// ॥ जय श्री राम जय श्री कृष्ण ॥