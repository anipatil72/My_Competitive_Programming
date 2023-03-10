#include <bits/stdc++.h>
using namespace std;

bool isPossible(vector<int> &nums)
{

    int n = nums.size();

    if (n<3||n==4||n==5)
    {
        return false;
    }

    map<int,int> m;

    for (int i = 0; i < n; i++)
    {
            m[nums[i]]++;

    }

    if (n==3&&m.size()<3)
    {
            return false;
    }

    
    


    
    
    
    
}

int main()
{

    return 0;
}