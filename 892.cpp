// ॥ श्री गणेशाय नमः ॥

#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
#define ll long long
#define ull unsigned long long
using namespace std;

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

int maximumChocolates(int r, int c, vector<vector<int>> &grid)
{

    int c = grid[0].size();

    int r = grid.size();

    vector<vector<int>> ref(c, vector<int>(c));

    vector<vector<vector<int>>> dp(r, ref);

    // int ac = 0, bc = c - 1;

    int maxi = 0;

    for (int i = 0; i < c; i++)
    {
        for (int j = 0; j < c; j++)
        {
            if (i == j)
            {
                dp[r - 1][i][j] = grid[r - 1][j];
            }
            else
            {
                dp[r - 1][i][j] = grid[r - 1][i] + grid[r - 1][j];
            }
        }
    }

    // dp[0][0][c - 1] = grid[0][0] + grid[0][c - 1];

    int ans = 0;

    for (int i = r - 2; i >= 0; i--)
    {

        for (int ac = 0; ac < c; ac++)
        {

            for (int bc = 0; bc < c; bc++)
            {

                int tem = 0;

                for (int da = -1; da <= +1; da++)
                {
                    if (ac + da >= 0 && ac + da < c)
                    {
                        for (int db = -1; db <= +1; db++)
                        {

                            if (bc + db >= 0 && bc + db < c)
                            {

                                tem = max(tem, dp[i + 1][ac + da][bc + db]);
                                // if (bc == ac)
                                // {

                                //     dp[i][ac][bc] = grid[i][bc] + dp[i - 1][ac + da][bc + db];

                                //     ans = max(ans, dp[i][ac][bc]);
                                // }
                                // else
                                // {
                                //     dp[i][ac][bc] = grid[i][bc] + grid[i][ac] + dp[i - 1][ac + da][bc + db];

                                //     ans = max(ans, dp[i][ac][bc]);
                                // }
                            }
                        }
                    }
                }

                if (bc == ac)
                {

                    dp[i][ac][bc] = grid[i][bc] + tem;

                    ans = max(ans, dp[i][ac][bc]);
                }
                else
                {
                    dp[i][ac][bc] = grid[i][bc] + grid[i][ac] + tem;

                    ans = max(ans, dp[i][ac][bc]);
                }
            }
        }
    }

    return dp[0][0][c - 1];
}

int main()
{

    int rows = 3, cols = 4;

    vector<vector<int>> grid = {{2, 3, 1, 2}, {3, 4, 2, 2}, {5, 6, 3, 5}};

    cout << maximumChocolates(3, 4, grid);

    return 0;
}

// ॥ जय श्री राम जय श्री कृष्ण ॥