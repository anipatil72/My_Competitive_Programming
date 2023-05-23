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

int solve(int N, vector<int> &p)
{
    // vector<int> wanked(N, 1);

    // vector<int> child(N, 0);

    // int maxi = 0, cand = 0;

    // for (int i = 1; i < N; i++)
    // {

    //     child[p[i]]++;

    //     // if (child[p[i]] > maxi)
    //     // {
    //     //     maxi = child[p[i]];
    //     //     cand = p[i];
    //     // }
    // }

    int ans = 0;
    unordered_map<int, bool> mp;

    for (int i = 1; i < N; i++)
    {
        if (p[i] != 0 && mp.count(p[i]) == 0)
        {
            mp[p[i]] = true;
            ans++;
        }
    }

    return ans;

    // if (cand != 0)
    // {
    //     int parent = p[cand];

    //     int baap = cand;

    //     while (parent != -1)
    //     {
    //         int tem = p[parent];

    //         p[parent] = baap;

    //         baap = parent;

    //         parent = tem;
    //     }
    // }

    // p[cand] = -1;

    // dbg(p);
    // dbg(child);

    // cout << "This is teh new home : " << cand << endl;

    // for (int i = 0; i < N; i++)
    // {
    //     int parent = p[i];

    //     int score = 0;

    //     while (parent != cand && wanked[parent] == 1)
    //     {
    //         score++;

    //         wanked[parent] = 0;

    //         parent = p[parent];
    //     }

    //     fin += score;
    //     // cout << "I am here : " << i << " and here : score = " << score << endl;
    // }

    // return fin;
}

int main()
{

    vector<int> v = {-1, 0, 1};

    int n = 3;

    cout << solve(n, v);

    return 0;
}

// ॥ जय श्री राम जय श्री कृष्ण ॥