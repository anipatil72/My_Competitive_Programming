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

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
// typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_multiset;

int minSubArrayLen(int target, vector<ll> &nums)
{
    int n = nums.size();

    vector<ll> pref(n);

    pref[0] = nums[0];

    for (int i = 1; i < n; i++)
    {
        pref[i] = pref[i - 1] + 0LL + nums[i];
    }

    // dbg(pref);

    if (pref[n - 1] < target)
    {
        return 0;
    }

    ll ans = INT_MAX;

    for (int i = 0; i < n; i++)
    {
        ll temp = pref[i] - target;

        if (temp >= 0)
        {
            ll pos = (ll)(upper_bound(pref.begin(), pref.end(), temp) - pref.begin());

            // dbg(i, temp, pos);
            ans = min(ans, i - pos + 1);
        }
    }

    if (ans == INT_MAX)
    {
        return 0;
    }

    return ans;
}

int main()
{

    vector<ll> v = {1, 4, 4};

    int target = 1;

    cout << minSubArrayLen(target, v);

    return 0;
}

// ॥ जय श्री राम जय श्री कृष्ण ॥