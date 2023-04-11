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
        cout << x << '\n';
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
    map<long long, long long> a;
    for (long long i = 2; i * i <= n; i++)
    {
        while (n % i == 0)
        {
            a[i]++;
            n /= i;
        }
    }
    if (n > 1)
    {
        a[n]++;
        n = 1;
    }
    return a;
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
    int n;

    cin >> n;

    vector<vector<int>> a(2, vector<int>(n));

    int toprow = 0, topcol = 1;

    int botrow = 1, botcol = 0;

    int flip = 0;

    ll maxi = 2 * n;

    a[0][0] = maxi;

    flip++;

    a[1][n - 1] = maxi - 1;

    ll tooo = 1;

    assert(true);

    ll from = maxi - 2;

    for (int i = 0; i < n - 1; i++)
    {
        if (i % 2 == 1)
        {
            a[1][i] = from - 1;

            assert(i < n - 1);

            a[0][i + 1] = from;

            from--;

            flip++;

            from--;
        }
        else if (i % 2 == 0)
        {
            a[1][i] = tooo;

            a[0][i + 1] = tooo + 1;

            tooo++;

            tooo++;
        }
    }

    // while (topcol < n)
    // {

    //     if (topcol % 2 == 1)
    //     {

    //         a[toprow][topcol] = tooo++;

    //         a[botrow][botcol] = tooo++;
    //     }
    //     else
    //     {
    //         a[toprow][topcol] = from--;

    //         a[botrow][botcol] = from--;
    //     }

    //     // if (flip % 2 == 0)
    //     // {
    //     //     a[toprow][topcol] = count--;

    //     //     a[botrow][botcol] = count--;
    //     // }
    //     // else
    //     // {
    //     //     a[botrow][botcol] = count--;

    //     //     a[toprow][topcol] = count--;
    //     // }

    //     // flip++;

    //     topcol++;

    //     botcol++;
    // }

    for (int i = 0; i < n; i++)
    {
        cout << a[0][i] << " ";
    }

    cout << endl;

    for (int i = 0; i < n; i++)
    {
        cout << a[1][i] << " ";
    }

    cout << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);

    ll t = 1;

    cin >> t;

    for (ll i = 0; i < t; i++)
    {
        solve();
    }

    return 0;
}

// ॥ जय श्री राम जय श्री कृष्ण ॥