// ॥ श्री गणेशाय नमः ॥

#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
#define ll long long
#define ull unsigned long long
using namespace std;

int search(vector<int> &nums, int target)
{
    int n = nums.size();

    if (binary_search(nums.begin(), nums.end(), target))
    {
        return (int)(lower_bound(nums.begin(), nums.end(), target) - nums.begin());
    }

    return -1;
}

int main()
{

    return 0;
}

// ॥ जय श्री राम जय श्री कृष्ण ॥