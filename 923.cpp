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

vector<int> pivotArray(vector<int> &arr, int pivot)
{
    int n = arr.size();

    int low = 0, high = n - 1;

    int i = low - 1;

    vector<int> ans;

    for (int j = low; j <= high; j++)
    {
        if (arr[j] < pivot)
        {
            i++;

            swap(arr[j], arr[i]);
        }
        else if (arr[j] > pivot)
        {
            ans.push_back(arr[j]);
        }
    }

    for (int j = low; j <= high; j++)
    {
        if (arr[j] == pivot)
        {
            i++;

            swap(arr[j], arr[i]);
        }
    }

    i++;

    int pos = 0;

    for (int j = i; j < n && pos < ans.size(); j++)
    {

        arr[i] = ans[pos];

        i++;

        pos++;
    }

    // Lastly swapping the pivot element

    // swap(arr[i + 1], arr[high]);

    return arr; /// Returns the index of the final pivot
}

int main()
{

    vector<int> nums = {-3, 4, 3, 2};

    int pivot = 2;

    vector<int> ans = pivotArray(nums, pivot);

    dbg(ans);

    return 0;
}

// ॥ जय श्री राम जय श्री कृष्ण ॥