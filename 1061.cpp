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

int longestSubarray(vector<int> &nums)
{
    int n = nums.size();

    if (n == 1)
    {
        return nums[0] == 1;
    }

    int ans = 0;

    int sum = accumulate(nums.begin(), nums.end(), 0);

    if (sum == n)
    {
        return n - 1;
    }

    int prev = 0, cur = 0;

    for (int i = 0; i < n; i++)
    {
        if (nums[i] == 0)
        {
            if (nums[i + 1] == 1)
            {
                if (i + 1 == n - 1)
                {
                    ans = max(ans, cur + prev);
                    prev = cur;

                    cur = 1;

                    break;
                }

                ans = max(ans, cur + prev);

                prev = cur;

                cur = 0;
            }
            else
            {
                ans = max(ans, cur + prev);

                cur = prev = 0;
            }
        }
        else
        {
            cur++;
        }

        // cout << cur << " " << prev << endl;
    }

    ans = max(ans, cur + prev);

    return ans;
}

int main()
{

    // [0,1,1,1,0,1,1,0,1]

    vector<int> test = {1, 1, 0, 1};

    cout << longestSubarray(test);

    return 0;
}

// ॥ जय श्री राम जय श्री कृष्ण ॥