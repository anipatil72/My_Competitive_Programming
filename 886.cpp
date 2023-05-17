// ॥ श्री गणेशाय नमः ॥

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define ll long long
#define ull unsigned long long
using namespace std;
using namespace __gnu_pbds;

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
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
#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)

int recur(int fir, int sec, vector<int> &a, vector<int> &b, vector<vector<int>> &dp)
{
    // cout << "I am here : fir = " << fir << " sec = " << sec << endl;
    if (fir >= a.size())
    {
        return 0;
    }

    if (sec >= b.size())
    {
        return 0;
    }

    if (dp[fir][sec] != -1)
    {
        return dp[fir][sec];
    }

    int take = -1e9;

    int nottake = -1e9;

    if (a[fir] == b[sec])
    {
        take = 1 + recur(fir + 1, sec + 1, a, b, dp);
    }
    else
    {
        nottake = max({recur(fir + 1, sec, a, b, dp), recur(fir, sec + 1, a, b, dp)});
    }

    // dbg(dp);

    return dp[fir][sec] = max(take, nottake);
}

int maxUncrossedLines(vector<int> &nums1, vector<int> &nums2)
{
    int n = nums1.size();

    int m = nums2.size();

    vector<vector<int>> dp(n, vector<int>(m, -1));

    return recur(0, 0, nums1, nums2, dp);
}

int main()
{

    vector<int> u = {2, 5, 1, 2, 5};
    vector<int> v = {10, 5, 2, 1, 5, 2};

    cout << maxUncrossedLines(u, v);

    return 0;
}

// Done

// ॥ जय श्री राम जय श्री कृष्ण ॥