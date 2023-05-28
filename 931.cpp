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

int recur(int index, int sum, vector<int> &a, vector<vector<int>> &dp)
{
    if (index == 0)
    {
        if (sum == 0 && a[0] == 0)
        {
            return 2;
        }

        if (sum == 0 || a[0] == sum)
        {
            return 1;
        }

        return 0;
    }

    if (dp[index][sum] != -1)
    {
        return dp[index][sum];
    }

    int notTaken = recur(index - 1, sum, a, dp);

    int taken = 0;

    if (sum >= a[index])
    {
        taken = recur(index - 1, sum - a[index], a, dp);
    }

    return dp[index][sum] = taken + notTaken;
}

int findWays(vector<int> &num, int tar)
{
    int n = num.size();

    vector<vector<int>> dp(n, vector<int>(tar + 1, -1));

    return recur(n - 1, tar, num, dp);
}

bool canPartitionKSubsets(vector<int> &arr, int k)
{

    int n = arr.size();

    if (k == 1)
    {
        return true;
    }

    if (n == 1 && k != 1)
    {
        return false;
    }

    long long sum = 0;

    for (int i = 0; i < n; i++)
    {
        sum += (arr[i]);
    }

    if (sum % k != 0)
    {
        return false;
    }

    sum /= k;
}

int main()
{

    return 0;
}

// ॥ जय श्री राम जय श्री कृष्ण ॥