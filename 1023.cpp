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

template <typename T_vector>
void output_vector(const T_vector &v, bool add_one = false, int start = -1, int end = -1)
{
    if (start < 0)
        start = 0;
    if (end < 0)
        end = int(v.size());

    for (int i = start; i < end; i++)
    {

        if (i == end - 1)
        {
            cout << v[i] + (add_one ? 1 : 0) << endl;
        }
        else
        {
            cout << v[i] + (add_one ? 1 : 0) << ' ';
        }
    }
}

int findNumberOfLIS(vector<int> &nums)
{
    int n = nums.size();

    int maxi = 1;

    vector<int> dp(n, 1);

    vector<int> hash(n, 1);

    for (int i = 0; i < n; i++)
    {
        int tem = 0;
        for (int j = 0; j < i; j++)
        {
            if (nums[j] < nums[i])
            {
                tem = max(tem, dp[j]);
            }
        }

        dp[i] = tem + 1;

        int dex = 0;

        for (int j = 0; j < i; j++)
        {
            if (dp[j] == tem && nums[j] < nums[i])
            {
                dex += hash[j];
            }
        }

        hash[i] = (dex == 0 ? 1 : dex);

        maxi = max(maxi, dp[i]);
    }

    // cout << "This is nums : " << endl;
    // output_vector(nums);

    // cout << "This is dp : " << endl;
    // output_vector(dp);

    // cout << "This is Hash : " << endl;
    // output_vector(hash);

    int count = 0;

    for (int i = 0; i < n; i++)
    {
        if (dp[i] == maxi)
        {
            count += hash[i];
        }
    }

    return count;
}

// [1,2,4,3,5,4,7,2]

int main()
{

    vector<int> test = {1, 2, 4, 3, 5, 4, 7, 2};

    cout << findNumberOfLIS(test);

    return 0;
}

// ॥ जय श्री राम जय श्री कृष्ण ॥