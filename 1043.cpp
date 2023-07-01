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

template <typename T_vector>
void print_2D(vector<T_vector> &v)
{
    for (int i = 0; i < v.size(); i++)
    {
        for (int j = 0; j < v[i].size(); j++)
        {
            cout << v[i][j] << " ";
        }
        cout << endl;
    }
}

int recur(int index, int jindex, vector<int> &a, vector<vector<int>> &dp)
{
    if (index > jindex)
    {
        return 0;
    }

    if (dp[index][jindex] != -1)
    {
        return dp[index][jindex];
    }

    int ans = 0;

    for (int i = index; i <= jindex; i++)
    {
        int des = a[index - 1] * a[i] * a[jindex + 1] + recur(index, i - 1, a, dp) + recur(i + 1, jindex, a, dp);

        ans = max(ans, des);
    }

    return dp[index][jindex] = ans;
}

int maxCoins(vector<int> &a)
{
    int n = a.size();

    a.push_back(1);

    a.insert(a.begin(), 1);

    vector<vector<int>> dp(n + 2, vector<int>(n + 2, 0));

    for (int i = n; i >= 1; i--)
    {

        for (int j = i; j <= n; j++)
        {

            int ans = 0;

            for (int k = i; k <= j; k++)
            {
                int des = a[i - 1] * a[k] * a[j + 1] + dp[i][k - 1] + dp[k + 1][j];

                ans = max(ans, des);
            }

            dp[i][j] = ans;
        }
    }

    return dp[1][n];

    // return recur(1, n, a, dp);
}

int main()
{

    vector<int> test = {7, 1, 8};

    cout << maxCoins(test);

    return 0;
}

// ॥ जय श्री राम जय श्री कृष्ण ॥