#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> threeSum(vector<int> &nums)
{

    int n = nums.size();

    sort(nums.begin(), nums.end());

    vector<vector<int>> ans;

    for (int i = 0; i < n; i++)
    {
        int low = i + 1, high = n - 1;

        

        while (low < high)
        {
            if (nums[i] + nums[low] + nums[high] == 0)
            {
                ans.push_back({nums[i], nums[low], nums[high]});

                while (low < high && nums[low] == nums[low - 1])
                {
                    low++;
                }
                while (low < high && nums[high] == nums[high + 1])
                {
                    high--;
                }

                low++;
                high--;
            }
            else if (nums[i] + nums[low] + nums[high] < 0)
            {
                low++;
            }
            else
            {
                high--;
            }
        }
    }

    return ans;
}

int main()
{

    return 0;
}