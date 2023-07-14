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

bool recur(vector<vector<int>> &adj, vector<int> &vis, int index)
{
    bool ans = true;

    vis[index] = 0;

    for (int i = 0; i < adj[index].size(); i++)
    {

        if (vis[adj[index][i]] == 1)
        {
            bool cur = recur(adj, vis, index);

            if (!cur)
            {
                return false;
            }
        }
        else
        {
            return false;
        }
    }

    return true;
}

bool canFinish(int numCourses, vector<vector<int>> &pre)
{
    int n = numCourses;

    vector<vector<int>> adj(n);

    int req = pre.size();

    for (int i = 0; i < req; i++)
    {
        adj[pre[i][0]].push_back(pre[i][1]);
    }

    vector<int> visited(n, 1);

    for (int i = 0; i < n; i++)
    {
        if (visited[i] == 1)
        {
            bool des = recur(adj, visited, i);

            if (!des)
            {
                return false;
            }
        }
    }

    return true;

    // return recur(adj, visited, 0);
}

int main()
{

    return 0;
}

// ॥ जय श्री राम जय श्री कृष्ण ॥