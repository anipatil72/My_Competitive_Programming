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

class KthLargest
{
    priority_queue<int, vector<int>, greater<int>> p;

public:
    KthLargest(int k, vector<int> &nums)
    {

        int n = nums.size();

        for (int i = 0; i < min(n, k); i++)
        {
            p.push(nums[i]);
        }

        for (int i = k; i < n; i++)
        {

            if (p.top() < nums[i])
            {
                p.pop();

                p.push(nums[i]);
            }
        }
    }

    int add(int val)
    {

        int tem = val;

        if (!p.empty())
        {
            tem = p.top();
            if (p.top() < val)
            {

                p.pop();

                p.push(val);

                tem = p.top();
            }
        }
        else
        {
            p.push(val);

            tem = p.top();
        }

        return tem;
    }
};

int main()
{

    return 0;
}

// ॥ जय श्री राम जय श्री कृष्ण ॥