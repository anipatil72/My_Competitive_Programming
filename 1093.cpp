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

bool myComp(vector<int> &a, vector<int> &b)
{
    if (a[1] == b[1])
    {
        return a[0] < b[0];
    }

    return a[1] < b[1];
}

int maxEvents(vector<vector<int>> &events)
{
    int n = events.size();

    sort(events.begin(), events.end(), myComp);

    int ans = 0, last = 0;

    for (int i = 0; i < n; i++)
    {
    }
}

int main()
{

    vector<vector<int>> test = {{1, 5},
                                {1, 1},
                                {2, 2},
                                {3, 3},
                                {4, 4}};

    sort(test.begin(), test.end(), myComp);

    for (auto x : test)
    {
        cout << x[0] << " " << x[1] << endl;
    }

    return 0;
}

// ॥ जय श्री राम जय श्री कृष्ण ॥