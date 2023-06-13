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

vector<string> commonChars(vector<string> &words)
{
    vector<int> pos(26, 0);

    bool flag = true;

    int n = words.size();

    for (int i = 0; i < n; i++)
    {
        int len = words[i].length();

        vector<int> tem(26, 0);

        for (int j = 0; j < len; j++)
        {
            tem[words[i][j] - 'a']++;
        }

        if (flag)
        {
            pos = tem;

            flag = false;
        }
        else
        {
            for (int j = 0; j < 26; j++)
            {
                pos[j] = min(pos[j], tem[j]);
            }
        }
    }

    dbg(pos);

    vector<string> ans;

    string dum = "abcdefghijklmnopqrstuvwxyz";

    for (int i = 0; i < 26; i++)
    {
        for (int j = 0; j < pos[i]; j++)
        {
            char d = dum[i];

            string nex = "";
            nex += d;

            ans.push_back(nex);
        }
    }

    return ans;
}

int main()
{

    vector<string> test = {"bella", "label", "roller"};

    vector<string> ans = commonChars(test);

    dbg(ans);

    return 0;
}

// ॥ जय श्री राम जय श्री कृष्ण ॥