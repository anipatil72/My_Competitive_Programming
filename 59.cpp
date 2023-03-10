#include <bits/stdc++.h>
using namespace std;

int maxx(int a, int b)
{
    return (a > b ? a : b);
}

int main()
{

    int i, j, k, left = 0, right;
    int m = INT_MAX;

    int a[] = {1, 10, 2, -41, 7, 51, 11, 0};
    int n = sizeof(a) / sizeof(int);

    int b[n];

    for (i = 0; i < n; i++)
    {
        b[i] = (a[i] == 0 ? 1 : 0);
    }

    int best = 0, sum = 0;

    for (i = 0; i < n; i++)
    {
        sum = maxx(sum + a[i], a[i]);
        best = maxx(best, sum);
    }

    cout << best << endl;

    return 0;
}