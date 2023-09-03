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

bool isEdge(int row, int col, int n, int m)
{
    if (row == 0 || col == 0 || row == n - 1 || col == m - 1)
    {
        return true;
    }

    return false;
}

bool isValid(int row, int col, int n, int m)
{
    if (row >= 0 && row < n && col >= 0 && col < m)
    {
        return true;
    }

    return false;
}

void solve()
{
    int n, m;

    cin >> n >> m;

    vector<vector<int>> mat(n, vector<int>(m, 0));
    vector<vector<int>> vis(n, vector<int>(m, -1));

    queue<vector<int>> q;

    vector<int> man;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            char d;

            cin >> d;

            if (d == '#')
            {
                mat[i][j] = 1;
            }
            else if (d == '.')
            {

                mat[i][j] = 0;
            }
            else if (d == 'M')
            {
                q.push({i, j, 0});
                mat[i][j] = 0;

                vis[i][j] = 0;
            }
            else
            {
                mat[i][j] = 0;

                man.push_back(i);
                man.push_back(j);
            }
        }
    }

    while (!q.empty())
    {
        vector<int> des = q.front();

        q.pop();

        int row = des[0], col = des[1];

        vis[des[0]][des[1]] = des[2];

        if (isValid(row - 1, col, n, m) && mat[row - 1][col] == 0 && vis[row - 1][col] == -1)
        {
            q.push({row - 1, col, des[2] + 1});
        }

        if (isValid(row + 1, col, n, m) && mat[row + 1][col] == 0 && vis[row + 1][col] == -1)
        {
            q.push({row + 1, col, des[2] + 1});
        }

        if (isValid(row, col - 1, n, m) && mat[row][col - 1] == 0 && vis[row][col - 1] == -1)
        {
            q.push({row, col - 1, des[2] + 1});
        }

        if (isValid(row, col + 1, n, m) && mat[row][col + 1] == 0 && vis[row][col + 1] == -1)
        {
            q.push({row, col + 1, des[2] + 1});
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (vis[i][j] == -1)
            {
                vis[i][j] = 1e8;
            }
        }
    }

    queue<pair<vector<int>, string>> fin;

    fin.push({{man[0], man[1], 0}, ""});

    while (!fin.empty())
    {
        auto tem = fin.front();

        int row = tem.first[0], col = tem.first[1], dist = tem.first[2];

        string cur = tem.second;

        fin.pop();

        if (isEdge(row, col, n, m))
        {
            cout << "YES" << endl;

            cout << cur.length() << endl;

            cout << cur << endl;

            return;
        }

        if (isValid(row - 1, col, n, m) && mat[row - 1][col] == 0 && vis[row - 1][col] > dist + 1)
        {
            // q.push({row - 1, col, des[2] + 1});

            fin.push({{row - 1, col, dist + 1}, cur + 'U'});
        }

        if (isValid(row + 1, col, n, m) && mat[row + 1][col] == 0 && vis[row + 1][col] > dist + 1)
        {
            // q.push({row + 1, col, des[2] + 1});

            fin.push({{row + 1, col, dist + 1}, cur + 'D'});
        }

        if (isValid(row, col - 1, n, m) && mat[row][col - 1] == 0 && vis[row][col - 1] > dist + 1)
        {
            // q.push({row, col - 1, des[2] + 1});

            fin.push({{row, col - 1, dist + 1}, cur + 'L'});
        }

        if (isValid(row, col + 1, n, m) && mat[row][col + 1] == 0 && vis[row][col + 1] > dist + 1)
        {
            // q.push({row, col + 1, des[2] + 1});

            fin.push({{row, col + 1, dist + 1}, cur + 'R'});
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

    // cin >> t;

    for (ll i = 0; i < t; i++)
    {
        solve();
    }

    return 0;
}

// ॥ जय श्री राम जय श्री कृष्ण ॥