// ॥ श्री गणेशाय नमः ॥

#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
#define ll long long
#define ull unsigned long long
using namespace std;

vector<string> summaryRanges(vector<long long> &nums)
{
    long long n = nums.size();

    if (n == 0)
    {
        return {};
    }

    vector<string> ans;

    long long parent = nums[0];

    long long count = 1;

    long long cur = nums[0] + 1;

    for (long long i = 1; i < n; i++)
    {

        if (nums[i] != cur)
        {
            if (count == 1)
            {
                ans.push_back(to_string(parent));

                count = 1;

                parent = nums[i];

                cur = parent + 1;
            }
            else
            {
                string tem = to_string(parent) + "->" + to_string(cur - 1);

                ans.push_back(tem);

                count = 1;

                parent = nums[i];

                cur = parent + 1;
            }
        }
        else
        {
            count++;

            cur++;
        }
    }

    if (count == 1)
    {
        ans.push_back(to_string(parent));

        count = 1;

        // parent = nums[i];

        // cur = parent + 1;
    }
    else
    {
        string tem = to_string(parent) + "->" + to_string(cur - 1);

        ans.push_back(tem);

        count = 1;

        // parent = nums[i];

        // cur = parent + 1;
    }

    return ans;
}

long long main()
{

    return 0;
}

// ॥ जय श्री राम जय श्री कृष्ण ॥