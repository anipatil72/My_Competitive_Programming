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

double giveit(int row, int col, int n)
{
    int even = 0;

    if (row - 2 >= 0 && col - 1 >= 0)
    {
        even++;
    }

    if (row - 2 >= 0 && col + 1 < n)
    {
        even++;
    }

    if (row + 2 < n && col - 1 >= 0)
    {
        even++;
    }

    if (row + 2 < n && col + 1 < n)
    {
        even++;
    }

    // other

    if (row - 1 >= 0 && col - 2 >= 0)
    {
        even++;
    }

    if (row + 1 < n && col - 2 >= 0)
    {
        even++;
    }

    if (row - 1 >= 0 && col + 2 < n)
    {
        even++;
    }

    if (row + 1 < n && col + 2 < n)
    {
        even++;
    }

    double ans = 1.0 * even / 8;

    return ans;
}

void takeit(vector<vector<double>> &prob)
{
    int n = prob.size();

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            prob[i][j] = giveit(i, j, n);
        }
    }
}

double recur(int row, int col, int n, int k, vector<vector<vector<double>>> &dp)
{
    double des = 0.0;

    if (k == 0)
    {
        return 1.0;
    }

    // cout << "This is row : " << row << " and this is col : " << col << " and this is k : " << k << " and dp[row][col][k]=" << dp[row][col][k] << endl;

    if (dp[row][col][k] != -1.0)
    {
        return dp[row][col][k];
    }

    // int n = prob.size();

    if (row - 2 >= 0 && col - 1 >= 0)
    {
        des += 1.0 * recur(row - 2, col - 1, n, k - 1, dp) / 8;
    }

    if (row - 2 >= 0 && col + 1 < n)
    {
        des += 1.0 * recur(row - 2, col + 1, n, k - 1, dp) / 8;
    }

    if (row + 2 < n && col - 1 >= 0)
    {
        des += 1.0 * recur(row + 2, col - 1, n, k - 1, dp) / 8;
    }

    if (row + 2 < n && col + 1 < n)
    {
        des += 1.0 * recur(row + 2, col + 1, n, k - 1, dp) / 8;
    }

    // other

    if (row - 1 >= 0 && col - 2 >= 0)
    {
        des += 1.0 * recur(row - 1, col - 2, n, k - 1, dp) / 8;
    }

    if (row + 1 < n && col - 2 >= 0)
    {
        des += 1.0 * recur(row + 1, col - 2, n, k - 1, dp) / 8;
    }

    if (row - 1 >= 0 && col + 2 < n)
    {
        des += 1.0 * recur(row - 1, col + 2, n, k - 1, dp) / 8;
    }

    if (row + 1 < n && col + 2 < n)
    {
        des += 1.0 * recur(row + 1, col + 2, n, k - 1, dp) / 8;
    }

    return dp[row][col][k] = des;
}

double knightProbability(int n, int k, int row, int column)
{
    // vector<vector<double>> prob(n, vector<double>(n));

    // takeit(prob);

    vector<vector<vector<double>>> dp(n, vector<vector<double>>(n, vector<double>(k + 1, -1.0)));

    return recur(row, column, n, k, dp);
}

int main()
{
    int row = 0, column = 0, n = 3, k = 2;

    double ans = knightProbability(n, k, row, column);

    cout << ans << endl;

    // ll d = 1;

    // int t = 45;

    // while (t--)
    // {
    //     d *= 2;
    // }

    // cout << d << endl;

    return 0;
}

// ॥ जय श्री राम जय श्री कृष्ण ॥