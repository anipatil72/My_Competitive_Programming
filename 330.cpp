#include <bits/stdc++.h>
using namespace std;

#define ll long long

void solve()
{
    ll n, s;

    cin >> n >> s;

    ll sum = n * (n - 1) / 2;

    ll p = sum - s;

    if (p > n || p <= 0)
    {
        cout << "-1" << endl;
    }
    else
    {
        cout << p << endl;
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