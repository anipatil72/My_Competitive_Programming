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

bool myComp(int a, int b)
{
    if (abs(a) == abs(b))
    {
        return a < b;
    }

    abs(a) < abs(b);
}

int findMaxK(vector<int> &nums)
{
    int n = nums.size();

    sort(nums.begin(), nums.end(), myComp);

    int ans = -1;

    for (int i = 0; i < n - 1; i++)
    {
        if ((nums[i] < 0 && nums[i + 1] > 0) && (abs(nums[i]) == abs(nums[i + 1])))
        {
            ans = abs(nums[i]);
        }
    }

    return ans;
}

int main()
{

    return 0;
}

// ॥ जय श्री राम जय श्री कृष्ण ॥