#include <bits/stdc++.h>
using namespace std;

int solve(vector<int> &A) {

    int m = INT_MAX;
    int M = INT_MIN;

    for (int i = 0; i < A.size(); i++)
    {
            m = min(A[i],m);
            M = max(M,A[i]);


    }

    return m + M ;
    
}




int main() 
{

    

return 0;
}