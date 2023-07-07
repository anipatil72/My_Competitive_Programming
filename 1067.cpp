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

int minSubArrayLen(int target, vector<int> &nums)
{
    int n = nums.size();

    int left = 0, right = 0;

    ll sum = 0;

    int ans = n + 2;

    // cout << "This is left : " << left << " and this is right : " << right << endl;

    while (right < n)
    {

        if ((sum < target))
        {
            sum += nums[right];

            right++;
            // cout << "This is left : " << left << " and this is right : " << right << endl;
        }
        else
        {

            // right--;

            ans = min(ans, right - left);

            sum -= nums[left];

            left++;

            // cout << "This is left : " << left << " and this is right : " << right << endl;

            if (left == right)
            {
                sum += nums[right];
                right++;
                // cout << "This is left : " << left << " and this is right : " << right << endl;
            }
        }
    }

    while ((left < n) && (sum >= target))
    {
        ans = min(ans, right - left);

        sum -= nums[left];

        left++;
    }

    return (ans == n + 2 ? 0 : ans);
}

int main()
{

    vector<int> test = {2};

    int target = 1;

    cout << minSubArrayLen(target, test) << endl;

    return 0;
}

// ॥ जय श्री राम जय श्री कृष्ण ॥