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

// https://practice.geeksforgeeks.org/problems/find-whether-path-exist5238/1

bool check(int x, int y, vector<vector<int>> &grid, vector<vector<int>> &vis)
{
    int n = grid.size();

    if (x + 1 < n && grid[x + 1][y] == 3 && vis[x + 1][y] == 0)
    {
        return true;
    }

    if (y + 1 < n && grid[x][y + 1] == 3 && vis[x][y + 1] == 0)
    {
        return true;
    }

    if (x > 0 && grid[x - 1][y] == 3 && vis[x - 1][y] == 0)
    {
        return true;
    }

    if (y > 0 && grid[x][y - 1] == 3 && vis[x][y - 1] == 0)
    {
        return true;
    }
}

void dfs(int row, int col, vector<vector<int>> &mat, vector<vector<int>> &vis)
{
    int n = mat.size();

    int m = mat[0].size();

    vis[row][col] = 0;

    if ((row + 1 < n) && vis[row + 1][col] == 1 && mat[row + 1][col] == 3)
    {
        dfs(row + 1, col, mat, vis);
    }

    if ((col + 1 < m) && vis[row][col + 1] == 1 && mat[row][col + 1] == 3)
    {
        dfs(row, col + 1, mat, vis);
    }

    if (row > 0 && vis[row - 1][col] == 1 && mat[row - 1][col] == 3)
    {
        dfs(row - 1, col, mat, vis);
    }

    if (col > 0 && vis[row][col - 1] == 1 && mat[row][col - 1] == 3)
    {
        dfs(row, col - 1, mat, vis);
    }
}

bool is_Possible(vector<vector<int>> &grid)
{
    int destx, desty, sourcex, sourcey;

    int n = grid.size();

    vector<vector<int>> vis(n, vector<int>(n, 1));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (grid[i][j] == 1)
            {
                sourcex = i;
                sourcey = j;
            }
            else if (grid[i][j] == 2)
            {
                destx = i, desty = j;
            }
        }
    }

    if ((sourcex + 1 < n) && grid[sourcex + 1][sourcey] == 3)
    {
        dfs(sourcex + 1, sourcey, grid, vis);
    }

    if (check(destx, desty, grid, vis))
    {
        return true;
    }

    if ((sourcex > 0) && grid[sourcex - 1][sourcey] == 3)
    {
        dfs(sourcex - 1, sourcey, grid, vis);
    }

    if (check(destx, desty, grid, vis))
    {
        return true;
    }

    if ((sourcey + 1 < n) && grid[sourcex][sourcey + 1] == 3)
    {
        dfs(sourcex, sourcey + 1, grid, vis);
    }

    if (check(destx, desty, grid, vis))
    {
        return true;
    }

    if ((sourcey > 0) && grid[sourcex][sourcey - 1] == 3)
    {
        dfs(sourcex, sourcey - 1, grid, vis);
    }

    if (check(destx, desty, grid, vis))
    {
        return true;
    }

    return false;
}

int main()
{

    return 0;
}

// ॥ जय श्री राम जय श्री कृष्ण ॥