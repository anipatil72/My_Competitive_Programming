// ॥ श्री गणेशाय नमः ॥

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define ll long long
#define ull unsigned long long
using namespace std;
using namespace __gnu_pbds;

const int MOD = 1000000007;

// typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
// typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_multiset;

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
#define dbg(...) cerr << '[' << __FILE__ << ':' << __LINE__ << "] (" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)

// template <typename T_vector>
// void print_2D(vector<T_vector> &v)
// {
//     for (int i = 0; i < v.size(); i++)
//     {
//         for (int j = 0; j < v[i].size(); j++)
//         {
//             cout << v[i][j] << " ";
//         }
//         cout << endl;
//     }
// }

// Bhai maja aa gaya ! DP you are amazing !

bool retExp(char d)
{
    if (d == 'T')
    {
        return true;
    }

    return false;
}

bool evaluate(bool left, bool right, char d)
{
    if (d == '^')
    {
        return (left ^ right);
    }
    else if (d == '&')
    {
        return (left & right);
    }

    return (left | right);
}

int recur(int index, int jindex, bool exact, string &s, vector<vector<vector<long long>>> &dp)
{
    if (index > jindex)
    {
        return false;
    }

    if (index == jindex)
    {
        return exact == retExp(s[index]);
    }

    if (dp[index][jindex][exact] != -1)
    {
        return dp[index][jindex][exact] % MOD;
    }

    int count = 0;

    int n = s.length();

    long long ans = 0;

    for (int k = index; k <= jindex; k++)
    {
        if (count & 1)
        {
            long long leftTrue = recur(index, k - 1, true, s, dp);

            long long leftFalse = recur(index, k - 1, false, s, dp);

            long long rightTrue = recur(k + 1, jindex, true, s, dp);

            long long rightFalse = recur(k + 1, jindex, false, s, dp);

            // cout << endl;

            // dbg(index, jindex);
            // cout << "This is at k = " << k << endl;
            // dbg(leftTrue, leftFalse, rightTrue, rightFalse);
            // cout << endl;

            // if (leftTrue > 0 && rightTrue > 0)
            // {
            if (dp[index][jindex][evaluate(true, true, s[k])] == -1)
            {
                dp[index][jindex][evaluate(true, true, s[k])] = 0;
            }

            dp[index][jindex][evaluate(true, true, s[k])] += (leftTrue * rightTrue) % MOD;

            dp[index][jindex][evaluate(true, true, s[k])] %= MOD;
            // }

            // if (leftTrue > 0 && rightFalse > 0)
            // {
            if (dp[index][jindex][evaluate(true, false, s[k])] == -1)
            {
                dp[index][jindex][evaluate(true, false, s[k])] = 0;
            }

            dp[index][jindex][evaluate(true, false, s[k])] += (leftTrue * rightFalse) % MOD;

            dp[index][jindex][evaluate(true, false, s[k])] %= MOD;
            // }

            // if (leftFalse > 0 && rightTrue > 0)
            // {
            if (dp[index][jindex][evaluate(false, true, s[k])] == -1)
            {
                dp[index][jindex][evaluate(false, true, s[k])] = 0;
            }

            dp[index][jindex][evaluate(false, true, s[k])] += (leftFalse * rightTrue) % MOD;

            dp[index][jindex][evaluate(false, true, s[k])] %= MOD;
            // }

            // if (leftFalse > 0 && rightFalse > 0)
            // {
            if (dp[index][jindex][evaluate(false, false, s[k])] == -1)
            {
                dp[index][jindex][evaluate(false, false, s[k])] = 0;
            }

            dp[index][jindex][evaluate(false, false, s[k])] += (leftFalse * rightFalse) % MOD;

            dp[index][jindex][evaluate(false, false, s[k])] %= MOD;
            // }

            // dp[index][jindex][evaluate(leftTrue, rightTrue, s[k])] = 1;
            // dp[index][jindex][evaluate(leftTrue, rightFalse, s[k])] = 1;
            // dp[index][jindex][evaluate(leftFalse, rightTrue, s[k])] = 1;
            // dp[index][jindex][evaluate(leftFalse, rightFalse, s[k])] = 1;
        }

        count++;
    }

    if (dp[index][jindex][exact] == -1)
    {
        return dp[index][jindex][exact] = 0;
    }

    return dp[index][jindex][exact] % MOD;
}

int evaluateExp(string &exp)
{
    int n = exp.length();

    vector<vector<vector<long long>>> dp(n, vector<vector<long long>>(n, vector<long long>(2, -1)));

    long long ans = recur(0, n - 1, true, exp, dp);

    ans %= MOD;

    return ans;
}

int main()
{

    // string test = "F|T&F|T"; // T^T^F

    // cout << evaluateExp(test);

    int n;

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        string s;

        cin >> s;

        cout << evaluateExp(s) << endl;
    }

    // vector<int> a = {1, 2, 3};

    // bool test = true;

    // a[test] = 10;

    // cout << a[test] << endl;

    return 0;
}

// ॥ जय श्री राम जय श्री कृष्ण ॥