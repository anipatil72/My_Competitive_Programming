#include <bits/stdc++.h>
using namespace std;

int wiggleMaxLength(vector<int> &nums)
{

    int n = nums.size();

    vector<int> diff;

    for (int i = 0; i < n - 1; i++)
    {

        diff.push_back(nums[i+1] - nums[i]);
        
            
    }


    for (int i = 0; i < diff.size()-1; i++)
    {
        if ((diff[i]>0&&diff[i+1]<0)||(diff[i]<0&&diff[i+1]>0))
        {
            /* code */
        }
            
    }
    
    


}

int main()
{

    return 0;
}