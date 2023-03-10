#include <bits/stdc++.h>
using namespace std;

int singleNumber(vector<int> &nums)
{
    int n = nums.size();

    long long a = 0 ;

    for (int i = 0; i < n; i++)
    {
        a = a^nums[i];
    }


    return a;
}

int main()
{

    return 0;
}