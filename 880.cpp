// ॥ श्री गणेशाय नमः ॥

#include <bits/stdc++.h>
#include <chrono>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define ll long long
#define ull unsigned long long
using namespace std;
using namespace __gnu_pbds;

const int MOD = 1000000007;

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

ll MyNum(ll a, ll b)
{
    return a + rng() % (b - a + 1);
}

// http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2016/p0200r0.html
template <class Fun>
class y_combinator_result
{
    Fun fun_;

public:
    template <class T>
    explicit y_combinator_result(T &&fun) : fun_(std::forward<T>(fun)) {}
    template <class... Args>
    decltype(auto) operator()(Args &&...args) { return fun_(std::ref(*this), std::forward<Args>(args)...); }
};
template <class Fun>
decltype(auto) y_combinator(Fun &&fun) { return y_combinator_result<std::decay_t<Fun>>(std::forward<Fun>(fun)); }

template <typename A, typename B>
ostream &operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << "," << p.second << ')'; }
template <typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type>
ostream &operator<<(ostream &os, const T_container &v)
{
    os << '{';
    string sep;
    for (const T &x : v)
        os << sep << x, sep = ", ";
    return os << '}';
}

void dbg_out() { cerr << endl; }
template <typename Head, typename... Tail>
void dbg_out(Head H, Tail... T)
{
    cerr << ' ' << H;
    dbg_out(T...);
}
#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
// typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_multiset;

int recur(int index, int zero, int one, vector<int> &dp)
{
    if (index < 0)
    {
        return -1e9;
    }

    if (index == 0)
    {
        return dp[index] = 1;
    }

    if (dp[index] == (int)(-1e9))
    {
        return dp[index];
    }

    if (dp[index] != -1)
    {

        return dp[index] % MOD;
    }

    int fir = recur(index - one, zero, one, dp);

    int sec = recur(index - zero, zero, one, dp);

    int ans = 0;

    if (sec == (int)-1e9 && fir == (int)-1e9)
    {
        return dp[index] = (int)-1e9;
    }

    if (fir != (int)-1e9)
    {
        ans += (fir) % MOD;
        ans %= MOD;
    }

    if (sec != (int)-1e9)
    {
        ans += (sec) % MOD;
        ans %= MOD;
    }
    return dp[index] = ans % MOD;
}

int countGoodStrings(int low, int high, int zero, int one)
{
    vector<int> dp(high + 1, -1);

    int ans = 0;

    for (int i = low; i <= high; i++)
    {
        if (dp[i] == (int)(-1e9))
        {
        }
        else if (dp[i] == -1)
        {
            int tem = recur(i, zero, one, dp) % MOD;

            if (tem != (int)(-1e9))
            {
                ans += tem % MOD;
                ans %= MOD;
            }
        }
        else
        {
            ans += dp[i] % MOD;
            ans %= MOD;
        }
    }

    // dbg(dp);

    cout << dp[50000] << " " << dp[100000] << endl;

    // if (ans == (int)(-1e9))
    // {
    //     return 0;
    // }

    return ans % MOD;
}

int main()
{
    // cout << MyNum(1, 100) << endl;

    cout << countGoodStrings(50000, 100000, 50000, 50000);

    return 0;
}

// ॥ जय श्री राम जय श्री कृष्ण ॥