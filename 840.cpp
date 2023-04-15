// ॥ श्री गणेशाय नमः ॥

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define ll long long
#define ull unsigned long long
using namespace std;
using namespace __gnu_pbds;

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

long long findWays(vector<int> &num, int tar)
{
    int n = num.size();

    vector<vector<long long>> dp(n, vector<long long>(tar + 1, 0));

    // for (int i = 0; i < n; i++)
    // {
    //     dp[i][0] = 1;
    // }

    // if ()
    // {

    // }

    if (num[0] == 0)
    {
        // return 2;

        dp[0][0] = 2;
    }
    else if (num[0] <= tar)
    {
        // return 1;

        dp[0][num[0]] = 1;
    }

    // // dbg(dp);

    // if (num[0] <= tar)
    // {
    //     dp[0][num[0]] = 1;
    // }

    for (int i = 1; i < n; i++)
    {

        // dbg(i);

        // cout << "I am here ! " << endl;
        for (int j = 0; j <= tar; j++)
        {
            long long notpick = dp[i - 1][j];

            // dbg(i, j);
            long long pick = 0;

            if (j >= num[i])
            {
                pick = dp[i - 1][j - num[i]];
            }

            dp[i][j] = pick + notpick;
        }
    }

    // for (int i = 0; i < n; i++)
    // {
    //     for (int j = 0; j <= tar; j++)
    //     {
    //         cout << dp[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    return dp[n - 1][tar];
}

int recur(int index, int sum, vector<int> &a, vector<vector<int>> &dp)
{
    if (index == 0)
    {
        if (sum == 0 && a[0] == 0)
        {
            return 2;
        }

        if (sum == 0 || a[0] == sum)
        {
            return 1;
        }

        return 0;
    }

    if (dp[index][sum] != -1)
    {
        return dp[index][sum];
    }

    int notTaken = recur(index - 1, sum, a, dp);

    int taken = 0;

    if (sum >= a[index])
    {
        taken = recur(index - 1, sum - a[index], a, dp);
    }

    return dp[index][sum] = taken + notTaken;
}

int findWaysMemo(vector<int> &num, int tar)
{
    int n = num.size();

    vector<vector<int>> dp(n, vector<int>(tar + 1, -1));

    return recur(n - 1, tar, num, dp);
}

int main()
{

    int t = 100;

    cin >> t;

    while (t--)
    {

        int n, k;

        cin >> n >> k;

        vector<int> a(n);

        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }

        cout << "The answer is : " << endl;

        // cout << minSubsetSumDifference(a, n) << endl;

        cout << findWays(a, k) << endl;
    }

    return 0;
}

// ॥ जय श्री राम जय श्री कृष्ण ॥