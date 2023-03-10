#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> permute(vector<int> &nums)
{

    vector<vector<int>> ans;

    int n = nums.size();

    if (n==1)
    {
            ans.push_back(nums);
            return ans;
    }


    if (n==2)
    {
            ans.push_back(nums);

            next_permutation(nums.begin(),nums.end());
            ans.push_back(nums);
            return ans;
    }
    



    sort(nums.begin(),nums.end());

    vector<int> c = nums;

    ans.push_back(c);

    next_permutation(c.begin(),c.end());

    // ans.push_back(c);
    

    while (c!=nums)
    {

        ans.push_back(c);
        next_permutation(c.begin(),c.end());

        
    }
    

    
    
    return ans;

}

int main()
{

    // vector<int> v= {1,2,3};

    // vector<int> c = {1,2,3};

    // cout<<(v==c)<<endl;
    

    // next_permutation(s.begin(),s.end());

    // cout<<s<<endl;
    return 0;
}