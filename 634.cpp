// ॥ श्री गणेशाय नमः ॥

#include <bits/stdc++.h>
using namespace std;

bool myComp(pair<int, int> a, pair<int, int> b)
{
    if (a.second == b.second)
    {
        return a.first < b.first;
    }

    return a.second > b.second;
}

string frequencySort(string s)
{

    unordered_map<int, int> m;

    int n = s.length();

    for (int i = 0; i < n; i++)
    {
        m[s[i] - 'a']++;
    }

    vector<pair<int, int>> f(m.begin(), m.end());

    sort(f.begin(), f.end(), myComp);

    string ans = "";

    for (int i = 0; i < f.size(); i++)
    {

        char c = 'a' + f[i].first;

        for (int j = 0; j < f[i].second; j++)
        {
            ans += c;
        }
    }

    // cout << s;

    return ans;
}

int main()
{
    string s = "tree";

    string ans = frequencySort(s);

    cout<<ans;

    return 0;
}

// ॥ जय श्री राम जय श्री कृष्ण ॥