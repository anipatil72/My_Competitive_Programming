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
    int n;

    cin >> n;

    int tie = (n % 2 == 0);

    int reqwin = (n % 2 == 0 ? (n - 2) / 2 : (n - 1) / 2);
    int reqlos = (n % 2 == 0 ? (n - 2) / 2 : (n - 1) / 2);

    vector<int> curwins(n, reqwin);
    vector<int> curlos(n, reqlos);

    vector<int> curtie(n, tie);

    vector<vector<int>> res(n, vector<int>(n, 21));

    for (int i = 0; i < n; i++)
    {

        int now = i + 1;

        while (now < n)
        {
            if (curtie[i] > 0 && curtie[now] > 0)
            {
                cout << 0 << " ";

                curtie[i]--;

                curtie[now]--;
            }
            else if (curwins[i] > 0 && curlos[now] > 0)
            {

                cout << 1 << " ";

                curwins[i]--;

                curlos[now]--;
            }
            else
            {

                cout << -1 << " ";

                curlos[i]--;

                curwins[now]--;
            }

            now++;
        }

        // cout << endl;
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