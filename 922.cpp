// ॥ श्री गणेशाय नमः ॥

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define ll long long
#define ull unsigned long long
using namespace std;
using namespace __gnu_pbds;

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

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
// typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_multiset;

// Lomuto Partition
// Here we partition the array about the last element
// Slight modifications can be done to change the pivot about any element

// Hoare's Partition Always considers the first Element as its Pivot

int HoarePartition(vector<int> &arr, int low, int high)
{
    int pivot = arr[low];

    int i = low - 1, j = high + 1;

    while (true)
    {
        do
        {
            i++;

        } while (arr[i] < pivot);

        do
        {
            j--;
        } while (arr[j] > pivot);

        if (i >= j)
        {
            return j;
        }

        swap(arr[i], arr[j]);
    }
}

int LomutoPartition(vector<int> &arr, int low, int high)
{
    int pivot = arr[high];

    int i = low - 1;

    for (int j = low; j <= high - 1; j++)
    {
        if (arr[j] < pivot)
        {
            i++;

            swap(arr[j], arr[i]);
        }
    }

    // Lastly swapping the pivot element

    swap(arr[i + 1], arr[high]);

    return i + 1; /// Returns the index of the final pivot
}

// QuickSory using Lomuto Partition

void qSort(vector<int> &a, int low, int high)
{
    int n = a.size();

    if (low < high)
    {

        // cout << "I am going into Hoare Partition : " << low << " " << high << endl;
        int p = HoarePartition(a, low, high);

        // dbg(low, high);

        qSort(a, low, p);
        qSort(a, p + 1, high);
    }
}

int main()
{

    vector<int> a = {4, 3, 3, 2, 2, 2, 3, 4, 67};

    qSort(a, 0, a.size() - 1);

    // dbg(a);

    for (int i = 0; i < a.size(); i++)
    {
        cout << a[i] << " ";
    }

    return 0;
}

// ॥ जय श्री राम जय श्री कृष्ण ॥