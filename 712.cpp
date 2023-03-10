// ॥ श्री गणेशाय नमः ॥

#include <bits/stdc++.h>
#define ll long long
#define M 1000000007
using namespace std;

int minIncrementForUnique(vector<int> &nums)
{

    int n = nums.size();

    sort(nums.begin(), nums.end());

    vector<int> org = nums;

    int ans = 0;

    for (int i = 1; i < n; i++)
    {

        if (org[i] == org[i - 1])
        {
            org[i] += org[i - 1] - nums[i] + 1;

            ans += org[i - 1] - nums[i] + 1;
        }
    }

    cout << "This is org : " << endl;

    for (int i = 0; i < n; i++)
    {
        cout << org[i] << " ";
    }

    cout << endl;

    // cout << ans << endl;

    return ans;
}

int main()
{

    vector<int> nums = {3, 2, 1, 2, 1, 7};

    int ans = minIncrementForUnique(nums);

    cout << ans << endl;

    return 0;
}

// ॥ जय श्री राम जय श्री कृष्ण ॥