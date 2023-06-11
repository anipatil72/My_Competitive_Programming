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

int LomutoPartition(int arr[], int low, int high)
{
    int pivot = 0;

    int i = low - 1;

    for (int j = low; j <= high - 1; j++)
    {
        if (arr[j] < pivot)
        {
            i++;

            swap(arr[j], arr[i]);
        }
    }

    // Lastly swapping the pivot element

    // swap(arr[i + 1], arr[high]);

    return i + 1; /// Returns the index of the final pivot
}

// void Rearrange(int arr[], int n)
// {
//     int ans = LomutoPartition(arr, 0, n);
// }

// } Driver Code Ends
class Solution
{
public:
    void Rearrange(int arr[], int n)
    {
        auto merge = [&](int l, int mid, int r)
        {
            int size = r - l + 1;
            vector<int> t(size);

            int i, j, k;
            i = l;
            j = mid + 1;
            k = 0;

            while (i < mid + 1 && j < r + 1)
            {
                if (arr[i] >= 0 && arr[j] < 0)
                {
                    t[k++] = arr[j++];
                }
                else
                {
                    t[k++] = arr[i++];
                }
            }

            while (i < mid + 1)
            {
                t[k++] = arr[i++];
            }
            while (j < r + 1)
            {
                t[k++] = arr[j++];
            }

            k = 0;
            i = l;

            while (k < size)
            {
                arr[i++] = t[k++];
            }
        };

        function<void(int, int)> divide = [&](int l, int r)
        {
            if (l < r)
            {
                int mid = l + (r - l) / 2;

                divide(l, mid);
                divide(mid + 1, r);
                merge(l, mid, r);
            }
        };

        divide(0, n - 1);
    }
};

//{ Driver Code Starts.
void Rearrange(int arr[], int n);

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        long long j = 0;
        Solution ob;
        ob.Rearrange(arr, n);

        for (int i = 0; i < n; i++)
            cout << arr[i] << " ";
        cout << endl;
    }
    return 0;
}
int main()
{

    int a[] = {2, 0};

    Rearrange(a, 2);

    for (int i = 0; i < 2; i++)
    {
        cout << a[i] << " ";
    }

    return 0;
}

// ॥ जय श्री राम जय श्री कृष्ण ॥