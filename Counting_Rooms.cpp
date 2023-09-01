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
bool isValid(int row, int col, int n, int m)
{
    if (row >= 0 && row < n && col >= 0 && col < m)
    {
        return true;
    }

    return false;
}

void recur(int row, int col, vector<vector<int>> &mat, vector<vector<int>> &vis)
{
    int n = mat.size();

    int m = mat[0].size();

    vis[row][col] = 0;

    // cout << "Row : " << row << " and Col : " << col << endl;

    if (isValid(row - 1, col, n, m) && mat[row - 1][col] == 1 && vis[row - 1][col] == 1)
    {
        recur(row - 1, col, mat, vis);
    }

    if (isValid(row + 1, col, n, m) && mat[row + 1][col] == 1 && vis[row + 1][col] == 1)
    {
        recur(row + 1, col, mat, vis);
    }

    if (isValid(row, col - 1, n, m) && mat[row][col - 1] == 1 && vis[row][col - 1] == 1)
    {
        recur(row, col - 1, mat, vis);
    }

    if (isValid(row, col + 1, n, m) && mat[row][col + 1] == 1 && vis[row][col + 1] == 1)
    {
        recur(row, col + 1, mat, vis);
    }
}

void solve()
{
    int n, m;

    cin >> n >> m;

    vector<vector<int>> mat(n, vector<int>(m, 0));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            char s;

            cin >> s;

            mat[i][j] = (s == '.');
        }
    }

    // cout << "This is Matrix : " << endl;

    // for (int i = 0; i < n; i++)
    // {
    //     for (int j = 0; j < m; j++)
    //     {
    //         cout << mat[i][j];
    //     }
    //     cout << endl;
    // }

    // cout << endl;

    vector<vector<int>> vis(n, vector<int>(m, 1));

    int ans = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (mat[i][j] == 1 && vis[i][j] == 1)
            {
                recur(i, j, mat, vis);

                // cout << ans << endl;

                ans++;
            }
        }
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