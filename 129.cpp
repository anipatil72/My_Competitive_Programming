#include <bits/stdc++.h>
using namespace std;

int FirstMissingPositive(vector<int> &A)
{
    int n = A.size();
    for (int i = 0; i < n; i++)
    {
        if (A[i] == i + 1)
        {
            continue;

        }
        int prev = A[i];
        while (true)
        {
            if (prev > 0 && prev <= n && A[prev - 1] != prev)
            {
                int x = A[prev - 1];
                A[prev - 1] = prev;
                prev = x;
            }
            else
            {
                break;
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (A[i] != i + 1)
            return i + 1;
    }
    return n + 1;
}

int main()
{

    return 0;
}