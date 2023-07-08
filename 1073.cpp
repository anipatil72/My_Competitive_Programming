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

void merge(long long arr1[], long long arr2[], int n, int m)
{
    // code here

    int l = n - 1;
    int r = 0;

    while (l >= 0 && r < m)
    {
        if (arr1[l] > arr2[r])
        {
            long temp = arr1[l];
            arr1[l] = arr2[r];
            arr2[r] = temp;
            l--;
            r++;
        }
        else
        {
            break;
        }
    }

    sort(arr1, arr1 + n);
    sort(arr2, arr2 + m);
}

int main()
{

    return 0;
}

// ॥ जय श्री राम जय श्री कृष्ण ॥