// ॥ श्री गणेशाय नमः ॥

#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
#define ll long long
#define ull unsigned long long
using namespace std;

string largestWordCount(vector<string> &messages, vector<string> &senders)
{
    int n = senders.size();

    vector<pair<int, string>> pos;

    for (int i = 0; i < n; i++)
    {
        int count = 0;

        int len = messages[i].size();

        for (int j = 0; j < len; j++)
        {
            if (messages[i][j] == ' ')
            {
                count++;
            }
        }

        int words = count + 1;

        pos.push_back({words, senders[i]});
    }

    unordered_map<string, int> m;

    for (int i = 0; i < n; i++)
    {
        m[pos[i].second] += pos[i].first;
    }

    vector<pair<int, string>> poss;

    for (auto x : m)
    {
        poss.push_back({x.second, x.first});
    }

    sort(poss.rbegin(), poss.rend());

    return poss[0].second;
}

int main()
{

    return 0;
}

// ॥ जय श्री राम जय श्री कृष्ण ॥