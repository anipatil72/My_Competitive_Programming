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

int recur(int now, int k, int last, unordered_map<int, unordered_map<int, int>> &m)
{
    if (now > last)
    {
        return false;
    }

    if (now == last)
    {
        return true;
    }

    bool ans = 0;

    bool plus = 0, same = 0, minus = 0;

    if (m.count(now + k + 1) > 0)
    {
        if (m[now].count(now + k + 1) > 0)
        {
            plus = m[now][now + k + 1];
        }
        else
        {
            plus = recur(now + k + 1, k + 1, last, m);

            m[now][now + k + 1] = plus;
        }
    }

    if (m.count(now + k) > 0)
    {
        if (m[now].count(now + k) > 0)
        {
            same = m[now][now + k];
        }
        else
        {
            same = recur(now + k, k, last, m);

            m[now][now + k] = same;
        }
    }

    if ((k > 1) && m.count(now + k - 1) > 0)
    {
        if (m[now].count(now + k - 1) > 0)
        {
            minus = m[now][now + k - 1];
        }
        else
        {
            minus = recur(now + k - 1, k - 1, last, m);

            m[now][now + k - 1] = minus;
        }
    }

    return (plus | same | minus);
}

bool canCross(vector<int> &stones)
{
    int n = stones.size();

    if (n == 2)
    {
        if (stones[0] + 1 == stones[1])
        {
            return true;
        }

        return false;
    }

    if ((stones[0] + 1) != stones[1])
    {
        return false;
    }

    unordered_map<int, unordered_map<int, int>> m;

    for (int i = 0; i < n; i++)
    {
        m[stones[i]] = {};
    }

    return recur(stones[1], 1, stones[n - 1], m);
}

int main()
{

    vector<int> stones = {0, 1, 2, 3, 4, 8, 9, 11};

    cout << canCross(stones) << endl;

    // unordered_map<int, unordered_map<int, int>> m;

    // m[1] = {};

    // for (auto &x : m)
    // {
    //     cout << "For : " << x.first << " " << endl;
    //     for (auto &y : x.second)
    //     {
    //         cout << y.first << " " << y.second << endl;
    //     }
    // }

    return 0;
}

// ॥ जय श्री राम जय श्री कृष्ण ॥