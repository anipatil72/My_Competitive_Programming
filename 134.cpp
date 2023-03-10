#include <bits/stdc++.h>
using namespace std;

int swapsumEqual(int A[], int n, int B[], int m)
{

    int s1 = 0, s2 = 0;
    for (int i = 0; i < n; i++)
    {
        s1 += A[i];
    }
    for (int i = 0; i < m; i++)
    {
        s2 += B[i];
    }
    for (int i = 0; i < m; i++)
    {
        B[i] *= 2;
    }
    sort(B, B + m);
    for (int i = 0; i < n; i++)
    {
        int need = s2 - s1 + 2 * A[i];
        if (binary_search(B, B + m, need))
        {
            return 1;
        }
    }
    return -1;
}

int main()
{

    return 0;
}