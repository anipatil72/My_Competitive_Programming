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


void solve(){
    long long  n, m;
    cin>>n>>m;
    long long  ans = (m * (m + 1)) / 2 + (m * (n * (n + 1) / 2));
    // int val = 2 * m;
    // int cnt = 1;
    // while(cnt <= n)
    // {
    //     ans += val;
    //     val += m;
    //     cnt++;
    // }
    cout<<ans - m<<endl;
}

int main()
{
    long long t;

    cin >> t;

    for (long long i = 0; i < t; i++)
    {
        solve();
    }

    return 0;
}