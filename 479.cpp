#include <bits/stdc++.h>
using namespace std;

int solve(vector<int> &A)
{

    int n = A.size();

    unordered_map<int, int> m;

    int x = INT_MIN;

    for (int i = 0; i < n; i++)
    {
        m[A[i]]++;

        x = max(x, m[A[i]]);
    }

    return x;
}

int main()
{

    return 0;
}