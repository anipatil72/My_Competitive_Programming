// ॥ श्री गणेशाय नमः ॥

#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define M 1000000007
using namespace std;

vector<int> dijkstra(int V, vector<vector<int>> adj[], int S)
{

    vector<int> dis(V, INT_MAX);

    dis[S] = 0;

    priority_queue<pair<int, int>, vector<pair<int,int>, greater<pair<int,int> p;

    p.push({0, S});

    while (!p.empty())
    {
        pair<int, int> t = p.top();

        p.pop();

        for (int i = 0; i < adj[t.first].size(); i++)
        {
            if (dis[adj[t.first][i][0]] > dis[t.first] + adj[t.first][i][1])
            {
                dis[adj[t.first][i][0]] = dis[t.first] + adj[t.first][i][1];

                p.push({dis[adj[t.first][i][0]], adj[t.first][i][0]});
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