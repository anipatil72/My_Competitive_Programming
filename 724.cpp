// ॥ श्री गणेशाय नमः ॥

#include <bits/stdc++.h>
#define ll long long
#define M 1000000007
using namespace std;

void dfs(vector<int> adj[], vector<int> &visited, stack<int> &s, int node)
{
    visited[node] = 0;

    for (int i = 0; i < adj[node].size(); i++)
    {
        if (visited[adj[node][i]])
        {
            dfs(adj, visited, s, adj[node][i]);
        }
    }

    s.push(node);
}

vector<int> topoSort(int V, vector<int> adj[])
{
    vector<int> visited(V, 1);

    vector<int> ans;

    stack<int> s;

    for (int i = 0; i < V; i++)
    {

        if (visited[i])
        {
            dfs(adj, visited, s, i);
        }
    }

    while (!s.empty())
    {
        int d = s.top();

        ans.push_back(d);

        s.pop();
    }

    return ans;
}

int main()
{

    return 0;
}

// ॥ जय श्री राम जय श्री कृष्ण ॥