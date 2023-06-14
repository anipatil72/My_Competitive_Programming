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

void dfs(int row, int col, vector<vector<int>> &mat, int index, int &count)
{
    int n = mat.size();

    int m = mat[0].size();

    mat[row][col] = index;

    count++;

    if ((row + 1 < n) && mat[row + 1][col] == 1)
    {
        dfs(row + 1, col, mat, index, count);
    }

    if ((col + 1 < m) && mat[row][col + 1] == 1)
    {
        dfs(row, col + 1, mat, index, count);
    }

    if (row > 0 && mat[row - 1][col] == 1)
    {
        dfs(row - 1, col, mat, index, count);
    }

    if (col > 0 && mat[row][col - 1] == 1)
    {
        dfs(row, col - 1, mat, index, count);
    }
}

int MaxConnection(vector<vector<int>> &grid)
{
    int n = grid.size();

    vector<int> count;

    count.push_back(-1);
    count.push_back(-1);

    int index = 2;

    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (grid[i][j] == 1)
            {
                int num = 0;

                dfs(i, j, grid, index, num);

                count.push_back(num);

                ans = max(ans, num);

                index++;
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (grid[i][j] == 0)
            {

                int row = i, col = j;

                unordered_set<int> s;

                int tem = 0;

                if ((row + 1 < n) && grid[row + 1][col] != 0)
                {
                    // dfs(row + 1, col, mat, index, count);

                    s.insert(grid[row + 1][col]);

                    // tem += count[grid[row + 1][col]];
                }

                if ((col + 1 < n) && grid[row][col + 1] != 0)
                {
                    // dfs(row, col + 1, mat, index, count);

                    s.insert(grid[row][col + 1]);
                    // tem += count[grid[row][col + 1]];
                }

                if (row > 0 && grid[row - 1][col] != 0)
                {
                    // tem += count[grid[row - 1][col]];

                    s.insert(grid[row - 1][col]);
                    // dfs(row - 1, col, mat, index, count);
                }

                if (col > 0 && grid[row][col - 1] != 0)
                {
                    // tem += count[grid[row][col - 1]];
                    s.insert(grid[row][col - 1]);
                    // dfs(row, col - 1, mat, index, count);
                }

                for (auto x : s)
                {
                    tem += count[x];
                }

                ans = max(ans, tem + 1);
            }
        }
    }

    // dbg(grid);

    // dbg(count);

    return ans;
}

int main()
{

    vector<vector<int>> test = {{1, 1}, {0, 1}};

    int ans = MaxConnection(test);

    cout << "This is final Answer : " << ans << endl;

    return 0;
}

// ॥ जय श्री राम जय श्री कृष्ण ॥