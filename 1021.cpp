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

vector<int> largestDivisibleSubset(vector<int> &nums)
{
    int n = nums.size();

    sort(nums.begin(), nums.end());

    vector<int> hash(n, -1);

    for (int i = 0; i < n; i++)
    {
        hash[i] = i;
    }

    vector<int> dp(n, 1);

    int ans = 1;

    int dex = 0;

    for (int i = 0; i < n; i++)
    {
        int tem = 0, index = -1;

        for (int j = 0; j < i; j++)
        {
            if (nums[i] % nums[j] == 0)
            {
                if (tem < dp[j])
                {
                    tem = dp[j];

                    index = j;
                }
            }
        }

        dp[i] = 1 + tem;

        hash[i] = index == -1 ? i : index;

        if (ans < dp[i])
        {
            ans = dp[i];

            dex = i;
        }
    }

    vector<int> path;

    while (hash[dex] != dex)
    {
        path.push_back(nums[dex]);

        dex = hash[dex];
    }

    path.push_back(nums[dex]);

    reverse(path.begin(), path.end());

    return path;
}

int main()
{

    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    return 0;
}

// ॥ जय श्री राम जय श्री कृष्ण ॥