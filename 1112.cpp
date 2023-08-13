// ॥ श्री गणेशाय नमः ॥

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define ll long long
#define ull unsigned long long
using namespace std;
using namespace __gnu_pbds;

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
// typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_multiset;

int maxValueAfterReverse(vector<int> &nums)
{
    int n = nums.size();

    vector<int> post(n), ant(n);

    int mini = n - 1, maxi = n - 1;

    for (int i = n - 2; i >= 0; i--)
    {
        post[i] = maxi;

        ant[i] = mini;

        if (nums[i] < nums[mini])
        {
            mini = i;
        }

        if (nums[i] > nums[maxi])
        {
            maxi = i;
        }
    }

    int value = 0;

    for (int i = 0; i < n - 1; i++)
    {
        value += abs(nums[i] - nums[i + 1]);
    }

    int laabh = 0;

    for (int i = 0; i < n - 2; i++)
    {

        // first swap with minimum
        int pos = ant[i];

        if (pos != n - 1)
        {
            int desk = abs(nums[i] - nums[i + 1]) + abs(nums[pos] - nums[pos + 1]);

            int now = abs(nums[pos] - nums[i]) + abs(nums[pos + 1] - nums[i + 1]);

            if (now > desk)
            {
                laabh = max(laabh, now - desk);
            }
        }
        else
        {
            int desk = abs(nums[i] - nums[i + 1]);

            int now = abs(nums[pos] - nums[i]);

            if (now > desk)
            {
                laabh = max(laabh, now - desk);
            }
        }

        // then swap with maximum

        pos = post[i];

        if (pos != n - 1)
        {
            int desk = abs(nums[i] - nums[i + 1]) + abs(nums[pos] - nums[pos + 1]);

            int now = abs(nums[pos] - nums[i]) + abs(nums[pos + 1] - nums[i + 1]);

            if (now > desk)
            {
                laabh = max(laabh, now - desk);
            }
        }
        else
        {
            int desk = abs(nums[i] - nums[i + 1]);

            int now = abs(nums[pos] - nums[i]);

            if (now > desk)
            {
                laabh = max(laabh, now - desk);
            }
        }
    }

    return value + laabh;
}

int main()
{

    vector<int> nums = {2, 4, 9, 24, 2, 1, 10};

    cout << maxValueAfterReverse(nums) << endl;

    return 0;
}

// ॥ जय श्री राम जय श्री कृष्ण ॥