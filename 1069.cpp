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

int partition(int arr[], int low, int high)
{
    // int n = sizeof(arr)/sizeof(arr[0]);

    if (low >= high)
    {
        return -1;
    }

    int index = low - 1;

    int pivot = arr[high];

    for (int i = low; i < high; i++)
    {
        if (arr[i] <= pivot)
        {
            index++;

            swap(arr[index], arr[i]);
        }
    }

    index++;

    swap(arr[index], arr[high]);

    return index;
}

void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        int ans = partition(arr, low, high);

        // int mid = (low + high) / 2;

        quickSort(arr, low, ans - 1);

        quickSort(arr, ans + 1, high);
    }
}

int main()
{

    int arr[] = {2, 1, 4, 1, 5, 2};

    int n = sizeof(arr) / sizeof(arr[0]);

    quickSort(arr, 0, n - 1);

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    cout << endl;

    return 0;
}

// ॥ जय श्री राम जय श्री कृष्ण ॥