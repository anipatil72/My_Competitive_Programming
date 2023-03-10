#include <bits/stdc++.h>
using namespace std;

int numMatchingSubseq(string s, vector<string> &words)
{

    int n = words.size();

    int l = s.length();

    vector<vector<int>> v(26);

    for (int i = 0; i < l; i++)
    {
        v[s[i] - 'a'].push_back(i);
    }

    int count = 0, last;

    for (int i = 0; i < n; i++)
    {
        if (words[i] == "")
        {
            count++;
            continue;
        }

        vector<int> index(26, 0);
        bool flag = true;

        for (int j = 0; j < words[i].length(); j++)
        {
            if (v[words[i][j] - 'a'].size() == 0)
            {
                flag = false;
                break;
            }

            if (j == 0)
            {
                last = v[words[i][j] - 'a'][index[words[i][j] - 'a']];
                index[words[i][j] - 'a']++;
                continue;
            }

            if (index[words[i][j] - 'a'] >= v[words[i][j] - 'a'].size())
            {
                flag = false;
                break;
            }

            if ((index[words[i][j] - 'a'] < v[words[i][j] - 'a'].size()) && (upper_bound(v[words[i][j] - 'a'].begin() ,v[words[i][j] - 'a'].end(),last)==v[words[i][j] - 'a'].end()))
            {
                flag = false;
                break;
            }

            if ((index[words[i][j] - 'a'] < v[words[i][j] - 'a'].size()) && (upper_bound(v[words[i][j] - 'a'].begin() ,v[words[i][j] - 'a'].end(),last)!=v[words[i][j] - 'a'].end()))
            {


                int d = distance(v[words[i][j]-'a'].begin(),upper_bound(v[words[i][j] - 'a'].begin() ,v[words[i][j] - 'a'].end(),last));

                last = v[words[i][j] - 'a'][index[words[i][j] - 'a']];
                index[words[i][j] - 'a'] = d ;
            }
        }

        if (flag)
        {
            count++;
        }
    }

    return count;
}

int main()
{

    string s = "agbhcide";

    vector<string> words = {"acd", "aeh", "a", "ghi", ""};

    cout << numMatchingSubseq(s, words);

    return 0;
}