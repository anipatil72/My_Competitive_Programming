#include <bits/stdc++.h>
using namespace std;

bool myComp(pair<int, int> a, pair<int, int> b)
{
    return a.second < b.second;
}

vector<int> topKFrequent(vector<int> &nums, int k)
{

    int n = nums.size();

    unordered_map<int, int> m;

    for (int i = 0; i < n; i++)
    {
        m[nums[i]]++;
    }

    vector<pair<int, int>> d;

    for (auto i = m.begin(); i != m.end(); i++)
    {
        d.push_back({i->first, i->second});
    }

    sort(d.begin(), d.end(), myComp);

    vector<int> ans;

    for (int i = 0; i < k; i++)
    {
        ans.push_back(d[i].first);
    }

    return ans;
}

int main()
{

    return 0;
}