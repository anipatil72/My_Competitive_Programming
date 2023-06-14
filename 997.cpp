// ॥ श्री गणेशाय नमः ॥

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define ll long long
#define ull unsigned long long
using namespace std;
using namespace __gnu_pbds;

// typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_multiset;

long long numberOfPairs(vector<int> &nums1, vector<int> &nums2, int diff)
{
    int n = nums1.size();
    ordered_multiset s;

    vector<int> des(n, 0);

    for (int i = 0; i < n; i++)
    {
        des[i] = nums1[i] - nums2[i];
    }

    long long ans = 0;

    for (int i = 0; i < n; i++)
    {
        ans += (s.order_of_key(des[i] + diff + 1));

        s.insert(des[i]);
    }

    return ans;
}

int main()
{
    ordered_multiset s;

    // s.insert(1);
    // s.insert(2);
    // s.insert(3);
    // s.insert(3);
    // s.insert(4);
    // s.insert(5);

    cout << (s.order_of_key(4)) << endl;

    return 0;
}

// ॥ जय श्री राम जय श्री कृष्ण ॥