#include <bits/stdc++.h>
using namespace std;

int findKthLargest(vector<int> &nums, int k)
{

    priority_queue<int,vector<int>,greater<int>> p ;

    for (int i = 0; i < k; i++)
    {
            p.push(nums[i]);
    }

    for (int i = k; i < nums.size()-1; i++)
    {
         if(p.top()> nums[i])
         {


                p.pop();
                p.push(nums[i]);

         }
            
    }
    
    


    return p.top();

}

int main()
{

    return 0;
}