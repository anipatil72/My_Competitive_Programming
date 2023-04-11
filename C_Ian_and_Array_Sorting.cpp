// ॥ श्री गणेशाय नमः ॥

#include <bits/stdc++.h>
#include <random>
#include <complex>
#include <tuple>
#include <functional>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
#include <cstdint>
#include <ctime>
#include <cassert>
#include <complex>
#include <string>
#include <cstring>
#include <chrono>
using namespace std;
#define ll long long
#define lld long double
#define ull unsigned long long
#define uint unsigned int

template <typename typC, typename typD>
istream &operator>>(istream &cin, pair<typC, typD> &a)
{
    return cin >> a.first >> a.second;
}
template <typename typC>
istream &operator>>(istream &cin, vector<typC> &a)
{
    for (auto &x : a)
        cin >> x;
    return cin;
}
template <typename typC, typename typD>
ostream &operator<<(ostream &cout, const pair<typC, typD> &a) { return cout << a.first << ' ' << a.second; }
template <typename typC, typename typD>
ostream &operator<<(ostream &cout, const vector<pair<typC, typD>> &a)
{
    for (auto &x : a)
        cout << x << endl;
    return cout;
}
template <typename typC>
ostream &operator<<(ostream &cout, const vector<typC> &a)
{
    int n = a.size();
    if (!n)
        return cout;
    cout << a[0];
    for (int i = 1; i < n; i++)
        cout << ' ' << a[i];
    return cout;
}

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
ll myRandomNumber(ll B)
{
    return (ull)rng() % B;
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

// returns map containing factor and multiplicity, Eg: 60 = {{2,2},{3,1},{5,1}}

map<long long, long long> factorize(long long n)
{
    map<long long, long long> ans;
    for (long long i = 2; i * i <= n; i++)
    {
        while (n % i == 0)
        {
            ans[i]++;
            n /= i;
        }
    }
    if (n > 1)
    {
        ans[n]++;
        n = 1;
    }
    return ans;
}

// -------------------Important Notes------------------- //
// ***For Interactive Problems remember to remove multi test cases condition*** //
// (int)log2(x) + 1  -> to calculate number of bits of a number
// s.erase(0, min(s.find_first_not_of('0'), s.size()-1));   //for removing leading zero's
// Remember about unique function usage
// yi=(t|xi)⊕xi
// (int index = str.find(substr, pos)) != string::npos    // for checking substring 'substr' in string 'str'
// ((x >> j) & 1) ===> to check if the j-th bit is on/off
// log2(n&(-n)) returns a number in which only the rightmost bit is set in n
// alternatively ffs(n) also gives the index of the rightmeost set bit
// x |= (1 << i) ===> to set the i-th bit on

void solve()
{
    ll n;
    cin >> n;

    vector<ll> a(n);

    cin >> a;

    if (n == 2)
    {
        cout << (is_sorted(a.begin(), a.end()) ? "YES" : "NO") << endl;

        return;
    }

    if (is_sorted(a.begin(), a.end()))
    {
        cout << "YES" << endl;

        return;
    }

    // cout << "This is a : " << endl;

    // cout << a << endl;

    vector<ll> b = a;

    ll sum = 0;

    for (int i = 1; i < n - 1; i++)
    {

        if (b[i] > b[i - 1])
        {
            ll diff = b[i] - b[i + 1];

            b[i] += diff;
            b[i + 1] += diff;

            // sum += diff;
        }
    }

    if (b[n - 1] >= b[n - 2])
    {
        cout << "YES" << endl;

        return;
    }
    else
    {
        ll temp = 0;

        for (int i = n - 2; i > 0; i--)
        {
            if (b[i] > b[i + 1])
            {
                ll diff = b[i] - b[i + 1];

                b[i] -= diff;

                b[i - 1] -= diff;
            }
        }

        if (b[0] > b[1])
        {
            cout << "NO" << endl;
        }
        else
        {
            cout << "YES" << endl;
        }
    }

    // ll dif = b[n - 2] - b[n - 1];

    // b[n - 2] -= dif;
    // b[n - 3] -= dif;

    // b[n - 1] += (ll)(1e15);
    // b[n - 2] += (ll)(1e15);

    // if (is_sorted(b.begin(), b.end()))
    // {
    //     cout << "YES" << endl;

    //     return;
    // }

    // cout << "NO" << endl;
    // int due = 0;

    // vector<ll> a(n);

    // cin >> a;

    // ll flip = 1;

    // for (int i = 0; i < n - 1; i++)
    // {
    //     if (a[i] > a[i + 1])
    //     {
    //         flip = 0;

    //         due++;

    //         break;
    //     }
    // }

    // if (flip)
    // {
    //     cout << "YES" << endl;
    //     return;
    // }

    // bool flag = 0;

    // int x = a[n - 1];

    // for (int i = n - 1; i > 0; i--)
    // {
    //     if (i == n - 1)
    //     {
    //         flag = 1;
    //         due--;
    //         continue;
    //     }

    //     if (a[i] >= x)
    //     {
    //         ll from = a[i] - x;

    //         due--;
    //         a[i] -= from;

    //         assert(i > 0);

    //         a[i - 1] -= from;
    //     }
    //     else
    //     {
    //         ll tem = x - a[i];

    //         a[i] += tem;

    //         due++;

    //         a[i - 1] += tem;
    //     }
    // }

    // if (a[0] <= a[n - 1])
    // {
    //     cout << "YES" << endl;

    //     return;
    // }
    // else
    // {
    //     if (n % 2 == 0)
    //     {
    //         cout << "NO" << endl;
    //     }
    //     else
    //     {
    //         cout << "YES" << endl;
    //     }
    // }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);

    ll t = 1;

    cin >> t;

    cout << "I stopped here ! " << endl;

    cout << "I didnt come here ! " << endl;

    // cin >> t;

    for (ll i = 0; i < t; i++)
    {
        solve();
    }

    return 0;
}

// ॥ जय श्री राम जय श्री कृष्ण ॥