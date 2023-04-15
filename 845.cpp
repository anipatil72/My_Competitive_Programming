// ॥ श्री गणेशाय नमः ॥

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define ll long long
#define ull unsigned long long
using namespace std;
using namespace __gnu_pbds;

int findWays(int n, vector<int> &arr, int target)
{

    long long sum = accumulate(arr.begin(), arr.end(), 0LL);

    vector<vector<int>> dp(n, vector<int>(sum + 1, 0));

    if (arr[0] == 0)
    {
        dp[0][0] = 2;
    }
    else
    {

        dp[0][0] = 1;
    }

    if (arr[0] != 0 && arr[0] <= sum)
    {
        dp[0][arr[0]] = 1;
    }

    for (int i = 1; i < n; i++)
    {

        // dbg(i);

        // cout << "I am here ! " << endl;
        for (int j = 0; j <= sum; j++)
        {
            long long notpick = dp[i - 1][j];

            // dbg(i, j);
            long long pick = 0;

            if (j >= arr[i])
            {
                pick = dp[i - 1][j - arr[i]];
            }

            dp[i][j] = (pick + notpick);
        }
    }

    return dp[n - 1][target];
}

int countPartitions(int n, int d, vector<int> &arr)
{
    long long sum = accumulate(arr.begin(), arr.end(), 0LL);

    ll target = (sum - d);

    if (target < 0 || target & 1)
    {
        return 0;
    }

    target /= 2;

    return findWays(n, arr, target);
}

int targetSum(int n, int target, vector<int> &arr)
{

    return countPartitions(n, target, arr);
}

int main()
{

    return 0;
}

// ॥ जय श्री राम जय श्री कृष्ण ॥