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

int findPairs(vector<int> &nums, int k)
{
    int n = nums.size();

    unordered_map<int, int> m;

    int ans = 0;

    for (int i = 0; i < n; i++)
    {

        if (m.count(nums[i]) > 0)
        {
            if (k == 0 && m[nums[i]] == 1)
            {
                m[nums[i]]++;
                ans++;
            }

            continue;
        }

        int back = nums[i] - k;
        int front = nums[i] + k;

        if (m.count(back) > 0)
        {
            ans += m[back];
        }

        if (back != front && (m.count(front) > 0))
        {
            ans += m[front];
        }

        m[nums[i]]++;
    }

    return ans;
}

int main()
{

    return 0;
}

// ॥ जय श्री राम जय श्री कृष्ण ॥