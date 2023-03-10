// ॥ श्री गणेशाय नमः ॥

#include <bits/stdc++.h>
#define ll long long
#define M 1000000007
using namespace std;

void dfs(vector<vector<int>>& adj, vector<int>& ans, int node, string& labels)
{

    int x = 0 ;

    int n = adj[node].size();

    for (int i = 0; i < n; i++)
    {
        if (ans[adj[node][i]]==-1)
        {
            
        }
        
    }
    



}

vector<int> countSubTrees(int n, vector<vector<int>> &edges, string labels)
{

    vector<vector<int>> adj(n);

    vector<int> ans(n, -1);

    int m = edges.size();

    for (int i = 0; i < m; i++)
    {
        adj[edges[i][0]].push_back(edges[i][1]);
    }

    for (int i = 0; i < n; i++)
    {
        if (adj[i].size() == 0)
        {

            ans[i] = 1;
        }
    }


}

int main()
{

    return 0;
}

// ॥ जय श्री राम जय श्री कृष्ण ॥