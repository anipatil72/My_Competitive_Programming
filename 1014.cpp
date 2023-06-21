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

vector<int> getAverages(vector<int> &nums, int k)
{
    int n = nums.size();

    vector<int> ans(n, -1);

    int left = k - 1, right = n - k;

    if (left > right)
    {
        return ans;
    }

    if (left == right || (left + 1 == right))
    {
        return ans;
    }

    long long fir = accumulate(nums.begin(), nums.begin() + 2 * k + 1, 0LL);

    dbg(fir);

    long long tot = fir;
    dbg(tot);

    ans[k] = (tot) / (2 * k + 1);

    for (int i = left + 2; i < right; i++)
    {
        tot -= nums[i - k - 1];

        tot += nums[i + k];

        dbg(tot);

        ans[i] = (tot) / (2 * k + 1);
    }

    return ans;
}

int main()
{
    vector<int> test = {7, 4, 3, 9, 1, 8, 5, 2, 6};

    int k = 3;

    vector<int> ans = getAverages(test, k);

    dbg(ans);
    return 0;
}

// ॥ जय श्री राम जय श्री कृष्ण ॥