#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> permute(vector<int> &nums)
{

    vector<vector<int>> ans;

    int n = nums.size();

    if (n == 1)
    {
        ans.push_back(nums);
        return ans;
    }

    if (n == 2)
    {
        ans.push_back(nums);

        if (nums[0]==nums[1])
        {
                return ans;
        }
        

        next_permutation(nums.begin(), nums.end());
        ans.push_back(nums);
        return ans;
    }

    sort(nums.begin(), nums.end());

    vector<int> c = nums;

    ans.push_back(c);

    next_permutation(c.begin(), c.end());

    // ans.push_back(c);

    while (c != nums)
    {

        ans.push_back(c);
        next_permutation(c.begin(), c.end());
    }

    return ans;
}

int main()
{

    vector<int> v = {2,2,2};

    vector<vector<int>> ans;

    ans = permute(v);

    for (int i = 0; i < ans.size(); i++)
    {
            for (int j = 0; j < ans[i].size(); j++)
            {
                    cout<<ans[i][j]<<" ";
            }

            cout<<endl;
            
    }
    

    return 0;
}