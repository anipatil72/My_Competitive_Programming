// ॥ श्री गणेशाय नमः ॥

#include <bits/stdc++.h>

#include <unordered_set>

#define ll long long
#define ull unsigned long long
#define M 1000000007
using namespace std;

vector<vector<string>> findSequences(string beginWord, string endWord, vector<string> &wordList)
{
    unordered_set<string> s(wordList.begin(), wordList.end());

    queue<vector<string>> q;

    q.push({beginWord});

    vector<string> usedonLevel;

    usedonLevel.push_back(beginWord);

    int level = 0;

    vector<vector<string>> ans;

    while (!q.empty())
    {
        vector<string> cur = q.front();
        q.pop();

        if (cur.size() > level)
        {
            level++;

            for (auto x : usedonLevel)
            {
                s.erase(x);
            }

            usedonLevel.clear();
        }

        string temp = cur.back();

        if (temp == endWord)
        {
            if (ans.size() == 0)
            {
                ans.push_back(cur);
            }
            else if (ans[0].size() == cur.size())
            {

                ans.push_back(cur);
            }
        }

        for (int i = 0; i < temp.size(); i++)
        {

            char d = temp[i];
            for (char j = 'a'; j <= 'z'; j++)
            {

                temp[i] = j;

                if (s.count(temp) > 0)
                {

                    cur.push_back(temp);

                    q.push(cur);

                    usedonLevel.push_back(temp);

                    cur.pop_back();
                }
            }

            temp[i] = d;
        }
    }

    return ans;
}

int main()
{

    return 0;
}

// ॥ जय श्री राम जय श्री कृष्ण ॥