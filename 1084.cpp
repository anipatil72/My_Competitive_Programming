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

// pair<int64_t, int64_t> recur(int index, int jindex, bool turn, vector<int> &nums)
// {

//     if (index > jindex)
//     {

//         dbg(index, jindex, 0, 0);

//         return {0, 0};
//     }

//     if (index == jindex)
//     {
//         return {nums[index], nums[index]};

//         if (turn)
//         {
//             dbg(index, jindex, turn, nums[index], 0);
//             return {nums[index], 0};
//         }

//         dbg(index, jindex, turn, 0, nums[jindex]);

//         return {0, nums[jindex]};
//     }

//     pair<int64_t, int64_t> fir = recur(index + 1, jindex, !turn, nums);

//     pair<int64_t, int64_t> las = recur(index, jindex - 1, !turn, nums);

//     int64_t mini = min({nums[index] + fir.second, nums[jindex] + las.second});
//     int64_t maxi = max({nums[index] + fir.first, nums[jindex] + las.first});

//     dbg(index, jindex, turn, maxi, mini);

//     if (turn)
//     {
//         return {maxi, mini};
//     }

//     return {mini, maxi};
// }

// bool PredictTheWinner(vector<int> &nums)
// {
//     int n = nums.size();

//     if (n % 2 == 0)
//     {
//         return true;
//     }

//     // pair<int64_t, int64_t> fir = recur(1, n - 1, 1, nums);

//     // pair<int64_t, int64_t> las = recur(0, n - 2, 1, nums);

//     // if ((nums[0] + 0LL + fir.second >= fir.first) || (nums[n - 1] + las.second >= las.first))
//     // {
//     //     cout << "We won" << endl;

//     //     return true;
//     // }

//     pair<int64_t, int64_t> des = recur(0, n - 1, 1, nums);

//     return des.first >= des.second;
// }

int64_t recur(int index, int jindex, bool turn, vector<int> &nums)
{

    // if (index > jindex)
    // {

    //     // dbg(index, jindex, 0, 0);

    //     return {0, 0};
    // }

    if (index == jindex)
    {
        // return {nums[index], nums[index]};

        if (turn)
        {
            dbg(index, jindex, turn, nums[index], 0);
            return nums[index];
        }

        dbg(index, jindex, turn, 0, nums[jindex]);

        return 0;
    }

    // pair<int64_t, int64_t> fir = recur(index + 1, jindex, !turn, nums);

    // pair<int64_t, int64_t> las = recur(index, jindex - 1, !turn, nums);

    // int64_t mini, maxi;

    // if (turn)
    // {
    //     mini = min(nums[index] + fir.second, nums[jindex] + las.second);

    //     maxi = max(nums[index] + fir.second, nums[jindex] + las.second);
    // }
    // else
    // {
    //     mini = min(fir.first, las.first);

    //     maxi = max(fir.first, las.second);
    // }

    // // int64_t mini = min({(turn ? nums[index] : 0) + fir.first, (turn ? nums[jindex] : 0) + las.first});
    // // int64_t maxi = max({(turn ? nums[index] : 0) + fir.second, (turn ? nums[jindex] : 0) + las.second});

    // dbg(index, jindex, turn, maxi, mini);

    // return {maxi, mini};
}

bool PredictTheWinner(vector<int> &nums)
{
    int n = nums.size();

    if (n % 2 == 0)
    {
        return true;
    }

    // pair<int64_t, int64_t> fir = recur(1, n - 1, 1, nums);

    // pair<int64_t, int64_t> las = recur(0, n - 2, 1, nums);

    // if ((nums[0] + 0LL + fir.second >= fir.first) || (nums[n - 1] + las.second >= las.first))
    // {
    //     cout << "We won" << endl;

    //     return true;
    // }

    int64_t des = recur(0, n - 1, 1, nums);

    return true;
}

int main()
{

    vector<int> nums = {1, 5, 2};

    cout << PredictTheWinner(nums);

    return 0;
}

// ॥ जय श्री राम जय श्री कृष्ण ॥