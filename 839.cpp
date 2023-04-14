// ॥ श्री गणेशाय नमः ॥

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define ll long long
#define ull unsigned long long
using namespace std;
using namespace __gnu_pbds;

bool subsetSumToK(int n, int k, vector<int> &arr)
{

    vector<vector<bool>> dp(n, vector<bool>(k + 1, 0));

    for (int i = 0; i < n; i++)
    {
        dp[i][0] = true;
    }

    dp[0][arr[0]] = 1;

    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j <= k; j++)
        {
            dp[i][j] = ((j >= arr[i] ? dp[i - 1][j - arr[i]] : false) | (dp[i - 1][j]));
        }
    }

    // return recur(n-1, k, dp, arr);

    return dp[n - 1][k];
}

bool canPartition(vector<int> &arr, int n)
{

    if (n == 1)
    {
        return false;
    }

    long long sum = 0;

    for (int i = 0; i < n; i++)
    {
        sum += (arr[i]);
    }

    if (sum & 1)
    {
        return false;
    }

    sum /= 2;

    return subsetSumToK(n, sum, arr);
}

int minSubsetSumDifference(vector<int> &arr, int n)
{

    long long sum = 0;

    // for (int i = 0; i < n; i++)
    // {
    //     sum += arr[i];
    // }

    sum = accumulate(arr.begin(), arr.end(), 0LL);

    long long target = sum;

    vector<vector<bool>> dp(n, vector<bool>(target + 1, 0));

    for (int i = 0; i < n; i++)
    {
        dp[i][0] = true;
    }

    if (arr[0] <= target)
    {
        dp[0][arr[0]] = 1;
    }

    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j <= target; j++)
        {
            dp[i][j] = ((j >= arr[i] ? dp[i - 1][j - arr[i]] : false) | (dp[i - 1][j]));
        }
    }

    cout << "This is dp : " << endl;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= target; j++)
        {
            cout << dp[i][j] << " ";
        }

        cout << endl;
    }

    long long mini = (int)(1e9);

    for (int i = 0; i <= target; i++)
    {

        if (dp[n - 1][i])
        {
            mini = min(mini, abs(sum - 2 * i));
        }
    }

    return mini;
}

int findWays(vector<int> &arr, int tar)
{
    long long sum = 0;

    int n = arr.size();

    // for (int i = 0; i < n; i++)
    // {
    //     sum += arr[i];
    // }

    sum = accumulate(arr.begin(), arr.end(), 0LL);

    if (sum < tar)
    {
        return 0;
    }

    long long target = sum;

    vector<vector<bool>> dp(n, vector<bool>(target + 1, 0));

    for (int i = 0; i < n; i++)
    {
        dp[i][0] = true;
    }

    if (arr[0] <= target)
    {
        dp[0][arr[0]] = 1;
    }

    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j <= target; j++)
        {
            dp[i][j] = ((j >= arr[i] ? dp[i - 1][j - arr[i]] : false) | (dp[i - 1][j]));
        }
    }

    cout << "This is dp : " << endl;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= target; j++)
        {
            cout << dp[i][j] << " ";
        }

        cout << endl;
    }

    // long long mini = (int)(1e9);

    int ans = 0;

    for (int i = 0; i < n; i++)
    {
        ans += (dp[i][tar]);
    }

    return ans;
}

int main()
{

    int t = 100;

    cin >> t;

    while (t--)
    {

        int n, k;

        cin >> n >> k;

        vector<int> a(n);

        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }

        cout << "The answer is : " << endl;

        // cout << minSubsetSumDifference(a, n) << endl;

        cout << findWays(a, k);
    }

    return 0;
}

// ॥ जय श्री राम जय श्री कृष्ण ॥