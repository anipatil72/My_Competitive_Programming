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
#define ull unsigned long long
#define uint unsigned int
#define lld long double

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

ll check(ll b, ll a, int minus)
{
    double anss = sqrt(a);

    long double ans = (long double)b + (1.0 * minus) * anss;

    if ((ll)(ans)-ans == 0.0)
    {
        return (ll)ans;
    }

    if (ans < 0)
    {
        return ((ll)ans) - 1;
    }

    return ((ll)(ans)) + 1;
}

void solve()
{
    // int n, m;

    // cin >> n >> m;

    // vector<int> slopes(n);

    // for (int i = 0; i < n; i++)
    // {

    //     cin >> slopes[i];
    // }

    // sort(slopes.begin(), slopes.end());

    // for (int i = 0; i < m; i++)
    // {
    //     ll a, b, c;

    //     cin >> a >> b >> c;

    //     if (a * c <= 0)
    //     {
    //         cout << "NO" << endl;

    //         continue;
    //     }

    int n, m;
    cin >> n >> m;
    vector<lld> slopes;
    for (int i = 0; i < n; i++)
    {
        lld x;
        cin >> x;
        slopes.push_back(x);
    }

    sort(slopes.begin(), slopes.end());

    for (int j = 0; j < m; j++)
    {
        lld a, b, c;
        cin >> a >> b >> c;
        lld val = b - 2.0 * sqrtl(a * c);
        lld val2 = b + 2.0 * sqrtl(a * c);
        auto itr = (int)(upper_bound(slopes.begin(), slopes.end(), val) - slopes.begin());
        if (itr == (int)(slopes.size()))
        {
            cout << "NO" << endl;
            continue;
        }
        lld value = slopes[itr];
        // debug(val)
        // debug(val2)
        if (value > val and value < val2)
        {
            cout << "YES" << endl;
            cout << (int)(slopes[itr]) << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }

    //     ll left = check(b, 4 * a * c, -1);

    //     ll right = check(b, 4 * a * c, 1);

    //     ll mini = min(left, right);
    //     ll maxi = max(left, right);

    //     auto lef = upper_bound(slopes.begin(), slopes.end(), mini);
    //     auto rig = lower_bound(slopes.begin(), slopes.end(), maxi);

    //     if (lef == rig)
    //     {
    //         cout << "NO" << endl;
    //     }
    //     else if (lef == slopes.end())
    //     {
    //         cout << "NO" << endl;
    //     }
    //     else
    //     {

    //         if (rig - lef >= 1)
    //         {

    //             cout << "YES" << endl;
    //             cout << (*lef) << endl;
    //         }
    //         else
    //         {
    //             cout << "NO" << endl;
    //         }
    //     }
    // }
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

    // double ans = sqrt(113);

    // ll an = (ll)(2.4);

    // cout << (((ll)ans - ans) < 0.0) << endl;

    return 0;
}

// ॥ जय श्री राम जय श्री कृष्ण ॥