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

vector<int> sortArrayByParityII(vector<int> &nums)
{
    // int n = nums.size();

    // int cur = 1000000, prev, index;

    // int even = 0, odd = 1;

    // // int tem = nums[0];

    // int pos = 0;

    // while (pos < n)
    // {

    //     cur = nums[pos];

    //     cout << "I am here ! : " << pos << endl;

    //     for (int i = 0; i < n; i++)
    //     {
    //         cout << nums[i] << " ";
    //     }

    //     cout << endl;

    //     nums[pos] = -1;

    //     int tex = (cur % 2 == 0 ? even : odd);

    //     int count = 0;

    //     while ((cur != -1) && (even < n && odd < n))
    //     {
    //         tex = (cur % 2 == 0 ? even : odd);
    //         int tem = nums[tex];

    //         cout << "I am at tex : " << tex << " " << cur << endl;

    //         nums[tex] = cur;

    //         // tex += 2;

    //         if (cur % 2 == 0)
    //         {
    //             even += 2;
    //         }
    //         else
    //         {
    //             odd += 2;
    //         }

    //         cur = tem;

    //         count++;
    //     }

    //     // dbg(nums);

    //     pos++;
    // }

    int n = nums.size();
    int i = 0;
    int j = 1;
    while (i < n && j < n)
    {
        if (nums[i] % 2 == 0)
        {
            i = i + 2;
        }
        else if (nums[j] % 2 == 1)
        {
            j = j + 2;
        }
        else
        {
            swap(nums[i], nums[j]);
        }
    }
    return nums;

    // for (int i = 0; i < n - 1; i++)
    // {
    //     if (nums[i] % 2 == 1)
    //     {

    //         index = i;

    //         break;
    //     }
    // }

    // if (nums[n - 1] % 2 == 0)
    // {
    //     swap(nums[index], nums[n - 1]);
    // }

    // for (int i = 0; i < n - 1; i++)
    // {
    //     if (i % 2 != nums[i] % 2)
    //     {
    //         cur = nums[i + 1];

    //         int parity = nums[i] % 2;

    //         prev = i;

    //         nums[i + 1] = nums[i];

    //         int tem = i + 1;

    //         while ((tem < n - 1) &&)
    //         {
    //         }
    //     }

    return nums;
    // }
}

int main()
{

    vector<int> a = {4, 2, 5, 7};

    vector<int> ans = sortArrayByParityII(a);

    return 0;
}

// ॥ जय श्री राम जय श्री कृष्ण ॥