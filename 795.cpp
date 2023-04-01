// ॥ श्री गणेशाय नमः ॥

#include <bits/stdc++.h>

#define ll long long
#define ull unsigned long long
using namespace std;

int spanningTree(int V, vector<vector<int>> adj[])
{
    int n = adj->size();

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;

    q.push({0, 0});

    vector<int> vis(V, 1);

    int sum = 0;

    while (!q.empty())
    {

        auto t = q.top();

        q.pop();

        int dis = t.first;

        int to = t.second;

        if (!vis[to])
        {
            continue;
        }

        // sum += t.first;

        sum += dis;

        vis[to] = 0;

        for (auto it : adj[to])
        {
            int adjNode = it[0];

            int edge = it[1];

            if (vis[adjNode])
            {
                q.push({edge, adjNode});
            }
        }
    }

    return sum;
}

int main()
{

    return 0;
}

// ॥ जय श्री राम जय श्री कृष्ण ॥