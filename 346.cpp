#include <bits/stdc++.h>
using namespace std;

vector<string> wordSubsets(vector<string> &words1, vector<string> &words2)
{

    int n = words1.size();
    int m = words2.size();

    vector<string> ans;

    vector<vector<int>> v;

    for (int i = 0; i < m; i++)
    {
        vector<int> c(26, 0);

        for (int j = 0; j < words2[i].length(); j++)
        {
            c[words2[i][j] - 'a']++;
        }

        v.push_back(c);
    }

    for (int i = 0; i < n; i++)
    {

        vector<int> cur(26, 0);

        for (int k = 0; k < words1[i].size(); k++)
        {
            cur[words1[i][k] - 'a']++;
        }

        bool flag = true;
        for (int j = 0; j < m; j++)
        {
            vector<int>test = cur;

            for (int p = 0; p < words2[j].length()&&(test[words2[j][p]-'a']!=-1); p++)
            {
                if (v[j][words2[j][p]-'a'] > test[words2[j][p]-'a'])
                {
                    flag = false;
                }
                test[words2[j][p]-'a']= -1;
            }
        }

        if (flag)
        {
            ans.push_back(words1[i]);
        }
    }


    return ans;
}

int main()
{

    vector<string> s = {"acaac","cccbb","aacbb","caacc","bcbbb"};
    vector<string> s2 = {"c","cc","b"};

    vector<string> ans = wordSubsets(s,s2);

    for (int i = 0; i < ans.size(); i++)
    {
            cout<<ans[i]<<" ";
    }
    

    return 0;
}