// ॥ श्री गणेशाय नमः ॥

#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define M 1000000007
using namespace std;

unordered_map<string, int> mpp;
vector<vector<string>> ans;

string b;
void dfs(string word, vector<string> &seq)
{

    if (word == b)
    {

        reverse(seq.begin(), seq.end());

        ans.push_back(seq);

        reverse(seq.begin(), seq.end());
        return;
    }
    else
    {

        for (int i = 0; i < word.size(); i++)
        {
            char org = word[i];

            int steps = mpp[word];

            for (char j = 'a'; j <= 'z'; j++)
            {

                word[i] = j;

                

                if (mpp.find(word) != mpp.end() && mpp[word] == steps + 1)
                {

                    seq.push_back(word);

                    dfs(word, seq);

                    seq.pop_back();

                    // mpp[word] = steps + 1;
                }
            }

            word[i] = org;
        }
    }
}

vector<vector<string>> findLadders(string beginWord, string endWord, vector<string> &wordList)
{

    set<string> s(wordList.begin(), wordList.end());

    queue<string> q;

    q.push({beginWord});

    b = beginWord;

    mpp[beginWord] = 1;

    s.erase(beginWord);

    int n = beginWord.length();

    while (!q.empty())
    {
        string word = q.front();

        int steps = mpp[word];

        q.pop();

        if (word == endWord)
        {
            break;
        }

        for (int i = 0; i < n; i++)
        {
            char org = word[i];

            for (char j = 'a'; j <= 'z'; j++)
            {

                word[i] = j;

                if (s.find(word) != s.end())
                {
                    q.push(word);

                    s.erase(word);
                    mpp[word] = steps + 1;
                }
            }

            word[i] = org;
        }
    }

    if (mpp.count(endWord) > 0)
    {

        vector<string> seq;

        seq.push_back(endWord);
        dfs(endWord, seq);
    }

    return ans;
}

int main()
{

    return 0;
}

// ॥ जय श्री राम जय श्री कृष्ण ॥