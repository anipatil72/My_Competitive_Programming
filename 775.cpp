// ॥ श्री गणेशाय नमः ॥

#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define M 1000000007
using namespace std;

#define MOD 1000000007

void __print(int x)
{
    cerr << x;
}
void __print(long x) { cerr << x; }
void __print(long long x) { cerr << x; }
void __print(unsigned x) { cerr << x; }
void __print(unsigned long x) { cerr << x; }
void __print(unsigned long long x) { cerr << x; }
void __print(float x) { cerr << x; }
void __print(double x) { cerr << x; }
void __print(long double x) { cerr << x; }
void __print(char x) { cerr << '\'' << x << '\''; }
void __print(const char *x) { cerr << '"' << x << '"'; }
void __print(const string &x) { cerr << '"' << x << '"'; }
void __print(bool x) { cerr << (x ? "true" : "false"); }

template <typename T, typename V>
void __print(const pair<T, V> &x)
{
    cerr << '{';
    __print(x.first);
    cerr << ',';
    __print(x.second);
    cerr << '}';
}
template <typename T>
void __print(const T &x)
{
    int f = 0;
    cerr << '{';
    for (auto &i : x)
        cerr << (f++ ? "," : ""), __print(i);
    cerr << "}";
}
void _print() { cerr << "]\n"; }
template <typename T, typename... V>
void _print(T t, V... v)
{
    __print(t);
    if (sizeof...(v))
        cerr << ", ";
    _print(v...);
}
#ifndef ONLINE_JUDGE
#define debug(x...)               \
    cerr << "[" << #x << "] = ["; \
    _print(x)
#else
#define debug(x...)
#endif

int uniquePaths(int m, int n, vector<vector<int>> &mat)
{
    vector<vector<int>> dp(m, vector<int>(n));

    dp[0][0] = 1;

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == 0 && j == 0)
            {
                dp[i][j] = 1;

                continue;
            }

            int left = (j == 0) ? 0 : (mat[i][j - 1] == 0 ? 0 : dp[i][j - 1]);

            int top = (i == 0) ? 0 : (mat[i - 1][j] == 0 ? 0 : dp[i - 1][j]);

            left %= MOD;

            top %= MOD;

            dp[i][j] = (left + 0LL + top) % MOD;
        }
    }

    if (mat[m - 1][n - 1] == 0)
    {
        return 0;
    }

    // debug(dp);

    return dp[m - 1][n - 1] % MOD;
}

int main()
{

    vector<vector<int>> grid = {{1, 1, 1},
                                {1, 0, 1},
                                {1, 1, 1}};

    cout << uniquePaths(grid.size(), grid[0].size(), grid);

    return 0;
}

// ॥ जय श्री राम जय श्री कृष्ण ॥