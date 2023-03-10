#include <bits/stdc++.h>
using namespace std;

void recur(set<vector<int>> &ans, vector<int> t, vector<int> &nums, int cur)
{
    int n = nums.size();

    if (cur > n - 1)
    {
        // ans.push_back(t);

        ans.insert(t);
        return;
    }

    recur(ans, t, nums, cur + 1);

    t.push_back(nums[cur]);
    recur(ans, t, nums, cur + 1);
}

vector<vector<int>> subsets(vector<int> &nums)
{

    int n = nums.size();

    sort(nums.begin(),nums.end());

    set<vector<int>> ans;

    vector<int> t;

    int cur = 0;

    recur(ans,t,nums,cur);

    vector<vector<int>> a(ans.begin(),ans.end());

    return a;
}

int main()
{

    return 0;
}