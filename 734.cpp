// ॥ श्री गणेशाय नमः ॥

#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define M 1000000007
using namespace std;

void dfs(vector<vector<pair<int, int>>> &adj, vector<int> &dis, vector<int> & stopp, int node, int dst, int stops, int k, int cur)
{

    if (node == dst)
    {
        if (dis[dst] > cur)
        {
            dis[dst] = cur;
        }

        return;
    }

    if (stops >= k)
    {

        return;
    }

    if (cur>=stopp[node])
    {
            return ;
    }

    stopp[node] = cur;
    

    for (int i = 0; i < adj[node].size(); i++)
    {

        dfs(adj, dis,stopp, adj[node][i].first, dst, stops + 1, k, cur + adj[node][i].second);
    }
}

int findCheapestPrice(int n, vector<vector<int>> &flights, int src, int dst, int k)
{

    vector<vector<pair<int, int>>> adj(n);

    for (int i = 0; i < flights.size(); i++)
    {
        adj[flights[i][0]].push_back({flights[i][1], flights[i][2]});
    }

    queue<pair<int, int>> q;

    vector<int> dis(n, INT_MAX);
    vector<int> stopp(n, INT_MAX);

    vector<int> visited(n, 1);

    dis[src] = 0;

    visited[src] = 0;

    dfs(adj, dis,stopp, src, dst, -1, k, 0);

    if (dis[dst] == INT_MAX)
    {
        return -1;
    }

    return dis[dst];
}

int main()
{

    // cout << INFINITY << endl;

    vector<vector<int>> flights = {{0, 1, 1}, {0, 2, 5}, {1, 2, 1}, {2, 3, 1}};

    cout << findCheapestPrice(4, flights, 0, 3, 1) << endl;

    return 0;
}

// 4
// [[0,1,1],[0,2,5],[1,2,1],[2,3,1]]
// 0
// 3
// 1

// ॥ जय श्री राम जय श्री कृष्ण ॥