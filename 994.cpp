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

long long countBadPairs(vector<int> &nums)
{
    int n = nums.size();

    unordered_map<int, int> m;

    long long tem = 0;

    for (int i = 0; i < n; i++)
    {
        int des = nums[i] - i;

        if (m.count(des) > 0)
        {
            tem += m[des];
        }

        m[des]++;
    }

    long long ans = n * 1LL * (n - 1) / 2;

    ans -= tem;

    return ans;
}

int main()
{

    return 0;
}

// ॥ जय श्री राम जय श्री कृष्ण ॥