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

// // http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2016/p0200r0.html
// template <class Fun>
// class y_combinator_result
// {
//     Fun fun_;

// public:
//     template <class T>
//     explicit y_combinator_result(T &&fun) : fun_(std::forward<T>(fun)) {}
//     template <class... Args>
//     decltype(auto) operator()(Args &&...args) { return fun_(std::ref(*this), std::forward<Args>(args)...); }
// };
// template <class Fun>
// decltype(auto) y_combinator(Fun &&fun) { return y_combinator_result<std::decay_t<Fun>>(std::forward<Fun>(fun)); }

// template <typename A, typename B>
// ostream &operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << "," << p.second << ')'; }
// template <typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type>
// ostream &operator<<(ostream &os, const T_container &v)
// {
//     os << '{';
//     string sep;
//     for (const T &x : v)
//         os << sep << x, sep = ", ";
//     return os << '}';
// }

// void dbg_out() { cerr << endl; }
// template <typename Head, typename... Tail>
// void dbg_out(Head H, Tail... T)
// {
//     cerr << ' ' << H;
//     dbg_out(T...);
// }
// #define dbg(...) cerr << '[' << __FILE__ << ':' << __LINE__ << "] (" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)

int numberOfBoomerangs(vector<vector<int>> &points)
{
    int n = points.size();

    // unordered_map<int, int> m;

    int ans = 0;

    for (int i = 0; i < n; i++)
    {
        unordered_map<int, int> m;

        for (int j = 0; (j < n); j++)
        {

            // dbg(i, j);

            int xe = abs(points[i][0] - points[j][0]), ye = abs(points[i][1] - points[j][1]);

            int dis = xe * xe + ye * ye;

            m[dis]++;
        }

        // cout << "This is i = " << i << endl;

        // dbg(m);

        for (auto &x : m)
        {
            int d = x.second;

            ans += (d * (d - 1));
        }

        // dbg(ans);
    }

    return ans;
}

int main()
{

    vector<vector<int>> points = {{0, 0}, {1, 0}, {2, 0}};

    cout << numberOfBoomerangs(points);

    return 0;
}

// ॥ जय श्री राम जय श्री कृष्ण ॥