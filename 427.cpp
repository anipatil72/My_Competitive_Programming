#include <bits/stdc++.h>
using namespace std;

vector<vector<string>> groupAnagrams(vector<string> &strs)
{

    int n = strs.size();

    vector<vector<string>> ans;
    for (int j = 0; j < n; j++)
    {

        bool flag = true;

        for (int i = 0; i < ans.size(); i++)
        {
              if ((strs[j].length()==ans[i][0].length())&&(is_permutation(strs[j].begin(),strs[j].end(),ans[i][0].begin())))
              {
                    ans[i].push_back(strs[j]);
                    flag = false;
                    break;
              }
                
        }

        if (flag)
        {
            ans.push_back({strs[j]});
        }
        
        
        
    }
    
    return ans;
    
}

int main()
{

    // string s = "abc";

    // string d = "";

    // cout<<is_permutation(s.begin(),s.end(),d.begin());

    return 0;
}