// ॥ श्री गणेशाय नमः ॥

#include <bits/stdc++.h>
#define ll long long
#define M 1000000007
using namespace std;

bool isPossible(int N, vector<pair<int, int>> &prerequisites)
{
    vector<int> indeg(N + 1, 0);

    vector<vector<int>> adj(N);

    for (int i = 0; i < prerequisites.size(); i++)
    {

        adj[prerequisites[i].first].push_back(prerequisites[i].second);
    }

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < adj[i].size(); j++)
        {

            indeg[adj[i][j]]++;
        }
    }

    queue<int> q;

    for (int i = 0; i < N; i++)
    {
        if (indeg[i] == 0)
        {
            q.push(i);
        }
    }

    vector<int> ans;

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

    return ans.size() == N;
}

int main()
{

    return 0;
}

// ॥ जय श्री राम जय श्री कृष्ण ॥