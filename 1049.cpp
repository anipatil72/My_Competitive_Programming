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

int recur(int index, vector<int> &nums, int k, vector<int> &dp)
{
    int n = nums.size();

    if (index == n)
    {
        return 0;
    }

    if (dp[index] != -1)
    {
        return dp[index];
    }

    int maxi = -1, count = 0;

    int ans = 0;

    for (int i = index; i < n && count < k; i++)
    {
        maxi = max(maxi, nums[i]);

        count++;

        int des = 0;

        if (count == k)
        {
            des = maxi * count + recur(i + 1, nums, k, dp);

            // cout << "I am at index = " << index << " and i = " << i << " and here des = " << des << endl;

            ans = max(des, ans);

            break;
        }
        else
        {
            des = maxi * count + recur(i + 1, nums, k, dp);
            // cout << "I am at index = " << index << " and i = " << i << " and here des = " << des << endl;

            ans = max(des, ans);
        }
    }

    return dp[index] = ans;
}

int maxSumAfterPartitioning(vector<int> &arr, int k)
{
    int n = arr.size();

    vector<int> dp(n, -1);

    return recur(0, arr, k, dp);
}

int main()
{

    vector<int> test = {1};

    int k = 4;

    cout << maxSumAfterPartitioning(test, k) << endl;

    return 0;
}

// ॥ जय श्री राम जय श्री कृष्ण ॥