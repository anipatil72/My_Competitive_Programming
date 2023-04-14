// ॥ श्री गणेशाय नमः ॥

#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
#define ll long long
#define ull unsigned long long
using namespace std;

bool recur(int index, int target, vector<vector<int>> &dp, vector<int> &a)
{
    if (index == 1)
    {
        return dp[index][target] = (target == a[index]);
    }

    if (target == 0)
    {
        return dp[index][target] = 1;
    }

    if (dp[index][target] != -1)
    {
        return dp[index][target];
    }

    bool nottaken = recur(index - 1, target, dp, a);

    bool taken = 0;

    if (target >= a[index])
    {
        taken = recur(index - 1, target - a[index], dp, a);
    }

    return dp[index][target] = (taken || nottaken);
}

bool subsetSumToK(int n, int k, vector<int> &arr)
{

    vector<vector<int>> dp(n + 1, vector<int>(k + 1, -1));

    vector<int> a(n + 1);

    a[0] = 0;

    for (int i = 1; i <= n; i++)
    {
        a[i] = arr[i - 1];
    }

    return recur(n, k, dp, a);
}

int main()
{

    vector<int> arr = {6, 1, 2, 1};

    cout << subsetSumToK(4, 4, arr);

    return 0;
}

// ॥ जय श्री राम जय श्री कृष्ण ॥
