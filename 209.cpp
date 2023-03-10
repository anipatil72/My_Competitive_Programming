#include <bits/stdc++.h>
using namespace std;

int solve(vector<int> &A, vector<int> &B, int C) {

    int a = 0 ,b = 0;

    int n = A.size();
    int m = B.size();

    for (int i = 0; i < n; i++)
    {
            if (A[i]>C)
            {
                    a++;
            }
            
    }

    for (int i = 0; i < m; i++)
    {
            if (B[i]<C)
            {
                    b++;
            }
            
    }
    
    

    
    return max(a,b);

}

int main() 
{

return 0;
}