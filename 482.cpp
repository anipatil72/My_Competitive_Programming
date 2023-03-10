#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{

    ll n;

    cin >> n;

    unordered_map<ll, ll> m;

    for (int i = 0; i < n; i++)
    {
        int d;

        cin >> d;

        m[d] = i;
    }

    ll t;

    ll petya = 0, vasya = 0;

    cin >> t;

    for (int i = 0; i < t; i++)
    {
        int d;

        cin >> d;

        vasya += m[d] + 1;

        petya += n - m[d];
    }

    cout << vasya << " " << petya << endl;

    return 0;
}