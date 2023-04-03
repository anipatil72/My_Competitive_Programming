// ॥ श्री गणेशाय नमः ॥

#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
#define ll long long
#define ull unsigned long long
using namespace std;

bool recur(string s, unordered_map<int, set<string>> &m)
{
    int len = s.length();

    if (len == 0)
    {
        return true;
    }

    for (int i = 1; i <= len; i++)
    {
        if (m.count(i) > 0)
        {
            string front = s.substr(0, i);

            string back = s.substr(i);

            if (m[i].find(front) != m[i].end())
            {
                if (recur(back, m))
                {
                    return true;
                }
            }
        }
    }

    return false;
}

bool wordBreak(string s, vector<string> &wordDict)
{
    int n = wordDict.size();

    unordered_map<int, set<string>> m;

    for (int i = 0; i < n; i++)
    {
        m[wordDict[i].length()].insert(wordDict[i]);
    }

    int len = s.length();

    return recur(s, m);
}

int main()
{

    string s = "applepenapple";

    vector<string> wordDict = {"apple", "pen"};

    cout << wordBreak(s, wordDict);

    // for (int i = 1; i <= 8; i++)
    // {
    //     string tem = s.substr(i);
    //     cout << tem << endl;
    // }

    return 0;
}

// ॥ जय श्री राम जय श्री कृष्ण ॥