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

string reorganizeString(string s)
{
    int n = s.length();

    if (n == 1)
    {
        return s;
    }

    vector<int> des(26);

    for (int i = 0; i < n; i++)
    {
        des[s[i] - 'a']++;

        if (des[i] > (n + 1) / 2)
        {
            return "";
        }
    }

    // dbg(des);

    priority_queue<pair<int, int>> q;

    for (int i = 0; i < 26; i++)
    {
        q.push({des[i], i});
    }

    // dbg(q);

    string ans = "";

    int len = ans.size();

    pair<int, int> a;
    pair<int, int> b;

    a = q.top();

    q.pop();

    b = q.top();

    q.pop();

    ans += ((char)('a' + a.second));

    a.first--;

    // dbg(ans);

    while (ans.length() < n && (!q.empty()))
    {

        if (a.first == 0)
        {

            // if (q.empty())
            // {

            //     // char aa = 'a' + a.second;

            //     char bb = 'a' + b.second;

            //     if (ans.back() != bb && b.first == 1)
            //     {
            //         ans += bb;

            //         dbg(ans);

            //         return ans;
            //     }
            //     else if (b.first == 0)
            //     {
            //         dbg(ans);
            //         return ans;
            //     }

            //     dbg(ans);

            //     return "";
            // }

            a = q.top();

            q.pop();
        }

        if (b.first == 0)
        {

            // if (q.empty())
            // {

            //     char aa = 'a' + a.second;

            //     // char bb = 'a' + b.second;

            //     // cout << "I am here ! and the value of " << ans << endl;

            //     if (ans.back() != aa && a.first == 1)
            //     {
            //         ans += aa;

            //         dbg(ans);

            //         return ans;
            //     }
            //     else if (a.first == 0)
            //     {
            //         dbg(ans);
            //         return ans;
            //     }

            //     dbg(ans);
            //     return "";
            // }
            // cout << "I am here ! and the value of " << ans << endl;

            b = q.top();
            q.pop();
        }

        char aa = 'a' + a.second;

        char bb = 'a' + b.second;

        if (ans.back() == aa && a.first > 0)
        {
            // dbg(ans);
            ans += bb;
            dbg(ans);

            b.first--;
        }
        else if (ans.back() == bb && b.first > 0)
        {
            // dbg(ans);
            ans += aa;
            dbg(ans);

            a.first--;
        }

        // dbg(a, b);

        // dbg(ans);
    }

    // dbg(ans);

    return ans;
}

int main()
{

    string test = "vvvlo";

    cout << reorganizeString(test) << endl;

    return 0;
}

// ॥ जय श्री राम जय श्री कृष्ण ॥