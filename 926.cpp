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

int getMaxPathSum(vector<vector<int>> &matrix)
{
    int n = matrix.size();

    int m = matrix[0].size();

    vector<vector<int64_t>> dp(n, vector<int64_t>(m));

    int64_t ans = INT_MAX;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            int64_t uleft = INT_MAX;

            // int64_t uu = INT_MAX;

            int64_t uright = INT_MAX;

            if (i > 0)
            {

                // uu = dp[i - 1][j];

                if (j > 0)
                {
                    uleft = dp[i - 1][j - 1];
                }

                if (j < m - 1)
                {

                    uright = dp[i - 1][j + 1];
                }

                dp[i][j] = matrix[i][j] + (max({uleft, uright}));
            }
            else if (i == 0)
            {
                dp[i][j] = matrix[i][j];
            }

            if (i == n - 1)
            {
                ans = max(ans, dp[i][j]);
            }
        }
    }

    return ans;
}

int main()
{

    return 0;
}

// ॥ जय श्री राम जय श्री कृष्ण ॥