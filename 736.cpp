// ॥ श्री गणेशाय नमः ॥

#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
// #define M 1000000007
using namespace std;


vector<int> shortestPath(vector<vector<int>> &edges, int N, int M, int src)
{

    vector<vector<int>> adj(N);

    for (int i = 0; i < M; i++)
    {
        adj[edges[i][0]].push_back(edges[i][1]);
        adj[edges[i][1]].push_back(edges[i][0]);
    }

    vector<int> dis(N, -1);

    queue<pair<int, int>> q;

    q.push({src, 0});

    while (!q.empty())
    {
        pair<int, int> t = q.front();

        dis[t.first] = t.second;

        q.pop();

        for (int i = 0; i < adj[t.first].size(); i++)
        {

            if (dis[adj[t.first][i]] > dis[t.first] + 1)
            {
                q.push({adj[t.first][i], t.second + 1});
            }
        }
    }

    return dis;
}

int main()
{

    return 0;
}

// ॥ जय श्री राम जय श्री कृष्ण ॥