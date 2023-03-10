#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> anagrams(vector<string> &strs)
{

    int n = strs.size();

    vector<vector<int>> ans;
    for (int j = 0; j < n; j++)
    {

        bool flag = true;

        for (int i = 0; i < ans.size(); i++)
        {
            if ((strs[j].length() == strs[ans[i][0]-1].length()) && (is_permutation(strs[j].begin(), strs[j].end(), strs[ans[i][0]-1].begin())))
            {
                ans[i].push_back(j+1);
                flag = false;
                break;
            }
        }

        if (flag)
        {
            ans.push_back({j+1});
        }
    }

    return ans;
}

int main()
{

    return 0;
}