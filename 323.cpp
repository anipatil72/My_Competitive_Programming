#include <bits/stdc++.h>
using namespace std;

// int getIndex(vector<int> &nums, int target, bool getFirst)
// {
//     int s = 0;
//     int e = nums.size() - 1;
//     int ans = -1;
//     while (s <= e)
//     {
//         int mid = s + (e - s) / 2;
//         if (nums[mid] == target)
//         {
//             ans = mid; // storing answer then start searching again
//             if (getFirst)
//             {
//                 e = mid - 1;
//             } // we have to go left side for first position
//             else
//             {
//                 s = mid + 1;
//             } //   we have to go right side for last positon
//         }
//         else if (nums[mid] > target)
//         {
//             e = mid - 1;
//         }
//         else
//         {
//             s = mid + 1;
//         }
//     }
//     return ans;
// }

vector<int> searchRange(vector<int> &nums, int target)
{

    int n = nums.size();

    if (!binary_search(nums.begin(), nums.end(), target))
    {
        return {-1, -1};
    }

    int l = distance(nums.begin(), lower_bound(nums.begin(), nums.end(), target));
    int r = distance(nums.begin(), upper_bound(nums.begin(), nums.end(), target));

    return {l, r - 1};
}

int main()
{

    vector<int> v = {1, 2, 3};

    vector<int> p = searchRange(v, 4);

    for (int i = 0; i < 2; i++)
    {
        cout << p[i] << " ";
    }

    return 0;
}