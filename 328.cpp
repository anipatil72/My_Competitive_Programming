#include <bits/stdc++.h>
using namespace std;

vector<int> solve(vector<int> &A)
{

    int n = A.size();

    int i = 0 , j = 0 ;

    while (j<n)
    {
        if (A[j]==0)
        {
                A[i]=0;
                i++;
                j++;
                continue;
        }

        j++;
        
    }

    while (i<n)
    {
        A[i]=1;
    }


    return A;
    
    
}

int main()
{

    

    return 0;
}