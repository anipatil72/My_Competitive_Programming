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

// returns set of all divisors of a natural number

vector<int> getDivisors(int n)
{

    set<int> s;

    // Note that this loop runs till square root
    for (int i = 1; i <= sqrt(n); i++)
    {
        if (n % i == 0)
        {
            // If divisors are equal, print only one
            if (n / i == i)
            {

                s.insert(i);
            }
            else
            { // Otherwise print both

                s.insert(i);
                s.insert(n / i);
            }
        }
    }

    vector<int> ans(s.begin(), s.end());

    return ans;
}

void printvector(vector<int> &a)
{

    int n = a.size();

    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }

    cout << endl;
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
    int n, x;

    cin >> n >> x;

    if (n % x != 0)
    {
        cout << -1 << endl;

        return;
    }

    vector<int> a(n);

    for (int i = 0; i < n; i++)
    {
        a[i] = 1 + i;
    }

    a[0] = x;

    a[n - 1] = 1;

    if (x != n)
    {
        a[x - 1] = n;
    }

    vector<int> divi = getDivisors(n);

    auto it = lower_bound(divi.begin(), divi.end(), x);

    int pos = it - divi.begin();

    int sz = divi.size();

    int tem = pos + 1;

    ll temp = divi[tem];

    while (tem < sz - 1)
    {
        swap(a[pos], a[temp]);

        pos = temp;

        temp = divi[tem];

        tem++;
    }

    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }

    cout << endl;
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