#include <bits/stdc++.h>
using namespace std;

int perfectPeak(vector<int> &A)
{

    int n = A.size();
    int lmax[n], rmin[n];

    lmax[0] = A[0];

    for (int i = 1; i < A.size(); i++)
    {
        lmax[i] = max(A[i], lmax[i - 1]);
    }

    rmin[n - 1] = A[n - 1];

    for (int i = n - 2; i >= 0; i--)
    {
        rmin[i] = min(A[i], rmin[i + 1]);
    }

    for (int i = 1; i < n - 1; i++)
    {
        if (lmax[i - 1] < A[i] && rmin[i + 1] > A[i])
        {
            return 1;
        }
    }

    return 0;
}

int main()
{

    vector<int> a = {1, 2, 3, 4, 5, 4, 3, 2, 3, 10};

    cout<<perfectPeak(a);

    return 0;
}