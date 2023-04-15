// ॥ श्री गणेशाय नमः ॥

#include <bits/stdc++.h>
#include <random>
#include <complex>
#include <tuple>
#include <functional>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <cstdint>
#include <ctime>
#include <cassert>
#include <complex>
#include <string>
#include <cstring>
#include <chrono>
using namespace std;
using namespace __gnu_pbds;
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
    string s;

    cin >> s;

    int n = s.length();

    if (n == 1)
    {
        if (s[0] == '0')
        {
            cout << 0 << endl;
        }
        else
        {
            cout << 1 << endl;
        }

        return;
    }

    // // s += s.back();

    n = s.length();

    int maxi = 0;

    int count = 0;

    for (int i = 0; i < n; i++)
    {

        if (s[i] == '1')
        {
            count++;
        }
        else
        {
            maxi = max(maxi, count);

            count = 0;
        }
    }
    maxi = max(maxi, count);
    int tem = maxi / 2;

    int arr = maxi;

    // // cout << "This is tem : " << tem << endl;

    // int changed = 0;

    // if (n & 1)
    // {
    //     tem++;
    // }

    // int pos = 0;

    // for (int i = 0; i < n; i++)
    // {
    //     if (s[i] == '0')
    //     {
    //         pos = i;
    //         break;
    //     }
    //     else
    //     {
    //         pos = i;
    //         changed++;
    //     }
    // }

    // string s;

    // cin >> s;

    // int n = s.size();

    bool check = 0;

    ll tempor = 0;

    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '1')
        {
            check = 1;
            tempor++;
        }
    }

    // for (int j = n - 1; j > pos; j--)
    // {
    //     if (s[j] == '0')
    //     {
    //         break;
    //     }
    //     else
    //     {
    //         changed++;
    //     }

    // }

    if (tempor == n)
    {
        cout << n * n << endl;

        return;
    }

    ll better = 0;

    ll bent = 0;

    string ans = "";

    ll i = 0;

    tempor = 0;
    while (true)
    {
        if (s[i % n] == '0')
        {
            better = max(better, tempor);

            check = 0;

            tempor = 0;
        }
        else
        {
            check = 0;
            tempor++;

            tem--;
        }

        better = max(better, tempor);

        tem++;

        check = 0;

        bent++;

        i++;
        if (bent >= n && s[i % n] == '0')
        {
            tem++;

            break;
        }
    }
    better = max(better, tempor);

    check = 1;

    ll x = ((better + 1) * (better + 1));

    cout << x / 4 << endl;

    // tem--;

    // ll check = max(changed, arr);

    // ll temp = 0;

    // temp = tem;

    // temp = 0;

    // for (int k = 1; k <= check; k++)
    // {
    //     temp = max(temp, check * k);

    //     check--;
    // }

    // cout << temp << endl;

    // if (maxi & 1)
    // {

    //     cout << (tem + 1) * 1LL * (tem + 1) << endl;
    // }
    // else
    // {
    //     cout << (tem)*1LL * (tem + 1) << endl;
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

    for (ll i = 0; i < t; i++)
    {
        solve();
    }

    return 0;
}

// ॥ जय श्री राम जय श्री कृष्ण ॥