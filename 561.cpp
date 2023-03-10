#include <bits/stdc++.h>
using namespace std;

int findDuplicate(vector<int> &nums)
{

    int n = nums.size() - 1;
    

    for (int i = 0; i < n + 1; i++)
    {
        if (nums[i] != i + 1)
        {
            int prev = nums[nums[i] - 1];

            // nums[i] = i + 1;
            swap(nums[i], nums[nums[i] - 1]);

            if (nums[i] ==nums[nums[i] - 1])
            {
                    return nums[i];
            }
            

            while (nums[prev] != prev + 1)
            {

                int d = nums[nums[prev] - 1];
                // nums[prev] = prev + 1;
                swap(nums[prev], nums[nums[prev] - 1]);
                prev = d;
            }
        }

        for (int j = 0; j < n + 1; j++)
        {
            cout << nums[j] << " ";
        }

        cout << endl;
    }

    for (int i = 0; i < n + 1; i++)
    {
        if (nums[i] != i + 1)
        {
            return nums[i];
        }
    }

    return 0;
}

int main()
{

    vector<int> a = {1,1,2};

    int d = findDuplicate(a);

    cout << "The repreated number is : " << d << endl;

    return 0;
}