#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <cmath>
#include <bits/stdc++.h>

using namespace std;

const int MOD = 1e9 + 7;
const long long INF = 1e18;

vector<vector<pair<int, int>>> adj;
vector<long long> dist;
vector<int> ways;
vector<int> min_flights;
vector<int> max_flights;

void dijkstra(int n)
{
    dist.assign(n, INF);
    ways.assign(n, 0);
    min_flights.assign(n, INT_MAX);
    max_flights.assign(n, 0);

    dist[0] = 0;
    ways[0] = 1;
    min_flights[0] = 0;
    max_flights[0] = 0;

    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
    pq.push({0, 0});

    while (!pq.empty())
    {
        int u = pq.top().second;
        long long d = pq.top().first;
        pq.pop();

        if (d > dist[u])
            continue;

        for (auto &edge : adj[u])
        {
            int v = edge.first;
            int cost = edge.second;

            if (dist[u] + cost < dist[v])
            {
                dist[v] = dist[u] + cost;
                ways[v] = ways[u];
                min_flights[v] = min_flights[u] + 1;
                max_flights[v] = max_flights[u] + 1;
                pq.push({dist[v], v});
            }
            else if (dist[u] + cost == dist[v])
            {
                ways[v] = (ways[v] + ways[u]) % MOD;
                min_flights[v] = min(min_flights[v], min_flights[u] + 1);
                max_flights[v] = max(max_flights[v], max_flights[u] + 1);
            }
        }
    }
}

int main()
{
    int n, m;
    cin >> n >> m;

    adj.resize(n);

    for (int i = 0; i < m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        a--; // Adjust for 0-based indexing
        b--; // Adjust for 0-based indexing
        adj[a].push_back({b, c});
    }

    dijkstra(n);

    cout << dist[n - 1] << " " << ways[n - 1] << " " << min_flights[n - 1] << " " << max_flights[n - 1] << endl;

    return 0;
}
