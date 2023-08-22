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

void recur(vector<int> &nums, vector<int> &tem, vector<int> &vis, vector<vector<int>> &ans)
{
    int n = nums.size();

    if (tem.size() == n)
    {
        ans.push_back(tem);

        return;
    }

    for (int i = 0; i < n; i++)
    {
        if (vis[i] == 1)
        {
            vis[i] = 0;

            tem.push_back(nums[i]);

            recur(nums, tem, vis, ans);

            tem.pop_back();

            vis[i] = 1;
        }
    }
}

vector<vector<int>> prem(vector<int> &nums)
{
    int n = nums.size();

    vector<int> vis(n, 1);

    vector<int> tem;

    vector<vector<int>> ans;

    recur(nums, tem, vis, ans);

    return ans;
}

int main()
{

    vector<int> nums = {1, 2, 3};

    vector<vector<int>> ans;

    vector<int> tem;

    vector<int> vis(nums.size(), 1);

    recur(nums, tem, vis, ans);

    for (auto &x : ans)
    {
        for (auto &y : x)
        {
            cout << y << " ";
        }

        cout << endl;
    }

    return 0;
}

// ॥ जय श्री राम जय श्री कृष्ण ॥