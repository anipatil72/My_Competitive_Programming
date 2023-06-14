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

int giveRever(int n)
{
    string tem = to_string(n);

    reverse(tem.begin(), tem.end());

    return stoi(tem);
}

int countNicePairs(vector<int> &nums)
{
    int n = nums.size();

    int MOD = (int)1e9 + 7;

    unordered_map<int, int> m;

    long long ans = 0;

    for (int i = 0; i < n; i++)
    {
        if (m.count(nums[i] - giveRever(nums[i])) > 0)
        {
            ans += m[nums[i] - giveRever(nums[i])];

            ans %= MOD;
        }

        m[nums[i] - giveRever(nums[i])]++;
    }

    return ans;
}

int main()
{

    // cout << INT_MAX << endl;

    return 0;
}

// ॥ जय श्री राम जय श्री कृष्ण ॥