#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> solve(vector<vector<int>> &A)
{

    int n = A.size();

    for (int i = 0; i < n; i++)
    {
            for (int j = i + 1; j < n; j++)
            {
                   swap(A[i][j],A[j][i]); 
            }
            
    }


    return A;
    
}

int main()
{

    return 0;
}