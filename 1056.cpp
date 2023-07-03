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

int countSquares(vector<vector<int>> &matrix)
{
    int n = matrix.size();

    int m = matrix[0].size();

    vector<vector<int>> dp(n, vector<int>(m, 0));
    int ans = 0;

    for (int i = 0; i < n; i++)
    {
        dp[i][0] = (matrix[i][0] == 1);

        ans += matrix[i][0];
    }

    for (int i = 1; i < m; i++)
    {
        dp[0][i] = (matrix[0][i] == 1);

        ans += matrix[0][i];
    }

    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j < m; j++)
        {

            if (matrix[i][j] == 1)
            {
                dp[i][j] = 1 + min({dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]});

                ans += dp[i][j];
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