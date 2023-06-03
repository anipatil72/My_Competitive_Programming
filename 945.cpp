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

int bfs(vector<vector<int>> &mat, vector<vector<int>> &vis)
{
    int n = mat.size();

    int m = n;

    vis[0][0] = 0;

    queue<pair<pair<int, int>, int>> q;

    q.push({{0, 0}, 0});

    int ans = -1;

    while (!q.empty())
    {

        pair<pair<int, int>, int> p = q.front();

        q.pop();

        if (p.first.first == n - 1 && p.first.second)
        {
            ans = p.second;

            break;
        }

        int row = p.first.first;

        int col = p.first.second;

        int dis = p.second;

        vis[row][col] = 0;

        if ((row + 1 < n) && vis[row + 1][col] == 1 && mat[row + 1][col] == 0)
        {
            // dfs(row + 1, col, mat, vis);
            q.push({{row + 1, col}, dis + 1});
        }

        if ((row + 1 < n) && (col + 1 < m) && vis[row + 1][col + 1] == 1 && mat[row + 1][col + 1] == 0)
        {
            // dfs(row + 1, col, mat, vis);
            q.push({{row + 1, col + 1}, dis + 1});
        }

        if ((row - 1 >= 0) && (col + 1 < m) && vis[row - 1][col + 1] == 1 && mat[row - 1][col + 1] == 0)
        {
            // dfs(row + 1, col, mat, vis);
            q.push({{row - 1, col + 1}, dis + 1});
        }

        if ((row + 1 < n) && (col - 1 >= 0) && vis[row + 1][col - 1] == 1 && mat[row + 1][col - 1] == 0)
        {
            // dfs(row + 1, col, mat, vis);
            q.push({{row + 1, col - 1}, dis + 1});
        }

        if ((row - 1 >= 0) && (col - 1 >= 0) && vis[row - 1][col - 1] == 1 && mat[row - 1][col - 1] == 0)
        {
            // dfs(row + 1, col, mat, vis);
            q.push({{row - 1, col - 1}, dis + 1});
        } 

        if ((col + 1 < m) && vis[row][col + 1] == 1 && mat[row][col + 1] == 0)
        {
            // dfs(row, col + 1, mat, vis); 
            q.push({{row, col + 1}, dis + 1});
        }

        if (row > 0 && vis[row - 1][col] == 1 && mat[row - 1][col] == 0)
        {
            q.push({{row - 1, col}, dis + 1});
            // dfs(row - 1, col, mat, vis);
        }

        if (col > 0 && vis[row][col - 1] == 1 && mat[row][col - 1] == 0)
        {
            q.push({{row, col - 1}, dis + 1});
            // dfs(row, col - 1, mat, vis);
        }
    }

    return ans;
}

int shortestPathBinaryMatrix(vector<vector<int>> &grid)
{
    int n = grid.size();

    if (grid[0][0] || grid[n - 1][n - 1] == 1)
    {
        return -1;
    }

    vector<vector<int>> vis(n, vector<int>(n, 1));

    int ans = bfs(grid, vis) + 1;

    return ans;
}

int main()
{

    vector<vector<int>> grid = {{1, 0, 0}, {1, 1, 0}, {1, 1, 0}};

    cout << shortestPathBinaryMatrix(grid);

    return 0;
}

// ॥ जय श्री राम जय श्री कृष्ण ॥