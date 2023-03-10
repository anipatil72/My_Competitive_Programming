// ॥ श्री गणेशाय नमः ॥

#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define M 1000000007
using namespace std;

vector<int> majorityElement(vector<int> &nums)
{
    int n = nums.size();

    unordered_map<int, int> m;

    vector<int> ans;

    for (int i = 0; i < n; i++)
    {
        m[nums[i]]++;
    }

    for (auto x : m)
    {
        if (x.second >= n / 3)
        {
            ans.push_back(x.first);
        }
    }

    return ans;
}

int main()
{

    return 0;
}

// ॥ जय श्री राम जय श्री कृष्ण ॥