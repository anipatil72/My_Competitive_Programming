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

long long test(long long mid, vector<int> &a, vector<int> &b)
{
    int n = a.size(), m = b.size();

    int pa = 0, pb = m - 1;

    long long tally = 0;

    for (pa; pa < n; pa++)
    {
        while (pb >= 0 && (a[pa] * 1LL * b[pb] > mid))
        {
            pb--;
        }

        tally += (pb + 1);
    }

    return tally;
}

// Very good problem

long long kthSmallestProduct(vector<int> &nums1, vector<int> &nums2, long long k)
{
    int n = nums1.size();

    int m = nums2.size();

    auto pos = lower_bound(nums1.begin(), nums1.end(), 0);

    auto fos = lower_bound(nums2.begin(), nums2.end(), 0);

    vector<int> pos1(pos, nums1.end());
    vector<int> pos2(fos, nums2.end());

    vector<int> pos1_rev = pos1;
    reverse(pos1_rev.begin(), pos1_rev.end());

    vector<int> pos2_rev = pos2;
    reverse(pos2_rev.begin(), pos2_rev.end());

    vector<int> neg1(nums1.begin(), pos);
    vector<int> neg2(nums2.begin(), fos);

    vector<int> neg1_rev = neg1;
    reverse(neg1_rev.begin(), neg1_rev.end());

    vector<int> neg2_rev = neg2;
    reverse(neg2_rev.begin(), neg2_rev.end());

    int64_t left = -(1e10), right = 1e10, mid;

    while (left < right)
    {
        mid = (left + right - 1) / 2;

        int64_t tem = 0;

        if (mid >= 0)
        {
            tem += (pos1.size() * 1LL * neg2.size()) + (pos2.size() * 1LL * neg1.size()) + test(mid, pos1, pos2) + test(mid, neg1_rev, neg2_rev);
        }
        else
        {
            tem += (test(mid, pos1, neg2) + test(mid, pos2, neg1));
        }

        if (tem < k)
        {
            left = mid + 1;
        }
        else
        {
            right = mid;
        }
    }

    return left;
    // vector<int> firpos = nums1;

    // vector<int> firneg = nums1;

    // reverse(firneg.begin(), firneg.end());

    // for (int i = 0; i < n; i++)
    // {
    //     firneg[i] *= -1;
    // }

    // vector<int> secpos = nums2;

    // vector<int> secneg = nums2;

    // reverse(secneg.begin(), secneg.end());

    // for (int i = 0; i < m; i++)
    // {
    //     secneg[i] *= -1;
    // }
}

int main()
{

    return 0;
}

// ॥ जय श्री राम जय श्री कृष्ण ॥