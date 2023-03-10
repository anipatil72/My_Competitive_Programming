// ॥ श्री गणेशाय नमः ॥

#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define M 1000000007
using namespace std;

int maxDistance(vector<vector<int>> &grid)
{
    int n = grid.size();

    if (n == 1)
    {
        return -1;
    }

    int ones = 0, zeros = 0;

    vector<pair<int, int>> a;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (grid[i][j] == 1)
            {
                ones++;
                a.push_back({i, j});
            }
            else
            {
                zeros++;
            }
        }
    }

    if (ones == 0 || zeros == 0)
    {
        return -1;
    }

    vector<vector<int>> dis(n, vector<int>(n, (int)1e4));

    queue<pair<pair<int, int>, int>> q;

    for (int i = 0; i < ones; i++)
    {

        auto p = a[i];

        dis[p.first][p.second] = 0;

        q.push({{p.first, p.second}, 0});
    }

    while (!q.empty())
    {
        auto p = q.front();

        int row = p.first.first;

        int col = p.first.second;

        int d = p.second;

        q.pop();

        if (row > 0)
        {
            if (dis[row - 1][col] > d + 1)
            {
                dis[row - 1][col] = d + 1;

                q.push({{row - 1, col}, d + 1});
            }
        }

        if (row < n - 1)
        {

            if (dis[row + 1][col] > d + 1)
            {
                dis[row + 1][col] = d + 1;

                q.push({{row + 1, col}, d + 1});
            }
        }
        if (col > 0)
        {
            if (dis[row][col - 1] > d + 1)
            {
                dis[row][col - 1] = d + 1;

                q.push({{row, col - 1}, d + 1});
            }
        }

        if (col < n - 1)
        {

            if (dis[row][col + 1] > d + 1)
            {
                dis[row][col + 1] = d + 1;

                q.push({{row, col + 1}, d + 1});
            }
        }
    }

    int ans = 1;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (grid[i][j] == 0)
            {
                ans = max(ans, dis[i][j]);
            }
        }
    }

    return ans;
}

// [[1,0,1],[0,0,0],[1,0,1]]

int main()
{

    vector<vector<int>> grid = {{1, 0, 1}, {0, 0, 0}, {1, 0, 1}};

    cout << maxDistance(grid);

    return 0;
}

// ॥ जय श्री राम जय श्री कृष्ण ॥