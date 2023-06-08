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
// returns set of all divisors of a natural number

// Frequently asked Question in amazon

int kthFactor(int n, int k)
{
    int tem = n;

    vector<int> des;

    int count = 0;

    for (int i = 1; i <= (int)sqrt(n); i++)
    {
        if (n % i == 0)
        {
            if (n / i == i)
            {
                count++;

                if (count == k)
                {
                    return i;
                }
            }
            else
            {
                count++;

                if (count == k)
                {
                    return i;
                }

                des.push_back(n / i);
            }
        }
    }

    reverse(des.begin(), des.end());

    if (des.size() + count < k)
    {
        return -1;
    }

    return des[k - des.size() - 1];
}

int main()
{

    return 0;
}

// ॥ जय श्री राम जय श्री कृष्ण ॥