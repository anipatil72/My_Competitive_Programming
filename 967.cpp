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

// Leetcode HARD to do

int minChanges(vector<int> &nums, int k)
{

    int n = nums.size();

    vector<int> a = nums;

    vector<int> b = nums;

    int cur = 0;

    if (k == 1)
    {
        int test = 0;

        for (int i = 0; i < n; i++)
        {
            test += (nums[i] != 0);
        }

        return test;
    }

    for (int i = 0; i < k - 1; i++)
    {
        cur ^= a[i];
    }

    int ans = 0;

    if (a[k - 1] != cur)
    {
        a[k - 1] = cur;

        ans++;
    }

    for (int i = k; i < n; i++)
    {

        if ((a[i] == a[i - k]) || (a[i] == 0))
        {
        }
        else
        {
            a[i] = a[i - k];

            // cur = 0;

            ans++;
            // cur = 0;
        }
    }

    reverse(b.begin(), b.end());

    for (int i = 0; i < k - 1; i++)
    {
        cur ^= b[i];
    }

    // int ans = 0;
    int tens = 0;

    if (b[k - 1] != cur)
    {
        b[k - 1] = cur;

        ans++;
    }

    for (int i = k; i < n; i++)
    {

        if ((b[i] == b[i - k]) || (b[i] == 0))
        {
        }
        else
        {
            b[i] = b[i - k];

            // cur = 0;

            tens++;
            // cur = 0;
        }
    }

    return min(ans, tens);

    // return 0;
}

int main()
{

    vector<int> test = {4, 11, 31, 2, 16, 12, 0, 27, 11, 26, 8, 23, 2, 2, 22, 5, 9};

    int k = 3;

    cout << minChanges(test, k);
    // dbg(test);

    // int tt = 100;

    // int a, b;

    // while (tt--)
    // {
    //     cin >> a >> b;
    //     cout << (a ^ b) << endl;
    // }

    return 0;
}

// [4,11,31,2,16,12,0,27,11,26,8,23,2,2,22,5,9]
// 3

// ॥ जय श्री राम जय श्री कृष्ण ॥