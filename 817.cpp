// ॥ श्री गणेशाय नमः ॥

#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
#define ll long long
#define ull unsigned long long
using namespace std;

bool myComp(pair<int, string> a, pair<int, string> b)
{
    if (a.first == b.first)
    {
        return a.second < b.second;
    }

    return a.first > b.first;
}

vector<string> topKFrequent(vector<string> &words, int k)
{
    int n = words.size();

    unordered_map<string, int> m;

    for (int i = 0; i < n; i++)
    {
        m[words[i]]++;
    }

    vector<pair<int, string>> pos;

    for (auto x : m)
    {
        pos.push_back({x.second, x.first});
    }

    sort(pos.begin(), pos.end(), myComp);

    vector<string> ans(k);

    for (int i = 0; i < k; i++)
    {
        ans[i] = pos[i].second;
    }

    return ans;
}

int main()
{

    return 0;
}

// ॥ जय श्री राम जय श्री कृष्ण ॥