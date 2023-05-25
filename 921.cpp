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

// C++ Program for counting inversions in an array

// This uses the idea of Merge function of Merge Sort

int countandMerge(vector<int> &a, int left, int mid, int right)
{
    // dbg(left, mid, right);
    int sizleft = mid - left + 1, sizright = right - mid;

    // dbg(sizleft, sizright);

    vector<int> leftarray(sizleft);
    vector<int> rightarray(sizright);

    for (int i = 0; i < sizleft; i++)
    {
        leftarray[i] = a[left + i];
    }

    for (int i = 0; i < sizright; i++)
    {
        rightarray[i] = a[mid + 1 + i];
    }
    // dbg(leftarray, rightarray);

    int result = 0, des = 0, dex = 0, k = left;

    while (des < sizleft && dex < sizright)
    {
        if (leftarray[des] <= rightarray[dex])
        {
            a[k] = leftarray[des];

            des++;
        }
        else
        {
            a[k] = rightarray[dex];

            dex++;

            result += (sizleft - des);
        }

        // dbg(des, dex, k);
        k++;
    }

    while (des < sizleft)
    {
        a[k] = leftarray[des];

        k++;

        des++;
    }

    while (dex < sizright)
    {
        a[k] = rightarray[dex];

        k++;

        dex++;
    }

    return result;
}

int countInversions(vector<int> &a, int left, int right)
{

    int res = 0;

    // dbg(left, right, "CountInversions");

    if (left < right)
    {
        int mid = left + (right - left) / 2;

        res += countInversions(a, left, mid);

        res += countInversions(a, mid + 1, right);

        res += countandMerge(a, left, mid, right);
    }

    return res;
}

int main()
{

    vector<int> v = {4, 3, 2, 1};

    cout << countInversions(v, 0, 3) << endl;
    dbg(v);

    return 0;
}

// ॥ जय श्री राम जय श्री कृष्ण ॥