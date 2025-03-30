// // ॥ श्री गणेशाय नमः ॥

// #include <bits/stdc++.h>
// #include <random>
// #include <complex>
// #include <tuple>
// #include <functional>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// #include <cstdint>
// #include <ctime>
// #include <cassert>
// #include <complex>
// #include <string>
// #include <cstring>
// #include <chrono>
// using namespace std;
// using namespace __gnu_pbds;
// #define ll long long
// #define lld long double
// #define ull unsigned long long
// #define uint unsigned int

// typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
// // typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_multiset;

// template <typename typC, typename typD>
// istream &operator>>(istream &cin, pair<typC, typD> &a)
// {
//     return cin >> a.first >> a.second;
// }
// template <typename typC>
// istream &operator>>(istream &cin, vector<typC> &a)
// {
//     for (auto &x : a)
//         cin >> x;
//     return cin;
// }
// template <typename typC, typename typD>
// ostream &operator<<(ostream &cout, const pair<typC, typD> &a) { return cout << a.first << ' ' << a.second; }
// template <typename typC, typename typD>
// ostream &operator<<(ostream &cout, const vector<pair<typC, typD>> &a)
// {
//     for (auto &x : a)
//         cout << x << '\n';
//     return cout;
// }
// template <typename typC>
// ostream &operator<<(ostream &cout, const vector<typC> &a)
// {
//     int n = a.size();
//     if (!n)
//         return cout;
//     cout << a[0];
//     for (int i = 1; i < n; i++)
//         cout << ' ' << a[i];
//     return cout;
// }

// mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
// ll myRandomNumber(ll B)
// {
//     return (ull)rng() % B;
// }

// int GCD(int a, int b)
// {
//     if (b == 0)
//     {
//         return a;
//     }

//     return GCD(b, a % b);
// }

// int LCM(int a, int b)
// {
//     return (a * b) / GCD(a, b);
// }

// // returns map containing factor and multiplicity, Eg: 60 = {{2,2},{3,1},{5,1}}

// map<long long, long long> factorize(long long n)
// {
//     map<long long, long long> ans;
//     for (long long i = 2; i * i <= n; i++)
//     {
//         while (n % i == 0)
//         {
//             ans[i]++;
//             n /= i;
//         }
//     }
//     if (n > 1)
//     {
//         ans[n]++;
//         n = 1;
//     }
//     return ans;
// }

// // -------------------Important Notes------------------- //
// // **For Interactive Problems remember to remove multi test cases condition** //
// // (int)log2(x) + 1  -> to calculate number of bits of a number
// // s.erase(0, min(s.find_first_not_of('0'), s.size()-1));   //for removing leading zero's
// // Remember about unique function usage
// // yi=(t|xi)⊕xi
// // (int index = str.find(substr, pos)) != string::npos    // for checking substring 'substr' in string 'str'
// // ((x >> j) & 1) ===> to check if the j-th bit is on/off
// // log2(n&(-n)) returns a number in which only the rightmost bit is set in n
// // alternatively ffs(n) also gives the index of the rightmeost set bit
// // x |= (1 << i) ===> to set the i-th bit on

// void solve()
// {
//     int n, m, k;

//     cin >> n >> m >> k;

//     vector<int> prices(n);

//     // priority_queue<int, vector<int>, greater<int>> pq;

//     for (int i = 0; i < n; i++)
//     {
//         cin >> prices[i];

//         // pq.push(prices[i]);
//     }

//     sort(prices.begin(), prices.end());

//     vector<int> tickets(n, 0);

//     int total = k;

//     int des = 0;

//     while (des < n && total > 0)
//     {
//         if (total >= m)
//         {
//             total -= m;

//             tickets[des] = m;
//         }
//         else if (total < m)
//         {

//             tickets[des] = total;
//             total = 0;
//         }

//         des++;
//     }
// }

// int main()
// {
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL);
//     // freopen("input.txt","r",stdin);
//     // freopen("output.txt","w",stdout);

//     ll t = 1;

//     // cin >> t;

//     for (ll i = 0; i < t; i++)
//     {
//         solve();
//     }

//     return 0;
// }

#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;
typedef long long ll;

ll solve_test_case()
{
    int n, k;
    ll m;
    cin >> n >> m >> k;
    vector<ll> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    ll min_cost = LLONG_MAX;

    // Try all possible combinations of buying tickets on different days
    // We'll use a recursive approach with dynamic programming
    vector<vector<ll>> dp(n + 1, vector<ll>(k + 1, LLONG_MAX));
    dp[0][0] = 0;

    for (int day = 0; day < n; day++)
    {
        for (int bought = 0; bought <= k; bought++)
        {
            if (dp[day][bought] == LLONG_MAX)
                continue;

            // Try buying different amounts of tickets on current day
            for (ll buy = 0; buy <= min(m, (ll)(k - bought)); buy++)
            {
                if (bought + buy > k)
                    break;

                ll new_cost = dp[day][bought];
                // Calculate cost of buying tickets on current day
                new_cost += buy * a[day];

                // Update prices for subsequent days
                vector<ll> new_prices = a;
                for (int next_day = day + 1; next_day < n; next_day++)
                {
                    new_prices[next_day] += buy;
                }

                // Update dp state
                dp[day + 1][bought + buy] = min(dp[day + 1][bought + buy], new_cost);

                if (bought + buy == k)
                {
                    min_cost = min(min_cost, new_cost);
                }
            }
        }
    }

    return min_cost;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--)
    {
        cout << solve_test_case() << "\n";
    }

    return 0;
}

// // ॥ जय श्री राम जय श्री कृष्ण ॥