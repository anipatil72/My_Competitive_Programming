#include <bits/stdc++.h>
using namespace std;

// function to check prime
bool isPrime(int n)
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
// Sieve of Erathosthenes
vector<bool> sieve(int n)
{
    vector<bool> v(n + 1, true);
    for (int i = 2; i * i <= n; i++)
    {
        if (v[i])
        {
            for (int j = i * i; j <= n; j = i + j)
            {
                v[j] = false;
            }
        }
    }
    return v;
}
int GCD(int a, int b)
{
    if (b == 0)
    {
        return a;
    }

    return GCD(b, a % b);
}

int LCM(int a, int b)
{
    return (a * b) / GCD(a, b);
}
void solve()
{

    int m, n;

    int x, y;

    int M = INT_MIN;

    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {

            int d;

            cin >> d;

            if (d > M)
            {
                M = d;

                x = i;

                y = j;
            }
        }
    }

    int ax = max(x + 1, n - (x));

    int ay = max(y + 1, m - (y));

    cout<<ax * ay<<endl;;
}

int main()
{
    int t;

    cin >> t;

    for (int i = 0; i < t; i++)
    {
        solve();
    }

    return 0;
}