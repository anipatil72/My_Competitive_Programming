#include <bits/stdc++.h>
using namespace std;

void recur(vector<int> &nums, int &sum, int &count, int target, vector<vector<int>> &ans, vector<int> &temp, int cur)
{
    if (sum > target)
    {
        //  count--;
        return;
    }

    if (sum == target)
    {
        count++;

        ans.push_back(temp);
        return;
    }

    int n = nums.size();

    for (int i = cur; i < n; i++)
    {
        sum += nums[i];

        temp.push_back(nums[i]);

        recur(nums, sum, count, target, ans, temp, i);

        sum -= nums[i];
        temp.pop_back();
    }
}

vector<vector<int>> combinationSum4(vector<int> &nums, int target)
{

    int cnt = 0;

    int s = 0;

    vector<vector<int>> ans;

    vector<int> temp;

    for (int i = 0; i < nums.size(); i++)
    {

        s += nums[i];

        temp.push_back(nums[i]);

        recur(nums, s, cnt, target, ans, temp, i);

        temp.pop_back();

        s -= nums[i];
    }

    return ans;
}

void factorial(vector<long long>& v,int n)
{

    long long prod = 1;

    for (int i = 1; i <= n; i++)
    {
        prod*=i;
        v.push_back(prod);
            
    }
    
    
}

int FinalAns(vector<vector<int>>& a)
{
    int n = a.size();

    int m = INT_MIN;

    for (int i = 0; i < n; i++)
    {

        int d = a[i].size();
          m = max(m,d);  
    }

    vector<long long> fac ;

    factorial(fac,m);

    for (int i = 0; i < n; i++)
    {
            unordered_map<int,int> m;

            for (int j = 0; j < a[i].size(); j++)
            {
                    m[a[i][j]]++;
            }


            long long 
            
    }
    
    
}

int main()
{

    vector<int> nums = {1, 2, 4};

    int target = 32;

    vector<vector<int>> ans = combinationSum4(nums, target);



    // for (int i = 0; i < ans.size(); i++)
    // {
    //     for (int j = 0; j < ans[i].size(); j++)
    //     {
    //         cout << ans[i][j] << " ";
    //     }

    //     cout << "\n";
    // }

    // cout << combinationSum4(nums, target);

    return 0;
}