// ॥ श्री गणेशाय नमः ॥

#include <bits/stdc++.h>
using namespace std;

vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &nums2)
{

    int n = nums2.size();

    if (n == 1)
    {
        return {-1};
    }

    unordered_map<int, int> m;

    stack<int> s;

    m[nums2[n - 1]] = -1;

    s.push(nums2[n - 1]);

    for (int i = n - 2; i >= 0; i--)
    {

        while (s.empty() == false && s.top() <= nums2[i])
        {
            s.pop();
        }

        int ng = (s.empty()) ? -1 : s.top();

        m[nums2[i]] = ng;

        s.push(nums2[i]);
    }

    vector<int> ans;

    for (int i = 0; i < nums1.size(); i++)
    {
        ans.push_back(m[nums1[i]]);
    }

    return ans;
}

int main()
{

    return 0;
}

// ॥ जय श्री राम जय श्री कृष्ण ॥