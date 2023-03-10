#include <bits/stdc++.h>
using namespace std;

int solve(vector<int> &A, int B)
{

    int n  = A.size();

    int l = 0 , r = 0 ;

    unordered_map<int,int> m;

    int ans = 0 ;

    while (r<n)
    {
        if (m.size()<B)
        {
            m[A[r]]++;
            r++;

            

           continue;
        }
        if (m.size()==B)
        {
                ans++;
        }
        
        
            
        
        
        
    }
    
}

int main()
{

    return 0;
}