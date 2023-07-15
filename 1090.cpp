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

int longestSubsequence(vector<int> &arr, int difference)
{
    int n = arr.size();

    unordered_map<int, int> m;

    // if (difference < 0)
    // {
    //     // for (int i = 0; i < n; i++)
    //     // {

    //     // }

    //     difference *= -1;
    // }

    int ans = 0;

    for (int i = 0; i < n; i++)
    {
        int des = arr[i] - difference;

        if (m.count(des) > 0)
        {
            int the = m[des];

            m[arr[i]] = the + 1;

            ans = max(ans, the + 1);
        }
        else
        {
            m[arr[i]] = 1;

            ans = max(ans, 1);
        }
    }

    return ans;
}

int main()
{
    vector<int> fin = {1, 5, 7, 8, 5, 3, 4, 2, 1};

    int k = -2;

    cout << longestSubsequence(fin, k);

    return 0;
}

// ॥ जय श्री राम जय श्री कृष्ण ॥