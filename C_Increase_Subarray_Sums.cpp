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

ll maxSubArraySum(vector<int> &a)
{
    int size = a.size();
    ll max_so_far = LLONG_MIN, max_ending_here = 0;

    for (int i = 0; i < size; i++)
    {
        max_ending_here = max_ending_here + a[i];
        if (max_so_far < max_ending_here)
        {
            max_so_far = max_ending_here;
        }
        if (max_ending_here < 0)
        {
            max_ending_here = 0;
        }
    }

    return max_so_far;
}

template <typename T_vector>
void output_vector(const T_vector &v, bool add_one = false, int start = -1, int end = -1)
{
    if (start < 0)
    {
        start = 0;
    }
    if (end < 0)
    {
        end = int(v.size());
    }

    for (int i = start; i < end; i++)
    {
        cout << v[i] + (add_one ? 1 : 0) << (i < end - 1 ? ' ' : '\n');
    }
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

void solve()
{
    int n, x;

    cin >> n >> x;

    vector<int> a(n);

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    vector<ll> pref(n + 1);

    for (int i = 1; i <= n; i++)
    {
        int j = 0;

        ll temp = LLONG_MIN;

        ll tem = 0;

        while (j < i)
        {
            tem += a[j];

            j++;
        }

        temp = max(temp, tem);

        while (j < n)
        {
            tem += (a[j]);

            tem -= (a[j - i]);

            temp = max(temp, tem);
            j++;
        }

        pref[i] = max(0LL, temp) + i * x;
    }

    pref[0] = max(pref[n], 0LL) - n * x;

    output_vector(pref);
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