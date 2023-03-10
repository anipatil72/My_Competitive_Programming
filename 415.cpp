#include <bits/stdc++.h>
using namespace std;

void recur(vector<int> &v, vector<vector<int>> &ans, vector<int> &t, int target, int cur, int &sum)
{

    sum += v[cur];

    t.push_back(v[cur]);

    if (sum > target)
    {
        sum -= v[cur];

        t.pop_back();

        return;
    }

    if (sum == target)
    {

        ans.push_back(t);

        sum -= v[cur];
        t.pop_back();

        return;
    }

    for (int i = cur; i < v.size(); i++)
    {

        if (i>cur&&v[i]==v[i-1])
        {
               continue; 
        }

        recur(v, ans, t, target, i + 1, sum);
    }

    sum -= v[cur];
    t.pop_back();
}

vector<vector<int>> combinationSum(vector<int> &candidates, int target)
{

    int n = candidates.size();

    sort(candidates.begin(),candidates.end());

    vector<vector<int>> ans;

    vector<int> temp;

    int sum = 0;
    int cur = 0;

    for (int i = 0; i < candidates.size(); i++)
    {

        if (i>0&&candidates[i]==candidates[i-1])
        {
               continue; 
        }
        
            recur(candidates, ans, temp, target, i, sum);

    }

    return ans;
}

int main()
{

    vector<int> can = {2,5,2,1,2};

    int target = 5;

    vector<vector<int>> ans = combinationSum(can, target);

    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < ans[i].size(); j++)
        {
            cout << ans[i][j] << " ";
        }

        cout << endl;
    }

    return 0;
}