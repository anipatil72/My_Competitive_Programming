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

// int distributeCookies(vector<int> &cookies, int k)
// {
//     int n = cookies.size();

//     priority_queue<int, vector<int>, greater<int>> q;

//     sort(cookies.begin(), cookies.end());

//     for (int i = 0; i < k; i++)
//     {
//         q.push(cookies[i]);
//     }

//     for (int i = k; i < n; i++)
//     {
//         int des = q.top();

//         des += cookies[i];

//         q.pop();

//         q.push(des);
//     }

//     int ans = 0;

//     while (!q.empty())
//     {
//         ans = max(ans, q.top());

//         q.pop();
//     }

//     return ans;
// }

int check(vector<int> &fin, vector<int> &nums)
{
    int k = fin.size();

    int n = nums.size();

    int ans = 0;

    for (int i = 0; i < k; i++)
    {
        int tem = 0;

        int des = fin[i];

        for (int j = 0; j < n; j++)
        {
            if ((des & (1 << j)))
            {
                tem += nums[j];
            }
        }

        ans = max(ans, tem);
    }

    return ans;
}

void recur(int index, vector<int> &nums, vector<int> &fin, int &ans)
{
    int n = nums.size();

    int k = fin.size();

    if (index == n)
    {
        ans = min(ans, check(fin, nums));

        return;
    }

    for (int j = 0; j < k; j++)
    {
        int des = fin[j];

        fin[j] |= (1 << index);

        recur(index + 1, nums, fin, ans);

        fin[j] &= ~(1 << index);
    }
}

int distributeCookies(vector<int> &cookies, int k)
{
    int n = cookies.size();
    vector<int> fin(k, 0);

    int ans = 1e9;

    recur(0, cookies, fin, ans);

    return ans;
}
int main()
{

    vector<int> test = {8, 15, 10, 20, 8};

    int k = 2;

    cout << distributeCookies(test, k);

    return 0;
}

// ॥ जय श्री राम जय श्री कृष्ण ॥