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

int maximumRequests(int n, vector<vector<int>> &requests)
{
    int q = requests.size();

    int ans = 0;

    int fin = (1 << (q));

    for (int i = 0; i < fin; i++)
    {
        vector<int> sum(n, 0);

        for (int j = 0; j < q; j++)
        {
            if (((1 << (j)) & i) > 0)
            {
                sum[requests[j][0]]--;
                sum[requests[j][1]]++;
            }
        }

        bool flag = true;

        for (int j = 0; j < n; j++)
        {
            if (sum[j] != 0)
            {
                flag = false;

                break;
            }
        }

        if (flag)
        {
            ans = max(ans, __builtin_popcount(i));
        }
    }

    return ans;
}

int main()
{

    return 0;
}

// ॥ जय श्री राम जय श्री कृष्ण ॥