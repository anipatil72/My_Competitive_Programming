#include <bits/stdc++.h>
using namespace std;

int climbStairs(int n)
{

    if (n == 1 || n == 2 || n == 3)
    {
        return n;
    }

    vector<int> v(n, 0);

    v[n - 1] = 1;

    v[n - 2] = 2;

    for (int i = n - 3; i >= 0; i--)
    {
        v[i] = v[i + 1] + v[i + 2];
    }

    return v[0];
}

int main()
{

    return 0;
}