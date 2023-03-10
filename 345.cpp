#include <bits/stdc++.h>
using namespace std;

int searchInsert(vector<int> &nums, int target)
{

    auto l = lower_bound(nums.begin(),nums.end(),target);

    int d = distance(nums.begin(),l);

    return d;
}

int main()
{

    return 0;
}