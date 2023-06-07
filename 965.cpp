// ॥ श्री गणेशाय नमः ॥

#include <bits/stdc++.h>
#include <chrono>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define ll long long
#define ull unsigned long long
using namespace std;
using namespace __gnu_pbds;

mt19937_64 rng(chrono::steady_clock().now().time_since_epoch().count());

int64_t myRandomNumber(int a, int b)
{
    return a + rng() % (b - a);
}

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
// typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_multiset;

class Solution
{
    unordered_map<int, pair<int, vector<int>>> m;

public:
    Solution(vector<int> &nums)
    {

        for (int i = 0; i < nums.size(); i++)
        {
            m[nums[i]].first = 0;
            m[nums[i]].second.push_back(i);
        }
    }

    int pick(int target)
    {
        m[target].first++;

        if (m[target].first == m[target].second.size())
        {
            m[target].first = 0;
        }

        int fir = m[target].first;

        // int las = m[target].first;

        // if (las == fir)
        // {
        //     las = 0;
        // }

        return m[target].second[fir];
    }
};

int main()
{

    cout << myRandomNumber(2, 5) << endl;

    return 0;
}

// ॥ जय श्री राम जय श्री कृष्ण ॥