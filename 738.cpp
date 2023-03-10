// ॥ श्री गणेशाय नमः ॥

#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define M 1000000007
using namespace std;

vector<vector<string>> wordLadderLength(string startWord, string targetWord, vector<string> &wordList)
{
    set<string> s(wordList.begin(), wordList.end());

    int n = wordList.size();

    int m = startWord.length();

    queue<pair<vector<string>, int>> q;

    vector<vector<string>> ans;

    q.push({{startWord}, 1}); 

    if (s.find(startWord) != s.end())
    {

        s.erase(startWord);
    }

    int mini = 0;

    bool flag = true;

    while (!q.empty())
    {
        pair<vector<string>, int> p = q.front();

        q.pop();

        // flag&&(p.first.back() == targetWord)) || ((p.first.back() == targetWord) && p.second == mini)

        if ((p.first.back() == targetWord))
        {

            // if (flag)
            // {
            //     flag = false;

            //     mini = p.second;
            // }

            ans.push_back(p.first);

            continue;

            // return p.second;
        }
        bool flag = true;

        int cur = 1;

        set<string> st;

        // st.insert(startWord);

        for (int i = 0; i < m; i++)
        {
            string cur = p.first.back();

            for (int j = 0; j < 26; j++)
            {
                char c = 'a' + j;

                char d = cur[i];

                cur[i] = c;

                if (s.find(cur) != s.end())
                {

                    // cout << "I am here : " << endl;

                    // cout << "This is cur : " << cur << endl;

                    flag = false;

                    // if (cur != targetWord)
                    // {
                    //     s.erase(cur);
                    // }



                    p.first.push_back(cur);

                    p.second++;

                    q.push(p);

                    p.first.pop_back();
                    p.second--;
                    // q.push({cur, p.second + 1});
                }

                cur[i] = d;
            }
        }

        if (flag&&p.first.back()==startWord)
        {
           return {}; 
        }
        
    }

    return ans;
}

int main()
{

    string startWord = "cbcb", targetWord = "baca";

    // vector<string> wordList = {"des", "der", "dfr", "dgt", "dfs"};
    vector<string> wordList = {"cccc", "caab", "aacc", "abca", "baca"};

    // cccc
    // caab
    // aacc
    // baca
    // abca
    // cbcb
    // baca

    vector<vector<string>> ans = wordLadderLength(startWord, targetWord, wordList);

    if (ans.size() == 0)
    {
        cout << "Not Possible !" << endl;
    }
    else
    {

        for (int i = 0; i < ans.size(); i++)
        {
            for (int j = 0; j < ans[i].size(); j++)
            {
                cout << ans[i][j] << " ";
            }

            cout << endl;
        }
    }

    return 0;
}

// ॥ जय श्री राम जय श्री कृष्ण ॥