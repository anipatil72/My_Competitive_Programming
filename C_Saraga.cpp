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

// http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2016/p0200r0.html
template <class Fun>
class y_combinator_result
{
    Fun fun_;

public:
    template <class T>
    explicit y_combinator_result(T &&fun) : fun_(std::forward<T>(fun)) {}
    template <class... Args>
    decltype(auto) operator()(Args &&...args) { return fun_(std::ref(*this), std::forward<Args>(args)...); }
};
template <class Fun>
decltype(auto) y_combinator(Fun &&fun) { return y_combinator_result<std::decay_t<Fun>>(std::forward<Fun>(fun)); }

template <typename A, typename B>
ostream &operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << "," << p.second << ')'; }
template <typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type>
ostream &operator<<(ostream &os, const T_container &v)
{
    os << '{';
    string sep;
    for (const T &x : v)
        os << sep << x, sep = ", ";
    return os << '}';
}

void dbg_out() { cerr << endl; }
template <typename Head, typename... Tail>
void dbg_out(Head H, Tail... T)
{
    cerr << ' ' << H;
    dbg_out(T...);
}
#define dbg(...) cerr << '[' << __FILE__ << ':' << __LINE__ << "] (" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)

// -------------------Important Notes------------------- //
// **For Interactive Problems remember to remove multi test cases condition** //
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
    string a, b;

    cin >> a >> b;

    int na = a.length();

    int nb = b.length();

    vector<int> dash_a(26, -1);
    vector<int> dash_b(26, -1);

    for (int i = 1; i < na; i++)
    {
        if (dash_a[a[i] - 'a'] == -1)
        {
            dash_a[a[i] - 'a'] = i;
        }
    }

    // Anyway it doesn't matter. This is all very standard nothing out of the ordinary.

    for (int i = nb - 2; i >= 0; i--)
    {
        if (dash_b[b[i] - 'a'] == -1)
        {
            dash_b[b[i] - 'a'] = i;
        }
    }

    int len = na + nb + 2;
    int index_a = -1, index_b = -1;

    for (int i = 1; i < na; i++)
    {
        if (dash_b[a[i] - 'a'] != -1)
        {
            if (len > (i + nb - dash_b[a[i] - 'a']))
            {
                index_a = i;
                index_b = dash_b[a[i] - 'a'];

                len = (i + nb - dash_b[a[i] - 'a']);
            }
        }
    }

    for (int i = nb - 2; i >= 0; i--)
    {
        if (dash_a[b[i] - 'a'] != -1)
        {
            if (len > (dash_a[b[i] - 'a'] + nb - i))
            {
                index_b = i;
                index_a = dash_a[a[i] - 'a'];

                len = (dash_a[b[i] - 'a'] + nb - i);
            }
        }
    }

    if (index_a == -1 || index_b == -1)
    {
        cout << "-1" << endl;
        return;
    }

    string ans = "";

    for (int i = 0; i < index_a; i++)
    {
        ans += a[i];
    }

    for (int i = index_b; i < nb; i++)
    {
        ans += b[i];
    }

    cout << ans << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);

    ll t = 1;

    // cin >> t;

    for (ll i = 0; i < t; i++)
    {
        solve();
    }

    return 0;
}

// ॥ जय श्री राम जय श्री कृष्ण ॥