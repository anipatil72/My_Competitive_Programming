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

int maximalNetworkRank(int n, vector<vector<int>> &roads)
{
    vector<unordered_set<int>> adj(n);

    int len = roads.size();

    for (int i = 0; i < len; i++)
    {
        adj[roads[i][0]].insert(roads[i][1]);
        adj[roads[i][1]].insert(roads[i][0]);
    }

    int ans = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (i != j)
            {
                int des = (adj[i].size() + adj[j].size());

                if (adj[i].count(j) > 0)
                {
                    ans = max(ans, des - 1);
                }
                else
                {
                    ans = max(ans, des);
                }
            }
        }
    }

    return ans;
}

int main()
{

    return 0;
}

// ॥ जय श्री राम जय श्री कृष्ण ॥