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

class DSU
{

public:
    vector<int> parent;

    vector<int> rank;

    DSU(int n)
    {

        parent.resize(n);

        rank.resize(n);

        for (int i = 0; i < n; i++)
        {
            parent[i] = i;

            rank[i] = 0;
        }
    }

    int find(int x)
    {

        if (x == parent[x])
        {

            return x;
        }

        parent[x] = find(parent[x]);

        return parent[x];
    }

    void Union(int x, int y)
    {
        int x_rep = find(x), y_rep = find(y);

        if (x_rep == y_rep)
        {
            return;
        }

        if (rank[x] > rank[y])
        {

            parent[y_rep] = x_rep;
        }
        else if (rank[x] < rank[y])
        {
            parent[x_rep] = y_rep;
        }
        else
        {
            parent[y_rep] = x_rep;

            rank[x_rep]++;
        }
    }
    int giveConnected()
    {
        int ans = 0;

        for (int i = 0; i < parent.size(); i++)
        {
            if (parent[i] == i)
            {
                ans++;
            }
        }

        return ans;
    }
};

vector<bool> friendRequests(int n, vector<vector<int>> &restrictions, vector<vector<int>> &requests)
{
    vector<int> baap(n, -1);

    // DSU forest(n);

    set<pair<int, int>> s;

    unordered_set<int> seniors;

    int len = restrictions.size();

    for (int i = 0; i < len; i++)
    {
        if (restrictions[i][0] < restrictions[i][1])
        {
            s.insert({restrictions[i][0], restrictions[i][1]});
        }
        else
        {
            s.insert({restrictions[i][1], restrictions[i][0]});
        }

        baap[restrictions[i][0]] = -2;
        baap[restrictions[i][1]] = -2;
    }

    // dbg(s);

    int ven = requests.size();

    vector<bool> ans;

    for (int i = 0; i < ven; i++)
    {
        // dbg(forest.parent);
        int x = baap[requests[i][0]];
        int y = baap[requests[i][1]];
        // dbg(forest.parent);

        if (x != y)
        {
            if (x < y)
            {
                if (s.find({x, y}) != s.end())
                {
                    ans.push_back(false);
                }
                else
                {
                    // forest.Union(x, y);
                    // dbg(forest.parent);
                    ans.push_back(true);
                }
            }
            else
            {
                if (s.find({y, x}) != s.end())
                {
                    ans.push_back(false);
                }
                else
                {
                    // forest.Union(x, y);
                    // dbg(forest.parent);
                    ans.push_back(true);
                }
            }
        }
        else
        {
            ans.push_back(true);
        }
    }

    // dbg(forest.parent);

    // return ans;
}

int main()
{

    vector<vector<int>> restrictions = {{0, 1}, {1, 2}, {2, 3}};

    vector<vector<int>> requests = {{0, 4}, {1, 2}, {3, 1}, {3, 4}};

    int n = 5;

    vector<bool> des = friendRequests(n, restrictions, requests);

    dbg(des);

    return 0;
}

// ॥ जय श्री राम जय श्री कृष्ण ॥