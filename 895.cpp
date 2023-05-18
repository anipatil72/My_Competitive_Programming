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

void dfs(int row, int col, vector<vector<int>> &mat, vector<vector<int>> &vis, int check)
{
    int n = mat.size();

    int m = mat[0].size();

    vis[row][col] = 0;

    if (check == 1)
    {
        mat[row][col] = 0;
    }

    if ((row + 1 < n) && vis[row + 1][col] == 1 && mat[row + 1][col] == 1)
    {
        dfs(row + 1, col, mat, vis, check);
    }

    if ((col + 1 < m) && vis[row][col + 1] == 1 && mat[row][col + 1] == 1)
    {
        dfs(row, col + 1, mat, vis, check);
    }

    if (row > 0 && vis[row - 1][col] == 1 && mat[row - 1][col] == 1)
    {
        dfs(row - 1, col, mat, vis, check);
    }

    if (col > 0 && vis[row][col - 1] == 1 && mat[row][col - 1] == 1)
    {
        dfs(row, col - 1, mat, vis, check);
    }
}

int closedIslands(vector<vector<int>> &mat, int N, int M)
{
    vector<vector<int>> vis(N, vector<int>(M, 1));

    int n = mat.size();

    int m = mat[0].size();

    for (int i = 0; i < n; i++)
    {
        if (vis[i][0] == 1 && mat[i][0] == 1)
        {
            dfs(i, 0, mat, vis, 1);
        }

        if (vis[i][m - 1] == 1 && mat[i][m - 1] == 1)
        {
            dfs(i, m - 1, mat, vis, 1);
        }
    }

    for (int i = 0; i < m; i++)
    {
        if (vis[0][i] == 1 && mat[0][i] == 1)
        {
            dfs(0, i, mat, vis, 1);
        }

        if (vis[n - 1][i] == 1 && mat[n - 1][i] == 1)
        {
            dfs(n - 1, i, mat, vis, 1);
        }
    }

    int count = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (mat[i][j] == 1 && vis[i][j] == 1)
            {
                count++;

                dfs(i, j, mat, vis, 0);
            }
        }
    }

    return count;
}

int main()
{

    return 0;
}

// ॥ जय श्री राम जय श्री कृष्ण ॥