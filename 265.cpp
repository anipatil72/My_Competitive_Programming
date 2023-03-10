#include <bits/stdc++.h>
using namespace std;

vector<int> solve(string A)
{
    int n = A.length();

    vector<int> v (26,0);

    for (int i = 0; i < n; i++)
    {
            v[A[i]-'a']++;
    }



    return v;
    
}

int main()
{

    return 0;
}