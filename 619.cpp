#include <bits/stdc++.h>
// #include<set.h>
using namespace std;

vector<int> intersection(vector<int> &nums1, vector<int> &nums2)
{
    int n1 = nums1.size();

    unordered_map<int, int> m;

    set<int> k;

    for (int i = 0; i < n1; i++)
    {
        m[nums1[i]]++;
    }

    for (int i = 0; i < nums2.size(); i++)
    {
        if (m.count(nums2[i]) > 0)
        {
            // ans.push_back(nums2[i]);

            // k[nums2[i]]++;

            k.insert(nums2[i]);
        }
    }

    vector<int> ans(k.begin(), k.end());

    return ans;
}

int main()
{

    return 0;
}