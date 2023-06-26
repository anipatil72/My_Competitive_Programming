// ॥ श्री गणेशाय नमः ॥

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define ll long long
#define ull unsigned long long
using namespace std;
using namespace __gnu_pbds;

#define MAX 1000

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

template <typename T_vector>
void print_2D(vector<T_vector> &v)
{
    for (int i = 0; i < v.size(); i++)
    {
        for (int j = 0; j < v[i].size(); j++)
        {
            cout << v[i][j] << " ";
        }
        cout << endl;
    }
}

template <typename T_vector>
void output_vector(const T_vector &v, bool add_one = false, int start = -1, int end = -1)
{
    if (start < 0)
        start = 0;
    if (end < 0)
        end = int(v.size());

    for (int i = start; i < end; i++)
    {

        if (i == end - 1)
        {
            cout << v[i] + (add_one ? 1 : 0) << endl;
        }
        else
        {
            cout << v[i] + (add_one ? 1 : 0) << ' ';
        }
    }
}

void faaltu(int64_t des, vector<vector<int>> &ans, int m)
{

    vector<int> tem(m, 0);

    for (int j = 0; j < m; j++)
    {
        tem[j] = ((des & (1 << (m - 1 - j))) > 0);
    }

    // cout << "This is tem" << endl;

    // output_vector(tem);

    // cout << "This is des : " << des << endl;

    ans.push_back(tem);
}

vector<vector<int>> uniqueRow(vector<vector<int>> &M, int row, int col)
{
    unordered_set<int64_t> s;

    int n = row, m = col;
    vector<vector<int>> ans;

    dbg(s);

    for (int i = 0; i < n; i++)
    {
        int64_t dex = 0;

        for (int j = 0; j < m; j++)
        {
            if (M[i][j] == 1)
            {
                dex |= (1 << (m - 1 - j));
            }
        }

        // cout << "This is dex : ";
        // cout << dex << endl;

        if (s.count(dex) == 0)
        {
            faaltu(dex, ans, m);

            // print_2D(ans);

            s.insert(dex);

            // dbg(s);
        }
    }

    // print_2D(ans);
    return ans;
}

int main()
{

    int row = 3, col = 4;
    vector<vector<int>> M = {{1, 1, 0, 1},
                             {1, 0, 0, 1},
                             {1, 1, 0, 1}};

    vector<vector<int>> ans = uniqueRow(M, row, col);

    return 0;
}

// ॥ जय श्री राम जय श्री कृष्ण ॥