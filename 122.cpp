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

    int n, m = INT_MAX, u;

    cin >> n;

    if (n % 2 == 1)
    {

        for (int i = 0; i < n; i++)
        {

            int d ;

            cin >> d;
        }
        cout << "Mike" << endl;
        return;
    }

    else
    {

        for (int i = 0; i < n; i++)
        {

            int d ;

            cin >> d;

            if (d < m)
            {
                m = d;

                u = i;
            }
        }

        if (u % 2 == 0)
        {
            cout << "Joe" << endl;
            return ;
        }
        else
        {
            cout << "Mike" << endl;
            return;
        }
    }
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