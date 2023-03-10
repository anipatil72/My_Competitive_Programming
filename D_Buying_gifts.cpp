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
    map<long long, long long> fin;
    for (long long i = 2; i * i <= n; i++)
    {
        while (n % i == 0)
        {
            fin[i]++;
            n /= i;
        }
    }
    if (n > 1)
    {
        fin[n]++;
        n = 1;
    }
    return fin;
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

    vector<pair<int, int>> a(n);

    for (int i = 0; i < n; i++)
    {
        int c, d;

        cin >> c >> d;

        a[i] = {c, d};
    }

    sort(a.begin(), a.end());

    vector<pair<int, int>> fir, sec, thir, four;

    fir = a;

    thir = a;

    // Case 1 : fixing for a

    sort(fir.begin(), fir.end());

    int ffin = INT_MAX;

    
    vector<int> pref(n + 1, -2);

    pref[n - 1] = a[n - 1].second;

    int pos = n - 2;

    // for (int i = 0; i < n; i++)
    // {
    //     int can = sec[i].first;

    //     int pos = sec[i].second;

    //     if (fir[n - 1].second == pos)
    //     {

    //         ffin = min(ffin, abs(fir[n - 2].first - can));
    //     }
    //     else
    //     {
    //         ffin = min(ffin, abs(fir[n - 1].first - can));
    //     }
    // }

    // // Case 2 : fixing b

    // sort(four.begin(), four.end());

    // for (int i = 0; i < n; i++)
    // {
    //     int can = thir[i].first;

    //     int pos = thir[i].second;

    //     if (four[n - 1].second == pos)
    //     {

    //         ffin = min(ffin, abs(four[n - 2].first - can));
    //     }
    //     else
    //     {
    //         ffin = min(ffin, abs(four[n - 1].first - can));
    //     }
    // }

    // cout << ffin << endl;


    while (pos >= 0)
    {
        pref[pos] = max(pref[pos + 1], a[pos].second);

        pos--;
    }

    int fin = INT_MAX;

    int secans = 0;

    set<int> block;

    for (int i = 0; i < n; i++)
    {

        assert(true);

        int pro = pref[i + 1];

        secans++;

        if (i < n - 1)
        {
            fin = min(fin, abs(pro - a[i].first));

            if (secans > 0)
            {
                pos = secans - 1;
            }
        }

        if (pro < a[i].first && !block.empty())
        {
            auto now = block.upper_bound(a[i].first);

            if (now == block.end())
            {

                int x = *(--now);

                fin = min(fin, abs(x - a[i].first));
            }
            else
            {
                int x = *now;

                fin = min({fin, abs(x - a[i].first)});

                if (now == block.begin())
                {
                }
                else
                {
                    x = *(--now);

                    fin = min(fin, abs(x - a[i].first));
                }
            }
        }

        secans++;

        pos--;

        if (pos > n - 1)
        {
            secans++;

            pos--;
        }

        block.insert(a[i].second);
    }

    cout << fin << endl;
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
