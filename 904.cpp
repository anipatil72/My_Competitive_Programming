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

void dfs(int row, int col, vector<vector<int>> &mat, vector<vector<int>> &vis, vector<pair<int, int>> &far, vector<pair<int, int>> &near, int which)
{
    int n = mat.size();

    int m = mat[0].size();

    vis[row][col] = 0;

    if (which == 1)
    {
        far.push_back({row, col});
    }
    else
    {

        near.push_back({row, col});
    }

    if ((row + 1 < n) && vis[row + 1][col] == 1 && mat[row + 1][col] == 1)
    {
        dfs(row + 1, col, mat, vis, far, near, which);
    }

    if ((col + 1 < m) && vis[row][col + 1] == 1 && mat[row][col + 1] == 1)
    {
        dfs(row, col + 1, mat, vis, far, near, which);
    }

    if (row > 0 && vis[row - 1][col] == 1 && mat[row - 1][col] == 1)
    {
        dfs(row - 1, col, mat, vis, far, near, which);
    }

    if (col > 0 && vis[row][col - 1] == 1 && mat[row][col - 1] == 1)
    {
        dfs(row, col - 1, mat, vis, far, near, which);
    }
}

int shortestBridge(vector<vector<int>> &grid)
{
    int n = grid.size();

    vector<vector<int>> vis(n, vector<int>(n, 1));

    vector<pair<int, int>> far, near;

    int which = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (vis[i][j] == 1 && grid[i][j] == 1)
            {
                dfs(i, j, grid, vis, far, near, ++which);
            }
        }
    }

    int len = far.size();

    int pass = near.size();

    int dis = 200;

    for (int i = 0; i < len; i++)
    {
        for (int j = 0; j < pass; j++)
        {
            dis = min(dis, abs(near[j].first - far[i].first) + abs(near[j].second - far[i].second));
        }
    }

    return dis - 1;
}

int main()
{

    return 0;
}

// ॥ जय श्री राम जय श्री कृष्ण ॥