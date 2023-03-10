// ॥ श्री गणेशाय नमः ॥

#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
// #define M 1000000007
using namespace std;

int countPaths(int n, vector<vector<int>> &roads)
{
    vector<vector<pair<int, int>>> adj(n);

    for (int i = 0; i < roads.size(); i++)
    {
        int fir = roads[i][0];
        int sec = roads[i][1];
        int cos = roads[i][2];

        adj[fir].push_back({sec, cos});
        adj[sec].push_back({fir, cos});
    }

    vector<int> dis(n, 1e9);

    vector<int> ways(n, 0);

    int M = (int)(1e9 + 7);

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;

    dis[0] = 0;

    ways[0] = 1;

    q.push({0, 0});

    while (!q.empty())
    {

        auto p = q.top();

        q.pop();

        int d = p.first;

        int node = p.second;

        for (int i = 0; i < adj[node].size(); i++)
        {

            if (dis[adj[node][i].first] == d + adj[node][i].second)
            {

                ways[adj[node][i].first] = (ways[node] + 0LL + ways[adj[node][i].first]) % M;
            }
            else if (dis[adj[node][i].first] > d + adj[node][i].second)
            {
                dis[adj[node][i].first] = d + adj[node][i].second;

                ways[adj[node][i].first] = (ways[node]);

                q.push({d + adj[node][i].second, adj[node][i].first});
            }
        }
    }

    // vector<>

    // debug(ways);

    return ways[n - 1] % M;
}

int main()
{
    int n = 7, m = 10;

    vector<vector<int>> edges = {{0, 6, 7}, {0, 1, 2}, {1, 2, 3}, {1, 3, 3}, {6, 3, 3}, {3, 5, 1}, {6, 5, 1}, {2, 5, 1}, {0, 4, 5}, {4, 6, 2}};

    cout << countPaths(n, edges);

    return 0;
}

// ॥ जय श्री राम जय श्री कृष्ण ॥