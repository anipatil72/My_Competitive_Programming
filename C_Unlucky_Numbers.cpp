// ॥ श्री गणेशाय नमः ॥

#include <bits/stdc++.h>
#include <random>
#include <complex>
#include <tuple>
#include <functional>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
#include <cstdint>
#include <ctime>
#include <cassert>
#include <complex>
#include <string>
#include <cstring>
#include <chrono>
using namespace std;
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

string resNum;
int diff;                  // minimise the diff.... minimum diff is definitely 0
bool dp[10][10][19][2][2]; // mx,mn,idx,tight
// vector<vector<vector<vector<vector<bool>>>>> dp(11,vector<vector<vector<vecor<int>>>>(11,vector<vector<vector<int>>>))
void rec(int idx, string curr, string beg, string lim, int mx, int mn, bool greaterThanBeg, bool smallerThanMx)
{
    // cout<<idx<<" "<<curr<<" "<<beg<<" "<<lim<<" "<<greaterThanBeg<<" "<<smallerThanMx<<"\n";
    if (idx == beg.size())
    {
        if (diff > (mx - mn))
        {
            diff = mx - mn, resNum = curr;
        }
        return;
    }
    if (dp[mx][mn][idx][greaterThanBeg][smallerThanMx] == 1)
    {
        return;
    }

    dp[mx][mn][idx][greaterThanBeg][smallerThanMx] = 1;

    if (!greaterThanBeg && !smallerThanMx)
    { // can only use from beg to lim...
        char org = curr[idx];
        for (int i = beg[idx] - '0'; i <= lim[idx] - '0'; i++)
        {
            curr[idx] = (char)('0' + i);
            // cout<<"char: "<<curr[idx]<<"\n";
            rec(idx + 1, curr, beg, lim, mx > i ? mx : i, mn < i ? mn : i, (greaterThanBeg || (i > (beg[idx] - '0'))), (smallerThanMx || ((i < (lim[idx] - '0')))));
        }
        curr[idx] = org;
    }
    else if (greaterThanBeg && !smallerThanMx)
    {
        char org = curr[idx];
        for (int i = 0; i <= lim[idx] - '0'; i++)
        {
            curr[idx] = '0' + i;
            // cout<<"char2: "<<curr[idx]<<"\n";
            rec(idx + 1, curr, beg, lim, mx > i ? mx : i, mn < i ? mn : i, 1, curr[idx] < lim[idx]);
        }
        curr[idx] = org;
    }
    else if (!greaterThanBeg && smallerThanMx)
    {
        char org = curr[idx];
        for (int i = beg[idx] - '0'; i <= 9; i++)
        {
            curr[idx] = '0' + i;
            // cout<<"char3: "<<curr[idx]<<"\n";
            rec(idx + 1, curr, beg, lim, mx > i ? mx : i, mn < i ? mn : i, curr[idx] > beg[idx], 1);
        }
        curr[idx] = org;
    }
    else
    {
        char org = curr[idx];
        for (int i = 0; i <= 9; i++)
        {
            curr[idx] = '0' + i;
            // cout<<"char4: "<<curr[idx]<<"\n";
            rec(idx + 1, curr, beg, lim, mx > i ? mx : i, mn < i ? mn : i, 1, 1);
        }

        curr[idx] = org;
    }
}

void solve()
{
    int n = 1, m = 0;
    string a, b;
    cin >> a >> b;
    if (a.size() != b.size())
    {
        for (int i = 0; i < a.size(); i++)
        {
            cout << "9";
        } // all 99s.. ans ->0
        cout << "\n";
        return;
    }
    memset(dp, 0, sizeof dp);
    diff = 10;
    string curr = a;
    resNum = a;
    rec(0, curr, a, b, 0, 9, 0, 0);
    cout << resNum << "\n";
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