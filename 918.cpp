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
#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)

vector<int> max_of_subarrays(int *arr, int n, int k)
{
    deque<pair<int, int>> q;

    vector<int> ans(n - k + 1);

    int mex = arr[0];

    for (int i = 0; i < k; i++)
    {

        // mex = max(mex, arr[i]);
        // q.push_front({arr[i], i});

        int x = arr[i];

        while (!q.empty() && q.front().first < x)
        {
            q.pop_front();
        }

        q.push_front({x, i});
    }

    ans[0] = q.back().first;

    for (int i = k; i < n; i++)
    {
        if (q.back().second <= (i - k))
        {
            q.pop_back();
        }

        int x = arr[i];

        while (!q.empty() && q.front().first < x)
        {
            q.pop_front();
        }

        q.push_front({x, i});

        // dbg(q);

        mex = q.back().first;

        ans[i - k + 1] = mex;
    }

    return ans;
}

int main()
{

    int a[] = {1, 2, 3, 1, 4, 5, 2, 3, 6};

    int n = 9;

    int k = 3;

    vector<int> tem = max_of_subarrays(a, n, k);

    dbg(tem);

    return 0;
}

// ॥ जय श्री राम जय श्री कृष्ण ॥