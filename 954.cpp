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

vector<vector<int>> findWinners(vector<vector<int>> &matches)
{
    int n = matches.size();

    unordered_map<int, pair<int, int>> m;

    for (int i = 0; i < n; i++)
    {
        m[matches[i][0]].first++;

        m[matches[i][1]].second++;
    }

    vector<vector<int>> ans(2);

    for (auto x : m)
    {
        if (x.second.second == 0)
        {
            ans[0].push_back(x.first);
        }
        else if (x.second.second == 1)
        {
            ans[1].push_back(x.first);
        }
    }

    sort(ans[0].begin(), ans[0].end());
    sort(ans[1].begin(), ans[1].end());

    return ans;
}

int main()
{

    return 0;
}

// ॥ जय श्री राम जय श्री कृष्ण ॥