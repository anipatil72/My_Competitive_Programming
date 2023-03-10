#include <bits/stdc++.h>
using namespace std;

bool isPowerOfThree(int n)
{

    if (n <= 0)
    {
        return false;
    }

    long double c = log10(n) / log10(4);

    int x = c;

    return (c - x) == 0;
}

int main()
{

    int a = 27;

    long double c = log10(a) / log10(3);

    int n = c;

    // cout<<c<<endl;

    return 0;
}