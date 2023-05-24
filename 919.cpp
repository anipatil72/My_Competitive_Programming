// ॥ श्री गणेशाय नमः ॥

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define ll long long
#define ull unsigned long long
using namespace std;
using namespace __gnu_pbds;

const int MOD = 1000000007;

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

vector<vector<int>> matrixMultiplication(vector<vector<int>> &A, vector<vector<int>> &B)
{
    int an = A.size();

    int am = A[0].size();

    int bn = B.size();

    int bm = B[0].size();

    if (am != bn)
    {
        return {};
    }

    vector<vector<int>> ans(an, vector<int>(bm));

    for (int i = 0; i < an; i++)
    {

        for (int k = 0; k < bm; k++)
        {
            int tem = 0;

            for (int j = 0; j < am; j++)
            {

                long long des = (A[i][j] * 1LL * B[j][k]);

                int dess = des % MOD;

                tem += dess;

                tem %= MOD;
            }

            ans[i][k] = tem;
        }
    }

    return ans;
}

vector<vector<int>> matrixExponentiation(vector<vector<int>> A, ll n)
{
    if (n == 1)
    {
        return A;
    }

    if (n & 1)
    {

        vector<vector<int>> des = matrixExponentiation(A, n - 1);
        return matrixMultiplication(A, des);
    }

    vector<vector<int>> des = matrixExponentiation(A, n / 2);

    return matrixMultiplication(des, des);
}

int countStrings(long long int N)
{

    vector<vector<int>> fib0 = {{1}, {1}};

    vector<vector<int>> id = {{1, 1}, {1, 0}};
    vector<vector<int>> dest = matrixExponentiation(id, N);

    vector<vector<int>> fin = matrixMultiplication(dest, fib0);

    return fin[0][0];
}

int main()
{

    // vector<vector<int>> ans = matrixMultiplication(id, id);

    // vector<vector<int>> test = {{1}, {1}};

    // vector<vector<int>> fin = matrixMultiplication(ans, test);

    // dbg(fin);

    cout << countStrings(100000000000);

    return 0;
}

// ॥ जय श्री राम जय श्री कृष्ण ॥