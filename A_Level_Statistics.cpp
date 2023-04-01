// ॥ श्री गणेशाय नमः ॥

#include <bits/stdc++.h>
#include <random>
#include <complex>
#include <tuple>
#include <functional>
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
    int n;

    cin >> n;

    vector<pair<int, int>> p;

    for (int i = 0; i < n; i++)
    {
        int c, d;

        cin >> c >> d;

        p.push_back({c, d});
    }

    for (int i = 0; i < n; i++)
    {

        if (i == 0)
        {
            if (p[i].first < p[i].second)
            {
                cout << "NO" << endl;

                return;
            }
        }
        else
        {
            if (p[i].first < p[i].second)
            {
                cout << "NO" << endl;

                return;
            }

            if ((p[i].first < p[i - 1].first) || (p[i].second < p[i - 1].second))
            {
                cout << "NO" << endl;

                return;
            }

            if ((p[i].second - p[i - 1].second) > (p[i].first - p[i - 1].first))
            {

                cout << "NO" << endl;

                return;
            }
        }
    }

    cout << "YES" << endl;
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

// 500
// 1
// 0 0
// 1
// 0 1
// 1
// 1 0
// 1
// 1 1
// 1
// 1 2
// 2
// 0 0
// 0 0
// 2
// 0 0
// 0 1
// 2
// 0 0
// 1 0
// 2
// 0 0
// 1 1
// 2
// 0 0
// 1 2
// 2
// 0 1
// 0 0
// 2
// 0 1
// 0 1
// 2
// 0 1
// 0 2
// 2
// 0 1
// 1 0
// 2
// 0 1
// 1 1
// 2
// 0 1
// 1 2
// 2
// 0 1
// 2 0
// 2
// 0 1
// 2 1
// 2
// 0 1
// 2 2
// 2
// 0 1
// 2 3
// 2
// 1 0
// 0 0
// 2
// 1 0
// 0 1
// 2
// 1 0
// 1 0
// 2
// 1 0
// 1 1
// 2
// 1 0
// 1 2
// 2
// 1 1
// 0 0
// 2
// 1 1
// 0 1
// 2
// 1 1
// 0 2
// 2
// 1 1
// 1 0
// 2
// 1 1
// 1 1
// 2
// 1 1
// 1 2
// 2
// 1 1
// 2 0
// 2
// 1 1
// 2 1
// 2
// 1 1
// 2 2
// 2
// 1 1
// 2 3
// 2
// 1 2
// 0 0
// 2
// 1 2
// 0 1
// 2
// 1 2
// 0 2
// 2
// 1 2
// 0 3
// 2
// 1 2
// 1 0
// 2
// 1 2
// 1 1...

// ॥ जय श्री राम जय श्री कृष्ण ॥