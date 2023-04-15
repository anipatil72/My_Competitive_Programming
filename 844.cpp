// ॥ श्री गणेशाय नमः ॥

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define ll long long
#define ull unsigned long long
using namespace std;
using namespace __gnu_pbds;

int recur(int index, int sum, vector<int> &num, vector<vector<int>> &dp)
{
    if (index < 0)
    {

        return (int)1e8;
    }

    if (sum == 0)
    {
        return 0;
    }

    if (dp[index][sum] != -1)
    {
        return dp[index][sum];
    }

    int nottake = recur(index - 1, sum, num, dp);

    int take = (int)1e9;

    if (sum >= num[index])
    {
        take = 1 + recur(index, sum - num[index], num, dp);
    }

    return dp[index][sum] = min(take, nottake);
}

int minimumElements(vector<int> &num, int x)
{
    int n = num.size();

    vector<vector<int>> dp(n, vector<int>(x + 1, -1));

    int ans = recur(n - 1, x, num, dp);

    if (ans == (int)1e8 || (ans == (int)1e9))
    {
        return -1;
    }

    return ans;
}

int minimumElementsTab(vector<int> &num, int x)
{

    int n = num.size();

    vector<vector<int>> dp(n, vector<int>(x + 1, 0));

    int ans = 0;

        // int ans = recur(n - 1, x, num, dp);

    // if (ans == (int)1e8 || (ans == (int)1e9))
    // {
    //     return -1;
    // }

    return ans;
}

int main()
{

    int tt;

    cin >> tt;

    while (tt--)
    {

        int n, x;

        cin >> n >> x;

        vector<int> a(n);

        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }

        cout << minimumElements(a, x) << endl;
    }

    return 0;
}

// ॥ जय श्री राम जय श्री कृष्ण ॥