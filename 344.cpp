#include <bits/stdc++.h>
using namespace std;

int solve(vector<string> &A)
{

    int n = A.size();

    vector<int> visited(26,1);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <A[i].length(); j++)
        {
             
                  visited[A[i][j]-'a']= 0;
                    
             
            
                
        }
        
        
    }


    for (int i = 0; i < 26; i++)
    {
        if (visited[i]==1)
        {
            return 0;
        }
        
    }
    


    return 1;
    
}

int main()
{

    return 0;
}