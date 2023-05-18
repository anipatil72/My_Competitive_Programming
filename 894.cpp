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

void dfs(int index, vector<vector<int>> &adj, vector<int> &vis)
{
    vis[index] = 0;

    // dbg(index);

    // dbg(vis);

    for (int i = 0; i < adj[index].size(); i++)
    {

        if (vis[adj[index][i]] == 1)
        {
            dfs(adj[index][i], adj, vis);
        }
        else if (vis[adj[index][i]] == 2)
        {
            vis[adj[index][i]] = 0;

            // cout << "Here I found 2 : " << endl;

            // dbg(index);
        }
    }
}

vector<int> findSmallestSetOfVertices(int n, vector<vector<int>> &edges)
{
    int m = edges.size();

    vector<vector<int>> adj(n);

    vector<int> vis(n, 1);

    for (int i = 0; i < m; i++)
    {
        adj[edges[i][0]].push_back(edges[i][1]);
    }

    for (int i = 0; i < n; i++)
    {
        if (vis[i] == 1)
        {
            dfs(i, adj, vis);

            vis[i] = 2;
        }
    }

    // int count = 0;

    vector<int> fin;

    for (int i = 0; i < n; i++)
    {
        if (vis[i] == 2)
        {
            // count++;

            fin.push_back(i);
        }
    }

    return fin;
}

int main()
{

    vector<vector<int>> edges = {{0, 1}, {0, 2}, {2, 5}, {3, 4}, {4, 2}};

    int vertices = 6;

    vector<int> ans = findSmallestSetOfVertices(vertices, edges);

    cout << "This is the answer : " << endl;

    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }

    return 0;
}

// ॥ जय श्री राम जय श्री कृष्ण ॥