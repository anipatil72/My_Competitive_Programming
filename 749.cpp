// ॥ श्री गणेशाय नमः ॥

#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define M 1000000007
using namespace std;

void __print(int x) { cerr << x; }
void __print(long x) { cerr << x; }
void __print(long long x) { cerr << x; }
void __print(unsigned x) { cerr << x; }
void __print(unsigned long x) { cerr << x; }
void __print(unsigned long long x) { cerr << x; }
void __print(float x) { cerr << x; }
void __print(double x) { cerr << x; }
void __print(long double x) { cerr << x; }
void __print(char x) { cerr << '\'' << x << '\''; }
void __print(const char *x) { cerr << '"' << x << '"'; }
void __print(const string &x) { cerr << '"' << x << '"'; }
void __print(bool x) { cerr << (x ? "true" : "false"); }

template <typename T, typename V>
void __print(const pair<T, V> &x)
{
    cerr << '{';
    __print(x.first);
    cerr << ',';
    __print(x.second);
    cerr << '}';
}
template <typename T>
void __print(const T &x)
{
    int f = 0;
    cerr << '{';
    for (auto &i : x)
        cerr << (f++ ? "," : ""), __print(i);
    cerr << "}";
}
void _print() { cerr << "]\n"; }
template <typename T, typename... V>
void _print(T t, V... v)
{
    __print(t);
    if (sizeof...(v))
        cerr << ", ";
    _print(v...);
}
#ifndef ONLINE_JUDGE
#define debug(x...)               \
    cerr << "[" << #x << "] = ["; \
    _print(x)
#else
#define debug(x...)
#endif

int maxPoints(vector<vector<int>> &points)
{
    int n = points.size();

    if (n == 1)
    {
        return 1;
    }

    // sort(points.begin(), points.end());

    unordered_map<double, int> ver;

    map<pair<pair<int, int>, int>, int> m;

    // set<pair<double, int>> s;

    int inf = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            int slopenum, slopeden;

            auto x = points[i];

            auto y = points[j];

            slopenum = (y[1] - x[1]);

            if ((y[0] - x[0]) == 0)
            {
                // m[-1.0]++;

                ver[x[0]]++;

                inf++;

                continue;
            }

            slopeden = (y[0] - x[0]);

            int g = __gcd(slopenum, slopeden);

            slopenum/=g;

            slopeden/=g;

            if (slopenum == 0)
            {

                m[{{0, 0}, x[1]}]++;
            }
            else
            {
                int c = y[1] * (slopeden) - y[0] * (slopenum);

                m[{{slopenum, slopeden}, c}]++;
            }

            // m[slope]++;
        }
    }

    // debug(m);
    // debug(s);
    int mini = INT_MIN;

    for (auto x : m)
    {
        mini = max(mini, x.second);
    }

    // mini = max(mini, inf);

    for (auto x : ver)
    {
        mini = max(mini, x.second);
    }

    map<int, int> pos;

    for (int i = 2; i <= 300; i++)
    {
        pos[(((i - 1) * (i)) / 2)] = i;
    }

    // debug(pos);

    // cout << mini << endl;

    return pos[mini];
}

int main()
{

    vector<vector<int>> points = {{-6, -1}, {3, 1}, {12, 3}};

    // [[1,1],[3,2],[5,3],[4,1],[2,3],[1,4]]

    cout << maxPoints(points);

    return 0;
}

// [[4,5],[4,-1],[4,0]]

// [[0,0],[4,5],[7,8],[8,9],[5,6],[3,4],[1,1]]

// [[-6,-1],[3,1],[12,3]]

// ॥ जय श्री राम जय श्री कृष्ण ॥