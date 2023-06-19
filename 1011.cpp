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

int distributeTicket(int n, int k)
{
    if (n == 1)
    {
        return 1;
    }

    if (n == 2)
    {
        return 2;
    }

    if (k == 1)
    {
        return n / 2 + 1;
    }

    int tem = n / k;

    int rem = n % k;

    int ans = 0;

    if (tem & 1)
    {
        // int t = tem / 2;
        int des = ceil(1.0 * tem / 2);

        if (rem == 0)
        {

            ans = des * k;
        }
        else
        {
            ans = des * k + 1;
        }
    }
    else
    {
        int t = tem / 2;

        if (rem == 0)
        {
            ans = k * t + 1;
        }
        else
        {
            ans = k * t + rem;
        }
    }

    return ans;
}

int main()
{

    // cout << ceil(1.0 * 5 / 2) << endl;

    int n = 5, k = 1;

    cout << distributeTicket(n, k) << endl;

    return 0;
}

// ॥ जय श्री राम जय श्री कृष्ण ॥