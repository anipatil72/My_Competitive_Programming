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

// template <typename T_vector>
// void print_2D(vector<T_vector> &v)
// {
//     for (int i = 0; i < v.size(); i++)
//     {
//         for (int j = 0; j < v[i].size(); j++)
//         {
//             cout << v[i][j] << "   ";
//         }
//         cout << endl;
//     }
// }

int getMaxPathSum(vector<vector<int>> &matrix)
{
    int n = matrix.size();

    int m = matrix[0].size();

    if (n == 1)
    {
        return matrix[0][0];
    }

    vector<vector<int64_t>> dp(n, vector<int64_t>(m));

    int64_t ans = INT_MAX;

    for (int i = 0; i < n; i++)
    {
        dp[0][i] = matrix[0][i];
    }

    for (int i = 1; i < n; i++)
    {

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> p;

        for (int k = 0; k < m; k++)
        {
            p.push({dp[i - 1][k], k});
        }

        for (int j = 0; j < m; j++)
        {
            pair<int, int> d = p.top();

            if (d.second == j)
            {
                p.pop();

                dp[i][j] = matrix[i][j] + p.top().first;

                p.push(d);
            }
            else
            {
                dp[i][j] = matrix[i][j] + d.first;
            }

            // int64_t uleft = INT_MAX;

            // // int64_t uu = INT_MAX;

            // int64_t uright = INT_MAX;

            // if (i > 0)
            // {

            //     // uu = dp[i - 1][j];

            //     if (j > 0)
            //     {
            //         uleft = dp[i - 1][j - 1];
            //     }

            //     if (j < m - 1)
            //     {

            //         uright = dp[i - 1][j + 1];
            //     }

            //     dp[i][j] = matrix[i][j] + (min({uleft, uright}));
            // }
            // else if (i == 0)
            // {
            //     dp[i][j] = matrix[i][j];
            // }

            // if (i == n - 1)
            // {
            //     ans = min(ans, dp[i][j]);
            // }
        }
    }

    ans = *min_element(dp[n - 1].begin(), dp[n - 1].end());
    // cout << "This is DP : " << endl;
    // print_2D(dp);

    return ans;
}

//

int main()
{

    vector<vector<int>> des = {{-73, 61, 43, -48, -36}, {3, 30, 27, 57, 10}, {96, -76, 84, 59, -15}, {5, -49, 76, 31, -7}, {97, 91, 61, -46, 67}};
    // cout << "This is Matrix : " << endl;
    // print_2D(des);

    ll ans = getMaxPathSum(des);

    cout << ans << endl;

    return 0;
}

// ॥ जय श्री राम जय श्री कृष्ण ॥