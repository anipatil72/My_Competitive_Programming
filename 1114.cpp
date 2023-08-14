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

vector<int> singleNumber(vector<int> nums)
{
    int n = nums.size();

    vector<int> fir, sec;

    int x = 0;

    for (int i = 0; i < n; i++)
    {
        x ^= nums[i];
    }

    int des;

    for (int i = 0; i < 32; i++)
    {
        if (((1 << i) & x))
        {

            des = i;

            break;
        }
    }

    int peh, dus;

    for (int i = 0; i < n; i++)
    {
        if ((1 << des) & nums[i])
        {
            // fir.push_back(nums[i]);

            peh ^= nums[i];
        }
        else
        {
            // sec.push_back(nums[i]);

            dus ^= nums[i];
        }
    }

    // for (auto &g : fir)
    // {
    //     peh ^= g;
    // }

    // for (auto &g : sec)
    // {
    //     dus ^= g;
    // }

    return {peh, dus};
}

int main()
{

    return 0;
}

// ॥ जय श्री राम जय श्री कृष्ण ॥