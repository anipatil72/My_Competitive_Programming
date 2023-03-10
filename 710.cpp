// ॥ श्री गणेशाय नमः ॥

#include <bits/stdc++.h>
#define ll long long
#define M 1000000007
using namespace std;

bool dfs(int node, vector<int>& vis, vector<int>& pathvis, vector<int> adj[], vector<int> & ans )
{
    vis[node] = 0 ;

    pathvis[node] = 0 ;

    for (int i = 0; i < adj[node].size(); i++)
    {
            if (vis[adj[node][i]]==1)
            {
                    
                if (dfs(adj[node][i], vis, pathvis, adj, ans)==true)
                {

                        ans[adj[node][i]]  =0 ;
                        return true;
                }
                    
            }
            else if(pathvis[adj[node][i]]==0)
            {
                ans[adj[node][i]] = 0 ;
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

    vector<int> ans(V, 1);


    for (int i = 0; i < V; i++)
    {

        if (vis[i])
        {

            
            bool b1 = dfs(i, vis, pathvis, adj, ans);

            if (b1)
            {
                    ans[i] = 0 ;
            }
            
            
        }
        
            
    }

    return false;
     

    // int patthVis[V];
}

vector<int> eventualSafeNodes(int V, vector<int> adj[])
{

   vector<int> vis(V, 1);

    vector<int> pathvis(V, 1);

    vector<int> ans(V, 1);


    for (int i = 0; i < V; i++)
    {

        if (vis[i])
        {

            
            bool b1 = dfs(i, vis, pathvis, adj, ans);

            if (b1)
            {
                    ans[i] = 0 ;
            }
            
            
        }
        
            
    }

    vector<int> fin;

    for (int i = 0; i < V; i++)
    {
            if (ans[i])
            {
                    fin.push_back(i);
            }
            
    }
    

    // return false;

    return fin;
   
}

int main()
{

    return 0;
}

// ॥ जय श्री राम जय श्री कृष्ण ॥