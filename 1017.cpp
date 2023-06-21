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
#define dbg(...) cerr << '[' << __FILE__ << ':' << __LINE__ << "] (" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)

long long minCost(vector<int> &nums, vector<int> &cost)
{
    int n = nums.size();

    vector<pair<int, int>> p(n);

    for (int i = 0; i < n; i++)
    {
        p[i] = {nums[i], cost[i]};
    }

    sort(p.begin(), p.end());

    for (int i = 0; i < n; i++)
    {
        nums[i] = p[i].first;

        cost[i] = p[i].second;
    }

    dbg(p);

    vector<ll> pref(n, 0);

    pref[0] = cost[0];

    for (int i = 1; i < n; i++)
    {
        pref[i] = cost[i] + pref[i - 1];
    }

    dbg(pref);

    // vector<ll> dref(n, 0);

    // dref[0] = nums[0];

    // for (int i = 1; i < n; i++)
    // {
    //     dref[i] = dref[i - 1] + 0LL + nums[i];
    // }

    ll left = 0, right = 0;

    ll sum = 0;

    for (int i = 0; i < n; i++)
    {
        sum += cost[i] * 1LL * nums[i];
    }

    right = sum;

    dbg(sum);

    ll ans = 1e15;

    for (int i = 0; i < n; i++)
    {
        // dbg(left, right);

        ll y = (i == 0 ? cost[i] * 1LL * nums[i] : (nums[i] - nums[i - 1]) * 1LL * (pref[i - 1]));
        left += y;

        left += (cost[i] * 1LL * nums[i]);

        ll x = (i == 0 ? (pref[n - 1] - pref[i]) * 1LL * (nums[i]) : (pref[n - 1] - pref[i]) * 1LL * (nums[i] - nums[i - 1]));

        right -= x;
        right -= (cost[i] * 1LL * nums[i]);

        dbg(left, right, x, y);

        ans = min(ans, left + right);
    }

    return ans;
}

int main()
{

    vector<int> nums = {1, 3, 5, 2};
    vector<int> cost = {2, 3, 1, 14};

    cout << minCost(nums, cost) << endl;

    return 0;
}

// ॥ जय श्री राम जय श्री कृष्ण ॥