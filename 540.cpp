#include <bits/stdc++.h>
using namespace std;

int findClosestNumber(vector<int> &nums)
{
    int l = *lower_bound(nums.begin(),nums.end(),0);
    int u = *upper_bound(nums.begin(),nums.end(),0);

    if (abs(l)==abs(u))
    {
            return u;
    }
    else
    {
        return abs(l)>abs(u)?abs(u):abs(l);
    }

    return 0;
    
    
}

int main()
{

    return 0;
}