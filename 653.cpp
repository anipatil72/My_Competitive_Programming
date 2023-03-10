// ॥ श्री गणेशाय नमः ॥

#include <bits/stdc++.h>
using namespace std;

vector<int> findDuplicates(vector<int> &nums)
{

    int n = nums.size();

    vector<int> ans;

    for (int i = 0; i < n; i++)
    {
        if (i + 1 != nums[i])
        {
            int prev = nums[i];

            while (nums[prev - 1] != prev)
            {
                int d = nums[prev - 1];

                // swap(nums[prev - 1], nums[nums[prev] - 1]);

                nums[prev - 1] = prev;

                prev = d;
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        if (i + 1 != nums[i])
        {
            ans.push_back(i+1);
        }
    }

    return ans;
}

int main()
{

    vector<int> v = {4,3,2,7,8,2,3,1};

    vector<int> a = findDuplicates(v);

    for (int i = 0; i < v.size(); i++)
    {
        cout<<v[i]<<" ";
    }
    

    return 0;
}

// ॥ जय श्री राम जय श्री कृष्ण ॥