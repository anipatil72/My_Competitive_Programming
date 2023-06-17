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

bool isValidRow(int row, int n)
{
    return !(row >= n || row < 0);
}

bool isValidCol(int col, int m)
{
    return !(col >= m || col < 0);
}

vector<int> findDiagonalOrder(vector<vector<int>> &mat)
{
    int n = mat.size();

    int m = mat[0].size();

    vector<int> ans;

    int row = 0, col = 0;

    int turn = 0;

    int tot = n * m;

    while (ans.size() < tot)
    {
        // dbg(turn);

        // dbg(row, col);
        if (turn & 1)
        {
            ans.push_back(mat[row][col]);

            row++;

            col--;
            // dbg(row, col);
        }
        else
        {
            ans.push_back(mat[row][col]);

            row--;

            col++;
            // dbg(row, col);
        }

        if (isValidCol(col, m) && row < 0)
        {
            row++;

            turn++;
        }
        else if (isValidCol(col, m) && row >= n)
        {
            row--;

            col += 2;

            turn++;
        }
        else if (isValidRow(row, n) && col < 0)
        {
            col++;

            turn++;
        }
        else if (isValidRow(row, n) && col >= m)
        {
            col--;

            row += 2;

            turn++;
        }
        else if (!isValidRow(row, n) && !isValidCol(col, m))
        {

            if (row == n && col < 0)
            {
                row--;

                col += 2;
            }
            else if (col == m && row < 0)
            {
                row += 2;

                col--;
            }
            else
            {
                col += 2;

                row--;
            }

            turn++;
        }

        // if (!isValidRow(row, n) && isValidCol(col, m))
        // {
        //     if (row < 0)
        //     {
        //         row++;
        //     }
        //     else
        //     {
        //         row--;
        //     }

        //     turn++;
        //     // dbg(row, col);
        //     // dbg(turn);
        // }
        // else if (isValidRow(row, n) && (!isValidCol(col, m)))
        // {
        //     if (col < 0)
        //     {
        //         col++;
        //     }
        //     else
        //     {
        //         col--;
        //     }
        //     // dbg(row, col);
        //     // dbg(turn);

        //     turn++;
        // }
        // else if (!isValidRow(row, n) && !isValidCol(col, m))
        // {
        //     // row++;

        // if (row == n && col < 0)
        // {
        //     row--;

        //     col += 2;
        // }
        // else if (col == m && row < 0)
        // {
        //     row += 2;

        //     col--;
        // }
        // else
        // {
        //     col += 2;

        //     row--;
        // }

        //     // col--;

        //     // row++;

        //     // dbg(row, col);
        //     // dbg(turn);
        //     turn++;
        //     // dbg(turn);
        // }
    }

    return ans;
}

int main()
{

    vector<vector<int>> test = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};

    vector<int> ans = findDiagonalOrder(test);

    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }

    cout << endl;

    return 0;
}

// ॥ जय श्री राम जय श्री कृष्ण ॥