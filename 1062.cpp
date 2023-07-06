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
// binary search hain re baba

int check(vector<int> &nums, int d)
{
    int n = nums.size();

    int sum = 0;

    for (int i = 0; i < n; i++)
    {
        sum += ceil(1.0 * nums[i] / d);
    }

    return sum;
}

int smallestDivisor(vector<int> &nums, int threshold)
{
    int n = nums.size();

    int left = 1, right = *max_element(nums.begin(), nums.end()) + 1, mid;

    int ans = right;

    while (left < right)
    {
        mid = (left + right) / 2;

        // cout << left << " " << right << endl;

        // cout << mid << endl;

        if (check(nums, mid) <= threshold)
        {
            ans = mid;
            right = mid;
        }
        else
        {
            left = mid + 1;
        }
    }

    return ans;
}

int main()
{

    vector<int> test = {1, 2, 5, 9};

    int threshold = 6;

    cout << smallestDivisor(test, threshold);

    return 0;
}

// ॥ जय श्री राम जय श्री कृष्ण ॥