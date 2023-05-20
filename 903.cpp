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

template <typename T_vector>
void output_vector(const T_vector &v, bool add_one = false, int start = -1, int end = -1)
{
    if (start < 0)
        start = 0;
    if (end < 0)
        end = int(v.size());

    for (int i = start; i < end; i++)
    {

        if (i == end - 1)
        {
            cout << v[i] + (add_one ? 1 : 0) << endl;
        }
        else
        {
            cout << v[i] + (add_one ? 1 : 0) << ' ';
        }
    }
}

void digout(vector<vector<string>> &equations, vector<double> &values, unordered_map<char, double> &m, int id)
{
    string temp(equations[id][0].length(), '?');

    // cout << "I am digging out at : " << id << endl;

    // int len = equations[id][0].length();

    // for (int i = 0; i < len; i++)
    // {
    //     if (equations[id][0][i] != '?')
    //     {
    //         cout << "I am adding : " << equations[id][0][i] << " here!" << endl;
    //         m[equations[id][0][i]] = 1.0 / values[id];

    //         // equations[id][0][i] = '?';

    //         // break;
    //     }
    // }

    if (temp == equations[id][0])
    {
        for (int i = 0; i < equations[id][1].length(); i++)
        {
            if (equations[id][1][i] != '?')
            {
                // cout << "I am adding : " << equations[id][1][i] << " here!" << endl;
                m[equations[id][1][i]] = 1.0 / values[id];

                equations[id][1][i] = '?';

                // break;
            }
        }
    }
    else
    {
        for (int i = 0; i < equations[id][0].length(); i++)
        {
            if (equations[id][0][i] != '?')
            {
                // cout << "I am adding : " << equations[id][0][i] << " here!" << endl;
                m[equations[id][0][i]] = values[id];

                equations[id][0][i] = '?';

                // break;
            }
        }
    }

    // dbg(equations, values, m, "101");
}

void simplify(vector<vector<string>> &equations, vector<double> &values, unordered_map<char, double> &m, vector<int> &rem)
{
    int n = equations.size();

    for (int i = 0; i < n; i++)
    {
        int len = equations[i][0].length();

        for (int j = 0; j < len; j++)
        {
            if (m.count(equations[i][0][j]) > 0)
            {
                values[i] /= (1.0 * m[equations[i][0][j]]);

                // dbg(values, "118");

                equations[i][0][j] = '?';

                rem[i]--;
            }
        }

        // dbg(equations, values, m, "126");

        len = equations[i][1].length();

        for (int j = 0; j < len; j++)
        {
            if (m.count(equations[i][1][j]) > 0)
            {
                values[i] *= (1.0 * m[equations[i][1][j]]);

                equations[i][1][j] = '?';

                rem[i]--;
            }
        }

        // dbg(equations, values, m, "142");
    }
}

void processInput(vector<vector<string>> &equations)
{
    int n = equations.size();

    vector<vector<string>> shadow(n);

    for (int i = 0; i < n; i++)
    {
        vector<int> pos1(26, 0);
        vector<int> pos2(26, 0);

        int len = equations[i][0].length();

        for (int j = 0; j < len; j++)
        {
            pos1[equations[i][0][j] - 'a']++;
        }

        len = equations[i][1].length();

        for (int j = 0; j < len; j++)
        {
            pos2[equations[i][1][j] - 'a']++;
        }

        for (int j = 0; j < 26; j++)
        {
            if (pos1[j] > pos2[j])
            {
                pos1[j] -= pos2[j];

                pos2[j] = 0;
            }
            else
            {
                pos2[j] -= pos1[j];

                pos1[j] = 0;
            }
        }

        string upp = "", low = "";

        for (int j = 0; j < 26; j++)
        {
            for (int k = 0; k < pos1[j]; k++)
            {
                char d = 'a' + j;

                upp += d;
            }

            for (int k = 0; k < pos2[j]; k++)
            {

                char d = 'a' + j;

                low += d;
            }
        }

        shadow[i] = {upp, low};
    }

    equations = shadow;
}

