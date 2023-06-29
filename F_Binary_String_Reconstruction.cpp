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

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
// typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_multiset;

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
// **For Interactive Problems remember to remove multi test cases condition** //
// (int)log2(x) + 1  -> to calculate number of bits of a number
// s.erase(0, min(s.find_first_not_of('0'), s.size()-1));   //for removing leading zero's
// Remember about unique function usage
// yi=(t|xi)⊕xi
// (int index = str.find(substr, pos)) != string::npos    // for checking substring 'substr' in string 'str'
// ((x >> j) & 1) ===> to check if the j-th bit is on/off
// log2(n&(-n)) returns a number in which only the rightmost bit is set in n
// alternatively ffs(n) also gives the index of the rightmost set bit
// x |= (1 << i) ===> to set the i-th bit on

void solve(ll tt, ll index)
{
    int a, b, c;

    cin >> c >> b >> a;

    // if (tt == 918 && index == 111)
    // {
    //     cout << "I am here ! : " << c << b << a;
    // }

    string ans = "";

    if (a == 0 && b == 0 && c > 0)
    {
        for (int i = 0; i < c + 1; i++)
        {
            ans += '0';
        }
    }
    else
    {
        for (int i = 0; i < a + 1; i++)
        {
            ans += '1';
        }

        for (int i = 0; i < b; i++)
        {
            if (i & 1)
            {
                ans += '1';
            }
            else
            {
                ans += '0';
            }
        }

        for (int i = 0; i < c + (b != 0 && c != 0 && b % 2 == 0); i++)
        {
            ans += '0';
        }
    }

    cout << ans << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("input.txt","r",stdin);
    // freopen("Binary_String_reconstruction.txt", "w", stdout);

    ll t = 1;

    cin >> t;

    for (ll i = 0; i < t; i++)
    {
        solve(t, i);
    }

    return 0;
}

// 0 0 1
// 0 0 2
// 0 0 3
// 0 0 4
// 0 0 5
// 0 0 6
// 0 0 7
// 0 0 8
// 0 0 9
// 0 1 0
// 0 1 1
// 0 1 2
// 0 1 3
// 0 1 4
// 0 1 5
// 0 1 6
// 0 1 7
// 0 1 8
// 0 1 9
// 0 2 0
// 0 2 1
// 0 2 2
// 0 2 3
// 0 2 4
// 0 2 5
// 0 2 6
// 0 2 7
// 0 2 8
// 0 2 9
// 0 3 0
// 0 3 1
// 0 3 2
// 0 3 3
// 0 3 4
// 0 3 5
// 0 3 6
// 0 3 7
// 0 3 8
// 0 3 9
// 0 4 0
// 0 4 1
// 0 4 2
// 0 4 3
// 0 4 4
// 0 4 5
// 0 4 6
// 0 4 7
// 0 4 8
// 0 4 9
// 0 5 0
// 0 5 1
// 0 5 2
// 0 5 3
// 0 5 4
// 0 5 5
// 0 5 6
// 0 5 7
// 0 5 8
// 0 5 9
// 0 6 0
// 0 6 1
// 0 6 2
// 0 6 3
// 0 6 4
// 0 6 5
// 0 6 6
// 0 6 7
// 0 6 8
// 0 6 9
// 0 7 0
// 0 7 1
// 0 7 2

// ॥ जय श्री राम जय श्री कृष्ण ॥