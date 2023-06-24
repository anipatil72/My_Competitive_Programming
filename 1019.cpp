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

bool containsDuplicate(vector<int> &nums)
{
    int n = nums.size();

    unordered_set<int> s;

    s.insert(nums[0]);

    for (int i = 1; i < n; i++)
    {
        if (s.count(nums[i]) > 0)
        {
            return true;
        }

        s.insert(nums[i]);
    }

    return false;
}

int main()
{

    return 0;
}

// ॥ जय श्री राम जय श्री कृष्ण ॥