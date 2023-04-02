// ॥ श्री गणेशाय नमः ॥

#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
#define ll long long
#define ull unsigned long long
using namespace std;

vector<vector<int>> kClosest(vector<vector<int>> &points, int k)
{
    int n = points.size();

    vector<pair<long long, int>> pos(n);

    for (int i = 0; i < n; i++)
    {
        pos[i].first = points[i][0] * 1LL * points[i][0] + points[i][1] * 1LL * points[i][1];

        pos[i].second = i;
    }

    sort(pos.begin(), pos.end());

    vector<vector<int>> ans(k);

    for (int i = 0; i < k; i++)
    {
        ans[i] = points[pos[i].second];
    }

    return ans;
}

int main()
{

    return 0;
}

// ॥ जय श्री राम जय श्री कृष्ण ॥