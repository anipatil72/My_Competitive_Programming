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

// https://leetcode.com/problems/find-k-pairs-with-smallest-sums/  Will do by two pointers only !!, I was wrong!

vector<vector<int>> kSmallestPairs(vector<int> &nums1, vector<int> &nums2, int k)
{
    // int n = a.size();

    // int m = b.size();

    // long long possi = n * 1LL * m;

    // if (k == 1)
    // {
    //     return {{a[0], b[0]}};
    // }

    // vector<vector<int>> ans;

    // set<pair<int, int>> dec;

    // ans.push_back({a[0], b[0]});

    // int aa = 0, bb = 0, ba = 1, ab = 1;

    // dbg(aa, ab, bb, ba);

    // int num = 1;

    // while (num < k && (num < possi) && (aa < n && ab < m && ba < n && bb < m))
    // {

    //     // check the bounds

    //     // aa < n , ab < m , bb < m , ba < n;

    //     dbg(ans);

    //     dbg(aa, ab, bb, ba);

    //     if ((aa < n && ab < m && bb < m && ba < n) && (a[aa] + b[ab] > b[bb] + a[ba]))
    //     {

    //         dbg(aa, ab, bb, ba);

    //         dbg(ans);

    //         ans.push_back({a[ba], b[bb]});

    //         dbg(ans);

    //         dbg(aa, ab, bb, ba);

    //         num++;

    //         ba++;

    //         dbg(aa, ab, bb, ba);

    //         if (ba >= n)
    //         {
    //             bb++;

    //             dbg(aa, ab, bb, ba);

    //             ba = aa + 1;

    //             dbg(aa, ab, bb, ba);
    //         }
    //     }
    //     else
    //     {
    //         dbg(aa, ab, bb, ba);

    //         dbg(ans);

    //         ans.push_back({a[aa], b[ab]});

    //         dbg(ans);

    //         dbg(aa, ab, bb, ba);

    //         num++;

    //         //

    //         ab++;

    //         dbg(aa, ab, bb, ba);

    //         if (ab >= m)
    //         {

    //             aa++;

    //             dbg(aa, ab, bb, ba);

    //             ab = bb + 1;

    //             dbg(aa, ab, bb, ba);
    //         }
    //     }

    //     // return ans;
    // }

    // while ((num < k) && (num < possi) && (aa < n))
    // {
    //     while ((num < k) && ab < m)
    //     {

    //         dbg(aa, ab, bb, ba);

    //         dbg(ans);

    //         ans.push_back({a[aa], b[ab]});

    //         dbg(ans);

    //         dbg(aa, ab, bb, ba);

    //         num++;

    //         ab++;

    //         dbg(aa, ab, bb, ba);
    //     }

    //     ab = 0;

    //     aa++;

    //     dbg(aa, ab, bb, ba);
    // }

    // while ((num < k) && (num < possi) && bb < m)
    // {
    //     while ((num < k) && ba < n)
    //     {

    //         dbg(aa, ab, bb, ba);

    //         dbg(ans);

    //         ans.push_back({a[ba], b[bb]});

    //         dbg(ans);

    //         dbg(aa, ab, bb, ba);

    //         num++;

    //         ba++;

    //         dbg(aa, ab, bb, ba);
    //     }

    //     ba = 0;

    //     bb++;

    //     dbg(aa, ab, bb, ba);
    // }

    // return ans;

    vector<vector<int>> ret;
    auto comp = [&nums1, &nums2](const pair<int, int> &a, const pair<int, int> &b)
    {
        return nums1[a.first] + nums2[a.second] > nums1[b.first] + nums2[b.second];
    };
    priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(comp)> pq(comp);

    pq.push({0, 0});
    while (pq.size() && k--)
    {
        auto idx = pq.top();

        pq.pop();

        int i = idx.first, j = idx.second;

        ret.push_back(vector<int>({nums1[i], nums2[j]}));

        if (j + 1 < nums2.size())
        {
            pq.push({i, j + 1});
        }
        if (i + 1 < nums1.size())
        {
            pq.push({i + 1, j});
        }
    }
    return ret;
}

int main()
{

    vector<int> a = {-10, -4, 0, 0, 6};

    vector<int> b = {3, 5, 6, 7, 8, 100};

    int k = 10;

    vector<vector<int>> ans = kSmallestPairs(a, b, k);

    dbg(ans);

    return 0;
}

// [-10,-4,0,0,6]
// [3,5,6,7,8,100]
// 10

// Answer is : [[-10,3],[-10,5],[-10,6],[-10,7],[-10,8],[-4,3],[-4,5],[-4,6],[0,3],[0,3]]

//             {{-10, 3}, {-10, 5}, {-10, 6}, {-10, 7}, {-10, 8}, {-4, 3}, {0, 3}, {0, 3}, {6, 3}, {-4, 5}}

// ॥ जय श्री राम जय श्री कृष्ण ॥