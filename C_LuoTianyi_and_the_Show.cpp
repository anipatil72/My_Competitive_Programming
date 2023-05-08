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
// ***For Interactive Problems remember to remove multi test cases condition*** //
// (int)log2(x) + 1  -> to calculate number of bits of a number
// s.erase(0, min(s.find_first_not_of('0'), s.size()-1));   //for removing leading zero's
// Remember about unique function usage
// yi=(t|xi)⊕xi
// (int index = str.find(substr, pos)) != string::npos    // for checking substring 'substr' in string 'str'
// ((x >> j) & 1) ===> to check if the j-th bit is on/off
// log2(n&(-n)) returns a number in which only the backmost bit is set in n
// alternatively ffs(n) also gives the index of the backmeost set bit
// x |= (1 << i) ===> to set the i-th bit on

void solve()
{
    ll n, x, m;

    vector<ll> v;

    ll back = 0, front = 0;
    cin >> n >> m;

    ll p = 0;

    set<ll> s;

    ll fin = 0, temp = 0;

    v.push_back(-1);

    for (int i = 0; i < n; i++)
    {
        cin >> x;

        string stew = "sgk";

        int tem = x;

        if (x == -1)
        {
            back++;
        }
        else if (x == -2)
        {
            front++;

            tem--;
        }
        else
        {
            p++;
            tem++;

            s.insert(x);
        }
    }

    int check = 0;

    for (auto fogg : s)
    {
        v.push_back(fogg);
    }

    vector<int> d;

    d.push_back(-3);

    v.push_back(-2);

    vector<ll> c;

    ll ans = 0;

    ll len = v.size();

    for (int i = 0; i < len; i++)
    {
        x = v[i];

        if (i == len - 1)
        {
            ans = max(ans, min(0LL + back + len - 2, m));
        }
        else if (i == 0)
        {

            c.push_back(ans);

            ans = max(ans, min(front + 0LL + len - 2, m));
        }
        else
        {
            ans = max(ans, 1 + 0LL + min(back + i - 1, x - 1) + min(front + 0LL + (len - i - 2), m - x));
        }
    }
    fin = ans;

    cout << fin << endl;
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