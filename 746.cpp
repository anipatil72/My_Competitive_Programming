// ॥ श्री गणेशाय नमः ॥

#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define M 1000000007
using namespace std;

vector<int> shortestPath(int n, int m, vector<vector<int>> &edges)
{
    // int n, m;

    // cin >> n >> m;

    vector<unordered_map<int, int>> adj(n + 1);

    vector<int> dis(n + 1, INT_MAX);

    vector<int> pred(n + 1);

    // vector<int> path;

    dis[1] = 0;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> p;

    p.push({0, 1});

    for (int i = 0; i < m; i++)
    {

        int a, b, w;

        a = edges[i][0];
        b = edges[i][1];
        w = edges[i][2];
        // cin >> a >> b >> w;

        if (adj[a].count(b) > 0)
        {
            adj[a][b] = min(adj[a][b], w);
            adj[b][a] = min(adj[b][a], w);
        }
        else
        {
            adj[a][b] = w;
            adj[b][a] = w;
        }
    }

    while (!p.empty())
    {
        pair<int, int> d = p.top();

        int x = d.second;

        int y = d.first;

        p.pop();

        for (auto i = adj[x].begin(); i != adj[x].end(); i++)
        {

            int g = i->first;

            int h = i->second;

            if (dis[g] > dis[x] + adj[x][g])
            {
                dis[g] = dis[x] + adj[x][g];

                pred[g] = x;

                p.push({dis[g], g});
            }
        }
    }

    if (dis[n] == INT_MAX)
    {
        // cout << "-1" << endl;

        return {-1};
    }

    vector<int> ans;

    int temp = n;

    while (temp != 1)
    {

        ans.push_back(temp);

        temp = pred[temp];
    }

    ans.push_back(1);

    reverse(ans.begin(), ans.end());

    return ans;
}

int main()
{

    return 0;
}

// ॥ जय श्री राम जय श्री कृष्ण ॥