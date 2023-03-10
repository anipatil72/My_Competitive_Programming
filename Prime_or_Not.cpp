// ॥ श्री गणेशाय नमः ॥

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define uint unsigned int
#define M 1000000007
// function to check prime
bool isPrime(ll n)
{
    if (n == 1)
    {
        return false;
    }
    if (n == 2 || n == 3)
    {
        return true;
    }
    if (n % 2 == 0 || n % 3 == 0)
    {
        return false;
    }
    for (int i = 5; i * i <= n; i = i + 6)
    {
        if (n % i == 0)
        {
            return false;
        }
        if (n % (i + 2) == 0)
        {
            return false;
        }
    }
    return true;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll t = 1;

    cin >> t;

    for (int i = 0; i < t; i++)
    {
        ll n;

        cin >> n;

        cout << ((isPrime(n) == true) ? "YES" : "NO") << '\n';
    }

    return 0;
}

// ॥ जय श्री राम जय श्री कृष्ण ॥