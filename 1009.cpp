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

bool checkPossibility(vector<int> &nums)
{
    int n = nums.size();

    if (n == 1 || n == 2)
    {
        return true;
    }

    int index = -1;

    for (int i = 0; i < n - 1; i++)
    {
        if (nums[i] > nums[i + 1])
        {
            index = i;

            // nums[i + 1] = nums[i];

            break;
        }
    }

    if (index == n - 2 || index == -1)
    {
        return true;
    }

    if (index == 0)
    {
        nums[index] = nums[index + 1];
        return is_sorted(nums.begin(), nums.end());
    }

    int fir = nums[index];

    int sec = nums[index + 1];

    nums[index + 1] = fir;

    if (is_sorted(nums.begin(), nums.end()))
    {
        return true;
    }

    nums[index + 1] = sec;

    nums[index] = sec;

    return is_sorted(nums.begin(), nums.end());
}

int main()
{

    vector<int> a = {1, 1, 1};

    cout << is_sorted(a.begin(), a.end()) << endl;

    return 0;
}

// ॥ जय श्री राम जय श्री कृष्ण ॥