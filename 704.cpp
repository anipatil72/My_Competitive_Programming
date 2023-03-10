// ॥ श्री गणेशाय नमः ॥

#include <bits/stdc++.h>
#define ll long long
#define M 1000000007
using namespace std;

bool isBipartite(int V, vector<int> adj[])
{
    vector<int> color(V, -1);

    queue<int> q;

    for (int j = 0; j < V; j++)
    {
        if (color[j] == -1)
        {

            color[j] = 0;

            q.push(j);

            while (!q.empty())
            {
                int t = q.front();

                int tc = color[t];

                q.pop();

                for (int i = 0; i < adj[t].size(); i++)
                {

                    if (color[adj[t][i]] == -1)
                    {
                        color[adj[t][i]] = !tc;

                        q.push(adj[t][i]);
                    }
                    else if (color[adj[t][i]] == tc)
                    {
                        return false;
                    }
                }
            }
        }
    }

    return true;
}

int main()
{

    return 0;
}

// ॥ जय श्री राम जय श्री कृष्ण ॥