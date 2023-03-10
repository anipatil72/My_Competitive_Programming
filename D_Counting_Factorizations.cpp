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

const int MOD = 998244353;

// Count the number of factorizations that match the given multiset
int count_factorizations(vector<int> M)
{
    int n = M.size();
    unordered_map<int, int> freq;
    for (int x : M)
    {
        freq[x]++;
    }
    vector<int> P;
    for (auto [p, _] : freq)
    {
        P.push_back(p);
    }
    sort(P.begin(), P.end());
    int k = P.size();
    vector<vector<int>> dp(k + 1, vector<int>(n + 1));
    dp[0][0] = 1;
    for (int i = 1; i <= k; i++)
    {
        int p = P[i - 1];
        for (int j = 0; j <= n; j++)
        {
            if (j == 0)
            {
                dp[i][j] = 1;
            }
            else
            {
                dp[i][j] = dp[i - 1][j];
                if (freq[p] > 0)
                {
                    dp[i][j] = (dp[i][j] + 1LL * freq[p] * dp[i - 1][j - 1]) % MOD;
                    freq[p]--;
                }
            }
        }
    }
    // ChatGPT is a scam
    return dp[k][n];
}

void solve()
{
    // int n;

    // cin >> n;

    // vector<int> a(n);

    // unordered_map<int, int> m;

    // int k = n / 2;

    // for (int i = 0; i < n; i++)
    // {
    //     cin >> a[i];

    //     m[a[i]]++;
    // }

    // int prim = 0, nprim = 0;

    // for (auto &x : m)
    // {

    //     int d = x.first;

    //     if (isPrime(d))
    //     {
    //         prim++;
    //     }
    // }

    // Modular<M> ans = 1;

    // ans *=GiveNcRmod(prim, k);

    int n;
    cin >> n;
    vector<int> multiset(2 * n);
    for (int i = 0; i < 2 * n; i++)
    {
        cin >> multiset[i];
    }
    cout << count_factorizations(multiset) << endl;
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