vector<double> calcEquation(vector<vector<string>> &equations, vector<double> &values, vector<vector<string>> &queries)
{
    int n = equations.size();

    processInput(equations);

    // output_vector(equations);

    // for (int i = 0; i < n; i++)
    // {
    //     cout << equations[i] << " ";
    // }

    vector<int> rem(n);

    for (int i = 0; i < n; i++)
    {
        rem[i] = equations[i][0].length() + equations[i][1].length();
    }

    unordered_map<char, double> m;

    for (int i = 0; i < n; i++)
    {
        int len = equations[i][0].length();

        for (int j = 0; j < len; j++)
        {
            if (m.count(equations[i][0][j]) == 0)
            {

                if (rem[i] > 1)
                {
                    m[equations[i][0][j]] = 1.0;

                    // rem[i]--;
                    simplify(equations, values, m, rem);
                }
                else
                {
                    digout(equations, values, m, i);

                    simplify(equations, values, m, rem);
                }
            }
        }

        // dbg(equations, values, m, "184");

        len = equations[i][1].length();

        for (int j = 0; j < len; j++)
        {
            if (m.count(equations[i][1][j]) == 0)
            {

                if (rem[i] != 1)
                {
                    m[equations[i][1][j]] = 1.0;

                    // rem[i]--;
                    simplify(equations, values, m, rem);
                }
                else
                {
                    digout(equations, values, m, i);

                    simplify(equations, values, m, rem);
                }
            }
        }

        // dbg(equations, values, m, "209");
    }

    // for (int i = 0; i < n; i++)
    // {
    //     int len = equations[i][0].length();

    //     double numerator = 1.0;

    //     for (int j = 0; j < len; j++)
    //     {
    //         if (m.count(equations[i][0][j]) == 0)
    //         {
    //             // m[equations[i][0][j]] = 1.0;
    //         }
    //         else
    //         {
    //             values[i] /= m[equations[i][0][j]];

    //             equations[i][0][j] = '0';
    //         }
    //     }
    // }

    // for (int i = 0; i < n; i++)
    // {
    //     // if (m.count(equations[i][0][0]) == 0 && m.count(equations[i][1][0]) == 0)
    //     // {
    //     //     m[equations[i][1][0]] = 1.0;
    //     //     m[equations[i][0][0]] = values[i];
    //     // }
    //     // else if (m.count(equations[i][0][0]) != 0 && m.count(equations[i][1][0]) == 0)
    //     // {
    //     //     m[equations[i][1][0]] = m[equations[i][0][0]] / values[i];
    //     // }
    //     // else if (m.count(equations[i][0][0]) == 0 && m.count(equations[i][1][0]) != 0)
    //     // {
    //     //     m[equations[i][0][0]] = m[equations[i][1][0]] * values[i];
    //     // }
    //     // else
    //     // {
    //     //     if (values[i] != m[equations[i][0][0]] / m[equations[i][1][0]])
    //     //     {
    //     //         con[equations[i][1][0]] = m[equations[i][1][0]];

    //     //         con[equations[i][0][0]] = m[equations[i][0][0]];
    //     //     }
    //     // }

    //     // dbg(m);
    // }

    dbg(m, "261");

    int q = queries.size();

    vector<double> ans(q);

    for (int i = 0; i < q; i++)
    {

        int len = queries[i][0].length();

        double numerator = 1.0;

        bool flag = false;

        for (int j = 0; j < len; j++)
        {
            if (m.count(queries[i][0][j]) != 0)
            {
                // ans[i] = -1.0;

                numerator *= m[queries[i][0][j]];
            }
            else
            {

                flag = true;
                break;
            }
        }

        if (flag)
        {
            ans[i] = -1.0;

            continue;
        }

        len = queries[i][1].length();

        double denominator = 1.0;

        for (int j = 0; j < len; j++)
        {
            if (m.count(queries[i][1][j]) != 0)
            {
                // ans[i] = -1.0;

                denominator *= m[queries[i][1][j]];
            }
            else
            {

                flag = true;
                break;
            }
        }

        if (flag)
        {
            ans[i] = -1.0;

            continue;
        }

        ans[i] = numerator / denominator;
    }

    return ans;

    // return {};
}

int main()
{

    vector<vector<string>> equations = {{"a", "aa"}};
    vector<vector<string>> queries = {{"aa", "a"}, {"aa", "aa"}};

    vector<double> values = {9.0};

    vector<double> ans = calcEquation(equations, values, queries);

    output_vector(ans);

    // string a = "a";

    // string b = "aa";

    // cout << (b > a) << endl;
    // double z = 1.0 * 5 / 3;

    // cout << fixed << setprecision(5);

    // cout << z << endl;

    return 0;
}

// ॥ जय श्री राम जय श्री कृष्ण ॥