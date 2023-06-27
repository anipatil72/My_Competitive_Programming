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

vector<int> frequencySort(vector<int> &nums)
{
    unordered_map<int, int> m;

    int n = nums.size();

    for (int i = 0; i < n; i++)
    {
        m[nums[i]]++;
    }

    vector<vector<int>> pos(n + 1);

    for (auto x : m)
    {
        pos[x.second].push_back(x.first);
    }

    int des = 0;

    for (int i = 1; i < n + 1; i++)
    {

        if (pos[i].size() > 0)
        {
            sort(pos[i].begin(), pos[i].end(), greater<int>());

            for (int j = 0; j < pos[i].size(); j++)
            {
                for (int k = 0; k < i; k++)
                {
                    nums[des++] = pos[i][j];
                }
            }
        }
    }

    return nums;
}

int main()
{

    return 0;
}

// ॥ जय श्री राम जय श्री कृष्ण ॥