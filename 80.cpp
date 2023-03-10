#include <bits/stdc++.h>
using namespace std;

int search(vector<int> &nums, int target)
{
    long long int mid, high, low; 
    int index = -1;

    low = 0;
    high = nums.size() - 1;
    mid = (low + high) / 2;

    while (low <= high)
    {
        if (nums[mid] == target)
        {
            index = mid;
            break;
        }

        if (nums[low] == target)
        {
            index = low;
            break;
        }

        if (nums[high] == target)
        {
            index = high;
            break;
        }

        if (target > nums[mid])
        {
            low = mid + 1;
            high = high - 1;
            mid = (low + high) / 2;
            continue;
        }

        if (target < nums[mid])
        {
            high = mid - 1;
            low = low + 1;
            mid = (low + high) / 2;
            continue;
        }

        // cout<<low<<" "<<mid<<" "<<high<<endl;
    }

    return index;
}

int main()
{

    vector<int> a = {1, 5, 9, 16, 78, 354, 1099, 2600};

    cout << search(a, 718) << endl;

    return 0;
}