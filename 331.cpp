#include <bits/stdc++.h>
using namespace std;

int solve(vector<int> &A, int B, int C)
{

    int n = A.size();

    if (B%2==0)
    {
       int count = 0 ;

       for (int i = 0; i < n; i++)
       {
            if (A[i]%2==1)
            {
                    count++;
            }
            
       }

       return count*C;
            
    }
    
        int count = 0 ;

        for (int i = 0; i < n; i++)
        {
                if (A[i]%2==0)
                {
                        count++;
                }
                
        }

        return count*C;
        
    
    
    
}

int main()
{

    return 0;
}