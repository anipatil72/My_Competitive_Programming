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

    map<pair<int, int>, int> m;

    vector<int> single(26, 0);

    for (int i = 0; i < n; i++)
    {
        string s;

        cin >> s;

        int len = s.length();

        map<int, int> test;

        for (int j = 0; j < len; j++)
        {

            test[s[j] - 'a']++;
        }

        if (test.size() == 1)
        {
            auto it = test.begin();

            single[it->first] += it->second;
        }
        else if (test.size() == 2)
        {
            auto it = test.begin();

            auto itr = it;

            itr++;

            pair<int, int> pes = {it->first, itr->first};

            // if (pes.first > pes.second)
            // {

            //     int tem = pes.second;

            //     pes.second = pes.first;

            //     pes.first = tem;
            // }

            m[pes] += len;
        }
    }

    int ans = 0;

    for (int i = 0; i < 26; i++)
    {
        ans = max(single[i], ans);
    }

    for (auto x : m)
    {
        ans = max(ans, x.second + single[x.first.first] + single[x.first.second]);


    }

    for (int i = 0; i < 26; i++)
    {
        for (int j = i + 1; j < 26; j++)
        {

            ans = max(ans, single[i] + single[j]);
                
        }
        
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

    // cin >> t;

    for (ll i = 0; i < t; i++)
    {
        solve();
    }

    return 0;
}

// ॥ जय श्री राम जय श्री कृष्ण ॥