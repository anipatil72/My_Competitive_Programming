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

int isPossible(int n, int m, string s)
{
    int len = s.length();

    int maxleft = 0, minileft = 0, minidown = 0, maxdown = 0, curleft = 0, curdown = 0;

    int anleft = 0, andown = 0;

    for (int i = 0; i < len; i++)
    {
        if (s[i] == 'R')
        {
            curleft++;
        }
        else if (s[i] == 'L')
        {

            curleft--;
        }
        else if (s[i] == 'U')
        {

            curdown--;
        }
        else
        {
            curdown++;
        }

        minileft = min(minileft, curleft);
        minidown = min(minidown, curdown);
        maxdown = max(maxdown, curdown);
        maxleft = max(maxleft, curleft);

        if (abs(minileft - maxleft) >= m || abs(minidown - maxdown) >= n)
        {
            return 0;
        }

        // dbg(i, curleft, curdown, minileft, maxleft, minidown, maxdown);
    }

    return 1;
}

int main()
{

    string test = "LLRU";

    cout << isPossible(2, 3, test);

    return 0;
}

// ॥ जय श्री राम जय श्री कृष्ण ॥