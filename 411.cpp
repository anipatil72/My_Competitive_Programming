#include <bits/stdc++.h>
using namespace std;

int firstMissingPositive(vector<int> &nums)
{

    int n = nums.size();

    for (int i = 0; i < n; i++)
    {
         int j = nums[i];

         while(j>=1&&j<=n && (nums[j-1]!=j))
         {
            int prev = nums[j-1];

            nums[j-1] = j;

            j = prev;
         }
         
    }


    for (int i = 0; i < n; i++)
    {
        if (nums[i]!=(i+1))
        {
            return i+1;
        }
        
    }
    
    return n + 1;
}

int main()
{

    return 0;
}