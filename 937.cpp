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

vector<int> findDuplicates(vector<int> &nums)
{
    int n = nums.size();

    vector<int> ans;

    for (int i = 0; i < n; i++)
    {
        if (nums[i] != i + 1)
        {

            int prev = nums[i];

            nums[i] = -1;

            while (prev != -1)
            {
                int tt = nums[prev - 1];

                if (tt == prev)
                {
                    ans.push_back(tt);

                    break;
                }

                nums[prev - 1] = prev;

                prev = tt;
            }
        }
    }

    return ans;
}

int main()
{

    return 0;
}

// ॥ जय श्री राम जय श्री कृष्ण ॥