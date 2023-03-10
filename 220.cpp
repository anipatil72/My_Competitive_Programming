#include <bits/stdc++.h>
using namespace std;

int longestConsecutive(vector<int> &nums)
{

    int n = nums.size();

    if (n==1)
    {
            return 1 ;
    }
    

    unordered_map<int,int> m ;

    int count = 0;

    int ans = 0;



    for (int i = 0; i < n; i++)
    {
        m[nums[i]]++;
    }

    for (int i = 0; i < n; i++)
    {

        if (m.count(nums[i]-1)>0)
        {

              continue;  
        }

        count = 0;

        int c = nums[i];

            while (m.count(c)>0)
            {

                count++;
                c++;
               
            }


            ans = max(ans,count);

        
            
    }
    
    
    return ans ;

}

int main()
{

    vector<int> v = {0,3,7,2,5,8,4,6,0,1};

    cout<<longestConsecutive(v);

    return 0;
}