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

int recur(int index, int buy, vector<int> &points)
{
    int n = points.size();

    if (index == n - 1)
    {
        if (buy == 1)
        {
            return points[n - 1];
        }

        return 0;
    }

    if (buy == 1)
    {
        return max(recur(index + 1, 0, points), recur(index + 1, 1, points));
    }
}

int minCostConnectPoints(vector<vector<int>> &points)
{
    int n = points.size();
}

int main()
{

    return 0;
}

// ॥ जय श्री राम जय श्री कृष्ण ॥