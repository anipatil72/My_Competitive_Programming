// ॥ श्री गणेशाय नमः ॥

#include <bits/stdc++.h>
using namespace std;

#define ll long long

ll GCD(int a, int b)
{
    if (b == 0)
    {
        return a;
    }

    return GCD(b, a % b);
}

vector<long long> factorial()
{
    vector<long long> fact(9, 1);

    for (int i = 0; i <= 8; i++)
    {
        ll p = 1;

        for (int j = 1; j <= i; j++)
        {
            p *= j;
        }

        fact[i] = p;
    }

    return fact;
}

ll GiveNcR(int n, int r)
{

    // p holds the value of n*(n-1)*(n-2)...,
    // k holds the value of r*(r-1)...
    long long p = 1, k = 1;

    // C(n, r) == C(n, n-r),
    // choosing the smaller value
    if (n - r < r)
        r = n - r;

    if (r != 0)
    {
        while (r)
        {
            p *= n;
            k *= r;

            // gcd of p, k
            long long m = GCD(p, k);

            // dividing by gcd, to simplify
            // product division by their gcd
            // saves from the overflow
            p /= m;
            k /= m;

            n--;
            r--;
        }

        // k should be simplified to 1
        // as C(n, r) is a natural number
        // (denominator should be 1 ) .
    }

    else
        p = 1;

    // if our approach is correct p = ans and k =1
    // cout << p << endl;

    return p;
}

int countNumbersWithUniqueDigits(int n)
{

    if (n == 1)
    {
        return 2;
    }

    vector<long long> fact = factorial();

    ll ans = 10;

    for (int i = 2; i <= n; i++)
    {

        ans += GiveNcR(10, i) * fact[i] - GiveNcR(9, i - 1)*fact[i-1];
    }

    return ans;
}

int main()
{

    cout << countNumbersWithUniqueDigits(2);

    return 0;
}

// ॥ जय श्री राम जय श्री कृष्ण ॥