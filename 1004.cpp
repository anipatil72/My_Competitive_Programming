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

int localInversions(vector<int> &nums)
{
    int n = nums.size();

    int count = 0;

    for (int i = 0; i < n - 1; i++)
    {
        // cout << "I am here : " << i << " and here : " << nums[i] << " and " << nums[i + 1] << endl;
        if (nums[i] > nums[i + 1])
        {
            count++;
        }
    }

    return count;
}

int mergeAndCount(vector<int> &nums, int left, int right, int mid)
{
    if (left >= right)
    {
        return 0;
    }

    int inv = 0;

    int tot = right - left + 1;

    vector<int> sorted(tot);

    int fin = 0, l = left, r = mid + 1;

    while (l <= mid && r <= right)
    {
        if (nums[r] < nums[l])
        {
            inv += (mid - l + 1);

            sorted[fin++] = nums[r++];
        }
        else
        {
            sorted[fin++] = nums[l++];
        }
    }

    while (l <= mid)
    {
        sorted[fin++] = nums[l++];
    }

    while (r <= right)
    {

        sorted[fin++] = nums[r++];
    }

    for (int i = left; i <= right; i++)
    {
        nums[i] = sorted[i - left];
    }

    return inv;
}

int merge(vector<int> &nums, int left, int right)
{
    int inversions = 0;
    if (left < right)
    {
        int mid = left + (right - left) / 2;

        inversions += merge(nums, left, mid);
        inversions += merge(nums, mid + 1, right);

        inversions += mergeAndCount(nums, left, right, mid);
    }

    return inversions;
}

int globalInversons(vector<int> &nums)
{
    int n = nums.size();

    return merge(nums, 0, n - 1);
}

bool isIdealPermutation(vector<int> &nums)
{
    int n = nums.size();

    vector<int> tem = nums;

    if (n == 1)
    {
        return true;
    }

    int x = globalInversons(tem);

    int y = localInversions(nums);

    // cout << "This is globalinversions : " << x << " and these are localInversions : " << y << endl;

    return x == y;
}

int main()
{

    vector<int> a = {1, 0, 2};

    cout << isIdealPermutation(a) << endl;

    return 0;
}

// ॥ जय श्री राम जय श्री कृष्ण ॥