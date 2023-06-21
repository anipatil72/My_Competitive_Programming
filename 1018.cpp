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

vector<long long> minOperations(vector<int> &nums, vector<int> &queries)
{
    int n = nums.size();

    sort(nums.begin(), nums.end());

    vector<long long> pref(n, 0);

    pref[0] = nums[0];

    for (int i = 1; i < n; i++)
    {
        pref[i] = nums[i] + pref[i - 1];
    }

    int q = queries.size();

    vector<long long> ans;

    for (int i = 0; i < q; i++)
    {
        int pos = (int)(lower_bound(nums.begin(), nums.end(), queries[i]) - nums.begin());

        if (pos == n)
        {
            long long t = n * 1LL * queries[i];

            ans.push_back(t - pref[n - 1]);
        }
        else if (pos == 0)
        {

            long long t = n * 1LL * queries[i];

            ans.push_back(pref[n - 1] - t);
        }
        else
        {
            long long left = pos * 1LL * queries[i] - pref[pos - 1];

            long long right = pref[n - 1] - pref[pos - 1] - pos * 1LL * queries[i];

            ans.push_back(left + right);
        }
    }

    return ans;
}

int main()
{

    map<pair<int, int>, vector<int>> m = {{{1, 2}, {1, 2, 3}}, {{2, 3}, {1, 2, 3}}};

    return 0;
}

// ॥ जय श्री राम जय श्री कृष्ण ॥