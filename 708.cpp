// ॥ श्री गणेशाय नमः ॥

#include <bits/stdc++.h>
#define ll long long
#define M 1000000007
using namespace std;

bool dfs(int node, vector<int> &visited, vector<int> &visited1, vector<int> adj[])
{

    visited1[node] = 0;
    visited[node] = 0;

    int n = adj[node].size();

    for (int i = 0; i < n; i++)
    {

        if (visited[adj[node][i]] == 0)
        {
            return true;
        }
        else
        {
            if (dfs(adj[node][i], visited, visited1, adj) == true)
            {
                return true;
            }
        }
    }

    return false;
}

bool isCyclic(int V, vector<int> adj[])
{

    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < adj[i].size(); j++)
        {
            if (adj[i][j] == i)
            {
                return true;
            }
        }
    }

    vector<int> visited1(V, 1);

    for (int i = 0; i < V; i++)
    {
        if (visited1[i])
        {
            vector<int> visited(V, 1);
            bool b1 = dfs(i, visited, visited1, adj);

            if (b1 == false)
            {
                return true;
            }
        }
    }

    return false;
}

int main()
{

    return 0;
}

// ॥ जय श्री राम जय श्री कृष्ण ॥