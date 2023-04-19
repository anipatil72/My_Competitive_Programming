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

// int LCSubStr(string s, string t, int n, int m)
// {

//     // Create DP table
//     int dp[2][m + 1];
//     int res = 0;

//     for (int i = 1; i <= n; i++)
//     {
//         for (int j = 1; j <= m; j++)
//         {
//             if (s[i - 1] == t[j - 1])
//             {
//                 dp[i % 2][j] = dp[(i - 1) % 2][j - 1] + 1;
//                 if (dp[i % 2][j] > res)
//                     res = dp[i % 2][j];
//             }
//             else
//                 dp[i % 2][j] = 0;
//         }
//     }
//     return res;
// }

int longestCommonSubstringLength(string s1, string s2, int i, int j, int maxLen, vector<vector<vector<int>>> &dp)
{
    if (i <= 0 || j <= 0)
    {
        return maxLen;
    }

    if (dp[i][j][maxLen] != -1)
    {
        return dp[i][j][maxLen];
    }

    int maxLen1 = maxLen;
    if (s1[i - 1] == s2[j - 1])
    {
        maxLen1 = longestCommonSubstringLength(s1, s2, i - 1, j - 1, maxLen + 1, dp);
    }

    int maxLen2 = longestCommonSubstringLength(s1, s2, i, j - 1, 0, dp);
    int maxLen3 = longestCommonSubstringLength(s1, s2, i - 1, j, 0, dp);

    return dp[i][j][maxLen] = max(maxLen1, max(maxLen2, maxLen3));
}

// int main()
// {
//     string s1 = "qdef";
//     string s2 = "defq";

//     int n1 = s1.length();
//     int n2 = s2.length();

//     int maxLen = 0;

//     cout << "The length of the longest common substring of s1 and s2 is " << longestCommonSubstringLength(s1, s2, n1, n2, maxLen) << endl;

//     return 0;
// }

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
    string a, b;
    // int dp[100][100][100];

    vector<vector<vector<int>>> dp(100, vector<vector<int>>(100, vector<int>(100, -1)));

    cin >> a;

    cin >> b;

    // memset(dp, -1, sizeof(dp));
    int na = a.length();

    int nb = b.length();

    int ans = na + nb - 2 * longestCommonSubstringLength(a, b, na, nb, 0, dp);

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