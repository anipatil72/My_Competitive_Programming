// ॥ श्री गणेशाय नमः ॥

#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define M 1000000007
using namespace std;

int MinimumEffort(vector<vector<int>> &heights)
{
    int n = heights.size();
    int m = heights[0].size();

    // pair<int , pair<int,int>>

    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> q;

    vector<vector<int>> dis(n, vector<int>(m, 1e9));

    dis[0][0] = 0;

    q.push({0, {0, 0}});

    int dr[] = {-1, 0, 1, 0};
    int dc[] = {0, 1, 0, -1};

    while (!q.empty())
    {

        auto it = q.top();

        q.pop();
        int diff = it.first;

        int row = it.second.first;

        int col = it.second.second;

        if (row == n - 1 && col == m - 1)
        {
            return diff;
        }

        for (int i = 0; i < 4; i++)
        {
            int newr = row + dr[i];

            int ncol = col + dc[i];

            if (newr >= 0 && newr < n && ncol >= 0 && ncol < m)
            {
                int newEffort = max(abs(heights[row][col] - heights[newr][ncol]), diff);

                if (newEffort < dis[newr][ncol])
                {
                    dis[newr][ncol] = newEffort;

                    q.push({newEffort, {newr, ncol}});
                }
            }
        }
    }
}

int main()
{

    return 0;
}

// ॥ जय श्री राम जय श्री कृष्ण ॥