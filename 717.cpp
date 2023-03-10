// ॥ श्री गणेशाय नमः ॥

// Kahn's Algorithm for Topological Sorting of the dependencies

#include <bits/stdc++.h>
#define ll long long
#define M 1000000007
using namespace std;

vector<int> topoSort(int V, vector<int> adj[])
{
    vector<int> ans;
    vector<int> indeg(V, 0);

    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < adj[i].size(); j++)
        {
            indeg[adj[i][j]]++;
        }
    }

    queue<int> q;

    for (int i = 0; i < V; i++)
    {
        if (indeg[i] == 0)
        {
            q.push(i);
        }
    }

    while (!q.empty())
    {

        int t = q.front();

        ans.push_back(t);

        q.pop();

        for (int i = 0; i < adj[t].size(); i++)
        {
            indeg[adj[t][i]]--;

            if (indeg[adj[t][i]] == 0)
            {

                q.push(adj[t][i]);
            }
        }
    }

    return ans;
}

int main()
{

    return 0;
}

// ॥ जय श्री राम जय श्री कृष्ण ॥