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

int equalPairs(vector<vector<int>> &grid)
{
    int n = grid[0].size();

    map<vector<int>, int> m;

    for (int i = 0; i < n; i++)
    {
        vector<int> tem(n);
        for (int j = 0; j < n; j++)
        {
            tem[j] = grid[j][i];
        }

        m[tem]++;
    }

    int ans = 0;

    for (int i = 0; i < n; i++)
    {
        if (m.count(grid[i]) > 0)
        {
            ans += m[grid[i]];
        }
    }

    return ans;
}

int main()
{

    return 0;
}

// ॥ जय श्री राम जय श्री कृष्ण ॥