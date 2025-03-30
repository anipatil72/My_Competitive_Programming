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
// alternatively ffs(n) also gives the index of the rightmeost set bit
// x |= (1 << i) ===> to set the i-th bit on

void solve()
{
    int n;

    cin >> n;

    unordered_map<int, int> freq;

    for (int i = 0; i < n; i++)
    {
        int tt;

        cin >> tt;

        freq[tt]++;
    }

    unordered_map<int, vector<int>> count;

    for (auto it : freq)
    {
        count[it.second].push_back(it.first);
    }

    // 2 2 2 2
    if (count.count(2))
    {
        if (count[2].size() >= 4)
        {
            cout << "YES" << endl;

            int len = count[2].size();

            sort(count[2].begin(), count[2].end());

            ll one = count[2][0];
            ll two = count[2][1];
            ll three = count[2][len - 2];
            ll four = count[2][len - 1];

            int one_diff = three - one;
            int two_diff = four - two;

            int three_diff = four - one;
            int four_diff = three - two;

            if (one_diff * two_diff > three_diff * four_diff)
            {
                cout << one << " " << two << " ";
                cout << one << " " << four << " ";
                cout << three << " " << two << " ";
                cout << three << " " << four << " ";
            }
            else
            {
                cout << one << " " << three << " ";
                cout << one << " " << two << " ";
                cout << four << " " << three << " ";
                cout << four << " " << two << " ";
            }

            cout << endl;

            return;
        }
    }

    // 4 2 2

    if (count.count(4) && count.count(2))
    {
        if (count[4].size() >= 1 && count[2].size() >= 2)
        {
            cout << "YES" << endl;

            for (int i = 0; i < 2; i++)
            {
                cout << count[4][0] << " " << count[2][0] << " ";
            }

            for (int i = 0; i < 2; i++)
            {
                cout << count[4][0] << " " << count[2][1] << " ";
            }

            cout << endl;

            return;
        }
    }

    // 6 2

    if (count.count(6) && count.count(2))
    {
        if (count[6].size() >= 1 && count[2].size() >= 1)
        {
            cout << "YES" << endl;

            for (int j = 0; j < 3; j++)
            {
                cout << count[6][0] << " ";
            }

            for (int j = 0; j < 1; j++)
            {
                cout << count[2][0] << " ";
            }

            for (int j = 0; j < 3; j++)
            {
                cout << count[6][0] << " ";
            }

            for (int j = 0; j < 1; j++)
            {
                cout << count[2][0] << " ";
            }

            cout << endl;

            return;
        }
    }

    // 8
    if (count.count(8))
    {
        if (count[8].size() >= 1)
        {
            cout << "YES" << endl;

            for (int j = 0; j < 8; j++)
            {
                cout << count[8][0] << " ";
            }

            cout << endl;
            return;
        }
    }

    cout << "NO" << endl;
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