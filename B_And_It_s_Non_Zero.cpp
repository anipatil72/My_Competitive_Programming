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

    int left, right;

    cin >> left >> right;

    int ans = INT_MIN;

    int leftset;

    for (int i = 0; i < 32; i++)
    {
        if ((left & (1 << i)))
        {
            leftset = i;
        }
    }

    leftset++;

    int can1 = (1 << leftset);

    can1 = min(can1, right);

    int rightset;

    for (int i = 0; i < 32; i++)
    {
        if ((right & (1 << i)))
        {
            rightset = i;
        }
    }

    int can2 = (1 << rightset);
    int tem = max(left, can2 / 2);

    can2 = max(can2, left);

    // int ans = max({
    //     can1 - left,
    //     can2 - (tem&(tem-1)==0? tem - 1:tem) ,
    //     right - (can2&(can2-1)==0? can2 - 1 : can2)
    // });

    // cout << "Left : " << left << endl;
    // cout << "Right : " << right << endl;
    // cout << "leftset  : " << leftset << endl;
    // cout << "rightset : " << rightset << endl;
    // cout << "can1 : " << can1 << endl;
    // cout << "can2 : " << can2 << endl;
    // cout << "tem : " << tem << endl;
    // cout << "ans : " << ans << endl;

    cout << (right - left + 1) - ans << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);

    // int t = 30 - __builtin_clz(5);

    // cout<<t<<endl;

    ll t = 1;

    cin >> t;

    for (ll i = 0; i < t; i++)
    {
        solve();
    }

    // return 0;
}

// ॥ जय श्री राम जय श्री कृष्ण ॥