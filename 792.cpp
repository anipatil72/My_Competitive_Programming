// ॥ श्री गणेशाय नमः ॥

#include <bits/stdc++.h>
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

int getMaxPathSum(vector<vector<int>> &matrix)
{
    int n = matrix.size();

    int m = matrix[0].size();

    vector<vector<int64_t>> dp(n, vector<int64_t>(m));

    int64_t ans = INT_MIN;



    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            int64_t uleft = INT_MIN;

            int64_t uu = INT_MIN;

            int64_t uright = INT_MIN;

            if (i > 0)
            {

                uu = dp[i - 1][j];

                if (j > 0)
                {
                    uleft = dp[i - 1][j - 1];
                }

                if (j < m - 1)
                {

                    uright = dp[i - 1][j + 1];
                }

                dp[i][j] = matrix[i][j] + (max({uu, uleft, uright}));
            }
            else if (i == 0)
            {
                dp[i][j] = matrix[i][j];
            }

            if (i == n - 1)
            {
                ans = max(ans, dp[i][j]);
            }
        }
    }

    return ans;
}

int main()
{

    vector<vector<int>> mat = {{}};

    return 0;
}

// ॥ जय श्री राम जय श्री कृष्ण ॥