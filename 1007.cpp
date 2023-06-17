// ॥ श्री गणेशाय नमः ॥

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define ll long long
#define ull unsigned long long
using namespace std;
using namespace __gnu_pbds;

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

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
// typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_multiset;

long long minTime(int n, vector<int> &locations, vector<int> &types)
{
    map<int, pair<int, int>> m;

    long long ans = 0;

    for (int i = 0; i < n; i++)
    {
        if (m.count(types[i]) > 0)
        {
            if (m[types[i]].first > locations[i])
            {
                m[types[i]].first = locations[i];
            }

            if (m[types[i]].second < locations[i])
            {
                m[types[i]].second = locations[i];
            }
        }
        else
        {
            m[types[i]].second = locations[i];
            m[types[i]].first = locations[i];
        }
    }

    dbg(m);
    int len = m.size();

    vector<vector<long long>> des(2, vector<long long>(len + 2));
    vector<vector<long long>> dp(2, vector<long long>(len + 2));

    // des[0][0] = 0, des[1][0] = 0;

    auto it = m.begin();

    for (int i = 1; i <= len; i++)
    {
        des[0][i] = (*it).second.first;
        des[1][i] = (*it).second.second;

        it++;
    }
    // des[0][len + 1] = 0, des[1][len + 1] = 0;

    // dbg(des);

    // dp[0][len - 1] = abs(des[0][len - 1]) + abs(des[0][len - 1] - des[1][len - 1]);
    // dp[1][len - 1] = abs(des[1][len - 1]) + abs(des[0][len - 1] - des[1][len - 1]);

    for (int i = 1; i < n + 2; i++)
    {
        dp[0][i] = abs(des[0][i] - des[1][i]) + min(abs(des[0][i] - des[1][i - 1]) + dp[1][i - 1], abs(des[0][i] - des[0][i - 1] + dp[0][i - 1]));
        dp[1][i] = abs(des[0][i] - des[1][i]) + min(abs(des[1][i] - des[1][i - 1]) + dp[1][i - 1], abs(des[1][i] - des[0][i - 1] + dp[0][i - 1]));
    }

    // dbg(dp);

    ans = min(dp[0][0], dp[1][0]);

    // dbg(ans);

    // dbg(m);

    return ans;
}

int main()
{

    vector<int> locations = {1, 3, 5, 7};
    vector<int> types = {1, 2, 3, 1};

    cout << minTime(4, locations, types);

    return 0;
}

// ॥ जय श्री राम जय श्री कृष्ण ॥