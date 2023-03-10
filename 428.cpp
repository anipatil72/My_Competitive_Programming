#include <bits/stdc++.h>
using namespace std;

int maxSubArray(vector<int> &nums)
{

    int n = nums.size();

    int m = INT_MIN/2;

    int sum = INT_MIN/2, best = INT_MIN/2 ;

    for (int i = 0; i < n; i++)
    {

        sum = max(nums[i], sum + nums[i]);

        best = max(sum, best);
            
    }

    return best;
    
}

int main()
{

    return 0;
}