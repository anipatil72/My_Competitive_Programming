// ॥ श्री गणेशाय नमः ॥

#include <bits/stdc++.h>
#define ll long long
#define M 1000000007
using namespace std;

void dfs(vector<vector<int>> &edges, vector<vector<int>> &adj, vector<int> &visited, int k, int source, int destination, bool &yes)
{
    visited[k] = 0;

    for (int i = 0; i < adj[k].size(); i++)
    {
        if (visited[adj[k][i]] == 1)
        {

            // if (adj[k][i] == destination)
            // {
            //     yes = true;
            //     return;
            // }

            dfs(edges, adj, visited, adj[k][i], source, destination, yes);
        }
    }
}

bool validPath(int n, vector<vector<int>> &edges, int source, int destination)
{
    ll num = edges.size();

    sort(edges.begin(), edges.end());

    vector<int> visited(n, 1);

    vector<vector<int>> adj(n);

    // int i = 0 , j = 0 ;

    for (int i = 0; i < num; i++)
    {
        ll fir = edges[i][0];

        ll sec = edges[i][1];

        adj[fir].push_back(sec);
        adj[sec].push_back(fir);
    }

    bool ans = false;

    dfs(edges, adj, visited, source, source, destination, ans);

    return visited[destination];
}

int main()
{

    return 0;
}

// ॥ जय श्री राम जय श्री कृष्ण ॥