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

const int MAX = 10000;

int findK(vector<vector<int>> &a, int n, int m, int k)
{
    int left = 0, right = m - 1, up = 0, down = n - 1;

    int des = 0, ans = -1;

    for (int count = 0; left <= right && up <= down; count++)
    {
        if (count % 4 == 0)
        {
            // dbg(left, right, up, down);

            for (int i = left; i <= right && des < k; i++)
            {
                des++;

                // cout << "These are indices : " << up << " " << i << endl;

                // cout << a[up][i] << " ";

                // dbg(up, i);

                ans = a[up][i];
            }

            if (des == k)
            {
                return ans;
            }

            up++;
        }

        if (count % 4 == 1)
        {
            // dbg(left, right, up, down);

            for (int i = up; i <= down && des < k; i++)
            {
                des++;

                // cout << "These are indices : " << i << " " << right << endl;

                // dbg(i, right);

                ans = a[i][right];

                // cout << a[i][right] << " ";

                // cout << ans << endl;
            }

            if (des == k)
            {
                return ans;
            }

            right--;
        }

        if (count % 4 == 2)
        {
            // dbg(left, right, up, down);

            for (int i = right; i >= left && des < k; i--)
            {
                des++;

                // cout << "These are indices : " << down << " " << i << endl;

                // dbg(down, i);

                ans = a[down][i];

                // cout << a[down][i] << " ";

                // cout << ans << endl;
            }

            if (des == k)
            {
                return ans;
            }

            down--;
        }

        if (count % 4 == 3)
        {
            // dbg(left, right, up, down);

            for (int i = down; i >= up && des < k; i--)
            {
                des++;

                // cout << "These are indices : " << i << " " << left << endl;

                // dbg(i, left);

                ans = a[i][left];

                // cout << a[i][left] << " ";

                // cout << ans << endl;
            }

            if (des == k)
            {
                return ans;
            }

            left++;
        }

        // count++;
    }

    return ans;
}

int main()
{

    vector<vector<int>> spiral = {{1, 2, 3},
                                  {4, 5, 6},
                                  {7, 8, 9}};

    int k = 9;

    cout << findK(spiral, 3, 3, k) << endl;

    return 0;
}

// ॥ जय श्री राम जय श्री कृष्ण ॥