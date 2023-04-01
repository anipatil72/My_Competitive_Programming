// ॥ श्री गणेशाय नमः ॥

#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
#define ll long long
#define ull unsigned long long
using namespace std;

vector<int> bfsOfGraph(int V, vector<int> adj[])
{
    vector<int> ans;

    vector<int> vis(V, 1);

    queue<int> q;

    q.push(0);

    while (!q.empty())
    {
        int t = q.front();

        q.pop();

        vis[t] = 0;

        ans.push_back(t);

        for (int it : adj[t])
        {

            if (vis[it] == 1)
            {
                q.push(it);
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