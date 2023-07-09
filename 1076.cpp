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

bool findTriplets(int arr[], int n)
{

    sort(arr, arr + n);

    for (int i = 0; i < n; i++)
    {
        int des = arr[i];

        int left = i + 1, right = n - 1;

        while (left < right)
        {
            int tem = arr[left] + arr[right];

            if (tem + des < 0)
            {
                left++;
            }
            else if (tem + des > 0)
            {
                right--;
            }
            else
            {
                return true;
            }
        }
    }

    return false;
}

int main()
{

    return 0;
}

// ॥ जय श्री राम जय श्री कृष्ण ॥