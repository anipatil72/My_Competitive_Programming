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

class MountainArray
{
public:
    int get(int index);
    int length();
};

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

int peakIndexInMountainArray(vector<int> &arr, int n)
{
    // int n = arr.size();

    int left = 0, right = n - 1, mid;

    while (left < right)
    {
        mid = (left + right) / 2;

        if (arr[mid] < arr[mid + 1])
        {
            left = mid + 1;
        }
        else
        {
            right = mid;
        }
    }

    return left;
}

int binSearchSaral(int low, int high, vector<int> &arr, int target)
{
    int left = low, right = high, mid;

    dbg(left, right, mid);

    while (left < right)
    {
        mid = (left + right) / 2;
        dbg(left, right, mid);

        // if (arr[mid] == target)
        // {
        //     return mid;
        // }

        // if (arr[left] == target)
        // {
        //     return left;
        // }

        // if (arr[right] == target)
        // {
        //     return mid;
        // }

        if (arr[mid] < target)
        {
            left = mid + 1;
        }
        else
        {
            right = mid;
        }
        dbg(left, right, mid);
    }

    return left;
}

int binSearchUlta(int low, int high, vector<int> &arr, int target)
{
    int left = low, right = high, mid;
    dbg(left, right, mid);

    while (left < right)
    {
        mid = (left + right) / 2;
        dbg(left, right, mid);

        // if (arr[mid] == target)
        // {
        //     return mid;
        // }

        // if (arr[left] == target)
        // {
        //     return left;
        // }

        // if (arr[right] == target)
        // {
        //     return mid;
        // }

        if (arr[mid] < target)
        {
            right = mid - 1;
        }
        else
        {
            left = mid;
        }

        if (left + 1 == right)
        {
            break;
        }

        dbg(left, right, mid);
    }

    if (arr[left] == target)
    {
        return left;
    }

    return right;
}

int findInMountainArray(int target, vector<int> &mountainArr)
{
    int n = mountainArr.size();

    int peak = peakIndexInMountainArray(mountainArr, n);

    dbg(peak);

    if (mountainArr[peak] == target)
    {
        return peak;
    }

    int left = binSearchSaral(0, peak, mountainArr, target);

    dbg(left);

    if (mountainArr[left] == target)
    {
        return left;
    }

    int right = binSearchUlta(peak, n - 1, mountainArr, target);

    if (mountainArr[right] == target)
    {
        return right;
    }

    return -1;
}

int main()
{

    vector<int> test = {0, 5, 3, 1};

    cout << findInMountainArray(3, test);

    return 0;
}

// ॥ जय श्री राम जय श्री कृष्ण ॥