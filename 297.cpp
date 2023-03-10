#include <bits/stdc++.h>
using namespace std;

int solve(vector<int> &A, int B)
{

    int n = A.size();

    unordered_map<int, int> m;

    for (int i = 0; i < n; i++)
    {
        m[A[i]]++;

        if (B==0&&m.count(A[i])>=2)
        {
            return 1 ;
        }
        
    }

    for (int i = 0; i < n; i++)
    {

        if (m.count(A[i] - B) > 0 || m.count(A[i] + B) > 0)
        {
            return 1;
        }
    }

    return 0;
}

int main()
{

    return 0;
}