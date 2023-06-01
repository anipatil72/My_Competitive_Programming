// ॥ श्री गणेशाय नमः ॥

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define ll long long
#define ull unsigned long long
using namespace std;
using namespace __gnu_pbds;

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
// typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_multiset;

void recur(int index, vector<int> adj[], stack<int> &s, vector<int> &vis)
{
    vis[index] = 0;

    for (int i = 0; i < adj[index].size(); i++)
    {
        if (vis[adj[index][i]] == 1)
        {
            recur(adj[index][i], adj, s, vis);
        }
    }

    s.push(index);
}

vector<int> topoSort(int V, vector<int> adj[])
{
    vector<int> vis(V, 1);

    stack<int> s;

    for (int i = 0; i < V; i++)
    {
        if (vis[i] == 1)
        {
            recur(i, adj, s, vis);
        }
    }

    vector<int> ans;

    while (!s.empty())
    {
        ans.push_back(s.top());

        s.pop();
    }

    // reverse(ans.begin(), ans.end());

    return ans;
}

int main()
{

    return 0;
}

// ॥ जय श्री राम जय श्री कृष्ण ॥