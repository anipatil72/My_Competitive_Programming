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
    int x, y;
    cin >> x >> y;

    if (x == 1 || y == 1)
    {
        if (x == 1 && y != 1)
        {

            cout << "0";
            for (int i = 0; i < y; i++)
            {
                cout << "1";
            }

            cout << endl;

            return;
        }
        if (x != 1 && y == 1)
        {

            cout << "1";
            for (int i = 0; i < x; i++)
            {
                cout << "0";
            }

            cout << endl;
            return;
        }

        if (x == 1 && y == 1)
        {
            cout << "01";

            cout << endl;
            return;
        }
    }

    if (x > y)
    {

        int minotime = x / y;

        for (int i = 0; i < x + y; i++)
        {

            if (i == minotime)
            {
                cout << "1";
                minotime = minotime + x / y + 1;
                continue;
            }
            else
            {
                cout << "0";
            }
        }

       
    }

    if (x <= y)
    {

        int minotime = y / x;

        for (int i = 0; i < x + y; i++)
        {

            if (i == minotime)
            {
                cout << "0";
                minotime = minotime + y / x + 1;
                continue;
            }
            else
            {
                cout << "1";
            }
        }
    }

    

    cout << endl;
}

int main()
{
    int t;

    // cout<<(11%1)<<endl;

    cin >> t;

    for (int i = 0; i < t; i++)
    {
        solve();
    }

    return 0;
}