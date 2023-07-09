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

int missingNumber(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        if (arr[i] <= n && arr[i] > 0)
        {
            int tem = arr[i];

            while ((tem <= n && tem > 0) && (arr[tem - 1] != tem))
            {
                int prev = arr[tem - 1];

                arr[tem - 1] = tem;

                tem = prev;
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        if (arr[i] != i + 1)
        {
            return i + 1;
        }
    }

    return n + 1;
}

int main()
{

    int arr[] = {0, -10, 1, 3, -20};

    int n = (sizeof(arr) / sizeof(arr[0]));

    cout << missingNumber(arr, n);

    return 0;
}

// ॥ जय श्री राम जय श्री कृष्ण ॥