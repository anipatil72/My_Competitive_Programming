#include <bits/stdc++.h>
using namespace std;

int solve(vector<int> &A)
{

    int n = A.size();

    unordered_map<int,int> m;

    for (int i = 0; i < n; i++)
    {
            m[A[i]]++;
    }

    if (m.size()<3)
    {
            return 0;
    }
    
    

    nth_element(A.begin(),A.begin() + n-3,A.end());
    nth_element(A.begin(),A.begin() + n-2,A.end());
    nth_element(A.begin(),A.begin() + n-1,A.end());

    int a = A[n-1];
    int b = A[n-2];
    int c = A[n-3];

    
    
}

int main()
{

    return 0;
}