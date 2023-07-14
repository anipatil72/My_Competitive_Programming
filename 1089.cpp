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

bool canFinish(int numCourses, vector<vector<int>> &pre)
{
    int n = numCourses;

    int req = pre.size();

    vector<vector<int>> adj(n);

    for (int i = 0; i < req; i++)
    {
        adj[pre[i][0]].push_back(pre[i][1]);
    }

    vector<int> path(n, 1);

    vector<int> visited(n, 1);
}

int main()
{

    return 0;
}

// ॥ जय श्री राम जय श्री कृष्ण ॥