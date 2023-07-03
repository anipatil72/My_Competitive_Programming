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

// https://www.linkedin.com/posts/akshatshrivastavainsead_india-is-ranked-5th-on-gdp-but-singapore-activity-7081194657648455680-7u4n?utm_source=share&utm_medium=member_desktop

int largestRectangleArea(vector<int> &nums)
{
    int n = nums.size();

    // Creating a stack for indices

    stack<int> s;

    vector<int> pref(n);
    vector<int> suff(n);

    for (int i = 0; i < n; i++)
    {
        while (!s.empty() && nums[s.top()] >= nums[i])
        {
            s.pop();
        }

        if (s.empty())
        {
            pref[i] = -1;
        }
        else
        {
            pref[i] = s.top();
        }

        s.push(i);
    }

    stack<int> p;

    for (int i = n - 1; i >= 0; i--)
    {
        while (!p.empty() && nums[p.top()] >= nums[i])
        {
            p.pop();
        }

        if (p.empty())
        {
            suff[i] = n;
        }
        else
        {
            suff[i] = p.top();
        }

        p.push(i);
    }

    int ans = 1;

    for (int i = 0; i < n; i++)
    {

        if ((suff[i] - pref[i] - 1) == nums[i])
        {
            int des = (suff[i] - pref[i] - 1) * nums[i];

            ans = max(ans, des);
        }
    }

    return ans;
}

int maximalRectangle(vector<vector<char>> &matrix)
{
    int n = matrix.size();

    int m = matrix[0].size();

    vector<int> sum(m, 0);

    int ans = 0;

    for (int i = 0; i < n; i++)
    {
        bool flag = 0;

        for (int j = 0; j < m; j++)
        {
            if (matrix[i][j] == '0')
            {
                sum[j] = 0;
            }
            else
            {
                sum[j]++;

                flag = true;
            }
        }

        if (flag)
        {
            ans = max(ans, largestRectangleArea(sum));
        }
    }

    return ans;
}

int main()
{

    return 0;
}

// ॥ जय श्री राम जय श्री कृष्ण ॥