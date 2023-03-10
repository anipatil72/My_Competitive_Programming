// ॥ श्री गणेशाय नमः ॥

#include <bits/stdc++.h>
#define ll long long
#define M 1000000007
using namespace std;

string oddString(vector<string> &words)
{
    int n = words.size();

    int m = words[0].size();

    // set<vector<int>> s;

    map<vector<int>, pair<int, int>> mp;

    for (int i = 0; i < n; i++)
    {
        vector<int> v;

        for (int j = 1; j < m; j++)
        {

            int d = words[i][j] - words[i][j - 1];

            v.push_back(d);
        }

        for (int k = 0; k < v.size(); k++)
        {
            cout << v[i] << " ";
        }

        cout << endl;

        // s.insert(v);

        mp[v].first++;

        mp[v].second = i;
    }

    auto it = mp.begin();

    int tem = it->second.first;

    if (tem == 1)
    {
        return words[it->second.second];
    }
    else
    {

        it++;

        return words[it->second.second];
    }

    return "just_in_case";
}

int main()
{

    vector<string> words = {"ddd", "poo", "baa", "onn"};

    cout << oddString(words) << endl;

    return 0;
}

// ॥ जय श्री राम जय श्री कृष्ण ॥