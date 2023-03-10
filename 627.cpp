// ॥ श्री गणेशाय नमः ॥

#include <bits/stdc++.h>
using namespace std;

int arrangeCoins(int n)
{
    long long p = 1;

    long long t = 1;

    while (p < n)
    {
        t++;

        p = t * (t + 1) / 2;
    }

    if (p == n)
    {
        return t;
    }
    else
    {
        return t - 1;
    }
}

int main()
{

    return 0;
}

// ॥ जय श्री राम जय श्री कृष्ण ॥