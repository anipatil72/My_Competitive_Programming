#include <bits/stdc++.h>
using namespace std;

int solve(vector<int> &A, int B)
{

    int n = A.size();

    for (int i = 1; i < n; i++)
    {

        int d = abs(A[i] - A[i - 1]);

        if (d != B || d != 2 * B || d != 0)
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