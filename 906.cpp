// ॥ श्री गणेशाय नमः ॥

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define ll long long
#define ull unsigned long long
using namespace std;
using namespace __gnu_pbds;

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

int recur(int index, vector<int> &dp, int count)
{
    cout << "I am here ! " << index << endl;

    count++;

    if (count >= 40)
    {
        return 0;
    }

    if (dp[index] != -1)
    {
        if (dp[index] == 1)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }

    dp[index] = 0;

    string tem = to_string(index);

    int len = tem.length();

    int sum = 0;

    for (int i = 0; i < len; i++)
    {
        sum += (tem[i] - '0') * (tem[i] - '0');
    }

    return dp[index] = recur(sum, dp, count + 1);
}

bool isHappy(int n)
{
    vector<int> dp(1200, -1);

    dp[1] = 1, dp[10] = 1, dp[100] = 1, dp[1000] = 1;

    string tem = to_string(n);

    int len = tem.length();

    int sum = 0;

    for (int i = 0; i < len; i++)
    {
        sum += (tem[i] - '0') * (tem[i] - '0');
    }

    int ans = recur(sum, dp, 1);

    return ans == 1;
}

int main()
{

    cout << isHappy(2);

    return 0;
}

// ॥ जय श्री राम जय श्री कृष्ण ॥