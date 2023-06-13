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

// https://leetcode.com/problems/delete-greatest-value-in-each-row/

int deleteGreatestValue(vector<vector<int>> &grid)
{
    int n = grid.size();

    int m = grid[0].size();

    for (int i = 0; i < n; i++)
    {
        sort(grid[i].begin(), grid[i].end());
    }

    int ans = 0;

    for (int i = 0; i < m; i++)
    {
        int tem = 0;
        for (int j = 0; j < n; j++)
        {
            tem = max(tem, grid[j][i]);
        }

        ans += tem;
    }

    return ans;
}

int main()
{

    return 0;
}

// ॥ जय श्री राम जय श्री कृष्ण ॥