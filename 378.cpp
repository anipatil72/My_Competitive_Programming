#include <bits/stdc++.h>
using namespace std;

void recur(vector<int> &v, int cur, int &m, int &sum)
{

    if (cur == v.size() - 1)
    {
        m = min(m, sum);
        sum--;
        return;
    }

    for (int i = 1; i <= v[cur] && ((cur + i) < v.size()); i++)
    {

        recur(v, cur + i, m, ++sum);
    }

    sum--;
}



int DyProSolution(vector<int>& v,vector<int>& dp)
{
    int n = v.size();

    dp[0] = 0;

    for (int i = 1; i < n; i++)
    {

        for (int j = 0; j < i; j++)
        {
                if ((v[j] + j>=i))
                {

                    if (dp[j]!=INT_MAX)
                    {
                            
                        dp[i] = min(dp[i],dp[j]+1);
                    }
                    
                }
                
        }
        
            
    }


    return dp[n-1];
    


    
}

int minJumps(vector<int> &v)
{
    int n = v.size();
    vector<int> dp(n,INT_MAX);

    if (n == 1 || n == 2)
    {
        if (n==1)
        {
                if (v[0]!=0)
                {
                        return 0;
                }
                
        }

        if (n==2)
        {
                if (v[0]!=0)
                {
                    return 1;
                }
                
        }
        
        

        return -1;
        
    }

    int x = DyProSolution(v,dp);

    return (x==INT_MAX)?-1:x;
}



int main()
{

    vector<int> v ={4,1,5,3,1,3,2,1,8};

    cout<<minJumps(v);


    return 0;
}