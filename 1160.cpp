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
// This is all very stadard nothing out of the ordinary.

int sqr(int x)
{
    return x * x;
}

// Only 2 xs are the original edges.
int dfs(int x, int y, int k, vector<vector<int>> &dp1)
{
    if (dp1[x][y] >= 0)
        return dp1[x][y];
    dp1[x][y] = sqr(x * y - k);
    for (int i = 1; i <= x - i; ++i)
    {
        dp1[x][y] = min(dp1[x][y], dfs(i, y, k, dp1) + dfs(x - i, y, k, dp1));
    }
    for (int i = 1; i <= y - i; ++i)
    {
        dp1[x][y] = min(dp1[x][y], sqr(x * i - k) + sqr(x * (y - i) - k));
    }
    return dp1[x][y];
}

// One x and one y are the original edges.
int dfs(int x, int y, int k, vector<vector<int>> &dp1, vector<vector<int>> &dp2)
{
    if (dp2[x][y] >= 0)
    {
        return dp2[x][y];
    }
    dp2[x][y] = sqr(x * y - k);
    // Not symetrical
    for (int i = 1; i < x; ++i)
    {
        dp2[x][y] = min(dp2[x][y], dfs(i, y, k, dp1, dp2) + sqr((i - x) * y - k));
    }
    // Not symetrical
    for (int i = 1; i < y; ++i)
    {
        dp2[x][y] = min(dp2[x][y], dfs(i, x, k, dp1, dp2) + sqr((i - y) * x - k));
    }
    return dp2[y][x] = dp2[x][y];
}

// both 2 xs and only 1 y are the original edges.
int dfs(int x, int y, int k, vector<vector<int>> &dp1, vector<vector<int>> &dp2, vector<vector<int>> &dp3)
{
    if (dp3[x][y] >= 0)
    {
        return dp3[x][y];
    }
    dp3[x][y] = sqr(x * y - k);
    // Not symetrical
    for (int i = 1; i < x; ++i)
    {
        dp3[x][y] = min(dp3[x][y], dfs(i, y, k, dp1, dp2, dp3) + dfs(x - i, y, k, dp1));
    }
    for (int i = 1; i <= y - i; ++i)
    {
        dp3[x][y] = min(dp3[x][y], dfs(x, i, k, dp1, dp2) + dfs(x, y - i, k, dp1, dp2));
    }
    return dp3[x][y];
}

int helper(int x, int y, int k, vector<vector<int>> &dp1, vector<vector<int>> &dp2, vector<vector<int>> &dp3)
{
    int r = sqr(x * y - k);
    for (int i = 1; i <= x - i; ++i)
    {
        r = min(r, dfs(i, y, k, dp1, dp2, dp3) + dfs(x - i, y, k, dp1, dp2, dp3));
    }
    for (int i = 1; i <= y - i; ++i)
    {
        // order matters.
        r = min(r, dfs(i, x, k, dp1, dp2, dp3) + dfs(y - i, x, k, dp1, dp2, dp3));
    }
    return r;
}

int solution(int x, int y, int k)
{
    if (x < y)
    {
        swap(x, y);
    }
    vector<vector<int>> dp1(x + 1, vector<int>(x + 1, -1)), dp2 = dp1, dp3 = dp1;
    return helper(x, y, k, dp1, dp2, dp3);
}

int main()
{
    cout << solution(4, 4, 15) << endl;
    cout << solution(2, 3, 3) << endl;
    cout << solution(1, 4, 7) << endl;
    return 0;
}

// ॥ जय श्री राम जय श्री कृष्ण ॥