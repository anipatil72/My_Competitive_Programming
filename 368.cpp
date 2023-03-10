#include <bits/stdc++.h>
using namespace std;

int mincoinchange(int n,vector<int>& v)
{
    int dp[n+1];

    dp[0] = 0;

    // for (int i = 1; i <= n; i++)
    // {
    // }
    
    

    for (int i = 1; i <= n; i++)
    {
        
            dp[i] = INT_MAX;
        for (int j = 0; j < v.size(); j++)
        {
            if (v[j]<=i)
            {

                int f = dp[i-v[j]];

                if (f!=INT_MAX)
                {
                    dp[i] = min(f + 1, dp[i]); 
                        
                }
                
            }
            
        }
        
    }

    if (dp[n]==INT_MAX)
    {
         return -1;   
    }
    

    return dp[n];
    
}

int main() 
{

    int sum = 5;

    vector<int> coins = {3,4,1};

    cout<<mincoinchange(sum,coins);

return 0;
}