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

vector<vector<int>> minimumAbsDifference(vector<int> &arr)
{
    int n = arr.size();

    sort(arr.begin(), arr.end());

    int mini = 1e7;

    for (int i = 0; i < n - 1; i++)
    {
        mini = min(mini, abs(arr[i] - arr[i + 1]));
    }

    vector<vector<int>> ans;

    for (int i = 0; i < n - 1; i++)
    {
        if (mini == abs(arr[i] - arr[i + 1]))
        {
            ans.push_back({arr[i], arr[i + 1]});
        }
    }

    return ans;
}

int main()
{

    return 0;
}

// ॥ जय श्री राम जय श्री कृष्ण ॥