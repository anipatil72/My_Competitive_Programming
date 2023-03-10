// ॥ श्री गणेशाय नमः ॥

#include <bits/stdc++.h>
#define ll long long
#define M 1000000007
using namespace std;

bool dfs(int node, vector<int>& vis, vector<int>& pathvis, vector<int> adj[] )
{
    vis[node] = 0 ;

    pathvis[node] = 0 ;

    for (int i = 0; i < adj[node].size(); i++)
    {
            if (vis[adj[node][i]]==1)
            {
                    
                if (dfs(adj[node][i], vis, pathvis, adj)==true)
                {
                        return true;
                }
                    
            }
            else if(pathvis[adj[node][i]]==0)
            {

                return true;
                
            }
            
            
    }

    pathvis[node] = 1;

    return false;
    

}


bool isCyclic(int V, vector<int> adj[])
{
    // int vis[V];

    vector<int> vis(V, 1);

    vector<int> pathvis(V, 1);

    for (int i = 0; i < V; i++)
    {

        if (vis[i])
        {

            
            if (dfs(i, vis, pathvis, adj))
            {
                    return true;
            }
            
        }
        
            
    }

    return false;
     

    // int patthVis[V];
}

int main()
{

    return 0;
}

// ॥ जय श्री राम जय श्री कृष्ण ॥