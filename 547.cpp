#include <bits/stdc++.h>
using namespace std;

bool myComp(pair<string, int> a, pair<string, int> b)
{
    return a.second < b.second;
}

vector<string> topKFrequent(vector<string> &words, int k)
{
    int n = words.size();

    unordered_map<string, int> m;

    for (int i = 0; i < n; i++)
    {
        m[words[i]]++;
    }

    vector<pair<string, int>> v;

    for (auto i = m.begin(); i != m.end(); i++)
    {
        v.push_back({i->first, i->second});
    }

    sort(v.begin(), v.end(), myComp);

    vector<string> ans;

    for (int i = 0; i < k; i++)
    {

        ans.push_back(v[i].first);
    }

    return ans;
}

int main()
{

    return 0;
}