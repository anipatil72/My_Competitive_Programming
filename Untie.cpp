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

int getCharCode(char ch)
{
    if (ch == 'R')
    {
        return 0;
    }
    if (ch == 'S')
    {
        return 1;
    }
    return 2;
}

int findMinCost(vector<int> &grid, int n)
{
    int temp = 10;

    vector<vector<int>> dp(n, vector<int>(3, (int)(2e8)));

    vector<int> prev(n);

    bool check = true;

    int dess = 0;

    if (grid[0] <= 3)
    {
        dp[0][grid[0]] = 0;
    }

    for (int i = 1; i < n && check; i++)
    {
        for (int j = 0; j < 3 && check; j++)
        {
            for (int k = 0; k < 3 && check; k++)
            {
                if (j != k)
                {
                    check = true;

                    dess++;

                    if (j == grid[i])
                    {
                        dp[i][j] = min(dp[i][j], dp[i - 1][k]);

                        prev[0] = dp[i][j];
                    }
                    else
                    {
                        prev[0] = 1 + dp[i][j];
                        dp[i][j] = min(dp[i][j], dp[i - 1][k] + 1);
                    }
                }
            }
        }
    }

    prev.clear();

    check = false;

    int anss = dess;

    if (grid[0] == 0)
    {
        return min(dp[n - 1][1], dp[n - 1][2]);
    }
    else if (grid[0] == 1)
    {
        return min(dp[n - 1][0], dp[n - 1][2]);
    }
    else if (grid[0] == 2)
    {
        return min(dp[n - 1][1], dp[n - 1][0]);
    }

    return 0;
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

int myHack(string &hereby, char ch)
{
    int len = hereby.length();

    string tempor = hereby;

    unordered_map<char, int> mp;

    int count = 0;

    int temp = 10;

    tempor[0] = ch;

    mp[ch]++;

    vector<int> grid(len);

    for (int i = 0; i < hereby.length(); i++)
    {
        mp[tempor[i]]++;
        grid[i] = getCharCode(tempor[i]);

        count++;
    }

    mp[tempor[len - 1]]++;

    int maxi = max(len, count);

    int deduce = findMinCost(grid, grid.size());

    if (tempor[0] != hereby[0])
    {
        mp['a']++;

        temp--;
        deduce++;
    }

    return deduce;
}

void solve()
{
    string des;
    cin >> des;

    int n = des.length();

    int fin = min({myHack(des, 'R'), myHack(des, 'S'), myHack(des, 'P')});

    cout << fin << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int testCases = 1;
    cin >> testCases;

    for (int i = 1; i <= testCases; i++)
    {
        cout << "Case #" << i << ": ";
        solve();
    }
    return 0;
}

// ॥ जय श्री राम जय श्री कृष्ण ॥