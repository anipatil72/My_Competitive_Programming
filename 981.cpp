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

vector<int> findRightInterval(vector<vector<int>> &intervals)
{
    int n = intervals.size();

    vector<pair<pair<int, int>, int>> v;

    for (int i = 0; i < n; i++)
    {
        v.push_back({{intervals[i][0], intervals[i][1]}, i});
    }

    sort(v.begin(), v.end());

    vector<int> ans;

    for (int i = 0; i < n; i++)
    {
        pair<pair<int, int>, int> p = {{intervals[i][1], intervals[i][0]}, 0};

        int pos = (int)(lower_bound(v.begin(), v.end(), p) - v.begin());

        if (pos == v.size())
        {
            ans.push_back(-1);
            // cout << "Ended!" << endl;
        }
        else
        {
            ans.push_back(v[pos].second);
            // cout << v[pos].first.first << " " << v[pos].first.second << endl;
        }
    }

    return ans;
}

int main()
{

    vector<pair<pair<int, int>, int>> v = {{{1, 4}, 0}, {{2, 2}, 1}, {{3, 4}, 2}};

    sort(v.begin(), v.end());

    pair<pair<int, int>, int> p = {{2, 2}, 0}; // for {2, 3};

    int pos = (int)(lower_bound(v.begin(), v.end(), p) - v.begin());

    if (pos == v.size())
    {
        cout << "Ended!" << endl;
    }
    else
    {
        cout << v[pos].first.first << " " << v[pos].first.second << endl;
    }

    return 0;
}

// ॥ जय श्री राम जय श्री कृष्ण ॥