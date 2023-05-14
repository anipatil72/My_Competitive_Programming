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

int recur(int temp, int n, int trial, vector<int> &a, vector<int> &dp)
{
    if (temp == 0)
    {
        return 0;
    }

    if (dp[temp] != -1)
    {
        return dp[temp];
    }

    int fin = 0;

    for (int i = 0; i < 2 * n; i++)
    {

        if ((temp & (1 << i)))
        {
            int ans = 0;

            for (int j = i + 1; j < 2 * n; j++)
            {
                if ((temp & (1 << j)))
                {
                    int tem = temp;

                    // for (int k = 31; k >= 0; k--)
                    // {

                    //     cout << (temp & (1 << k));
                    // }

                    // for (int i = 31; i >= 0; i--)
                    // {
                    //     cout << (((temp & (1 << i)) > 0) ? '1' : '0');
                    // }

                    // cout << endl;

                    tem -= (1 << i);
                    tem -= (1 << j);
                    // cout << "I am here : at i = " << i << " and j = " << j << endl;

                    // cout << "Here trial is : " << trial << endl;
                    ans = trial * (__gcd(a[i], a[j])) + recur(tem, n, trial + 1, a, dp);
                    // ans += ;
                    fin = max(fin, ans);
                }
            }
        }
    }

    return dp[temp] = fin;
}

int maxScore(vector<int> &nums)
{
    int n = nums.size();

    int index = (1 << (n)) - 1;

    vector<int> dp(index + 1, -1);

    return recur(index, n / 2, 1, nums, dp);
}

int main()
{

    vector<int> coins = {3, 4, 6, 8};

    cout << maxScore(coins) << endl;

    // int test = 7;

    // for (int i = 31; i >= 0; i--)
    // {
    //     cout << (((test & (1 << i)) > 0) ? '1' : '0');
    // }

    return 0;
}

// ॥ जय श्री राम जय श्री कृष्ण ॥