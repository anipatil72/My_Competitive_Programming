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

// template <typename typC, typename typD>
// istream &operator>>(istream &cin, pair<typC, typD> &a)
// {
//     return cin >> a.first >> a.second;
// }
// template <typename typC>
// istream &operator>>(istream &cin, vector<typC> &a)
// {
//     for (auto &x : a)
//         cin >> x;
//     return cin;
// }
// template <typename typC, typename typD>
// ostream &operator<<(ostream &cout, const pair<typC, typD> &a) { return cout << a.first << ' ' << a.second; }
// template <typename typC, typename typD>
// ostream &operator<<(ostream &cout, const vector<pair<typC, typD>> &a)
// {
//     for (auto &x : a)
//         cout << x << '\n';
//     return cout;
// }
// template <typename typC>
// ostream &operator<<(ostream &cout, const vector<typC> &a)
// {
//     int n = a.size();
//     if (!n)
//         return cout;
//     cout << a[0];
//     for (int i = 1; i < n; i++)
//         cout << ' ' << a[i];
//     return cout;
// }

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
#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)

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

bool myCompfora(pair<string, vector<int>> &a, pair<string, vector<int>> &b)
{
    long double af = ((1.0 * a.second[0]) / a.first.length());
    long double bf = ((1.0 * b.second[0]) / b.first.length());

    return af > bf;
}
bool myCompforb(pair<string, vector<int>> &a, pair<string, vector<int>> &b)
{
    long double af = ((1.0 * a.second[1]) / a.first.length());
    long double bf = ((1.0 * b.second[1]) / b.first.length());

    return af > bf;
}
bool myCompforc(pair<string, vector<int>> &a, pair<string, vector<int>> &b)
{
    long double af = ((1.0 * a.second[2]) / a.first.length());
    long double bf = ((1.0 * b.second[2]) / b.first.length());

    return af > bf;
}
bool myCompford(pair<string, vector<int>> &a, pair<string, vector<int>> &b)
{
    long double af = ((1.0 * a.second[3]) / a.first.length());
    long double bf = ((1.0 * b.second[3]) / b.first.length());

    return af > bf;
}
bool myCompfore(pair<string, vector<int>> &a, pair<string, vector<int>> &b)
{
    long double af = ((1.0 * a.second[4]) / a.first.length());
    long double bf = ((1.0 * b.second[4]) / b.first.length());

    return af > bf;
}

void solve()
{
    int n;

    cin >> n;

    vector<string> a(n);

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    vector<pair<string, vector<int>>> ca(n);

    for (int i = 0; i < n; i++)
    {
        string tem = a[i];

        vector<int> freq(5, 0);

        for (int j = 0; j < tem.length(); j++)
        {
            freq[tem[j] - 'a']++;
        }

        ca[i] = {tem, freq};
    }

    int ans = 0;

    sort(ca.begin(), ca.end(), myCompfora);

    // dbg(ca);

    int temp = 0;

    int tot = 0;

    int tota = 0;

    for (int i = 0; i < n; i++)
    {

        tot += ca[i].first.length();

        tota += ca[i].second[0];

        if ((tota > (tot - tota)))
        {
            temp++;

            ans = max(ans, temp);
            // dbg(temp, tot, tota, ans);
        }
        else
        {

            tot -= ca[i].first.length();

            tota -= ca[i].second[0];

            // break;
        }
    }

    // for b

    sort(ca.begin(), ca.end(), myCompforb);
    // dbg(ca);

    temp = 0, tot = 0, tota = 0;

    for (int i = 0; i < n; i++)
    {

        tot += ca[i].first.length();

        tota += ca[i].second[1];

        if ((tota > (tot - tota)))
        {
            temp++;

            ans = max(ans, temp);
            // dbg(temp, tot, tota, ans);
        }
        else
        {

            tot -= ca[i].first.length();

            tota -= ca[i].second[1];

            // break;
        }
    }

    // for c

    sort(ca.begin(), ca.end(), myCompforc);

    // dbg(ca);

    temp = 0, tot = 0, tota = 0;

    for (int i = 0; i < n; i++)
    {

        tot += ca[i].first.length();

        tota += ca[i].second[2];

        if ((tota > (tot - tota)))
        {
            temp++;

            ans = max(ans, temp);
            // dbg(temp, tot, tota, ans);
        }
        else
        {

            tot -= ca[i].first.length();

            tota -= ca[i].second[2];
            // break;
        }
    }

    // for d

    sort(ca.begin(), ca.end(), myCompford);
    // dbg(ca);

    temp = 0, tot = 0, tota = 0;

    for (int i = 0; i < n; i++)
    {

        tot += ca[i].first.length();

        tota += ca[i].second[3];

        if ((tota > (tot - tota)))
        {
            temp++;

            ans = max(ans, temp);
            // dbg(temp, tot, tota, ans);
        }
        else
        {

            tot -= ca[i].first.length();

            tota -= ca[i].second[3];
            // break;
        }
    }

    // for e

    sort(ca.begin(), ca.end(), myCompfore);
    // dbg(ca);

    temp = 0, tot = 0, tota = 0;

    for (int i = 0; i < n; i++)
    {

        tot += ca[i].first.length();
        tota += ca[i].second[4];

        ans = max(ans, temp);

        if (tot == 0 || (tota > (tot - tota)))
        {
            temp++;

            // tota += ca[i].second[4];
            // dbg(temp, tot, tota, ans);
        }
        else
        {

            tot -= ca[i].first.length();
            tota -= ca[i].second[4];
            // break;
        }
    }

    // cout << "The ans is : ";
    cout << ans << endl;
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