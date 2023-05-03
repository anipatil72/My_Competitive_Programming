// ॥ श्री गणेशाय नमः ॥

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define ll long long
#define ull unsigned long long
using namespace std;
using namespace __gnu_pbds;

vector<vector<int>> findDifference(vector<int> &nums1, vector<int> &nums2)
{
    int n = nums1.size();

    int m = nums2.size();

    unordered_map<int, int> mp1;
    unordered_map<int, int> mp2;

    for (int i = 0; i < n; i++)
    {
        if (mp1.count(nums1[i]) == 0)
        {
            mp1[nums1[i]]++;
        }
    }

    for (int i = 0; i < m; i++)
    {
        if (mp2.count(nums2[i]) == 0)
        {
            mp2[nums2[i]]++;
        }
    }

    vector<vector<int>> ans(2);

    unordered_map<int, int> test1, test2;

    for (int i = 0; i < n; i++)
    {

        if (mp2.count(nums1[i]) == 0 && test1.count(nums1[i]) == 0)
        {
            ans[0].push_back(nums1[i]);

            test1[nums1[i]]++;
        }
    }

    for (int i = 0; i < m; i++)
    {

        if (mp1.count(nums2[i]) == 0 && test2.count(nums2[i]) == 0)
        {
            ans[1].push_back(nums2[i]);

            test2[nums2[i]]++;
        }
    }

    return ans;
}

int main()
{

    return 0;
}

// ॥ जय श्री राम जय श्री कृष्ण ॥