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
// x |= (1 << i) ===> to set the i-th bit on

void solve()
{
    int n, k;

    cin >> n >> k;

    vector<int> pref(k);

    for (int i = 0; i < k; i++)
    {
        cin >> pref[i];
    }

    if (k == 1)
    {
        cout << "Yes" << endl;

        return;
    }

    vector<ll> a(k);

    a[0] = pref[0];

    for (int i = 1; i < k; i++)
    {
        a[i] = pref[i] - pref[i - 1];
    }

    int can = a[1];

    if (n != k && (a[0] > (n - k + 1) * 1LL * a[1]))
    {
        cout << "No" << endl;

        return;
    }

    for (int i = (n == k ? 0 : 1); i < k - 1; i++)
    {
        if (a[i] > a[i + 1])
        {
            cout << "No" << endl;

            return;
        }
    }

    cout << "Yes" << endl;
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

// 3 2
// 5 5
// 2 1
// 3
// 2 1
// 2
// 4 2
// 5 1
// 2 1
// 3
// 3 3
// 2 1 0
// 4 2
// 1 3
// 2 2
// 0 4
// 1 1
// 0
// 4 2
// 3 1
// 3 3
// 1 1 0
// 2 1
// 0
// 4 4
// 0 0 0 5
// 3 1
// 0
// 4 3
// 5 3 2
// 2 2
// 1 5
// 1 1
// 5
// 1 1
// 3
// 2 1
// 3
// 3 3
// 0 3 4
// 1 1
// 1
// 1 1
// 5
// 1 1
// 4
// 2 1
// 4
// 1 1
// 4
// 1 1
// 5
// 4 3
// 4 3 3
// 4 4
// 4 3 4 2
// 2 1
// 1
// 1 1
// 0
// 2 1
// 4
// 2 2
// 4 3
// 3 3
// 2 1 5
// 2 2
// 0 1
// 3 2
// 0 2
// 3 3
// 5 0 1
// 3 3
// 0 3 5
// 2 1
// 2
// 3 2
// 0 0
// 2 2
// 0 1
// 1 1
// 0
// 1 1
// 0
// 4 4
// 3 0 5 4
// 3 3
// 3 5 1
// 4 2
// 1 0
// 1 1
// 1
// 4 2
// 4 3
// 3 3
// 0 4 1
// 1 1
// 2
// 4 3
// 2 1 2
// 3 2
// 4 2
// 1 1
// 5...

// ॥ जय श्री राम जय श्री कृष्ण ॥
