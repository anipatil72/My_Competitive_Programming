// ॥ श्री गणेशाय नमः ॥

#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
#define ll long long
#define ull unsigned long long
using namespace std;

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

int lengthOfLongestSubstring(string s)
{
    int n = s.length();

    if (n == 0)
    {
        return n;
    }

    // vector<int> ref(26, 1);

    unordered_map<char, int> m;

    int left = 0, right = 0;

    // vector<int> temp = ref;

    int ans = 0;

    // temp[s[0] - '0'] = 0;

    int count = 0;

    // cout << "This is left : " << left << " "
    //      << "This is right : " << right << " count : " << count << endl;

    while (right < n)
    {
        // cout << "This is left : " << left << " "
        //      << "This is right : " << right<<" count : "<<count << endl;

        if (m.count(s[right]) == 0)
        {
            m[s[right]]++;
            // dbg(m);

            count++;

            ans = max(ans, count);
        }
        else
        {
            // temp = ref;

            // m.clear();

            m[s[right]]++;

            count++;

            char cur = s[right];

            while (left < right && m[cur] > 1)
            {

                // dbg(m);

                m[s[left]]--;

                // dbg(m);

                count--;

                // cout << "This is left : " << left << " "
                //      << "This is right : " << right << " count : " << count << endl;

                left++;
                // cout << "This is left : " << left << " "
                //      << "This is right : " << right << " count : " << count << endl;
            }

            // cout << "Here : " << right<<" count : "<<count << endl;

            // temp[s[right] - 'a'] = 0;

            // m[s[right]]++;

            // right++;

            // ans++;
            ans = max(ans, count);

            // count = 1;
        }
        // cout << "This is left : " << left << " "
        //      << "This is right : " << right << " count : " << count << endl;
        right++;
        // cout << "This is left : " << left << " "
        //      << "This is right : " << right << " count : " << count << endl;
    }
    ans = max(ans, count);

    return ans;
}

int main()
{

    string s = "dvdf";

    cout << lengthOfLongestSubstring(s);

    return 0;
}

// ॥ जय श्री राम जय श्री कृष्ण ॥