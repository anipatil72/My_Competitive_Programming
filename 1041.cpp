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

int droppedPackets(vector<vector<int>> &packets, int max_pack, int rate)
{
    int n = packets.size();

    sort(packets.begin(), packets.end());

    long long drop = 0;

    long long cur = packets[0][1];

    if (cur > max_pack)
    {
        drop += abs(cur - max_pack);

        cur = max_pack;
    }

    long long prev = packets[0][0];

    for (int i = 1; i < n; i++)
    {
        long long cur_time = packets[i][0];

        cur -= (cur_time - prev) * 1LL * rate;

        if (cur < 0)
        {
            cur = 0;
        }

        cur += packets[i][1];

        if (cur > max_pack)
        {
            drop += abs(max_pack - cur);
            cur = max_pack;
        }

        prev = packets[i][0];
    }

    return drop;
}

int main()
{
    vector<vector<int>> packets = {{2, 8}, {1, 10}, {3, 4}};

    int rate = 5, max_pack = 7;

    cout << droppedPackets(packets, max_pack, rate);

    return 0;
}

// ॥ जय श्री राम जय श्री कृष्ण ॥