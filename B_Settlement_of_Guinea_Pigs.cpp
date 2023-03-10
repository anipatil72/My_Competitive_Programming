// ॥ श्री गणेशाय नमः ॥

#include <bits/stdc++.h>
#include <random>
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

// -------------------Important Notes------------------- //
// ***For Interactive Problems remember to remove multi test cases condition*** //
// (int)log2(x) + 1  -> to calculate number of bits of a number
// s.erase(0, min(s.find_first_not_of('0'), s.size()-1));   //for removing leading zero's
// Remember about unique function usage
// yi=(t|xi)⊕xi
// (int index = str.find(substr, pos)) != string::npos    // for checking substring 'substr' in string 'str'
// ((x >> j) & 1) ===> to check if the j-th bit is on/off
// x |= (1 << i) ===> to set the i-th bit on

int search(int a)
{

    if (a % 2 == 0)
    {
        return a / 2;
    }

    return a / 2 + 1;
}

void solve()
{

    int n;
    cin >> n;

    vector<int> a;

    int summ = 0;

    for (int x = 0; x < n; x++)
    {
        int d;
        cin >> d;

        if (d == 1)
        {
            summ++;
        }
        else
        {
            a.push_back(summ);
            summ = 0;
        }
    }

    a.push_back(summ);

    int ans = 0;
    int sum = 0;

    for (int i = 0; i < a.size(); i++)
    {
        int index = sum > 0 ? sum - 1 : 0;

        int best = 0;

        if (sum > 0)
        {
            best = 1;
        }
        else
        {
            best = 0;
        }

        int p = search(index) + search(best);

        if (ans < p + a[i])
        {
            ans = p + a[i];
        }

        sum += a[i];
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

    cin >> t;

    for (ll i = 0; i < t; i++)
    {
        solve();
    }

    return 0;
}
