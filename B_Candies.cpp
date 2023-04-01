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
// log2(n&(-n)) returns a number in which only the rightmost bit is set in n
// alternatively ffs(n) also gives the index of the rightmeost set bit
// x |= (1 << i) ===> to set the i-th bit on

vector<int> recur(ll now, vector<int> spell, int count)
{
    if (count > 40)
    {
        return {};
    }

    if (now == 1)
    {

        return spell;
    }

    if (now % 2 == 0)
    {
        return {};
    }

    vector<int> tem1 = spell;

    tem1.push_back(1);

    vector<int> ans1 = recur((now + 1) / 2, tem1, count + 1);

    vector<int> tem2 = spell;

    tem2.push_back(2);

    vector<int> ans2 = recur((now - 1) / 2, tem2, count + 1);

    if (ans1.size() == 0 && ans2.size() == 0)
    {
        return {};
    }

    if (ans1.size() != 0)
    {
        return ans1;
    }

    return ans2;
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

void solve()
{

    int n;

    cin >> n;

    ll now = n;

    vector<int> ans = recur(now, {}, 0);

    if (ans.size() == 0)
    {

        cout << "-1" << endl;
    }
    else
    {
        cout << ans.size() << endl;

        reverse(ans.begin(), ans.end());

        printvector(ans);
    }
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