#include <bits/stdc++.h>
using namespace std;

vector<string> findAndReplacePattern(vector<string> &words, string pattern)
{

    int n = words.size();

    int m = pattern.length();

    vector<string> ans;

    vector<int> pat(m, -1);

    // unordered_map<char,int> map;

    for (int i = 0; i < m; i++)
    {
        pat[i] = pattern[i] - 'a';

        // map[pattern[i]]++;
    }

    // sort(pat.begin(),pat.end());

    for (int i = 0; i < n && (words[i].length() == m); i++)
    {
        vector<char> nb(26, -1);
        vector<int> visited(26,1);

        bool flag = true;

        for (int j = 0; j < m&&(visited[words[i][j]-'a']!=0); j++)
        {
            nb[pat[j]] = words[i][j];
            visited[words[i][j]-'a'] = 0;
        }

        for (int j = 0; j < m; j++)
        {
            if (nb[pat[j]] != words[i][j])
            {
                flag = false;
                break;
            }
        }

        if (flag)
        {
            ans.push_back(words[i]);
        }
    }

    return ans;
}

int main()
{

    return 0;
}