#include <bits/stdc++.h>
using namespace std;

void sortColors(vector<int> &nums)
{

    int n = nums.size();

    int i = 0, j = 0;

    while ((i < n && j < n) && nums[i] != 0)
    {
        i++;
        j++;
    }

    while (j < n && i < n)
    {
        if (nums[j] == 0)
        {
            swap(nums[i], nums[j]);
            i++;
            j++;
            continue;
        }

        j++;
    }

    j = i;

    while ((i < n && j < n) && nums[i] != 1)
    {
        i++;
        j++;
    }

    while (j < n && i < n)
    {
        if (nums[j] == 1)
        {
            swap(nums[i], nums[j]);
            i++;
            j++;
            continue;
        }

        j++;
    }

    j = i;

    while ((i < n && j < n) && nums[i] != 2)
    {
        i++;
        j++;
    }

    while (j < n && i < n)
    {
        if (nums[j] == 2)
        {
            swap(nums[i], nums[j]);
            i++;
            j++;
            continue;
        }

        j++;
    }
}

int main()
{

    return 0;
}