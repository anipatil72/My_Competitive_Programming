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

#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> memo;

int helper1(int n, int start, int i, int m, int u)
{
    if (memo[i][m] != -1)
    {
        return memo[i][m];
    }

    if (start == i && m < u)
    {
        memo[i][m] = 1 + helper1(n, start, i, m, m);
        return memo[i][m];
    }

    int r = 0;

    for (int j = 1; j <= n; j++)
    {
        if (m > 0 && i != j && (i % j == 0 || j % i == 0))
        {
            r += helper1(n, start, j, m - 1, u);
        }
    }

    memo[i][m] = r;

    return r;
}

int main()
{

    int N = 3;
    int P = 2;
    int X = 2;

    memo = vector<vector<int>>(N + 1, vector<int>(X + 1, -1));

    int ways = helper1(N, P, P, X, X);

    cout << "Number of possible ways to complete the game: " << ways << endl;

    return 0;
}

// ॥ जय श्री राम जय श्री कृष्ण ॥